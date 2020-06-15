#include <fstream>
#include <string>
#include <iostream>

void menu();

// The purpose of this program is to create simulated environments for the Chain tool found at https://github.com/CMUAbstract/libchain

int main(int argc, char *argv[]) {

	// Program should be able to allow changing parameters such as battery capacity.

	// Program should be able to trace to events.

	// Program should be able to create intermittent computing tasks.
	
	menu();

	return 0;
}

void menu() {

	std::cout << "Select an option to . Enter the option number followed by enter" << std::endl;

	std::cout << "1 Harvest Energy" << std::endl << "2 Create Task" << std::endl << "3 Run Simulation" << std::endl;

	int option;

	std::cin >> option;

	std::cout << option << std::endl;

}