#include <iostream>
#include <map>
#include <vector>

int origin_set;
int origin;


/**
 * Data struct: Data data collect from sensor to Channel,the blue color section in flow chart
 */
struct Data{ 
  int index;
  float value;

  Data* next;
};


/**
 * Channel_ptr struct: Data pointer to point at the current execution task addresss
 */
struct Channel_ptr{ //
  int task_ptr;

  Channel_ptr* next;
  Channel_ptr* prev;
};


/**
 * Data_nonvol class that is a vector linked list of nonvolatile data. Data_nonvol class 
 * is a singly linked list of data that is accessible to Channel class. Contains set()
 * and read() functions to update linked list of Data class.
 */
class Data_nonvol{
  private:
    Data* head;
  public:
    Data_nonvol();
    ~Data_nonvol();
    //function to get head of Data
    Data *getHead(){
      return this->head;
    }
    void set(int index, float value);   //add value of Data type to list at index 
    float read(int index);              //read value of Data type from list at index
};


/**
 * Task class that represents linked list of tasks. Task class is a doubly linked list
 * that includes set_origin functions, which have access to Class Data_nonvol
 */
class Task{
  public:
    Task();
    ~Task();
    Task(func f); //can you pass a function as a parameter??
    void set_origin(); //once set changes global variable and no other task can be origin
    int index;
    Task* head;       //head of task LL
    Task* prev_task;  //link to prev task in LL 
    Task* next_task;  //link to next task in LL

    // Channel* left;    //left task of channel  - do we need?
    // Channel* right;   //right task of channel - do we need?
    // Channel* self;    //self channel          - do we need?
};


/**
 * Channel class that represents linked list of channels. Channel class is a doubly linked list
 * that includes two functions (Ch_read, Ch_write), which have access to Class Data_nonvol
 */
class Channel{

  public:
    Channel();
    ~Channel();
    // Channel* left;     //link to left task - don't need these?
    // Channel* right;    //link to right task - don't need these?
    Channel(Task t1, Task t2);    //create channel between two tasks
    Data_nonvol Ch_read(int task_index, Data_nonvol Din); //read data in from prev task 
    void Ch_write(int task_index, Data_nonvol Dout); //write data out to next task

	private:
		std::vector<float> field;
	//pending ChSync and MultiOut
};


//modules to be written once task and Channel are working