#include <iostream>
#include <map>
#include <vector>

// Data struct: Data data collect from sensor to Channel,the blue color section in flow chart
struct Data{ 
  int index;
  float value;

  Data* next;
};

// Data_nonvol class that is a vector linked list of nonvolatile data. Data_nonvol class 
// is a singly linked list of data that is accessible to Channel class. Contains set()
// and read() functions to update linked list of Data class.
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

//Matrix class that will use the index of the Task (t0) to determine which data 
//is accessible to the task (i.e. Task Sensor (with index 0) has access to Matrix data (index 0))
class Nonvol_data_mtx {

  private:
    int row;
    int col;
    Data_nonvol *data;

  public:
    //Matrix dimensions. Useful for printing.
    int m, n;
    std::vector<std::vector<int> > matrix;

    //Constructor. Allocates nonvolatile data array size.
    Nonvol_data_mtx(int m, int n);

    Data_nonvol *getData(){
      return this->data;
    }

    void putData(Data_nonvol *newData){
      data = newData;
    }

    void setVals(int m, int n) {
      row = m;
      col = n;
    }

    int getRow(){
      return row;
    }
    
    int getCol(){
      return col;
    }

    //Destructor. Deletes the Data_nonvol array.
    ~Nonvol_data_mtx();

    //Inserts or updates an element of the Matrix.
    void set(int row, int column, int value);

    //Retrieves the element of the Matrix.
    int get(int row, int column);

};


// Task class that represents linked list of tasks. Task class is a doubly linked list
// that includes set_origin functions, which have access to Class Data_nonvol
class Task{
  public:
    Task();
    ~Task();
    int index;          //index used to determine which task (i.e. sensor, temperature, etc.)
    int get_origin();   //returns global origin variable, which is stored in nonvolatile memory
    void set_origin(int index);  //sets global origin variable and stores into nonvolatile memory
    void operator()(int index);
    //add each task function here??
    void sensor();
    void temperature();


 		Data_nonvol Ch_read(int task_index, Data_nonvol Din, Task t1, Task t2); //read data in from prev task 
    void Ch_write(int task_index, Data_nonvol Dout); //write data out to next task


   
};

/*
 //Channel class that represents linked list of channels. Channel class is a doubly linked list
 //that includes two functions (Ch_read, Ch_write), which have access to Class Data_nonvol
 
class Channel{

  public:
    Channel();
    ~Channel();
    // Channel* left;     //link to left task - don't need these?
    // Channel* right;    //link to right task - don't need these?


	private:
		std::vector<float> field;
	//pending ChSync and MultiOut
};


//modules to be written once task and Channel are working

*/