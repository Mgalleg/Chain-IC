#include "src/chain.h"
#include "src/timer.h"

using namespace std;

void power_on(Task &t, int model, int task);
void power_off(Task &t, int model, int task);

int main(int argc, char *argv[]) {

  //MAIN CODE SECTION: keep for final
  Task t0(0,1);  //start with arbitrary orig_model and orig_task for now...

  //set orig_model using get_origin_model() functions
  //FIXME: may combine into one function later...
  int orig_model = t0.get_origin_model();
  int orig_task = t0.get_origin_task();
  

#ifdef DEBUG
  int cnt=0;
#endif 
  
  while (cnt < 18) { //change condition to '1' later
    //wait(3);
    orig_model = t0.get_origin_model();
    orig_task = t0.get_origin_task();

    //use Task operator to execute next task based on index ("orig")
    t0(orig_model, orig_task);
    cnt++;
  }

  // code to test timer
  
  Task agr(0,1);
  int model = agr.get_origin_model();
  int task = agr.get_origin_task();

  cout << "starting timer test" << endl;

  Timer t = Timer();

  t.setInterval([&]() {
		model = agr.get_origin_model();
 		task = agr.get_origin_task();
		agr(model, task);
  }, 200);

  t.setTimeout([&]() {
    t.stop(); 
  }, 20000);
  
  while(true);

  return 0;
}