/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Yuvan Rengifo
 * Date        : March 9, 2023
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens honor system.
 ******************************************************************************/
#include <iostream>
#include <cctype>
using namespace std;

bool is_all_lowercase(const string &s) {
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
unsigned int letter = 0;
while( letter < s.length()){
	if(isupper(s[letter]) || isdigit(s[letter])){
		return false;
	}
	else{
		letter++;
	}
}
return true;
}

bool all_unique_letters(const string &s) {
    // TODO: returns true if all letters in string are unique, that is
    // no duplicates are found; false otherwise.
    // You MUST use only a single int for storage and work with bitwise
    // and bitshifting operators.  Using any other kind of solution will
    // automatically result in a grade of ZERO for the whole assignment.
	unsigned int storage = 0;
	for (unsigned int i = 0; i < s.length(); i++){
		unsigned int check;
		check = 1 << (s[i] - 'a');
		if((check & storage) != 0){
			return false;
		}
		else{
			storage |= check;
		}
	}

return true;
}

int main(int argc, char * const argv[]) {
    // TODO: reads and parses command line arguments.
    // Calls other functions to produce correct output.
	if(argc != 2){
	  cerr << "Usage: ./unique <string>" << endl;
	  return 1;
	}

	if(!(is_all_lowercase(argv[1]))) {
	   cerr << "Error: String must contain only lowercase letters." << endl;
	  return 1;
	    }

	else{
	    if(all_unique_letters(argv[1]) == true) {

	        cout << "All letters are unique." << endl;

	    }
	    if(all_unique_letters(argv[1]) == false){
 	       cout << "Duplicate letters found." << endl;
	    }
 	    }
	    return 0;
	}
