#ifndef JmpInstr_h
#define JmpInstr_h

#include "Instruction.h"
#include "AddressOperand.h"

class JmpInstr : public Instruction
{
	int* pc, *max_instr;
	AddressOperand* a1;
    std::string instr;

public:
    JmpInstr(Operand*, int*, int*, std::string);
	void execute();
    std::string print();
	
};

#endif
