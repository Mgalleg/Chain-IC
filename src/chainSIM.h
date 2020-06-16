u#ifndef MY_CHAINSIM_H
#define MY_CHAINSIM_H

#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>


//contains chain.h and repeat.h
// #include <libchain>

//contains matrix and vector classes
#include "Matrix.h"

using namespace std;



void menu();

// The purpose of this program is to create simulated environments for the Chain tool found at https://github.com/CMUAbstract/libchain


//Add more functions below
void pwr(); //when device is turned on. 
 
void temp(); //when device measures input from temperature sensor
 
void water(); //when device reads input from water sensor

void humidity(); //when device reads input from humidity sensor

void harvesting(); //will finish executing when enough energy is harvested
}
#endif /* MY_CHAINSIM_H */
