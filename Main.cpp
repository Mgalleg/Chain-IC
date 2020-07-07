#include "chainSIM.h"

using namespace std;

int main(int argc, char *argv[]) {


  Task temperature(0);
  Task water(1);
  Task humidity(2);
  


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
  
/*
  Task t0;

#ifdef DEBUG
  int cnt=0;
#endif 
  
  while (cnt < 2) { //change condition to '1' later
    //set orig to task index of next task to be executed
    int orig = t0.get_origin();

#ifdef DEBUG
    cout << "orig is " << orig << endl;
#endif

    //use Task operator to execute next task based on index ("orig")
    t0(orig);
    cnt++;
  }
  
*/


/*
  //### COMPLETE ###
  //MATRIX DATA TEST: test Data_nonvol, Nonvol_data_mtx and Ch_read  
  Task t1;
  Nonvol_data_mtx t_mtx(ROW,COL);
  Data_nonvol t0_data;
  Data_nonvol t1_data;
  
  //setup Data_nonvol with data 
  t0_data.set(0,2);
  t0_data.set(1,4);
  t0_data.set(2,6);
  t1_data.set(0,1);
  t1_data.set(1,3);
  t1_data.set(2,5);
  
  for (int i=0; i < 2; i++) {
    for (int j=0; j < 3; j++) {
      if (i == 0) {
        t_mtx.set(i, j, t0_data.read(j));
      } else if (i == 1) {
        t_mtx.set(i, j, t1_data.read(j));
      }
    }
  }
  
  for (int i=0; i < 2; i++) {
    for (int j=0; j < 3; j++) {
      cout << t_mtx.get(i, j) << " ";
    }
    cout << endl;
  }
  
  //test Ch_read function
  Data_nonvol t0_nonvol_data;
  t0_nonvol_data = t1.Ch_read(1,t_mtx);
  
  for (int i=0; i < 3; i++) {
    cout << t0_nonvol_data.read(i) << " ";
  }

*/

	return 0;
} 