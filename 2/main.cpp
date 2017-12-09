#include <iostream>

using namespace std;

int main()
{
    int a=0,b=0,answer=0;
    for(int i=1; i < 4000000; i=a+b){
        answer += (i*(i&1));
        a=b;
        b=i;
    }
    cout << answer << endl;
}
