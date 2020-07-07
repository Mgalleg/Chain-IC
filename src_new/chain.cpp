#include "chain.h"

using namespace std;

int origin_set;
int origin;

// Constructor of Data_nonvol class. Assigns NULL to head.
Data_nonvol::Data_nonvol(){
  head = NULL;
}

// Destructor of Data_nonvol class. 
Data_nonvol::~Data_nonvol(){}

// Set function of Data_nonvol class for writing data into LL. 
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

// Read function of Data_nonvol class for reading data from LL. 
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

// Constructor. Allocates nonvolatile data array size.
Nonvol_data_mtx::Nonvol_data_mtx(int row, int col){
  row = ROW;
  col = COL;
  //arbitrary size allocatation of matrix to represent limited nonvolatile memory
	matrix.resize(row, vector<int>(col));
}

//Destructor. Deletes the vector array.
Nonvol_data_mtx::~Nonvol_data_mtx(){
  this->matrix.clear();
  vector<vector<int> >().swap(this->matrix);
}

//class method to retrieve object's matrix contents attribute (via A(i,j) format) 
int& Nonvol_data_mtx::operator()(const int &row_num, const int &col_num) {
	return this->matrix[row_num][col_num];
}

//Inserts or updates an element of the Matrix.
void Nonvol_data_mtx::set(int row_num, int col_num, int value){
  matrix[row_num][col_num] = value;
}

//Retrieves the element of the Matrix.
int Nonvol_data_mtx::get(int row_num, int col_num){
  return matrix[row_num][col_num];
}

// Constructor of Task class.
Task::Task(){
  
}

// Destructor of Task class.
Task::~Task() {}

//Get_origin function of Task class. Returns the origin task variable "origin"
//which is stored in nonvolatile memory. This function will read data structure
//Nonvol_data_mtx (matrix) to find origin variable, which is stored in last row
int Task::get_origin(){
  //add code here to read nonvolatile memory based on last row index 
  
  
  //just for now, use index = 0 (i.e. origin is first task)
  index = 0;    //delete later
  
  
  //return origin value that was stored in nonvolatile memory
  return origin = index;
}

//Set_origin function of Task class. Sets the origin variable (i.e. the index of task 
//that will be the first task executed upon resuming after power failure).
void Task::set_origin(int tsk_idx){
  origin = tsk_idx;
  
  //Since origin variable is volatile (i.e. global), store origin variable in nonvolatile 
  //memory at last index of matrix. This stored origin variable will later be accessed 
  //via get_origin() function.
  
  
}

// Operator() function of Task class. Determines function (Task) to execute 
// based on task index provided.
void Task::operator()(int tsk_idx) {
  if (tsk_idx == 0) {
    //execute sensor() task
    this->sensor();
  } else if (tsk_idx ==1) {
    //execute temperature() task
    this->temperature();
  }
}

void Task::sensor() {
  //add sensor task function here, randomly generate 3 float data between 100 to 50 degree
  float A = 100;
  float B = 50;
  for (int i = 0; i < TEMP_NUM; i++){
    float data = A + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(B-A)));
    //need to storage data inside the data structure
  }
  this->set_origin(1);
}

void Task::temperature() {
  //add sensor task function here
  for (int i = 0; i < TEMP_NUM; i++){
    //read from data structure
    float avg = (A + B + C)/TEMP_NUM;
    //write Avg inside data structure;
  }

  this->set_origin(2);
}

void Task::TempIO(){
  //read the average data inside the list
  if (float avg > TEMP_HIGH){
    cout<<"temperature too high, turn fan on"<<endl;
  }else if(float avg < TEMP_LOW){
    cout<<"temperature too low, turn heater on"<<endl;
  }else{
    cout<<"temperature good"<<endl;
  }
  this->set_origin(0);
}

//read nonvolatile data structure (matrix) and allow access to data of matrix based 
//on task_index (i.e. set task_index to index of PREVIOUS task)
Data_nonvol Task::Ch_read(int task_index, Nonvol_data_mtx Din) {
  //do something with task_index?


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

//write to nonvolatile data structure (matrix) and allow access to data of 
//matrix based on task_index (i.e. set task_index to index of NEXT task)
void Task::Ch_write(int task_index, Nonvol_data_mtx Dout) {
  //do something with task_index 
  
  //write data to nonvolatile memory after some task completes
  //NOTE: this is extra work and supposed to represent actually having 
  //FRAM to write data to.
  
  
  
  
	// field[task_index] = Dout;
}


/*

 // Constructor of Channel class.
Channel::Channel() {}

 // Destructor of Channel class.
Channel::~Channel() {}

 // Channel operator of Channel class. Creates channel between task t1 and
 // task t2.
void Channel::set_chan(Task t1, Task t2) {
	left->head = t1->head;
	right->head = t2->head;
}

*/