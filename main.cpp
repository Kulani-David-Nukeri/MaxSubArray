/** 
 * @file main.cpp
 * @Synopsis Generates arrays containing random values, and tests for maximum subarray sum.
 * @author Tyson Cross
 * @version 0.1
 * @date 2016-08-14
 */

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

signed int rand_int(){
    return (rand() % 101) - 50 ;         // range -50 to 50
}

int brute_force(const int* a, const int len){       // Provide pointer to array, length len
    int max = a[0];                                 // first max is first element
    for (int i = 0; i < len; i++){                  // run through
        int max_local = a[i];
        for(int j = i; j < len; ++j){
            if(i!=j) max_local += a[j];
            if (max_local>max) max = max_local;
        }
    }
    return max;
}

int divide_and_conquer(const int* a, const int len){
	int max =0; //, max_local = 0;
    for (int i = 0; i < len; i++){};
    return max;
}

int kadane(const int* a, const int len){
    int max =0, max_local = 0;
    for (int i = 0; i < len; i++){
        max_local = max;
    }
    return max;

}

int main(int argc, char* argv[]){
    // Check for input arguement for maximum size of array input length
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " MAX_ARRAY_SIZE" << std::endl;
        return 1;
    }

    // convert input argument to integer
    istringstream ss(argv[1]);
    int max_num;
    if (!(ss >> max_num)){
        cerr << "Invalid number " << argv[1] << '\n';
        return 1;
    }

    // initialize random seed:
    srand (static_cast<unsigned int>(time(NULL)));

    // generate the increasing lengths of arrays with random numbers
    int** num_array;
    num_array = new int*[max_num];
    for (int i = 0; i < max_num; i++){
        num_array[i]= new int[i+1];
        for (int j = 0; j < (i+1) ; j++){
            num_array[i][j]=rand_int();
        }
    }

    // check

	cout << "Input Size " << "\t" << "Brute Force " << "\t" << "Divide and Conquer " << "\t" << "Kadane's Algorithm " << endl;
    for (int i = 0; i < max_num; i++){
			// cout << "Array " << i <<": { " ;
        for (int j = 0; j < (i+1) ; j++){
            // cout << num_array[i][j] << " ";
        }
			// cout << "}" << endl;
		cout << i+1 << "\t\t\t";
        cout << brute_force(num_array[i],i+1) << "\t\t\t";
		cout << divide_and_conquer(num_array[i],i+1) << "\t\t\t\t";
		cout << kadane(num_array[i],i+1) << endl;

    }

     //cleanup
    for (int i = 0; i < max_num; i++){
        delete[] num_array[i];
    }
    delete num_array;

       return 0;

}
