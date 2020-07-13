#include "src/chain.h"
#include "src/timer.h"

using namespace std;

void start_timer(Task &agr, Timer &t, int model, int task, int duration);

int main(int argc, char *argv[]) {

	/*
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
  }*/

  // code to test timer
  
	// Creating an object of type Task. Starting from the first temperature task
  Task agr(0,1);

  int model = agr.get_origin_model();
  int task = agr.get_origin_task();

  cout << "starting timer test" << endl;

	// An object of type Timer is declared
  Timer t = Timer();
	
	// Reading from waveform.txt. The Interval in which a device is on and off is stored in a vector
	ifstream file;

	file.open("waveform_data.txt");

	vector<int> data;

	string word;

	int count = 0;

	while(count < 3) {
		file >> word;
		string num = "";
		for(auto &c : word) {
			if(c != '[' && c != ']' && c != ',') {
				num += c;
			}
		}
		data.push_back(stoi(num));
		count++;
	}

	int duration = data[2];

	// The timer starts and the tasks begin executing and information begins printing on the console. The duration that the tasks execute is based on the interval for on from the waveform 
	start_timer(agr, t, model, task, duration);
	
	int delay = ( (duration*1000) / 1000 ) + 1;

	this_thread::sleep_for (chrono::seconds(delay));

	file.close();

  return 0;
}

void start_timer(Task &agr, Timer &t, int model, int task, int duration) {
	t.setInterval([&]() {
		model = agr.get_origin_model();
 		task = agr.get_origin_task();
		agr(model, task);
  }, 200);

  t.setTimeout([&]() {
    cout << "POWER FAILURE" << endl; 
		t.stop();
  }, duration*1000);
}