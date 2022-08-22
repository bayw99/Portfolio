#! /usr/bin/env python

# 1. ./segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 0
# Virtual Address Trace
# VA  0: 0x0000006c (decimal:  108) --> PA or segmentation violation? SEG1 Decimal Address: 492
# (108) base 10 = (1101100) base 2
# Max Segment = 2^(log2(128) - 1) = 2^(7 - 1) = 2^(6) = 64
# Decimal Representation of 0b101100 = 44
# Offset = 44 - 64 = -20
# |-20| <= 20 True (Valid)
# Physical Address = Base + Offset = 512 - 20 = 492
# Segment 1 
# VA  1: 0x00000061 (decimal:   97) --> PA or segmentation violation? SEG1 Violation
# VA  2: 0x00000035 (decimal:   53) --> PA or segmentation violation? SEG0 Violation
# VA  3: 0x00000021 (decimal:   33) --> PA or segmentation violation? SEG0 Violation
# VA  4: 0x00000041 (decimal:   65) --> PA or segmentation violation? SEG1 Violation
# ./segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 1
# Virtual Address Trace
# VA  0: 0x00000011 (decimal:   17) --> PA or segmentation violation? SEG0 Decimal Address: 17
# VA  1: 0x0000006c (decimal:  108) --> PA or segmentation violation? SEG1 Decimal Address: 492
# VA  2: 0x00000061 (decimal:   97) --> PA or segmentation violation? SEG1 Violation
# VA  3: 0x00000020 (decimal:   32) --> PA or segmentation violation? SEG0 Violation
# VA  4: 0x0000003f (decimal:   63) --> PA or segmentation violation? SEG0 Violation
#./segmentation.py -a 128 -p 512 -b 0 -l 20 -B 512 -L 20 -s 2 
# Virtual Address Trace
# VA  0: 0x0000007a (decimal:  122) --> PA or segmentation violation? SEG1 Decimal Address: 506
# VA  1: 0x00000079 (decimal:  121) --> PA or segmentation violation? SEG1 Decimal Address: 505
# VA  2: 0x00000007 (decimal:    7) --> PA or segmentation violation? SEG0 Decimal Address: 7
# VA  3: 0x0000000a (decimal:   10) --> PA or segmentation violation? SEG0 Decimal Address: 10
# VA  4: 0x0000006a (decimal:  106) --> PA or segmentation violation? SEG1 Violation

# 2. 
# Highest Legal VA in Seg 0 = 19
# Lowest Legal VA in Seg 1 = 108
# Lowest Illegal VA in Whole Address Space = 20
# Highest Illegal VA in Whole Address Space = 107

# 3. ./segmentation.py -a 16 -p 128 -A 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 --b0 0 --l0 2 --b1 128 --l1 2 -c
# SEG0 base = 0
# SEG0 bound = 2
# SEG1 base = 128
# SEG1 bound = 2

# 4. ./segmentation.py -a 256 -p 1024 --b0 0 --l0 115 --b1 1024 --l1 115 -c -n 100
# 256 * 0.9 = 115
# SEG0 & SEG1 bound is important 

import sys
from optparse import OptionParser
import random
import math

def convert(size):
    length = len(size)
    lastchar = size[length-1]
    if (lastchar == 'k') or (lastchar == 'K'):
        m = 1024
        nsize = int(size[0:length-1]) * m
    elif (lastchar == 'm') or (lastchar == 'M'):
        m = 1024*1024
        nsize = int(size[0:length-1]) * m
    elif (lastchar == 'g') or (lastchar == 'G'):
        m = 1024*1024*1024
        nsize = int(size[0:length-1]) * m
    else:
        nsize = int(size)
    return nsize


#
# main program
#
parser = OptionParser()
parser.add_option("-s", "--seed", default=0, help="the random seed", 
                  action="store", type="int", dest="seed")
parser.add_option("-A", "--addresses", default="-1",
                  help="a set of comma-separated pages to access; -1 means randomly generate", 
                  action="store", type="string", dest="addresses")
parser.add_option("-a", "--asize", default="1k",
                  help="address space size (e.g., 16, 64k, 32m, 1g)", 
                  action="store", type="string", dest="asize")
parser.add_option("-p", "--physmem", default="16k",
                  help="physical memory size (e.g., 16, 64k, 32m, 1g)", 
                  action="store", type="string", dest="psize")
parser.add_option("-n", "--numaddrs", default=5,
                  help="number of virtual addresses to generate",
                  action="store", type="int", dest="num")
parser.add_option("-b", "--b0", default="-1",
                  help="value of segment 0 base register",
                  action="store", type="string", dest="base0")
parser.add_option("-l", "--l0", default="-1",
                  help="value of segment 0 limit register",
                  action="store", type="string", dest="len0")
parser.add_option("-B", "--b1", default="-1",
                  help="value of segment 1 base register",
                  action="store", type="string", dest="base1")
