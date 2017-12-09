#include <iostream>

using namespace std;

unsigned int bang(unsigned int num)
{
    unsigned int ret = 1;
    while(num>1){
        ret *= num;
        num--;
    }
    return ret;
}
bool test(unsigned int n)
{
    unsigned int compsum=0;
    for(unsigned int i=n; i; i/=10)
        compsum+=bang(i%10);
    if(compsum == n)
        return true;
    return false;
}
int main()
{
    unsigned int answer = 0;
    for(unsigned int i=3; i < 2540160; i++)
        if(test(i)){
            cout << "Found one: " << i << endl;
            answer += i;
        }
    cout << "Answer = " << answer << endl;
}
