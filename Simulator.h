#ifndef Simulator_h
#define Simulator_h

#include <string>
#include <iostream>
#include <fstream>
#include "InstructionFactory.h"
#include "DataMemory.h"

using namespace std;

class Simulator
{
	ifstream inputFile;

	Instruction** instrmem;

	int memIndex, pc;
	bool canBuild, canRun, canMakeReport;
	
public:
	Simulator(std::string);
	bool build();
	void run();
    bool buildAndRun();
	void displayMemory();
	void displayCode();
	void makeReport(string);
};
#endif
