#include <iostream>

using namespace std;

int main()
{
    unsigned int answer = 0;
    asm("movl $1,%%ecx \n"
            "xor %%ebx,%%ebx \n"
            "xor %0,%0 \n"
            ".Fib1: \n"
            "test $1,%%ecx \n"
            "jne .Odd \n"
            "addl %%ecx,%0 \n"
            ".Odd: \n"
            "xaddl %%ebx,%%ecx \n"
            "cmpl $4000000,%%ecx \n"
            "jle .Fib1 \n"
            :"=r" (answer)
            :
            : "%ebx", "%ecx", "%edx"
       );
    cout << answer << endl;
}
