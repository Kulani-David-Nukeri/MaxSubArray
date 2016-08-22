/**
 * @file smooth.cpp
 * @Synopsis Smooths values in an input file, write a new output file.
 * @author Tyson Cross
 * @version 0.1
 * @date 2016-08-17
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;


///////////////////////////
//		Functions
//////////////////////////

struct data {
    int num;
    int brute;
    int divide;
    int kadane;
};

/** ======================================================================================= **/

////////////////////////////
//		Main
////////////////////////////

int main(void){
    /* Output setup */
    const string fileInName = "output.txt";
    const string fileOutName = "output_smoothed.txt";
    ifstream inputFile(fileInName, ios::in);
    ofstream outputFile(fileOutName, ios::out);

    // error checking
    if (!inputFile.is_open()) { cout << "Unable to open file:" << fileInName << endl; return -1;}
    if (!outputFile.is_open()) { cerr << "Unable to open file:" << fileOutName << endl; return -1;}

    string line;
    int linesCount = 0;
    int width = 20;

    while (getline(inputFile, line)) linesCount++;
    data values[linesCount];
    inputFile.clear();
    inputFile.seekg(0, ios::beg);

    getline(inputFile, line); // first line is Column Titles
    outputFile << line << endl;

    int j = 0;
    while (getline(inputFile, line)) {
        istringstream ss(line);
        while(!(ss.eof())){
            ss >> values[j].num >> values[j].brute >> values[j].divide >> values[j].kadane;
        }
        j++;
    }

    // Do something with values.

    for (int i = 0; i < linesCount-1; i++){
        outputFile << setw(width) << left << std::setprecision(7) << fixed << values[i].num;
        outputFile << setw(width) << left << std::setprecision(7) << fixed << values[i].brute;
        outputFile << setw(width) << left << std::setprecision(7) << fixed << values[i].divide;
        outputFile << setw(width) << left << std::setprecision(7) << fixed << values[i].kadane;
        outputFile << endl;
    }

    outputFile.close();
    inputFile.close();
    return 0;
}
