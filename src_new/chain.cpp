#include "chain.h"

int origin_set;
int origin;

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
    head->next = NULL;
  }
  else{ //insert new data at the end of list
    Data *p = head;
    while(p->next != NULL){
      p = p->next;
    }
    Data *t = new Data();
    p->next = t;
    t->value = value;
    t->index = index;
    t->next = NULL;
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
    if (p->next != NULL){
      while(p->index != index){
        p = p ->next;
      }
      return p->value;
    }
    else{
      if (p->index == index){
        return p->value;
      }
      return 0;
    }
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
// Task::Task(func f) {
	// perform task
// }

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
void Channel::set_chan(Task t1, Task t2) {
	left->head = t1->head;
	right->head = t2->head;
}

/**
 * Read function of Channel class for reading in non-volatile data 
 * from a previous task.
 */
Data_nonvol Channel::Ch_read(int task_index, Data_nonvol Din) {
  //do something with task_index...
  
  //read nonvolatile memory for most recent update 
  //NOTE: this is extra work and supposed to represent actually having 
  //FRAM to read from, otherwise, would be simple return of data.
  Data *p = new Data;
  p = Din.getHead();
  //add transfer of Data LL to Data_nonvol LL later...
  
  p->value = 0;
  
  return Din;
	// return field[task_index];
}

/**
 * Write function of Channel class for transferring non-volatile data 
 * to the next task.
 */
void Channel::Ch_write(int task_index, Data_nonvol Dout) {
  //do something with task_index 
  
  //write data to nonvolatile memory after some task completes
  //NOTE: this is extra work and supposed to represent actually having 
  //FRAM to write data to.
  
  
  
  
	// field[task_index] = Dout;
}