#include "src/chain.h"
#include "src/timer.h"

using namespace std;

int rst_cnt = 0;

void power_on(Task &agr, Timer &on, int model, int task, int duration_on, int duration_off);
void power_off(Timer &off, int duration_off);

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
  Task agr(0,0);
  
  int model = agr.get_origin_model();
  int task = agr.get_origin_task();

  cout << "starting timer test" << endl;

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

	int duration_on = (data[0] / data[2]) - data[1];
	int duration_off = data[1];
	int cycles = data[2];
	int delay = ( duration_on + duration_off ) + 1;
  
  cout << duration_on << " " << duration_off << " " << cycles << " " << delay << endl;

	// The timer starts and the tasks begin executing and information begins printing on the console. The duration that the tasks execute is based on the interval for on from the waveform 
  // An object of type Timer is declared
	// may need to use a while loop here to execute this process n times, where n is data[2]


  while (rst_cnt < cycles) {
    Timer on = Timer();
    cout << "rst_cnt is: " << rst_cnt << endl;
    power_on(agr, on, model, task, duration_on, duration_off);
    this_thread::sleep_for (chrono::seconds(duration_on));

    Timer off = Timer();
		power_off(off, duration_off);
		this_thread::sleep_for (chrono::seconds(duration_off));

    rst_cnt++;
  }
  cout << "***END OF MAIN***" << endl;

	file.close();

  return 0;
}

void power_on(Task &agr, Timer &on, int model, int task, int duration_on, int duration_off) {
  cout << "power_on function" << endl;
	on.setInterval([&]() {
    cout << "Running AGR Tasks..." << endl;
		model = agr.get_origin_model();
 		task = agr.get_origin_task();
		agr(model, task);
  }, 1000); // 200 was arbitrarily chosen and depends on the technology

  on.setTimeout([&]() {
    cout << "Stopping ON thread" << endl;
		on.stop();
  }, duration_on*1000);
}

void power_off(Timer &off, int duration_off) {
  cout << "\n***POWER FAILURE***\n" << endl;
	off.setInterval([&]() {
		cout << "Recharging..." << endl;
  }, 1000); // 5000 was arbitrarily chosen and depends on the environment

  off.setTimeout([&]() {
    cout << "Stopping OFF thread" << endl;
		off.stop();
  }, duration_off*1000);
}
