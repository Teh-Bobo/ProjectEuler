#include <iostream>
#include <cstdio>
#include "euler.h"
using namespace std;

bool test(unsigned long n)
{
    int nums[] = {17,13,11,7,5,3,2};
    for(int i=0; i <7; ++i,n/=10)
        if(((n%1000)%nums[i])!=0)
            return false;
    return true;
}
int main()
{
    unsigned long answer=0;
    pandigital pan;
    for(unsigned long i=1000000000; i <= 9876543210; ++i)
//        if(pan.isPandigital(i,0,9) && test(i))
        if(test(i) && pan.isPandigital(i,0,9))
            answer += i;
    cout << answer << endl;
}
