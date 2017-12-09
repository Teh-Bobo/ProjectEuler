#include <iostream>

bool is_pandigital_prod(int x,int y)
{
    int res = 0;
    register int temp = x;
    register int modtemp;
    register int shifttemp;
    while(temp){
        modtemp = temp%10;
        if(modtemp==0)
            return false;
        shifttemp = (1 << (modtemp -1));
        if(shifttemp & res)
            return false;
        res |= shifttemp;
        temp /= 10;
    }
    temp = y;
    while(temp){
        modtemp = temp%10;
        if(modtemp==0)
            return false;
        shifttemp = (1 << (modtemp -1));
        if(shifttemp & res)
            return false;
        res |= shifttemp; 
        temp/=10;
    }
    temp = x*y;
    while(temp){
        shifttemp=(1 << (temp%10 -1));
        if(shifttemp & res)
            return false;
        res |= shifttemp;
        temp/=10;
    }
    return (res == 0x1ff);
}

int main()
{
    std::cout << (char)127;
    for(int i=100; i<=9999; ++i)
        for(int j=1; j<=99; ++j)
            if(is_pandigital_prod(i,j))
                std::cout <<" " << i*j;
}
