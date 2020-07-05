#include <iostream>
#include <map>
#include <vector>

int origin_set;

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
	float channel_read(int task_index); //ChIn
	void channel_write(float data); //ChOut

	private:
		mem* data
	//pending ChSync and MultiOut
}

class mem{
	std::vector<std::vector<int>> field;

	float read(int task_index);
	void write(float data);
};

//modules to be written once task and channel are working