#include "JmpInstr.h"
#include <iostream>

JmpInstr::JmpInstr(Operand* op, int* pc_main, int* instr_count, std::string s)
{
	pc = pc_main;
	max_instr = instr_count;
    instr = s;

	if ((a1 = dynamic_cast<AddressOperand*>(op)) == NULL)
		throw std::invalid_argument("Operand must be a data address");
}

void JmpInstr::execute()
{
	if (a1->getValue() < *max_instr)		// valid address in instruction memory 
		*pc = a1->getAddressValue();

	else throw std::invalid_argument("a1 must have a valid address in Instruction memory");
}

std::string JmpInstr::print()
{
    return instr;
}
