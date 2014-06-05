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

/*	\file 8080Disasm.c
	\author	ludkiller
	\date	03/06/2014
	\TODO : Fix all Instructions taking 3 bytes.
*/

#include "8080Disasm.h"
#include <stdio.h>

int DisassembleOp_8080(unsigned char *rom, int pc)
{
	unsigned char *code = (char *)((void *)rom + pc);

	int opbytes = 1;
	switch(*code)	{
		case 0x00:	fprintf(stdout, "0x%02x : NOP",pc);	break;
		case 0x01:	fprintf(stdout, "0x%02x : LXI	B,#%02x%02x",pc, code[2],code[1]);	opbytes=3; break;
		case 0x02:	fprintf(stdout, "0x%02x : STAX	B",pc );	opbytes=1;	break;
		case 0x03:	fprintf(stdout, "0x%02x : INX	B",pc);		opbytes=1; break;
		case 0x04:	fprintf(stdout, "0x%02x : INR	B",pc );	opbytes=1;	break;
		case 0x05:	fprintf(stdout, "0x%02x : DCR	B",pc );	opbytes=1;	break;
		case 0x06:	fprintf(stdout, "0x%02x	: MVI	B,#%02x",pc,code[1]);	opbytes=2;	break;
		case 0x07:	fprintf(stdout, "0x%02x : RLC	",pc );		opbytes=1;	break;
		case 0x08:	/*! Not Used. */	break;
		case 0x09:	fprintf(stdout, "0x%02x : DAD	B",pc );	opbytes=1;	break;
		case 0x0A:	fprintf(stdout, "0x%02x : LDAX	B",pc );	opbytes=1;	break;
		case 0x0B:	fprintf(stdout, "0x%02x : DCX	B",pc );	opbytes=1;	break;
		case 0x0C:	fprintf(stdout, "0x%02x : INR	C",pc );	opbytes=1;	break;
		case 0x0D:	fprintf(stdout, "0x%02x : DCR	C",pc );	opbytes=1;	break;
		case 0x0E:	fprintf(stdout, "0x%02x : MVI	C,%02x",pc,code[1] );	opbytes=2;	break;
		case 0x0F:	fprintf(stdout, "0x%02x : RRC	", pc);		opbytes=1;	break;
		case 0x10:	/*! Not Used. */	break;
		case 0x11:	fprintf(stdout, "0x%02x : LXI	D,#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0x12:	fprintf(stdout, "0x%02x : STAX	D",pc );	opbytes=1;	break;
		case 0x13:	fprintf(stdout, "0x%02x : INX	D",pc );	opbytes=1;	break;
		case 0x14:	fprintf(stdout, "0x%02x : INR	D",pc );	opbytes=1;	break;
		case 0x15:	fprintf(stdout, "0x%02x : DCR	D",pc );	opbytes-1;	break;
		case 0x16:	fprintf(stdout, "0x%02x : MVI	D,#%02x",pc,code[1] );	opbytes=2;	break;
		case 0x17:	fprintf(stdout, "0x%02x : RAL	",pc );		opbytes=1;	break;
		case 0x18:	/*! Not Used. */	break;
		case 0x19:	fprintf(stdout, "0x%02x : DAD	D",pc );	opbytes=1;	break;
		case 0x1A:	fprintf(stdout, "0x%02x : LDAX	D",pc );	opbytes=1;	break;
		case 0x1B:	fprintf(stdout, "0x%02x : DCX	D",pc );	opbytes=1;	break;
		case 0x1C:	fprintf(stdout, "0x%02x : INR	E",pc );	opbytes=1;	break;
		case 0x1D:	fprintf(stdout, "0x%02x : DCR	E",pc );	opbytes=1;	break;
		case 0x1E:	fprintf(stdout, "0x%02x : MVI	E,#%02x",pc,code[1] );	opbytes=2;	break;
		case 0x1F:	fprintf(stdout, "0x%02x : RAR	",pc );		opbytes=1;	break;
		case 0x20:	fprintf(stdout, "0x%02x : RIM	",pc );		opbytes=1;	break;
		case 0x21:	fprintf(stdout, "0x%02x : LXI	H,#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0x22:	fprintf(stdout, "0x%02x : SHLD 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0x23:	fprintf(stdout, "0x%02x : INX	H",pc );	opbytes=1;	break;
		case 0x24:	fprintf(stdout, "0x%02x : INR	H",pc );	opbytes=1;	break;
		case 0x25:	fprintf(stdout, "0x%02x : DCR	H",pc );	opbytes=1;	break;
		case 0x26:	fprintf(stdout, "0x%02x : MVI	H,#%02x",pc,code[1] );	opbytes=2;	break;
		case 0x27:	fprintf(stdout, "0x%02x : DAA	",pc );		opbytes=1;	break;
		case 0x28:	/*! Not Used. */	break;
		case 0x29:	fprintf(stdout, "0x%02x : DAD	H",pc );	opbytes=1;	break;
		case 0x2A:	fprintf(stdout, "0x%02x : LHLD	#%02x%02x",pc,code[1],code[0] );	opbytes=3;break;
		case 0x2B:	fprintf(stdout, "0x%02x : DCX	H",pc );	opbytes=1;	break;
		case 0x2C:	fprintf(stdout, "0x%02x : INR	L",pc );	opbytes=1;	break;
		case 0x2D:	fprintf(stdout, "0x%02x : DCR	L",pc );	opbytes=1;	break;
		case 0x2E:	fprintf(stdout, "0x%02x : MVI	L,#%02x",pc,code[1] );	opbytes=2;	break;
		case 0x2F:	fprintf(stdout, "0x%02x : CMA	",pc );		opbytes=1;	break;
		case 0x30:	fprintf(stdout, "0x%02x : SIM	",pc );		opbytes=1;	break;
		case 0x31:	fprintf(stdout, "0x%02x : LXI	SP,%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0x32:	fprintf(stdout, "0x%02x : STA 	%02x%02x",pc ,code[2],code[1] );	opbytes=3;	break;
		case 0x33:	fprintf(stdout, "0x%02x : INX	SP",pc );	opbytes=1;	break;
		case 0x34:	fprintf(stdout, "0x%02x : INR	M",pc );	opbytes=1;	break;
		case 0x35:	fprintf(stdout, "0x%02x : DCR	M",pc );	opbytes=1;	break;
		case 0x36:	fprintf(stdout, "0x%02x : MVI	M,#%02x",pc,code[1] );	opbytes=2;	break;
		case 0x37:	fprintf(stdout, "0x%02x : STC 	",pc );		opbytes=1;	break;
		case 0x38:	/*!	Not Used. */	break;
		case 0x39:	fprintf(stdout, "0x%02x : DAD	SP",pc );	opbytes=1;	break;
		case 0x3A:	fprintf(stdout, "0x%02x : LDA 	%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0x3B:	fprintf(stdout, "0x%02x : DCX	SP",pc );	opbytes=1;	break;
		case 0x3C:	fprintf(stdout, "0x%02x : INR 	A",pc );	opbytes=1;	break;
		case 0x3D:	fprintf(stdout, "0x%02x : DCR	A",pc );	opbytes=1;	break;
		case 0x3E:	fprintf(stdout, "0x%02x : MVI	A,#%02x",pc,code[1] );	opbytes=2;	break;
		case 0x3F:	fprintf(stdout, "0x%02x : CMC	",pc );		opbytes=1;	break;
		case 0x40:	fprintf(stdout, "0x%02x : MOV	B,B",pc );	opbytes=1;	break;
		case 0x41:	fprintf(stdout, "0x%02x : MOV	B,C",pc );	opbytes=1;	break;
		case 0x42:	fprintf(stdout, "0x%02x : MOV	B,D",pc );	opbytes=1;	break;
		case 0x43:	fprintf(stdout, "0x%02x : MOV	B,E",pc );	opbytes=1;	break;
		case 0x44:	fprintf(stdout, "0x%02x : MOV	B,H",pc );	opbytes=1;	break;
		case 0x45:	fprintf(stdout, "0x%02x : MOV	B,L",pc );	opbytes=1;	break;
		case 0x46:	fprintf(stdout, "0x%02x : MOV	B,M",pc );	opbytes=1;	break;
		case 0x47:	fprintf(stdout, "0x%02x : MOV	B,A",pc );	opbytes=1;	break;
		case 0x48:	fprintf(stdout, "0x%02x : MOV	C,B",pc );	opbytes=1;	break;
		case 0x49:	fprintf(stdout, "0x%02x : MOV	C,C",pc );	opbytes=1;	break;
		case 0x4A:	fprintf(stdout, "0x%02x : MOV	C,D",pc );	opbytes=1;	break;
		case 0x4B:	fprintf(stdout, "0x%02x : MOV	C,E",pc );	opbytes=1;	break;
		case 0x4C:	fprintf(stdout, "0x%02x : MOV	C,H",pc );	opbytes=1;	break;
		case 0x4D:	fprintf(stdout, "0x%02x : MOV	C,L",pc );	opbytes=1;	break;
		case 0x4E:	fprintf(stdout, "0x%02x : MOV	C,M",pc );	opbytes=1;	break;
		case 0x4F:	fprintf(stdout, "0x%02x : MOV	C,A",pc );	opbytes=1;	break;
		case 0x50:	fprintf(stdout, "0x%02x : MOV	D,B",pc );	opbytes=1;	break;
		case 0x51:	fprintf(stdout, "0x%02x : MOV	D,C",pc );	opbytes=1;	break;
		case 0x52:	fprintf(stdout, "0x%02x : MOV	D,D",pc );	opbytes=1;	break;
		case 0x53:	fprintf(stdout, "0x%02x : MOV	D,E",pc );	opbytes=1;	break;
		case 0x54:	fprintf(stdout, "0x%02x : MOV	D,H",pc );	opbytes=1;	break;
		case 0x55:	fprintf(stdout, "0x%02x : MOV	D,L",pc );	opbytes=1;	break;
		default:	fprintf(stdout, "Invalid Opcode.");	break;
	}
	printf("\n");

	return opbytes;
}

