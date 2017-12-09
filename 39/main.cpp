#include <iostream>

using namespace std;

int main()
{
    int answer = 0,answerp=0;
    for(int p = 10; p<=1000; ++p){
        int thisp = 0;
        for(int c = p/3; c <= p-2; ++c)
            for(int b = 2; b < c; ++b)
                for(int a = 2; a <= b; ++a)
                    if((a+b+c) == p && (a*a+b*b) == (c*c) && ++thisp > answerp){
                        answerp = thisp;
                        answer = p;
                    }
    }
    cout << answer  << endl;
}
