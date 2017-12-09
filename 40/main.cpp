#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    char meh[10];
    string s = "";
    int answer = 1;
    for(unsigned int i=0; s.size() <= 1000000; ++i){
        sprintf(meh,"%d",i);
        s += meh;
    }
    for(int i=1; i<=1000000; i*=10)
        answer *= s[i] - '0';
    cout << answer << endl;
//    cout << s[1] << ' ' << s[10] << ' ' << s[100] << ' ';
  //  cout << s[1000] << ' ' << s[10000] << ' ' << s[100000] << ' ';
    //cout << s[1000000] << endl;
}
