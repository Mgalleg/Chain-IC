import os
import sys
import csv
import random
import unittest
import subprocess
import numpy as np
from scipy import signal
import matplotlib.pyplot as plt

check_output = lambda x: subprocess.check_output(x, universal_newlines=True)

class ProjectCppTest(unittest.TestCase):

    def setUp(self):

        print("Compiling C++ program before testing...\n")

        #call Makefile command to compile C++ code
        subprocess.check_call(["make", "all"])


    def gen_waveform(self):

        print("Generating random voltage waveform intervals...\n")

        # open output files
        outfile = open('waveform_data.txt', 'w')
        outfile2 = open('waveform_data_raw.txt', 'w')

        # generate random parameters for voltage waveform with "charge-time" range from 70 to 95
        # (i.e. "on-time" ranges from 5 to 30 ticks); number of cycles ranges from 3 to 10
        charge_time = random.randint(70, 95)
        cycles = random.randint(3, 10)
        tot_t = cycles * 100

        #print parameters
        print("Random voltage waveform intervals are:")
        print("Total Time (s): ", tot_t)
        print("Total Off (Charge) Time per Period (s): ", charge_time)
        print("Total On (Discharge) Time per Period (s): ", int(100-charge_time))
        print("Total Number of Periods: ", cycles)
        print('\n')

        # use random parameters to create sawtooth waveform
        t = np.linspace(0, tot_t, tot_t)
        triangle = signal.sawtooth(2 * np.pi * cycles * t, charge_time/100)

        # print waveform total time and charge time intervals/duration to output file
        parms_arr = [tot_t, charge_time, cycles]    # total time of waveform, total charge time per period, num of cycles
        print(parms_arr, file=outfile)

        # generate all waveform intervals into array using random parameters from above
        cnt = 0
        t_volt = []
        for i in range(0, cycles + 1):
            if i == 0:
                t_volt.append(i)
                vhi = int(charge_time)
                t_volt.append(vhi)
            else:
                if i < cycles:
                    vlo = i * 100
                    t_volt.append(vlo)
                    vhi = int((charge_time) + (i * 100))
                    t_volt.append(vhi)
                if i == cycles:
                    vlo = i * 100
                    t_volt.append(vlo)

        # print array of waveform voltage time intervals to output file
        print(t_volt, file=outfile)

        # print array of waveform raw data to output file
        print(triangle, file=outfile)
        print(triangle, file=outfile2)

        # close output files
        outfile.close()

        return t, triangle

    def test_chain_cpp(self):

        print("Testing Chain-based application\n")

        #generate random voltage waveform
        t, triangle = self.gen_waveform()

        #call Main executable with argument (waveform file)
        subprocess.check_call(["./Main", "waveform_data.txt"])


        # #plot waveforms
        # plt.plot(t, triangle)
        # plt.title('waveform')
        #
        # plt.grid(True, which='both')
        # plt.axhline(y=0, color='k')
        # plt.ylim(-1,1)
        # # plt.show()
        #
        #
        # #plot data and compare
        # x = []
        # y = []
        # csv_file = open('waveform_data_raw.txt', "r")
        #
        # data_list = [line.strip() for line in csv_file]  # separate lines within input text file
        #
        # # with open('waveform_data_raw.txt', 'r') as rawdata:
        # # line = csv.reader(rawdata, delimiter=' ')
        # for data in data_list:
        #     print(data)
        #     d = data.split(' ')
        #     print(d)
        #     break
        #     # str = d[0]
        #     # if str[0] != "[":
        #     #     # time_list.append(word[0])
        #     #     # results_list.append(word[1])
        #     #     x.append(float(d))
        #     #     # y.append(float(char[1]))
        #     #
        #     # print(x)
        #     # print(y)


        # #use test to determine outcome
        # self.assertTrue(np.array_equal(self.multiply(A,B), C), msg="Incorrect multiplication result")



if __name__ == '__main__':

    suite = unittest.TestSuite()

    if len(sys.argv) == 2 and sys.argv[1] == "test-chain":
        suite.addTest(unittest.defaultTestLoader.loadTestsFromTestCase(ProjectCppTest))

    result = unittest.TextTestRunner().run(suite)

    # Set the exit code based on the test result
    sys.exit(not result.wasSuccessful())
