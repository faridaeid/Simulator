//
//  DataMemroy.h
//  OOP Assignment Two Simulator
//
//  Created by Farida Eid on 11/25/16.
//  Copyright © 2016 Farida Eid. All rights reserved.
//

#ifndef DataMemory_h
#define DataMemory_h

#include <iostream>

class DataMemory
{
    static DataMemory* instance;
    int* memory;
	DataMemory();
    
public:
	static DataMemory* getInstance();
	int& operator[](int index);
	void print();
	void printConsole();
    static void createInstance();
};




#endif /* DataMemory_h */
