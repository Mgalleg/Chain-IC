#include <iostream>
#include <map>
#include <vector>

#define ROW 5   //total number of tasks + 1 
#define COL 10  //total number of data members that we will record (per vector)

#define TEMP_NUM 3  //how many time to measure temperature
#define TEMP_HIGH 90  //high temperature range
#define TEMP_LOW 65 //low temperature range

#define DEBUG   //comment out to not include DEBUG code

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
    int orig_index;   //index of origin stored for 
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
    Data_nonvol *data;

  public:
    //Matrix dimensions. Useful for printing.
    std::vector<std::vector<int> > matrix;

    //Constructor. Allocates nonvolatile data array size.
    Nonvol_data_mtx(int, int);

    //class method to retrieve object's matrix contents attribute (via A(i,j) format)
    int& operator()(const int &row_num, const int &col_num);

    Data_nonvol *getData(){
      return this->data;
    }

    void putData(Data_nonvol *newData){
      data = newData;
    }

    //Destructor. Deletes the Data_nonvol array.
    ~Nonvol_data_mtx();

    //Inserts or updates an element of the Matrix.
    void set(int row_num, int col_num, int value);

    //Retrieves the element of the Matrix.
    int get(int row_num, int col_num);

};


// Task class that represents linked list of tasks. Task class is a doubly linked list
// that includes set_origin functions, which have access to Class Data_nonvol
class Task{
  public:
    Task();
    ~Task();

    //index used to determine which task (i.e. sensor, temperature, etc.)
    int index;
    //returns global origin variable, which is stored in nonvolatile memory
    int get_origin();
    //sets global origin variable and stores into nonvolatile memory
    void set_origin(int index);
    // Operator() function of Task class. Determines function (Task) to execute 
    // based off of index provided.
    void operator()(int index);

    //tasks
    void sensor();
    void temperature();
    void TempIO();
    void water();
    void humidity();

    //read nonvolatile data structure (matrix) and allow access to data of matrix based 
    //on task_index (i.e. set task_index to index of PREVIOUS task)
 		Data_nonvol Ch_read(int task_index, Nonvol_data_mtx Din);
    
    //write to nonvolatile data structure (matrix) and allow access to data of 
    //matrix based on task_index (i.e. set task_index to index of NEXT task)
    void Ch_write(int task_index, Nonvol_data_mtx Dout); 

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