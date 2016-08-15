/**
 * @file main.cpp
 * @Synopsis Generates arrays containing random values, and records execution time for maximum subarray sum with three algorithms
 * @author Tyson Cross
 * @version 0.2
 * @date 2016-08-15
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;


///////////////////////////
//		Functions
//////////////////////////

signed int rand_int(){
	return (rand() % 101) - 50 ;								// range -50 to 50
}

int brute(const int* a, const int length){						// Provide pointer to array, length len
	int maximum = a[0];											// first max is first element
	for (int i = 0; i < length; i++){							// run through, iterating by steps (default 1)
		int max_local = a[i];									// current max is current element
		for(int j = i; j < length; ++j){						// from current element until end of elements,
			if(i!=j) max_local += a[j];							// avoid adding starting element twice, add elements so far
			if (max_local > maximum) maximum = max_local;		// compare current max to total maximum.
		}
	}
	return maximum;
}

//Below not correct, no evaluation is done on the maximum, it merely returns the sum of the array!!
int divide(const int* a, const int length){
	if (length==0) return 0;
	if (length==1) return a[0];

	int length_left = length / 2;
	int length_right = length - length_left;
	int left_side = divide(a, length_left);
	int right_side = divide(a + length_left, length_right);
	return left_side + right_side;
}

int kadane(const int* a, const int len){
	int maximum = a[0], max_local = a[0];
	for (int i = 1; i < len; i++){
		max_local += a[i];
		if (max_local < a[i]) max_local = a[i];
		if (maximum < max_local) maximum = max_local;
	}
	return maximum;
}


/*
 int kadane(const int* a, const int len){
	int maximum = 0, max_local = 0;
	for (int i = 0; i < len; i++){
		max_local += a[i];
		if (max_local < 0) max_local = 0;
		if (maximum < max_local) maximum = max_local;
	}
	return maximum;
}
*/

/** ================================================================================================================== */

////////////////////////////
//		Main
////////////////////////////

int main(int argc, char* argv[]){
	/* Profiling */ clock_t startTime = clock();

    /* Check for input arguement for maximum size of array input length */
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " MAX_ARRAY_SIZE <ITERATION_SKIP_SIZE>" << endl;
        return 1;
    }

    /* convert input argument to integer */
    istringstream ss(argv[1]);
    int max_num;
    if (!(ss >> max_num)){
        cerr << "Invalid number of iterations" << argv[1] << '\n';
        return 1;
    }

	/* optional stepping of iterations */
	int steps = 1;
	if (argc > 2) {
		istringstream ss_steps(argv[2]);
		if ((!(ss_steps >> steps))||(steps < 1)||(steps > max_num)){
			cerr << "Invalid number of steps " << argv[2] << '\n';
			return 1;
		}
	}

	/* Output setup */
	string fileOutName = "output.txt";
	ofstream outputFile(fileOutName, ios::out | ios::trunc);

	if (!outputFile.is_open()) { cerr << "Unable to open file:" << fileOutName << endl; return -1;}


    /* Initialize random seed */
    srand (static_cast<unsigned int>(time(NULL)));

    /* Generate the increasing lengths of arrays with random numbers */
    int** num_array;
    num_array = new int*[max_num];
    for (int i = 0; i < max_num; i+=steps){
        num_array[i]= new int[i+1];
        for (int j = 0; j < (i+1) ; j++){
            num_array[i][j]=rand_int();
        }
    }

    /* Output */
	int width = 20;
	outputFile << setw(width) << left << "Input Size";
	outputFile << setw(width) << left << "Brute Force";
	outputFile << setw(width) << left << "Divide and Conquer";
	outputFile << setw(width) << left << "Kadane's Algorithm";
	outputFile << endl;

    for (int i = 0; i < max_num; i+=steps){

		int length = i;

		auto time_brute_start = chrono::high_resolution_clock::now();
		int sum_brute = brute(num_array[i],length);
		auto time_brute_end = chrono::high_resolution_clock::now();
		auto time_brute = chrono::duration_cast<chrono::microseconds>(time_brute_end - time_brute_start); // INT version
		//auto time_brute = chrono::duration<double>(time_brute_end - time_brute_start); // FLOAT version

		auto time_divide_start = chrono::high_resolution_clock::now();
		int sum_divide = divide(num_array[i],length);
		auto time_divide_end = chrono::high_resolution_clock::now();
		auto time_divide = chrono::duration_cast<chrono::microseconds>(time_divide_end - time_divide_start); // INT version
		//auto time_divide = chrono::duration<double>(time_divide_end - time_divide_start); // FLOAT version

		auto time_kadane_start = chrono::high_resolution_clock::now();
		int sum_kadane = kadane(num_array[i],length);
		auto time_kadane_end = chrono::high_resolution_clock::now();
		auto time_kadane = chrono::duration_cast<chrono::microseconds>(time_kadane_end - time_kadane_start); // INT version
		//auto time_kadane = chrono::duration<double>(time_kadane_end - time_kadane_start); // FLOAT version


		/*
		// TEMP TO CHECK ALGORITHM //
		outputFile << setw(1) << "{ ";
		for (int j = 0; j < (i+1) ; j++){
			outputFile << num_array[i][j] << " ";
		}

		outputFile << "}" << endl;

		if ((sum_brute==sum_divide)&&(sum_brute==sum_kadane)&&(sum_divide==sum_kadane)){
			outputFile << setw(width) << left << "✓";		// matches
		} else{
			outputFile << setw(width) << left << "!";		// incorrect calculation
		}

		outputFile << setw(width) << left << sum_brute;
		outputFile << setw(width) << left << sum_divide;
		outputFile << setw(width) << left << sum_kadane;
		outputFile << endl;
		// End TEMP //
		*/

		/* Output */
		outputFile << setw(width) << left << length;
		outputFile << setw(width) << left << fixed << time_brute.count();
		outputFile << setw(width) << left << fixed << time_divide.count();
		outputFile << setw(width) << left << fixed << time_kadane.count();
		outputFile << endl;

	}

	/* Cleanup */
    for (int i = 0; i < max_num; i+=steps){
        delete[] num_array[i];
    }
    delete num_array;
	outputFile.close();

	/* Profiling */
	cout << "Executable Runtime: " << double( clock() - startTime) / (double) CLOCKS_PER_SEC << " seconds." << endl;
	cout << "Processing complete.";

	return 0;
}
/** ================================================================================================================== */


