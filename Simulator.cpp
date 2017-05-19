#include "Simulator.h"

Simulator::Simulator(string path)
{
	inputFile.open(path);

	instrmem = new Instruction*[1024];
	memIndex = 0;
	pc = 0;
	canRun = false;
	canBuild = true;
	canMakeReport = true;

	if (inputFile.fail())
	{
		canBuild = false;
		cerr << "Cannot Find file , or open it\n";
	}
}

bool Simulator::build()
{
    canRun = true;
	string s;
	while (!inputFile.eof())
	{
		getline(inputFile, s);
		if (s == "") continue;

		try
		{
			Instruction* instr = InstructionFactory::CreateInstruction(s, &pc, &memIndex);
			if (instr == NULL)	{
				canRun = false;
				cerr << "Unknown Instruction :\t" + s << endl;
			}
			else instrmem[memIndex++] = instr;
		}
		catch (invalid_argument e) { cerr << "Error in Instruction : " << s << " :\t" << e.what() << endl; }
	}

	return canRun;
}

void Simulator::run()
{
	if (canRun)
	{
		while (pc < 1024)
		{
			try
			{
				instrmem[pc++]->execute();
			}
			catch (invalid_argument e)
			{
				cerr << "Error in Instruction " << e.what() << endl;
				break;
			}
		}
	}
}

bool Simulator::buildAndRun()
{
    if(!build()) return false;
    else
    {
        run();
        return true;
    }
}


void Simulator::displayMemory()
{
	DataMemory::getInstance()->printConsole();
}

void Simulator::displayCode()
{
    for (int i=0; i<memIndex; i++) {
        cout<<instrmem[i]->print()<<endl;
    }
}

void Simulator::makeReport(string path)
{
    ofstream reportOutput;
    reportOutput.open(path);
    
    if(reportOutput.fail()) cerr<<"Error opening or creating report file";
    else
    {
        reportOutput<<"Report"<<endl;
        reportOutput<<"-------------------\n";
        
        reportOutput<<"Code:\n";
        
        for (int i=0; i<memIndex; i++) {
            reportOutput<<instrmem[i]->print()<<endl;
        }
        
        reportOutput<<"-------------------\n";
        reportOutput<<"Memory:\n";

        DataMemory::getInstance()->print();
        
    }
    
}
