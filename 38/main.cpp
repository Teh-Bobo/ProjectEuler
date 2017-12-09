#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;

bool isPandigital(char* num)
{//the name lies, it only check 9 digit pandigitals
    bool digits[10];
    for(int i=0; i < 10; ++i)
        digits[i] = false;
    for(int i=0; i < 9; ++i)
        digits[num[i]-'0'] = true;
    for(int i=1; i < 10; ++i)
        if(!digits[i])
            return false;
    return true;
}
unsigned int doGroup(void)
{//max must be >=2 and <=5
    char buff[10];
    unsigned int max = 0; 
    for(int i=5000;i<=9999;++i){
        sprintf(buff,"%d%d",i,i*2);
        if(isPandigital(buff) && atoi(buff) > max)
            max = atoi(buff);
    }
    for(int i=100;i<=333;++i){
        sprintf(buff,"%d%d%d",i,i*2,i*3);
        if(isPandigital(buff) && atoi(buff) > max)
            max = atoi(buff);
    }
    for(int i=10;i<=24;++i){
        sprintf(buff,"%d%d%d%d",i,i*2,i*3,i*4);
        if(isPandigital(buff) && atoi(buff) > max)
            max = atoi(buff);
    }
    for(int i=5;i<=9;++i){
        sprintf(buff,"%d%d%d%d%d",i,i*2,i*3,i*4,i*5);
        if(isPandigital(buff) && atoi(buff) > max)
            max = atoi(buff);
    }
    return max;
}
int main()
{
    cout << doGroup() << endl;
}
