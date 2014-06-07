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
		case 0x56:	fprintf(stdout, "0x%02x : MOV	D,M",pc );	opbytes=1;	break;
		case 0x57:	fprintf(stdout, "0x%02x : MOV	D,A",pc );	opbytes=1;	break;
		case 0x58:	fprintf(stdout, "0x%02x : MOV	E,B",pc );	opbytes=1;	break;
		case 0x59:	fprintf(stdout, "0x%02x : MOV	E,C",pc );	opbytes=1;	break;
		case 0x5A:	fprintf(stdout, "0x%02x : MOV	E,D",pc );	opbytes=1;	break;
		case 0x5B:	fprintf(stdout, "0x%02x : MOV	E,E",pc );	opbytes=1;	break;
		case 0x5C:	fprintf(stdout, "0x%02x : MOV	E,H",pc );	opbytes=1;	break;
		case 0x5D:	fprintf(stdout, "0x%02x : MOV	E,L",pc );	opbytes=1;	break;
		case 0x5E:	fprintf(stdout, "0x%02x : MOV	E,M",pc );	opbytes=1;	break;
		case 0x5F:	fprintf(stdout, "0x%02x : MOV	E,A",pc );	opbytes=1;	break;
		case 0x60:	fprintf(stdout, "0x%02x : MOV	H,B",pc );	opbytes=1;	break;
		case 0x61:	fprintf(stdout, "0x%02x : MOV	H,C",pc );	opbytes=1;	break;
		case 0x62:	fprintf(stdout, "0x%02x : MOV	H,D",pc );	opbytes=1;	break;
		case 0x63:	fprintf(stdout, "0x%02x : MOV	H,E",pc );	opbytes=1;	break;
		case 0x64:	fprintf(stdout, "0x%02x : MOV	H,H",pc );	opbytes=1;	break;
		case 0x65:	fprintf(stdout, "0x%02x : MOV	H,L",pc );	opbytes=1;	break;
		case 0x66:	fprintf(stdout, "0x%02x : MOV	H,M",pc );	opbytes=1;	break;
		case 0x67:	fprintf(stdout, "0x%02x : MOV	H,A",pc );	opbytes=1;	break;
		case 0x68:	fprintf(stdout, "0x%02x : MOV	L,B",pc );	opbytes=1;	break;
		case 0x69:	fprintf(stdout, "0x%02x : MOV	L,C",pc );	opbytes=1;	break;
		case 0x6A:	fprintf(stdout, "0x%02x : MOV	L,D",pc );	opbytes=1;	break;
		case 0x6B:	fprintf(stdout, "0x%02x : MOV	L,E",pc );	opbytes=1;	break;
		case 0x6C:	fprintf(stdout, "0x%02x : MOV	L,H",pc );	opbytes=1;	break;
		case 0x6D:	fprintf(stdout, "0x%02x : MOV	L,L",pc );	opbytes=1;	break;
		case 0x6E:	fprintf(stdout, "0x%02x : MOV	L,M",pc );	opbytes=1;	break;
		case 0x6F:	fprintf(stdout, "0x%02x : MOV	L,A",pc );	opbytes=1;	break;
		case 0x70:	fprintf(stdout, "0x%02x : MOV	M,B",pc );	opbytes=1;	break;
		case 0x71:	fprintf(stdout, "0x%02x : MOV	M,C",pc );	opbytes=1;	break;
		case 0x72:	fprintf(stdout, "0x%02x : MOV	M,D",pc );	opbytes=1;	break;
		case 0x73:	fprintf(stdout, "0x%02x : MOV	M,E",pc );	opbytes=1;	break;
		case 0x74:	fprintf(stdout, "0x%02x : MOV	M,H",pc );	opbytes=1;	break;
		case 0x75:	fprintf(stdout, "0x%02x : MOV	M,L",pc );	opbytes=1;	break;
		case 0x76:	fprintf(stdout, "0x%02x : HLT		",pc );	opbytes=1;	break;
		case 0x77:	fprintf(stdout, "0x%02x : MOV	M,A",pc );	opbytes=1;	break;
		case 0x78:	fprintf(stdout, "0x%02x : MOV	A,B",pc );	opbytes=1;	break;
		case 0x79:	fprintf(stdout, "0x%02x : MOV	A,C",pc );	opbytes=1;	break;
		case 0x7A:	fprintf(stdout, "0x%02x : MOV	A,D",pc );	opbytes=1;	break;
		case 0x7B:	fprintf(stdout, "0x%02x : MOV	A,E",pc );	opbytes=1;	break;
		case 0x7C:	fprintf(stdout, "0x%02x : MOV	A,H",pc );	opbytes=1;	break;
		case 0x7D:	fprintf(stdout, "0x%02x : MOV	A,L",pc );	opbytes=1;	break;
		case 0x7E:	fprintf(stdout, "0x%02x : MOV	A,M",pc );	opbytes=1;	break;
		case 0x7F:	fprintf(stdout, "0x%02x : MOV	A,A",pc );	opbytes=1;	break;
		case 0x80:	fprintf(stdout, "0x%02x : ADD	B",pc );	opbytes=1;	break;
		case 0x81:	fprintf(stdout, "0x%02x : ADD	C",pc );	opbytes=1;	break;
		case 0x82:	fprintf(stdout, "0x%02x : ADD	D",pc );	opbytes=1;	break;
		case 0x83:	fprintf(stdout, "0x%02x : ADD	E",pc );	opbytes=1;	break;
		case 0x84:	fprintf(stdout, "0x%02x : ADD	H",pc );	opbytes=1;	break;
		case 0x85:	fprintf(stdout, "0x%02x : ADD	L",pc );	opbytes=1;	break;
		case 0x86:	fprintf(stdout, "0x%02x : ADD	M",pc );	opbytes=1;	break;
		case 0x87:	fprintf(stdout, "0x%02x : ADD	A",pc );	opbytes=1;	break;
		case 0x88:	fprintf(stdout, "0x%02x : ADC	B",pc );	opbytes=1;	break;
		case 0x89:	fprintf(stdout, "0x%02x : ADC	C",pc );	opbytes=1;	break;
		case 0x8A:	fprintf(stdout, "0x%02x : ADC	D",pc );	opbytes=1;	break;
		case 0x8B:	fprintf(stdout, "0x%02x : ADC	E",pc );	opbytes=1;	break;
		case 0x8C:	fprintf(stdout, "0x%02x : ADC	H",pc );	opbytes=1;	break;
		case 0x8D:	fprintf(stdout, "0x%02x : ADC	L",pc );	opbytes=1;	break;
		case 0x8E:	fprintf(stdout, "0x%02x : ADC	M",pc );	opbytes=1;	break;
		case 0x8F:	fprintf(stdout, "0x%02x : ADC	A",pc );	opbytes=1;	break;
		case 0x90:	fprintf(stdout, "0x%02x : SUB	B",pc );	opbytes=1;	break;
		case 0x91:	fprintf(stdout, "0x%02x : SUB	C",pc );	opbytes=1;	break;
		case 0x92:	fprintf(stdout, "0x%02x : SUB	D",pc );	opbytes=1;	break;
		case 0x93:	fprintf(stdout, "0x%02x : SUB	E",pc );	opbytes=1;	break;
		case 0x94:	fprintf(stdout, "0x%02x : SUB	H",pc );	opbytes=1;	break;
		case 0x95:	fprintf(stdout, "0x%02x : SUB	L",pc );	opbytes=1;	break;
		case 0x96:	fprintf(stdout, "0x%02x : SUB	M",pc );	opbytes=1;	break;
		case 0x97:	fprintf(stdout, "0x%02x : SUB	A",pc );	opbytes=1;	break;
		case 0x98:	fprintf(stdout, "0x%02x : SBB	B",pc );	opbytes=1;	break;
		case 0x99:	fprintf(stdout, "0x%02x : SBB	C",pc );	opbytes=1;	break;
		case 0x9A:	fprintf(stdout, "0x%02x : SBB	D",pc );	opbytes=1;	break;
		case 0x9B:	fprintf(stdout, "0x%02x : SBB	E",pc );	opbytes=1;	break;
		case 0x9C:	fprintf(stdout, "0x%02x : SBB	H",pc );	opbytes=1;	break;
		case 0x9D:	fprintf(stdout, "0x%02x : SBB	L",pc );	opbytes=1;	break;
		case 0x9E:	fprintf(stdout, "0x%02x : SBB	M",pc );	opbytes=1;	break;
		case 0x9F:	fprintf(stdout, "0x%02x : SBB	A",pc );	opbytes=1;	break;
		case 0xA0:	fprintf(stdout, "0x%02x : ANA	B",pc );	opbytes=1;	break;
		case 0xA1:	fprintf(stdout, "0x%02x : ANA	C",pc );	opbytes=1;	break;
		case 0xA2:	fprintf(stdout, "0x%02x : ANA	D",pc );	opbytes=1;	break;
		case 0xA3:	fprintf(stdout, "0x%02x : ANA	E",pc );	opbytes=1;	break;
		case 0xA4:	fprintf(stdout, "0x%02x : ANA	H",pc );	opbytes=1;	break;
		case 0xA5:	fprintf(stdout, "0x%02x : ANA	L",pc );	opbytes=1;	break;
		case 0xA6:	fprintf(stdout, "0x%02x : ANA	M",pc );	opbytes=1;	break;
		case 0xA7:	fprintf(stdout, "0x%02x : ANA	A",pc );	opbytes=1;	break;
		case 0xA8:	fprintf(stdout, "0x%02x : XRA	B",pc );	opbytes=1;	break;
		case 0xA9:	fprintf(stdout, "0x%02x : XRA	C",pc );	opbytes=1;	break;
		case 0xAA:	fprintf(stdout, "0x%02x : XRA	D",pc );	opbytes=1;	break;
		case 0xAB:	fprintf(stdout, "0x%02x : XRA	E",pc );	opbytes=1;	break;
		case 0xAC:	fprintf(stdout, "0x%02x : XRA	H",pc );	opbytes=1;	break;
		case 0xAD:	fprintf(stdout, "0x%02x : XRA	L",pc );	opbytes=1;	break;
		case 0xAE:	fprintf(stdout, "0x%02x : XRA	M",pc );	opbytes=1;	break;
		case 0xAF:	fprintf(stdout, "0x%02x : XRA	A",pc );	opbytes=1;	break;
		case 0xB0:	fprintf(stdout, "0x%02x : ORA	B",pc );	opbytes=1;	break;
		case 0xB1:	fprintf(stdout, "0x%02x : ORA	C",pc );	opbytes=1;	break;
		case 0xB2:	fprintf(stdout, "0x%02x : ORA	D",pc );	opbytes=1;	break;
		case 0xB3:	fprintf(stdout, "0x%02x : ORA	E",pc );	opbytes=1;	break;
		case 0xB4:	fprintf(stdout, "0x%02x : ORA	H",pc );	opbytes=1;	break;
		case 0xB5:	fprintf(stdout, "0x%02x : ORA	L",pc );	opbytes=1;	break;
		case 0xB6:	fprintf(stdout, "0x%02x : ORA	M",pc );	opbytes=1;	break;
		case 0xB7:	fprintf(stdout, "0x%02x : ORA	A",pc );	opbytes=1;	break;
		case 0xB8:	fprintf(stdout, "0x%02x : CMP	B",pc );	opbytes=1;	break;
		case 0xB9:	fprintf(stdout, "0x%02x : CMP	C",pc );	opbytes=1;	break;
		case 0xBA:	fprintf(stdout, "0x%02x : CMP	D",pc );	opbytes=1;	break;
		case 0xBB:	fprintf(stdout, "0x%02x : CMP	E",pc );	opbytes=1;	break;
		case 0xBC:	fprintf(stdout, "0x%02x : CMP	H",pc );	opbytes=1;	break;
		case 0xBD:	fprintf(stdout, "0x%02x : CMP	L",pc );	opbytes=1;	break;
		case 0xBE:	fprintf(stdout, "0x%02x : CMP	M",pc );	opbytes=1;	break;
		case 0xBF:	fprintf(stdout, "0x%02x : CMP	A",pc );	opbytes=1;	break;
		case 0xC0:	fprintf(stdout, "0x%02x : RNZ	",pc );		opbytes=1;	break;
		case 0xC1:	fprintf(stdout, "0x%02x : POP	B",pc );	opbytes=1;	break;
		case 0xC2:	fprintf(stdout, "0x%02x : JNZ	#%02X%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xC3:	fprintf(stdout, "0x%02x : JMP	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xC4:	fprintf(stdout, "0x%02x : CNZ	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xC5:	fprintf(stdout, "0x%02x : PUSH 	B",pc );	opbytes=1;	break;
		case 0xC6:	fprintf(stdout, "0x%02x : ADI	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xC7:	fprintf(stdout, "0x%02x : RST 	0",pc );	opbytes=1;	break;
		case 0xC8:	fprintf(stdout, "0x%02x : R 	",pc );	opbytes=1;	break;
		case 0xC9:	fprintf(stdout, "0x%02x : RET 	",pc );	opbytes=1;	break;
		case 0xCA:	fprintf(stdout, "0x%02x : JZ 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xCB:	/*!	Unused Opcode. */	break;
		case 0xCC:	fprintf(stdout, "0x%02x : CZ 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xCD:	fprintf(stdout, "0x%02x : CALL 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xCE:	fprintf(stdout, "0x%02x : ACI 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xCF:	fprintf(stdout, "0x%02x : RST 	1",pc );	opbytes=1;	break;
		case 0xD0:	fprintf(stdout, "0x%02x : RNC	 ",pc );	opbytes=1;	break;
		case 0xD1:	fprintf(stdout, "0x%02x : POP	D",pc );	opbytes=1;	break;
		case 0xD2:	fprintf(stdout, "0x%02x : JNC	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xD3:	fprintf(stdout, "0x%02x : OUT 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xD4:	fprintf(stdout, "0x%02x : CNC	#%02x%02x",pc,code[2],code[1] );	opbytes=1;	break;
		case 0xD5:	fprintf(stdout, "0x%02x : PUSH 	D",pc );	opbytes=1;	break;
		case 0xD6:	fprintf(stdout, "0x%02x : SUI 	%02x",pc,code[1] );	opbytes=2;	break;
		case 0xD7:	fprintf(stdout, "0x%02x : RST 	2",pc );	opbytes=1;	break;
		case 0xD8:	fprintf(stdout, "0x%02x : RC 	 ",pc );	opbytes=1;	break;
		case 0xD9:	/*! Unused Opcode. */	break;
		case 0xDA:	fprintf(stdout, "0x%02x : JC 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xDB:	fprintf(stdout, "0x%02x : IN 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xDC:	fprintf(stdout, "0x%02x : CC 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xDD:	/*!	Unused Opcode */	break;
		case 0xDE:	fprintf(stdout, "0x%02x : SBI 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xDF:	fprintf(stdout, "0x%02x : RST 	3",pc );	opbytes=1;	break;
		case 0xE0:	fprintf(stdout, "0x%02x : RPO	 ",pc );	opbytes=1;	break;
		case 0xE1:	fprintf(stdout, "0x%02x : POP	H",pc );	opbytes=1;	break;
		case 0xE2:	fprintf(stdout, "0x%02x : JPO 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xE3:	fprintf(stdout, "0x%02x : XTHL	 ",pc );	opbytes=1;	break;
		case 0xE4:	fprintf(stdout, "0x%02x : CPO 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xE5:	fprintf(stdout, "0x%02x : PUSH 	H",pc );	opbytes=1;	break;
		case 0xE6:	fprintf(stdout, "0x%02x : ANI 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xE7:	fprintf(stdout, "0x%02x : RST 	4",pc );	opbytes=1;	break;
		case 0xE8:	fprintf(stdout, "0x%02x : RPE 	 ",pc );	opbytes=1;	break;
		case 0xE9:	fprintf(stdout, "0x%02x : PCHL 	 ",pc );	opbytes=1;	break;
		case 0xEA:	fprintf(stdout, "0x%02x : JPE 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xEB:	fprintf(stdout, "0x%02x : XCHG	 ",pc );	opbytes=1;	break;
		case 0xEC:	fprintf(stdout, "0x%02x : CPE 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xED:	/*! Unused Opcode. */	break;
		case 0xEE:	fprintf(stdout, "0x%02x : XRI 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xEF:	fprintf(stdout, "0x%02x : RST 	5",pc );	opbytes=1;	break;
		case 0xF0:	fprintf(stdout, "0x%02x : RP 	 ",pc );	opbytes=1;	break;
		case 0xF1:	fprintf(stdout, "0x%02x : POP	PSW",pc );	opbytes=1;	break;
		case 0xF2:	fprintf(stdout, "0x%02x : JP 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xF3:	fprintf(stdout, "0x%02x : DI 	 ",pc );	opbytes=1;	break;
		case 0xF4:	fprintf(stdout, "0x%02x : CP 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xF5:	fprintf(stdout, "0x%02x : PUSH 	PSW",pc );	opbytes=1;	break;
		case 0xF6:	fprintf(stdout, "0x%02x : ORI 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xF7:	fprintf(stdout, "0x%02x : RST 	6",pc );	opbytes=1;	break;
		case 0xF8:	fprintf(stdout, "0x%02x : RM 	 ",pc );	opbytes=1;	break;
		case 0xF9:	fprintf(stdout, "0x%02x : SPHL	 ",pc );	opbytes=1;	break;
		case 0xFA:	fprintf(stdout, "0x%02x : JM 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xFB:	fprintf(stdout, "0x%02x : EI 	 ",pc );	opbytes=1;	break;
		case 0xFC:	fprintf(stdout, "0x%02x : CM 	#%02x%02x",pc,code[2],code[1] );	opbytes=3;	break;
		case 0xFD:	/*!	Unused Opcode. */	break;
		case 0xFE:	fprintf(stdout, "0x%02x : CPI 	#%02x",pc,code[1] );	opbytes=2;	break;
		case 0xFF:	fprintf(stdout, "0x%02x : RST 	7",pc );	opbytes=1;	break;

		default:	fprintf(stdout, "Invalid Opcode.");	break;
	}
	printf("\n");

	return opbytes;
}

