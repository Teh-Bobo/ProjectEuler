#include <vector>
#include <omp.h>
class primesieve
{
private:
	std::vector<bool>* primes;
	std::vector<unsigned long>* nextlist;
public:
	primesieve(unsigned long,bool=false,bool=false);
	~primesieve();
	unsigned int size() {return primes->size();};
	bool isprime(unsigned long n){return primes->at(n);};
	unsigned long nextprime();
};
