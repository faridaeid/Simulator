#include "DataMemory.h"
#include <fstream>
#include <mutex>

std::mutex mtx;

DataMemory::DataMemory()
{
	memory = new int[1024]();
}

DataMemory* DataMemory::getInstance()
{
	return instance;
}

int& DataMemory::operator[](int index)
{
	if (index < 0 || index > 1023)
		throw std::invalid_argument("Invalid access to memory index");

	else return memory[index];
}


void DataMemory::createInstance()
{
    instance = new DataMemory();
    
}
void DataMemory::print()
{
	std::ofstream output;
	output.open("console.txt");
	for (int i = 0; i < 1024; i++)
		output << "Mem Cell : " << i << "\t\tValue : " << memory[i] << std::endl;
}

void DataMemory::printConsole()
{
	for (int i = 0; i < 1024; i++)
		std::cout << "Mem Cell : " << i << "\t\tValue : " << memory[i] << std::endl;
}

DataMemory* DataMemory::instance = NULL;
