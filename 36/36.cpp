#include <iostream>
#include <cstdio>

using namespace std;

bool isPalindrome10(int num)
{
    //only works for numbers less than 8 chars long
    char s[8];
    int length = sprintf(s,"%d",num);
    for(int i = 0; i < length/2; ++i)
        if(s[i] != s[length - i - 1])
            return false;
    return true;
}
bool isPalindrome2(int num)
{
    //only works for numbers less than 20 bits long
    unsigned int lmask = 1 << 20;
    unsigned int length = 20;
    for(;!(lmask & num); lmask = lmask >> 1,--length)
        ;
    for(unsigned int rmask = 1,i = 0; i <= length/2; 
            lmask = lmask >> 1,rmask = rmask << 1, ++i)
        if(((num & rmask)>>i) != ((num & lmask)>>(length-i)))
            return false;
    return true;
}
int main()
{
    unsigned int answer = 0;

    for(int i = 1; i < 1000000; ++++i)
        if(isPalindrome10(i) && isPalindrome2(i))
            answer += i;
    cout << answer << endl;
}
