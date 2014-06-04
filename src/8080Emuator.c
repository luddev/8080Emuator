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

	Intel 8080 , Intel are registered copyrights of Intel® 
*/

/*!
	TODO : Add Init checks.
*/

#include "8080Emuator.h"
#include "8080Disasm.h"
#include <malloc.h>


int Init_8080(char *fileName, Context8080 *context, ROMFile *romFile)	
{
	FILE *rom_file;
	
	rom_file = fopen(fileName,"rb");
	int rsize;
	fseek(rom_file,0,SEEK_END);
	rsize = ftell(rom_file);
	fseek(rom_file,0,SEEK_SET);

	romFile->rsize = rsize;
	romFile->m_ROM = (unsigned char *)malloc(rsize + 1);
	fread(romFile->m_ROM,rsize,1,rom_file);



	fclose(rom_file);

	/*
	for(int i =0 ; i < rsize ; i++)	{
		fprintf(stdout, "%02x ", romFile->m_ROM[i]);
		if(i % 20 == 0)
			printf("\n");
	}
	printf("\n");
	*/
	//Init Context
	context->pc = 0;
	context->pflags.allFlag = 0;

	return 1;

}


int Dispose_8080(Context8080 *context, ROMFile *romFile)
{
	free(romFile->m_ROM);
}


int Disasm_8080(Context8080 *context, ROMFile *romFile)
{
	fprintf(stdout, "Disassembling Now ... \n");
	while(context->pc < romFile->rsize)	{
		context->pc += DisassembleOp_8080(romFile->m_ROM,context->pc);

	}
	return DISASM_OK_8080;

}

