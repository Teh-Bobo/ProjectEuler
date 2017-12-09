#include <iostream>
#include <math.h>
#include <gmpxx.h>
bool isPrime(unsigned long n)
{
    for(unsigned long i=2; i < sqrt(n); ++i)
        if(n%i==0)
            return false;
    return true;
}
unsigned long nextPrime(unsigned long n)
{
    std::cerr << "Entering nextPrime: ";
    while(!isPrime(++n)){}
    std::cerr << "nextPrime returning " << n << '\n';
    return n;
}
unsigned long nextA(void)
{
    static unsigned long t = 100000000000000;
    t = nextPrime(t);
    return t;
}
int main()
{
    mpz_class ret,temp;
    mpz_fib_ui(ret.get_mpz_t(),100000000);
    for(int i=1; i <=10;++i){
        std::cerr << ret << '\n';
        mpz_fib_ui(temp.get_mpz_t(),nextA());
        ret += temp;
    }
    std::cout << ret << '\n';
}
