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
	\file 8080Emulator.h
	\brief Contains Required data for 8080 Emulation.

	\Author ludkiller
	\Date 02/06/2014

*/

#ifndef _8080_EMUATOR_H
#define _8080_EMUATOR_H

#define MAX_ROM_SIZE 2048

/*!
	\brief enum for 8080Emuator error and other codes.

*/

enum 
{
	BAD_OPCODE_8080 = 0,	/*!< if bad opcode return this. */
	BAD_MEMORY_8080
};

enum 
{ 	
	INIT_OK_8080,
	INIT_FAIL_8080,
	DISASM_OK_8080
};

/*!
	\brief status flags present in 8080Emuator in accordance with Intel® 8080 Documentation.
*/

typedef union	
{
	int allFlag;
	char c,z,e,d;

}statusFlags;

/*!
	\brief Flags for 8080 CPU.
*/


/*!
	\brief Context for our emulated 8080 Processor.

	Context8080 contains Processor current status.
*/

typedef struct 
{
	int pc;
	statusFlags pflags;
}Context8080;

/*!
	\brief ROM File currently handled by our program.
	
	ROMFile contains ROM File currently handled and other relevant data.


*/

typedef struct	
{
	int rsize;
	unsigned char *m_ROM;
}ROMFile;

/*!
	\brief Initialize 8080 Context and other required files.
	\param fileName : rom Filename.
	\param context : a pointer to 8080Context struct.
	\param romFile : a pointer to ROMFile struct.
*/

int Init_8080(char *fileName, Context8080 *context, ROMFile *romFile);

/*!
	\brief Disposes 8080 Context and Other dynamically allocated values.
	\param context : a pointer to 8080Context struct.
	\param romFile : a pointer to ROMFile struct.
	
*/

int Dispose_8080(Context8080 *context, ROMFile *romFile);

/*!
	\brief Main Disassemble loop to Disassemble the while data.
	\param context : a pointer to 8080Context struct.
	\param romFile : a pointer to ROMFile struct.
	
*/

int Disasm_8080(Context8080 *context, ROMFile *romFile);



#endif // _8080_EMUATOR_H
