#include "chainSIM.h"

const int threshold = 2000; //in mV. 

int g_task; //if 1, then temp task, if 2 then water task, if 3 then humidity task

int capacity; //in mV

void menu() {

	std::cout << "Select an option to . Enter the option number followed by enter" << std::endl;

	std::cout << "1 Harvest Energy" << std::endl << "2 Create Task" << std::endl << "3 Run Simulation" << std::endl;

	int option;

	std::cin >> option;

	std::cout << option << std::endl;

}

//when device needs to harvest energy. the previously attempted task is saved globally(a simulation for being stored in non-volatile memory)
void pwr() {
	harvesting();
	if(g_task == 1) {
		temp(ch, task); //need to somehow determine which channel and task the execution was on before power failure. maybe more global variables? or the Matrix class
	}
	else if(g_task == 2) {

	}
	else if(g_task == 3) {

	}
}

//some time is taken to harvest energy
void harvesting() {
	capacity = 0;

	while(cap < threshold) {
		cap+= (rand()%10);
	}
}

//tasks include reading temperature value from sensor, computing average, and turning fan on or off (accounting for recent water and humidity values if available)
void temp(ch, task) {

}

//tasks include reading water level in soil from sensor, computing average, and turning irigation system on or off (accounting for recent temperature and humidity values if available)
void water(ch, task) {

}

//tasks include reading humidity from sensor, computing average, and turning ventilation system on or off (accounting for recent temperature and water levels if available)
void humidity(ch, task) {

}