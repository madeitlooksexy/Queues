/*
@file		PriorityQueue.h
@author		Noah Yu - CS 260
@version	1.0

Generating a priority queue for scheduler.

*/

#pragma once
#include<queue>
#include<iostream>

queue<int>* const myQueue = new queue<int>[5];

using namespace std;

class priorityQueue {

public:

	//outputs information from sim to queue.
	//@param - none 
	void output();

	//inserts item to queue
	//@param - data (data provided to program)
	//@param - priority (level of priority for program with 0 being the highest priority)
	void enqueue(int data, int priority);

	//removes item from queue
	//param - data (the specific data needed for removal)
	void dequeue(int& data);

	//Schedules the time for pop/push operations in the queue.
	/*Values of starting time and the scheduling time are implemented with the time ceiling
	set for up to 50 milliseconds.*/ 
	/*Priorities for the program are set with 0 being the highest priority, whenever the program 
	utilizes push operations the item in the object are deprioritized, with 5 being the lowest priority.
	(set as arrays)*/
	void timeInQueue();

	//index for priorities/time
	int id[6];
	int dataSet = -1, startTime = 0, time = 0, schedule = 0;
	int scheduleArray[6];
	int timeRequired[6];
	int initialPriority[6];
	int currentPriority[6];
};

void priorityQueue::output() { //outputting information
	cout << "Author: Noah Yu" << endl << endl;
	cout << "	Initial		Time		Time		Time		Final" << endl;
	cout << "PID	Priority	Needed		Started		Ended	Priority" << endl;
}

void priorityQueue::enqueue(int data, int priority) { //inserting item to queue 
	if (priority > 5 || priority < 0) {
		priority = 5;
			cout << "Invalid priority. Priority set to 5.";
	}
	myQueue[priority].push(data);
}

void priorityQueue::dequeue(int& data) { //removing item from queue
	for (int pri = 5; pri >= 0; pri--) {
		if (myQueue[pri].empty()) {
			myQueue[pri].front();
			return;
		}
		return;
	}
}

void priorityQueue::timeInQueue() { //calculating item time in the queue
	int currPriority = 0;
	int queueSize = 0;
	int maxPriority = 5;
	int val = 0;

	while (currPriority <= 5) { //looping through until valid priority condition is met
		queueSize = myQueue[currPriority].size();
		if (queueSize != 0) {
			time = myQueue[currPriority].front(); //checking for queue size
			if (time <= 0) {					  //otherwise return element to first pos	
				myQueue[currPriority].pop();
				currentPriority[val] = currPriority;
				scheduleArray[val] = schedule;
				val++;
			}
			else {
				myQueue[currPriority].pop();
				if (currPriority + 1 <= maxPriority)
					myQueue[currPriority + 1].push(time);
				else
					myQueue[currPriority].push(time);
			}
			if (time >= 50) { //time set to 50 ms
				schedule = schedule + 50;
				time = time - 20;
			}
			else {
				time = 0;
				schedule = schedule + time;
			}
		}
		currPriority++;
	}
}
