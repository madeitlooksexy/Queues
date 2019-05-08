/*
@file		PriorityQueue.cpp
@author		Noah Yu - CS 260
@version	1.0

Priority scheduler for processes based off of simulation text.

*/

#include<iostream>
#include<string>
#include"PriorityQueue.h"
#include<fstream>

using namespace std;

int main() {

	//opening input stream to operate the file (sim.txt)
	std::ifstream inputStream;
	std::string fileName = "sim.txt";
	int priority;
	int timeRequired;
	int id = 1;
	int num = 0;

	inputStream.open(fileName); //opening stream
	if (!inputStream) { //if the sim is not accessible or found the program is stopped
		cout << "File " << fileName << " is not accessible." << endl;
		cout << "terminating program..." << endl;
		return false;
	}

	priorityQueue start; //start queue with data

	while (inputStream >> priority >> timeRequired) {
		start.id[num] = id;
		start.initialPriority[num] = priority;
		start.timeRequired[num] = timeRequired;
		start.enqueue(timeRequired, priority);
		num++; id++; start.dataSet++;
	}
	start.timeInQueue();
	start.output();
	inputStream.close(); //closing stream after completion of reading data
	return true;
}