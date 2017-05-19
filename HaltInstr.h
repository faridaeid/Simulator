#ifndef HaltInstr_h
#define HaltInstr_h

#include "Instruction.h"
#include <iostream>

class HaltInstr : public Instruction
{
	int* pc;
    std::string instr;

public:
    HaltInstr(int*, std::string);
	void execute();
    std::string print();

};

#endif 
