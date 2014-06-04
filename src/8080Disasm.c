/*
	8080Emuator is a Intel 8080 Emulator which can load and execute Intel 8080 Programs.
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

	Intel 8080 , Intel are registered copyrights of Intel® 
*/

/*	\file 
	\author
	\date
*/

#include "8080Disasm.h"
#include <stdio.h>

int DisassembleOp_8080(unsigned char *rom, int pc)
{
	unsigned char *code = (char *)((void *)rom + pc);

	int opbytes = 1;
	switch(*code)	{
		case 0x00:	fprintf(stdout, "0x%02x 0x%02x : NOP ",pc,*code );	break;
		case 0x01:	fprintf(stdout, "0x%02x 0x%02x : LXI \n", );
		case 0x02:	break;
		case 0x03:	break;
		case 0x04:	break;
		case 0x05:	break;
		case 0x06:	break;
		case 0x07:	break;
		case 0x08:	break;
		case 0x09:	break;
		case 0xA:	break;
		case 0xB:	break;
		case 0xC:	break;
		case 0xD:	break;
		case 0xE:	break;
		case 0xF:	break;
		case 0x10:	break;
		case 0x11:	break;
		case 0x12:	break;
		case 0x13:	break;
		case 0x14:	break;
		case 0x15:	break;
		case 0x16:	break;
		case 0x17:	break;
		case 0x18:	break;
		case 0x19:	break;
		case 0x1A:	break;
		case 0x1B:	break;
		case 0x1C:	break;
		case 0x1D:	break;
		case 0x1E:	break;
		case 0x1F:	break;
		case 0x20:	break;
		case 0x21:	break;
		case 0x22:	break;
		case 0x23:	break;
		case 0x24:	break;
		case 0x25:	break;
		case 0x26:	break;
		case 0x27:	break;
		case 0x28:	break;
		case 0x29:	break;
		case 0x2A:	break;
		case 0x2B:	break;
		case 0x2C:	break;
		case 0x2D:	break;
		case 0x2E:	break;
		case 0x2F:	break;
		case 0x30:	break;
		case 0x31:	break;
		case 0x32:	break;
		case 0x33:	break;
		case 0x34:	break;
		case 0x35:	break;

		default:	fprintf(stdout, "Invalid Opcode.\n");	break;
	}
	printf("\n");

	return opbytes;
}

