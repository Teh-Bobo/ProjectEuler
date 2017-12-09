#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "primesieve.h"
#include <cstdio>

using namespace std;

char* rotate(char* s,unsigned int size){
//    ostringstream sin;
//    sin << num;
//    string s = sin.str();
    if(size==1)
        return s;
    char temp = s[0];
    for(int i=1; i < size; ++i)
        s[i-1] = s[i];
    s[size-1] = temp;


//    s.push_back(s[s.size()-2]);
//    s.push_back('\0');
//    s.erase(s.size()-1,1);
//    s.erase(0,1);
    return s;
}
bool isCircularPrime(const unsigned int num,primesieve* ps)
{
    char s[12];
    int size = sprintf(s,"%d",num);
    for(int i=0; i < size; ++i){
        if(!ps->isprime(atoi(s)))
            return false;
        rotate(s,size);
//        cerr << n << endl;
    }
    return true;
}
int main()
{
    int answer = 0;
    primesieve ps(1000000);
    for(int i=1; i < 1000000;++i){ 
        if(isCircularPrime(i,&ps))
            ++answer;
    }
    cout << answer << endl;
}

