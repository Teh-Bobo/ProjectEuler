#include <iostream>
#include "primesieve.h"
using namespace std;

bool rtol(unsigned int num,primesieve* ps)
{
    for(;num;num/=10)
        if(!ps->isprime(num))
            return false;
    return true;
}
bool ltor(unsigned int num,primesieve* ps)
{
    unsigned mod = 1;
    for(;num%mod != num; mod*=10)
        ;
    for(;mod>1;mod/=10)
        if(!ps->isprime(num%mod))
            return false;
    return true;
}
int main()
{
    primesieve ps(739397);
    unsigned int answer = 0;
    for(unsigned int i = 11; i <739398; ++++i)
        if(rtol(i,&ps) && ltor(i,&ps))
            answer += i;
    cerr << answer << endl;
}
