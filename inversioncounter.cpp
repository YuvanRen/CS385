/*******************************************************************************
* Name : inversioncounter.cpp
* Author : Yuvan Rengifo
* Version : 1.0
* Date : April 20, 2023
* Description : Counts the number of inversions in an array.
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);
/**
* Counts the number of inversions in an array in Theta(n^2) time.
*/


long count_inversions_slow(int array[], int length) {
// TODO
/**
* Counts the number of inversions in an array in Theta(n lg n) time.
*/
	long counter = 0;
for(int i= 0; i <=length; i++){
	for(int j= i + 1; j<=length;j++){
		if(array[i] > array[j]){
			counter ++;
		}
	}
}
return counter;
}

long count_inversions_fast(int array[], int length) {
// TODO
// Hint: Use mergesort!
	   int *scratch = new int[length]();
	    long counter = mergesort(array, scratch, 0, length-1);
	    delete [] scratch;
	    return counter;
	}
static long mergesort(int array[], int scratch[], int low, int high) {
// TODO
    long inversions = 0;
    int mid, L, H;

    // Base case: if the subarray has length 1 or less, it is already sorted
    if (low < high) {
        mid = low + ((high - low) / 2);

        // Recursively sort the left and right halves of the array
        inversions += mergesort(array, scratch, low, mid);
        inversions += mergesort(array, scratch, mid+1, high);

        // Merge the sorted halves into a single sorted array
        L = low;
        H = mid + 1;
        for (int i = low; i <= high; i++) {
            if (L <= mid && (H > high || array[L] <= array[H])) {
                // Take the next element from the left half
                scratch[i] = array[L];
                L++;
            } else {
                // Take the next element from the right half
                scratch[i] = array[H];
                H++;

                // Increment inversions by the number of remaining elements in the left half
                inversions += (mid - L + 1);
            }
        }

        // Copy the merged array back into the original array
        for (int i = low; i <= high; i++) {
            array[i] = scratch[i];
        }
    }

    return inversions;
}

/*mergesort helper function
long merge(int A[], int B[], int lo,int mid,int hi){
	int i = lo, j = mid+1, k = lo;
	    long inversions = 0;

	    while (i <= mid && j <= hi) {
	        if (A[i] <= A[j]) {
	            B[k++] = A[i++];
	        }
	        else {
	            B[k++] = A[j++];
	            inversions += mid - i + 1;
	        }
	    }

	    while (i <= mid) {
	        B[k++] = A[i++];
	    }

	    while (j <= hi) {
	        B[k++] = A[j++];
	    }

	    for (i = lo; i <= hi; i++) {
	        A[i] = B[i];
	    }

	    return inversions;
	}
*/

int main(int argc, char *argv[]) {
// TODO: parse command-line argument
	bool slow = false;

	if (argc == 2){
	        ostringstream oss;
	        oss << argv[1];
	        if (oss.str() != "slow"){
	            cerr << "Error: Unrecognized option '" << oss.str() << "'." << endl;
	            return 1;
	        }
	    }

	    if (argc > 2){
	        cerr << "Usage: ./inversioncounter [slow]" << endl;
	        return 1;
	    }
	cout << "Enter sequence of integers, each followed by a space: " << flush;
	istringstream iss;
	int value, index = 0;
	vector<int> values;
	string str;
	str.reserve(11);
	char c;
	while (true) {
		c = getchar();
		const bool eoln = c == '\r' || c == '\n';
		if (isspace(c) || eoln) {
			if (str.length() > 0) {
				iss.str(str);
				if (iss >> value) {
					values.push_back(value);
				}
				else {
					cerr << "Error: Non-integer value '" << str
							<< "' received at index " << index << "." << endl;
					return 1;
}
				iss.clear();
				++index;
}
			if (eoln) {
				break;
}
			str.clear();
}
		else {
			str += c;
}
}

// TODO: produce output
	 if(index == 0){
	        cerr << "Error: Sequence of integers not received." << endl;
	        return 1;
	    }
		if(slow == true){
			cout << "Number of inversions: " << count_inversions_slow(&values[0], index) << endl;
		} else {
			cout << "Number of inversions: " << count_inversions_fast(&values[0], index) << endl;
	    }
return 0;
}
