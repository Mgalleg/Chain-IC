#include "chain.h"

/**
 * Constructor of Data_nonvol class. Assigns NULL to head.
 */
Data_nonvol::Data_nonvol(){
  head = NULL;
}

/**
 * Destructor of Data_nonvol class. 
 */
Data_nonvol::~Data_nonvol(){}

/**
 * Set function of Data_nonvol class for writing data into LL. 
 */
void Data_nonvol::set(int index,float value){
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

/**
 * Read function of Data_nonvol class for reading data from LL. 
 */
float Data_nonvol::read(int index){
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

/**
 * Constructor of Task class.
 */
Task::Task(){
  
}

/**
 * Destructor of Task class.
 */
Task::~Task() {}

/**
 * Task operator of Task class.
 */
Task::Task(func f) {
	//perform task
}

/**
 * Set_origin function of Task class. Sets the origin task (i.e. the task 
 * that is started once program resumes after power failur)
 */
void Task::set_origin(){
	if(origin_set != 1) {
		origin = index;
	}
}

/**
 * Constructor of Channel class.
 */
Channel::Channel() {}

/**
 * Destructor of Channel class.
 */
Channel::~Channel() {}

/**
 * Channel operator of Channel class. Creates channel between task t1 and
 * task t2.
 */
Channel(Task t1, Task t2) {
	left->head = t1->head;
	right->head = t2->head;
}

/**
 * Read function of Channel class for reading in non-volatile data 
 * from a previous task.
 */
float Channel::Ch_read(int task_index, Data_nonvol Din) {
	return field[task_index];
}

/**
 * Write function of Channel class for transferring non-volatile data 
 * to the next task.
 */
void Channel::Ch_write(int task_index, Data_nonvol Dout) {
	field[task_index] = Dout;
}