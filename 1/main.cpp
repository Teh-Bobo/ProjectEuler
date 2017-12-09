#include <iostream>

using namespace std;

int main()
{
    unsigned int answer = 0;
    asm(    "xor %%eax, %%eax \n" //eax is our result
            "movl $3, %%ecx \n" //ecx = i
            ".Loop1: \n"
            "addl %%ecx,%%eax \n"
            "addl $3, %%ecx \n"
            "cmp  $1000, %%ecx \n"
            "jl   .Loop1 \n"
            "movl $5, %%ecx \n"
            ".Loop2: \n"
            "addl %%ecx,%%eax \n"
            "addl $5, %%ecx \n"
            "cmp $1000, %%ecx \n"
            "jl .Loop2 \n"
            "xor %%ebx, %%ebx \n"
            "xor %%ecx, %%ecx \n"
            ".Loop3: \n"
            "addl %%ecx, %%ebx \n"
            "addl $15, %%ecx \n"
            "cmp $1000, %%ecx \n"
            "jl .Loop3 \n"
            "subl %%ebx, %%eax \n"
            "movl %%eax, %0 \n"
            :"=r" (answer)
            :
            : "%ecx", "%eax" ,"%ebx"
       );
    cout << answer << endl;
}
