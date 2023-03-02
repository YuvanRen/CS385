/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Yuvan Rengifo
 * Date        : March 2, 2023
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }
    int num_primes() const {
        return num_primes_;
    }
    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;
    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
};
PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}
void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.
	const int max_prime_width = num_digits(max_prime_),
	primes_per_row = 80 / (max_prime_width + 1);

	if(count_num_primes() <= primes_per_row){	//Single line
		for(int i = 2; i <= limit_; i++){
			if( i == 2){
				cout << i;
			}
			else if (is_prime_[i] == true){
				cout<< " " << i;

			}

		}
	}
	int primes = 0;
	if(count_num_primes() >=  primes_per_row){ // multiple lines
		for(int i = 2; i <=limit_; i++){
		if(num_digits(limit_) == 2){	//If limit has 2 digits
			if(is_prime_[i] == true){
				if( i != max_prime_ ){
					cout << i << " ";
				}
				cout << max_prime_;
		}
		}
		if(num_digits(limit_) >= 3){	//If limit has 3 or more digits
			if(is_prime_[i] == true){
				if( i != max_prime_ ){
					if( primes == 0){
					cout << setw(max_prime_width)<< i;
						}
					else{
					cout << setw(max_prime_width + 1) << i;
					}
					primes ++;
		}
				if(i == max_prime_){
					cout<< " " << max_prime_;
									}
			if(primes == 20){	// Reached max primes in a row
					cout<< endl;
					primes = 0;	// Start new line
														}
	}
}
	}}
}


int PrimesSieve::count_num_primes() const {
    // TODO: write code to count the number of primes found
	int count = 0;
	for(int i = 2 ; i <= limit_; i++){
		if( is_prime_[i] == true){
		count ++;
		}
	}

    return count;
}
void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
	for (int i = 0; i<= limit_;i++){
		is_prime_[i] = true;
	}
	for(int i = 2; i <= sqrt(limit_);i++){
		if (is_prime_[i] == true){
			for( int j = i*i; j <= limit_ ; j= j+i){
				is_prime_[j] = false;
			}
		}
	}

	for(int i = limit_; i >0 ; i--){
		if(is_prime_[i] == true){
			max_prime_ = i;
			break;
		}
	}
	num_primes_ = count_num_primes();

}
int PrimesSieve::num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.
	int digits = 0;
	while(num!=0){
		num = num/10;
		digits++;
	}
    return digits;
}
int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;
    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);
    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }
    // TODO: write code that uses your class to produce the desired output.
    PrimesSieve primes(limit);
    cout<<endl;
    	cout<< "Number of primes found: " << primes.num_primes() << endl;
    	cout<< "Primes up to " << limit << ":" << endl;
    	primes.display_primes();
    return 0;
}
