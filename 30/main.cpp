#include <iostream>
using namespace std;
#define POW5(a) ((a)*(a)*(a)*(a)*(a))
unsigned int sumdigitsto5(unsigned int base)
{
    unsigned int ret=0;
    register unsigned int temp;
    while(base){
        temp = base%10;
        ret+=POW5(temp);
        base/=10;
    }
    return ret;
}
int main()
{
    unsigned long ret=0;
    for(int i=2; i <= 354294; ++i)
        if(i == sumdigitsto5(i)) 
                ret+=i;
    cout << ret << endl;
}
