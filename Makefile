#
#	Project : 8080Emuator
#	Initial Author : ludkiller
#	Created : 03/06/2014
#	License : GNU GPL V2
#

#Compiler
CC = gcc

#linker
LD = ld

#Compile flags
CFLAGS = -c -std=c11

#Linker flags
LDFLAGS = 

#Required libraries.
LFLAGS = 

#Build path.
BUILDPATH = build/

#Output File Name
OFILE = 8080Emuator

all:link
	rm *.o

link:compile
	${CC} *.o -o ${BUILDPATH}${OFILE}

compile:
	${CC} ${CFLAGS} src/*.c

clean:
	rm *.o

indent:
