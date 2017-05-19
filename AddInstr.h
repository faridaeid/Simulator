//
//  AddInstr.hpp
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef AddInstr_hpp
#define AddInstr_hpp

#include "Instruction.h"
#include "AddressOperand.h"

class AddInstr : public Instruction
{
	Operand* in1;
	Operand* in2;
    AddressOperand* out1;
	std::string instr;
    
public:
    AddInstr(Operand*, Operand*, AddressOperand*, std::string);
    void execute();   
	std::string print();
};

#endif /* AddInstr_hpp */