parser.add_option("-L", "--l1", default="-1",
                  help="value of segment 1 limit register",
                  action="store", type="string", dest="len1")
parser.add_option("-c", help="compute answers for me",
                  action="store_true", default=False, dest="solve")


(options, args) = parser.parse_args()

print ("ARG seed"), options.seed
print ("ARG address space size"), options.asize
print ("ARG phys mem size"), options.psize
print ("")

random.seed(options.seed)
asize = convert(options.asize)
psize = convert(options.psize)
addresses = str(options.addresses)

if psize <= 1:
    print ('Error: must specify a non-zero physical memory size.')
    exit(1)

if asize == 0:
    print ('Error: must specify a non-zero address-space size.')
    exit(1)

if psize <= asize:
    print ('Error: physical memory size must be GREATER than address space size (for this simulation)')
    exit(1)

#
# need to generate base, bounds for segment registers
#
len0 = convert(options.len0)
len1 = convert(options.len1)
base0 = convert(options.base0)
base1 = convert(options.base1)

if len0 == -1:
    len0 = int(asize/4.0 + (asize/4.0 * random.random()))

if len1 == -1:
    len1 = int(asize/4.0 + (asize/4.0 * random.random()))

# now have to find room for them
if base0 == -1:
    done = 0
    while done == 0:
        base0 = int(psize * random.random())
        if (base0 + len0) < psize:
            done = 1

# internally, base1 points to the lower address, and base1+len1 the higher address
# (this differs from what the user would pass in, for example)
if base1 == -1:
    done = 0
    while done == 0:
        base1 = int(psize * random.random())
        if (base1 + len1) < psize:
            if (base1 > (base0 + len0)) or ((base1 + len1) < base0):
                done = 1
else:
    base1 = base1 - len1


if len0 > asize/2.0 or len1 > asize/2.0:
    print ('Error: length register is too large for this address space')
    exit(1)


print ('Segment register information:')
print ('')
print ('  Segment 0 base  (grows positive) : 0x%08x (decimal %d)' % (base0, base0))
print ('  Segment 0 limit                  : %d' % (len0))
print ('')
print ('  Segment 1 base  (grows negative) : 0x%08x (decimal %d)' % (base1+len1, base1+len1))
print ('  Segment 1 limit                  : %d' % (len1))
print ('')
nbase1  = base1 + len1

if (len0 + base0) > (base1) and (base1 > base0):
    print ('Error: segments overlap in physical memory')
    exit(1)


addrList = []
if addresses == '-1':
    # need to generate addresses
    for i in range(0, options.num):
        n = int(asize * random.random())
        addrList.append(n)
else:
    addrList = addresses.split(',')

#
# now, need to generate virtual address trace
#
print ('Virtual Address Trace')
i = 0
for vStr in addrList:
    # vaddr = int(asize * random.random())
    vaddr = int(vStr)
    if vaddr < 0 or vaddr >= asize:
        print ('Error: virtual address %d cannot be generated in an address space of size %d' % (vaddr, asize))
        exit(1)
    if options.solve == False:
        print ('  VA %2d: 0x%08x (decimal: %4d) --> PA or segmentation violation?' % (i, vaddr, vaddr))
    else:
        paddr = 0
        if (vaddr >= (asize / 2)):
            # seg 1
            paddr = nbase1 + (vaddr - asize)
            if paddr < base1:
                print ('  VA %2d: 0x%08x (decimal: %4d) --> SEGMENTATION VIOLATION (SEG1)' % (i, vaddr, vaddr))
            else:
                print ('  VA %2d: 0x%08x (decimal: %4d) --> VALID in SEG1: 0x%08x (decimal: %4d)' % (i, vaddr, vaddr, paddr, paddr))
        else:
            # seg 0
            if (vaddr >= len0):
                print ('  VA %2d: 0x%08x (decimal: %4d) --> SEGMENTATION VIOLATION (SEG0)' % (i, vaddr, vaddr))
            else:
                paddr = vaddr + base0
                print ('  VA %2d: 0x%08x (decimal: %4d) --> VALID in SEG0: 0x%08x (decimal: %4d)' % (i, vaddr, vaddr, paddr, paddr))
    i += 1

print ('')

if options.solve == False:
    print ('For each virtual address, either write down the physical address it translates to')
    print ('OR write down that it is an out-of-bounds address (a segmentation violation). For')
    print ('this problem, you should assume a simple address space with two segments: the top')
    print ('bit of the virtual address can thus be used to check whether the virtual address')
    print ('is in segment 0 (topbit=0) or segment 1 (topbit=1). Note that the base/limit pairs')
    print ('given to you grow in different directions, depending on the segment, i.e., segment 0')
    print ('grows in the positive direction, whereas segment 1 in the negative. ')
    print ('')





