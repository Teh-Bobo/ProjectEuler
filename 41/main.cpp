#include <iostream>
#include "euler.h"

using namespace std;
int main()
{
    primesieve ps(7654321);
    pandigital pan;
    cerr << "ps done..." << endl;
    for(unsigned int i=7654321; i; ----i){
        if(ps.isprime(i) && pan.isPandigital(i)){
            cout << i << endl;
            return 0;
        }
    }
}
