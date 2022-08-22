#! /bin/bash

#===================================
# System Information & Operations
# Bailey Williams
#===================================
# This program is demonstrating a script which a system administrator may find useful when tracking 
# different users activity, storage, and data. A system administrator can use this script to 
# backup & recover files, see context switching, the # of threads, the # of processes, the 
# # of interrupts, the users uptime including in kernal mode, and finally the disk and home space.

clear

backup_dir="backup"         #dir that will have the backups
working_dir="working"       #dir that is to be backed up
recovery_dir="recovery"     #dir where you want your recovery to be copied to
temp_dir="temp"             #needed temp dir

#function to backup files in working dir
function backup {
	{
    new_backup=B$(date +"%Y%m%d%H%M%S")
    if [ "$(ls -A $backup_dir)" ]; then
        mkdir $new_backup
        rsync -a  $working_dir"/" $temp_dir
        for entry in "$backup_dir"/*
        do
          rm -r $new_backup
          rsync -a  --compare-dest=../$entry/ $temp_dir/ $new_backup
          rm -r $temp_dir
          rsync -a $new_backup/ $temp_dir
        done
        mv $new_backup $backup_dir/$new_backup
        rm -r $temp_dir
    else
        rsync -av  $working_dir"/" backup/$new_backup
    fi
	} | whiptail --gauge "Backing up data ..." 10 60 0
}


#function that recovers files using the backup dir
function recovery {
	{
	  if [ "$(ls -A $backup_dir)" ]; then
    mkdir $temp_dir
    for entry in "$backup_dir"/*
    do
      rsync -av  --compare-dest=../$temp_dir/ $entry/ $recovery_dir
      rm -r $temp_dir
      rsync -av $recovery_dir/ $temp_dir/
      done
      rm -r $temp_dir
    else
      echo "No backup found"
    fi
	} | whiptail --gauge "Recovering data ..." 10 60 0
}

#function gets the # of context switching going on
function contextSwitch {
	{
	ctxt1=$(grep ctxt /proc/stat | awk '{print $2}')
        echo 50
	sleep 1
        ctxt2=$(grep ctxt /proc/stat | awk '{print $2}')
        ctxt=$(($ctxt2 - $ctxt1))
        result="Number os context switches: $ctxt"
	echo $result > result
	} | whiptail --gauge "Getting data ..." 10 60 0
}


#function gets the uptime in user and kernel made
function userKernelMode {
	{	
	raw=( $(grep "cpu " /proc/stat) )
        userfirst=$((${raw[1]} + ${raw[2]}))
        kernelfirst=${raw[3]}
	echo 50
        sleep 1
	raw=( $(grep "cpu " /proc/stat) )
        user=$(( $((${raw[1]} + ${raw[2]})) - $userfirst ))
	echo 90
        kernel=$(( ${raw[3]} - $kernelfirst ))
        sum=$(($kernel + $user))
        result="Percentage in usermode: \
        $((( $user*100)/$sum ))% \
        \nand in kernelmode: $((($kernel*100)/$sum ))%"
	echo $result > result
	echo 100
	} | whiptail --gauge "Getting data ..." 10 60 0
} 

#function gets the # of interupts
function interrupts {
	{
	ints=$(vmstat 1 2 | tail -1 | awk '{print $11}')
        result="Number of interupts:  $ints"
	echo 100
	echo $result > result
	} | whiptail --gauge "Getting data ..." 10 60 50
}

#function gets disk space utilization
function system_ds {	
        ds=$(df -h)
}| whiptail --gauge "Getting data ..." 10 60 0

#function gets home space of user
function home_space {
    #only superuser can get this information
    if [[ $(id -u ) == 0 ]]; then
        homespace=$(du -s /home* | sort -nr)
    fi
}| whiptail --gauge "Getting data ..." 10 60 0

# simple firewall using iptables
# will only be run if done by root user
iptables -F
iptables -X
iptables -t nat -F
iptables -t nat -X
iptables -t mangle -F
iptables -t mangle -X
modprobe ip_conntrack
modprobe ip_conntrack_ftp

# default filter
iptables -P INPUT DROP
iptables -P OUTPUT ACCEPT

#  access to loop back
iptables -A INPUT -i lo -j ACCEPT
iptables -A OUTPUT -o lo -j ACCEPT

# allow  UDP, DNS and Passive FTP
iptables -A INPUT -i eth0 -m state --state ESTABLISHED,RELATED -j ACCEPT

# drop and log it
iptables -A INPUT -j LOG
iptables -A INPUT -j DROP

backup
cat > "backup_$(date '+%F_%I_%M_%S%P').txt" <<- _EOF_
        System Information
	$(date)
	uptime=$(uptime | awk '{print $3;}')
	processes=$(ps ax | wc -l)
	threads=$(ps amx | wc -l)
	diskspace=$(df -h)
	homespace=$(du -s /home* | sort -nr)
	Directory backup complete.

_EOF_



while [ 1 ]
do
CHOICE=$(
whiptail --title "Operative & Backup System" --menu "Make your choice" 20 100 12 \
	"1)" "The name of this script."   \
	"2)" "Time since last boot."  \
	"3)" "Number of processes and threads." \
	"4)" "Number of context switches." \
	"5)" "How much time used in kernel mode and in user mode." \
	"6)" "Number of interrupts." \
	"7)" "Backup Files." \
	"8)" "Recover Files." \
	"9)" "Disk Space Utilization." \
	"10)" "Home Directory Space." \
	"11)" "End script"  3>&2 2>&1 1>&3	
)


result=$(whoami)
case $CHOICE in
	"1)")   
		result="I am $result, the name of the script is system"
	;;
	"2)")   
	        OP=$(uptime | awk '{print $3;}')
		result="This system has been up $OP minutes"
	;;

	"3)")   
	        p=$(ps ax | wc -l)
                t=$(ps amx | wc -l)
		result="Number of processes $p\nNumber os threads $t"
        ;;

	"4)")   
	        contextSwitch
		read -r result < result
        ;;

	"5)")   
                userKernelMode
		read -r result < result
        ;;

	"6)")   
		interrupts
		read -r result < result
        ;;
	"7)")
		backup
	;;
	"8)")
	  	recovery
	;;
	"9)")
		ds=$(df -h)
		result="Disk space utilization: $ds"
        ;;
	"10)") 
		homespace=$(du -s /home* | sort -nr)
		result="Home directory space: $homespace"
        ;;
	"11)") exit
        ;;
esac
whiptail --msgbox "$result" 30 78
done
exit


