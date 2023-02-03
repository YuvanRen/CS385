/*******************************************************************************
 * Filename: sqrt.cpp
 * Author  : Yuvan Rengifo
 * Version : 1.0
 * Date    : February 9, 2023
 * Description: Compute the square root of a double using Newton's method.
 * Pledge  : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
using namespace std;

double epsilon = .000001;

double sqrt(double num, double epsilon){
	if(num < 0){
		return numeric_limits<double>::quiet_NaN();
	}

	if(num == 0 || num == 1){
		return num;
	}
	return num;
}

int main(int argc, char* const argv[]) {
	double num;
	double epsilon;
	istringstream iss;

	if (argc < 2) {
	        cerr << "Usage: " << argv[0] << " <value> [epsilon]" << endl;
	        return 1;
	    }

	iss.str(argv[1]);
	if (!(iss >> num)) {
		cerr << "Error: Value argument must be a double." << endl;
		return 1;
	}
	iss.clear();

	iss.str(argv[2]);
	if(!(iss >> epsilon)){
		cerr<< "Error: Epsilon argument must be a positive double."<<endl;
	}

}
