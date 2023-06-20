#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;

//just a class so i can time my program. i found this on stackoverflow.
class Timer
{
    private:
    using Clock = chrono::steady_clock;
    using Second = chrono::duration<double, ratio<1>>;
    chrono::time_point<Clock> m_beg { Clock::now() };
    
public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

int main(){
    ofstream out("10milprimes.txt");
    Timer t;
    long double sqr;
    bool isPrime;
    unsigned int n = 10000000; // 10 million
    vector<unsigned long long> primes = {2, 3, 5}; // list of primes

    primes.reserve(n/2); // reserve space for the vector, so it doesnt have to resize every time a new prime is found

    for(unsigned long long i = 5; i < n; i+=2){
        sqr = sqrt(i); // if a number is not a prime, it is divisible by a prime number smaller than its square root
        int intsqr = sqr;
        isPrime = true;
                for(unsigned long long j = 0; j < primes.size(); j++){

            
            if(primes[j] > sqr)
            {
                break; // we dont have to check for primes bigger than the square root of i
            }
            if((i % primes[j] == 0))
            {
                isPrime = false; // if i is divisible by a prime number, it is not a prime number
                break;
            }
        } // end of loop for checking if i is a prime
            
        if(isPrime){
            primes.push_back(i);
        } 
    } // end of loop for iterating.
    
    cout << "Time elapsed: " << t.elapsed () << " seconds" << endl;
    
    for(int i = 0; i < primes.size(); i++){
        out << primes[i] << ", ";
    }

    out.close();
    return 0;
}