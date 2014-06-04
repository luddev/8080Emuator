/*
	8080Emuator is a Intel® 8080 Emulator which can load and execute Intel® 8080 Programs.
	Copyright (C) 2014-2016 ludkiller

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

	Intel 8080 , Intel are registered copyrights of Intel®.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <getopt.h>

#include "8080Emuator.h"
#include "8080Disasm.h"

int main(int argc, char **argv)	
{

	int rflag = 0;
    int dflag = 0;
    char c;

    char *rvalue = NULL;
    char *dvalue = NULL;

    while ((c = getopt(argc, argv, "r:d")) != -1)
	switch (c) {
	case 'd':
	    dflag = 1;
	    break;
	case 'r':
	    rflag = 1;
	    rvalue = optarg;
	    break;
	case '?':
	    //print help? 
		fprintf(stdout, "Usage : %s -r romFile.bin -d\n",argv[0] );
		fprintf(stdout, "-r : provide rom File \n-d to print disassembly \n");
	    return 1;
	default:
	    abort();
	}

	if(!rflag && !rvalue)	{
		fprintf(stdout, "Usage : %s -r romFile.bin -d\n",argv[0] );
		fprintf(stdout, "-r : provide rom File \n-d to print disassembly \n");
		return 1;
	}

	//Declare Processor Context and ROM Files.
	Context8080 context;
	ROMFile romFile;
	
	Init_8080(rvalue,&context,&romFile);

	Disasm_8080(&context,&romFile);


	return 0;
}
