#ifndef Jmp0Instr_h
#define Jmp0Instr_h

#include "Instruction.h"
#include "AddressOperand.h"


class Jmp0Instr : public Instruction
{
	int* pc, *max_instr;
	AddressOperand* a1;
	Operand* in1;
    std::string instr;

public:
    Jmp0Instr(Operand*, AddressOperand*, int*, int*, std::string);
	void execute();
    std::string print();

};

#endif
