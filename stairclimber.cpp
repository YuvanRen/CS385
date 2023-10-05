/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Yuvan Rengifo
 * Date        : March 24, 2023
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens honor system.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<int>> get_ways(int num_stairs){
	//TODO: Return a vector of vectors of inst representing
	//the different combinations of ways to climb num_stairs
	// stairs, moving up either 1, 2, or 3 stairs at a time.
	int n = num_stairs;
	vector<vector<int>> result;
	std::vector<std::vector<int>> ways;
	if(n == 0){
		ways.push_back({});
	}
	if(n == 1){
		ways.push_back({1});
	}
	if(n ==2){
		ways.push_back({1,1});
		ways.push_back({2});

	}
	else{
		 for (int i = 1; i <= 3; i++) {
		    result = get_ways(num_stairs - i);
		     int subs = result.size();
		        for (int j = 0; j < subs ; j++) {
		                result[j].insert(result[j].begin(), i);
		                ways.push_back(result[j]);
		            }
		        }
		    }
	return ways;
}

void display_ways(const vector< vector<int>> &ways){
	//TODO: Display the ways to climb stairs by iterating over
	//the vector of vectors and printing each combination
	int size = ways.size();
	int num_digits = 0;
		while(size/= 10 > 0){	//Setw space
			num_digits++;
		}
		for (int i = 0; i < size; i++) {
				cout << setw(num_digits) << i+1 << ". [" << ways[i][0];
				for (unsigned int j = 1; j < ways[i].size(); j++) {
					cout << ", " << ways[i][j];
				}
				cout << "]" << endl;
			}
		}

int main(int argc, char * const argv[]){
	int n;
	int m;
	istringstream iss;
	if(argc != 2){
		cerr <<"Usage: ./stairclimber <number of stairs>"<< endl;
				return 1;
	}
	iss.str(argv[1]);
	if(argc ==2){
		if(!(iss >> m)){
		cerr<<"Error: Number of stairs must be a positive integer"<< endl;
		}
		else if((!(iss >> n)) || n <=0 ){
			cerr<<"Error: Number of stairs must be a positive integer"<< endl;
		}
	}
vector<vector <int> > stair = get_ways(n);
display_ways(stair);
	return 0;
}
