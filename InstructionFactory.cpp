#include "InstructionFactory.h"
#include <string>

using namespace std;

Instruction*  InstructionFactory::CreateInstruction(const string& s, int* pc, int*instr_num)
{
	string instr = s;
	instr.erase(remove(instr.begin(), instr.end(), ' '), instr.end());  // remove all the spaces
	instr.erase(remove(instr.begin(), instr.end(), '\t'), instr.end());  // remove all the tabs
    instr.erase(remove(instr.begin(), instr.end(), '\r'), instr.end());  // remove all the \r characters


	int ind;
    // Instrcutions with common operands : ADD, MUL, LE
	if ((ind = int(instr.find("ADD"))) != string::npos ||
		(ind = int(instr.find("MUL"))) != string::npos ||
		(ind = int(instr.find("LE"))) != string::npos)       // ADD Instruction, three operands, output must be address
	{
		if (instr.find("LE") != string::npos)
			instr.erase(ind, 2);
		else
			instr.erase(ind, 3);

		Operand* in1 = OperandFactory::createOperand(instr.substr(0, instr.find(',')));     // Get the Operand, Operand factory will decide
                                                                                            //constant or address
		instr.erase(0, instr.find(',') + 1);

		Operand* in2 = OperandFactory::createOperand(instr.substr(0, instr.find(',')));
		instr.erase(0, instr.find(',') + 1);

		Operand* outop = OperandFactory::createOperand(instr);

		AddressOperand* out_add;        // If the out Operand wasn't an address throw and exception.
		if ((out_add = dynamic_cast<AddressOperand*>(outop)) == NULL)
			throw invalid_argument("Out Operand should be an address");
		
		if (int(s.find("ADD")) != string::npos)
			return new AddInstr(in1, in2, out_add, s);
		else if (int(s.find("MUL")) != string::npos)
			return new MulInstr(in1, in2, out_add,s);
		else return new LeInstr(in1, in2, out_add,s);
	}
    
    // Instructions with common operands NEG, ASS and JMP0
    else if((ind = int(instr.find("NEG"))) != string::npos ||
            (ind = int(instr.find("ASS"))) != string::npos ||
            (ind = int(instr.find("JMP0"))) != string::npos)
    {
        if (instr.find("JMP0") != string::npos)
            instr.erase(ind, 4);
        else
            instr.erase(ind, 3);
        
        Operand* in1 = OperandFactory::createOperand(instr.substr(0, instr.find(',')));
        instr.erase(0, instr.find(',') + 1);
        
        Operand* outop = OperandFactory::createOperand(instr);
        
        AddressOperand* out_add;
        if((out_add = dynamic_cast<AddressOperand*>(outop)) == NULL)
            throw invalid_argument("Out Operand should be an address");
        
        if(int(s.find("NEG")) != string::npos)
            return new NegInstr(in1, out_add,s);
        else if(int(s.find("ASS")) != string::npos)
            return new AssInstr(in1, out_add, s);
		else return new Jmp0Instr(in1, out_add, pc, instr_num,s);
    }
    
	else if ((ind = int(instr.find("READ"))) != string::npos ||
		(ind = int(instr.find("WRITE"))) != string::npos ||
		(ind = int(instr.find("JMP"))) != string::npos)
	{
		if (instr.find("JMP") != string::npos) instr.erase(ind, 3);
		if (instr.find("READ") != string::npos) instr.erase(ind, 4);
		if (instr.find("WRITE") != string::npos) instr.erase(ind, 5);

		Operand* op = OperandFactory::createOperand(instr);

		if (s.find("READ") != string::npos)
			return new ReadInstr(op,s);
		if (s.find("WRITE") != string::npos)
			return new WriteInstr(op,s);
		// JUMP instructions 
		else return new JmpInstr(op, pc, instr_num,s);
	}
	else if ((ind = int(instr.find("HALT"))) != string::npos)
		return new HaltInstr(pc, s);
    else return NULL;
}
