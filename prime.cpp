#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <fstream>

using namespace std;
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

int main() {
    ofstream out("10milprimes.txt");
    Timer t;
    unsigned int n = 1000000000; // onebillion
    vector<bool> isPrime(n + 1, true); // assume all numbers are prime initially
    vector<unsigned int> primes;

    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (unsigned int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i); // i is prime
            for (unsigned int j = i * i; j <= n; j += i) {
                isPrime[j] = false; // mark multiples of i as non-prime
            }
        }
    }

    cout << "Time elapsed: " << t.elapsed() << " seconds" << endl;

    for (unsigned int i = 0; i < primes.size(); i++) {
        out << primes[i] << ", ";
    }

    out.close();
    return 0;
}