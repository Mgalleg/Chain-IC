#include "chainSIM.h"

using namespace std;

int main(int argc, char *argv[]) {

/*

	// on();

  //test channel and task structures here
  //can include this in #ifdef statement for DEBUG
  Task sensor;
  Task temperature;

  Channel sensor2temp;
  Channel temp4rmsensor;
  
  Data_nonvol d1;
  Data_nonvol d2;

  //fill data (d1) with random values
  
  
  //read data to verify written
  cout << "hi" << endl;
  

  //execute task and update volatile memory



  //call Ch_write and write to nonvolatile memory
  sensor2temp.Ch_write(1, d1);
  
  //call Ch_read 
  d2 = sensor2temp.Ch_read(1, d1);
  
*/
  
  Task t0;
  
  while (1) {
    //set orig to task index of next task to be executed
    int orig = t0.get_origin();
    //use Task operator to execute next task based on index ("orig")
    t0(orig);
  }
  
  
  
  
  

	return 0;
} 