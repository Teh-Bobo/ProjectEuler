#include <iostream>
#include <vector>
#include "euler.h"

using namespace std;

int main()
{
    const int MAX = 5779;
    vector<bool> meh(MAX,false);
    primesieve ps(MAX,true);
    for(int i=3; i < MAX; ){
        for(int j = 1; (i+(2*j*j)) < MAX; ++j){
            meh[(i+(2*j*j))] = true;
            meh[i] = true;
        }
        while(!ps.isprime(++++i));
    }
    for(int i=3; i < MAX; ++++i){
        if(!meh[i]){
            cout << i << endl;
            break;
        }
    }
}
