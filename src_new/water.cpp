#include "chain.h"
#include <string>

//global variable

int main() {

	// linekd list of task need to be defined beforehand

	Task first(0);
	Task second(1);
	Task third(2);

	origin->next_task = second;
	second->next_task = third;

	//in case of power failure 
	 
	while(1) {
		current = current.choose_func();
		// similar to node = node->next but with the option of going back
		// node = node->prev
	}

	return 0;
}



void Task::choose_func() {
	if(index == 0) 
		Sense(self);
	else if(index == 1) 
		CmpAvg(self);
	else Alert(self);
}

Task Sense(Task &t) {
	//code
	.
	.
	.

	Task* next = t->next_task;

	return *(next);
}

Task CmpAvg(Task &t) {
	if something 
		Task * next = t->next_task;

	else Task *next = t->prev_task;

	return next;
}

Task Alert(Task &t) {
//code 
.
.
.
.
	Task* next = t->next_task;

	return next;
}


