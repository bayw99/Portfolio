import socket                   

port = 60000                    # Reserve a port 
s = socket.socket()             # Create a socket 
host = socket.gethostname()     
s.bind((host, port))            
s.listen(5)                     # Wait for connection

print ('Server listening....')

while True:
    conn, addr = s.accept()     # Connect with client
    print ('Got connection from'), addr
    data = conn.recv(1024)
    print('Server received', repr(data))

    filename='test.txt'
    f = open(filename,'rb')
    l = f.read(1024)
    while (l):
       conn.send(l)
       print('Sent ',repr(l))
       l = f.read(1024)
    f.close()

    print('Done sending')
    conn.close()