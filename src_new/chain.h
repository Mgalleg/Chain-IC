#include <iostream>
#include <map>
#include <vector>

int origin_set;
int origin;

//Struct Data: Data data collect from sensor to channel,the blue color section in my flow chart
struct Data{ 
  int index;
  float value;

  Data* next;
}

//struct Channel_ptr: Data pointer to point at the current exicution task addresss
struct Channel_ptr{ //
  int task_ptr;

  Channel_ptr* next;
  Channel_prt* prev;
}

//linked list of tasks can be made in main()
class task{
	task(func f); //can you pass a function as a parameter??
	void set_origin(); //once set changes global variable and no other task can be origin
	int index;
	task* next_task; //similar to linked lists
	channel* left; //
	channel* right;
};

class channel{
	task* left;
	task* right;

	channel(task t1, task t2);
	float read(int task_index); //ChIn
	void write(float data, int task_index); //ChOut

	private:
		std::vector<float> field;
	//pending ChSync and MultiOut
}


//modules to be written once task and channel are working