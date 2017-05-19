#include "HaltInstr.h"

HaltInstr::HaltInstr(int* pc_point, std::string s)
{
	pc = pc_point;
    instr = s;
}

void HaltInstr::execute()
{
	*pc = 1024;
}

std::string HaltInstr::print()
{
    return instr;
}
