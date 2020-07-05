#include "chain.h"

task(func f) {
	//perform task
}

void task::set_origin(){
	if(origin_set != 1) {
		origin = index;
	}
}

channel(task t1, task t2) {
	left->head = t1->head;
	right->head = t2->head;
}

float channel::read(int task_index) {
	return field[task_index];
}

void channel::write(float data, int task_index) {
	field[task_index] = data;
}