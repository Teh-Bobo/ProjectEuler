#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool isTriangleNum(unsigned int n)
{
    float temp = (-1+sqrt(1+8*n))/2;
    return temp == (int)temp;
}
bool isTriangleWord(string& s)
{
    unsigned int temp = 0;
    for(int i=0; i < s.size(); ++i)
        temp += s[i] - '@';
    return isTriangleNum(temp);
}
int main()
{
    string s;
    unsigned int answer =0;
    while(cin.good()){
        cin >> s;
        if(isTriangleWord(s))
            ++answer;
    }
    cout << answer << endl;
}
