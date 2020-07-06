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


Data_volatile::Data_volatile(){
  head = NULL;
}

Data_volatile::~Data_volatile(){}

//setting data into the linked list
void Data_volatile::set(int index,float value){
  if (head == NULL){ //start first data on list
    head = new Data();
    head->value = value;
    head->index = index;
  }
  else{ //insert new data at the end of list
    Data *p = head;
    while(p->next != NULL){
      p->next = p->next->next;
    }
    p->next = new Data();
    p->next->value = value;
    p->next->index = index;
  }
}
//read value out from linked list
float Data_volatile::read(int index){
  if (head == NULL){
    return 0;
  }
  else{
    Data *p = head;
    while(p->index != index){
      p->next = p->next->next;
    }
    return p->value;
  }
}