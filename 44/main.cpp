#include <iostream>
#include <math.h>
using namespace std;

bool isPentagonal(unsigned int n)
{
    float temp = (sqrt(24*n + 1)+1)/6;
    return temp == (int)temp;
}
int main()
{
    const int MAX = 1000000;
    unsigned int pent[MAX];
    unsigned int answer = -1;
    for(int i=1; i < MAX; ++i)
        pent[i] = i*(3*i-1)/2;

    for(int gap = 1; gap < MAX -1; ++gap)
            for(int i=1,j=gap+1; j < MAX; ++i,++j)
//    for(int i=100000; i < MAX-1; ++i)
//        for(int j = i+1; j < MAX; ++j)
            if(isPentagonal(pent[j]-pent[i]) &&
                    isPentagonal(pent[i]+pent[j]) && 
                    (pent[j]-pent[i]) < answer){
                answer = (pent[j]-pent[i]);
                cerr << answer << ' ' << i << ' ' << j << endl;
            }
    cout << answer << endl;
}
