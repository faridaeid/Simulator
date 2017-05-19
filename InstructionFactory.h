//
//  InstructionFactory.h
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef InstructionFactory_h
#define InstructionFactory_h

#include "Instruction.h"
#include "AddressOperand.h"
#include "ConstantOperand.h"
#include "OperandFactory.h"
#include <string>

#include "AddInstr.h"
#include "MulInstr.h"
#include "LeInstr.h"
#include "NegInstr.h"
#include "AssInstr.h"
#include "ReadInstr.h"
#include "WriteInstr.h"
#include "HaltInstr.h"
#include "JmpInstr.h"
#include "Jmp0Instr.h"

using namespace std;

class InstructionFactory
{
    
public:
	static Instruction* CreateInstruction(const string& s, int*, int*);
};

#endif /* InstructionFactory_h */
