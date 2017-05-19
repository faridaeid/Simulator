#include "Jmp0Instr.h"
#include <iostream>

Jmp0Instr::Jmp0Instr(Operand* in1Param, AddressOperand* a1Param, int* pcPointer, int* instrMax, std::string s)
{
	a1 = a1Param;
	in1 = in1Param;
	pc = pcPointer;
	max_instr = instrMax;
    instr = s;
}

void Jmp0Instr::execute()
{
	if (in1->getValue() == 0)
	{
		if (a1->getValue() < *max_instr)		// valid address in instruction memory 
			*pc = a1->getAddressValue();

		else throw std::invalid_argument("a1 must have a valid address in Instruction memory");
	}
}

std::string Jmp0Instr::print()
{
    return instr;
}
