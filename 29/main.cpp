#include <iostream>
#include <gmpxx.h>

#define MAX_A 100
#define MAX_B 100

int main()
{
    mpz_t res;
    mpz_init(res);
    for(unsigned long a=2; a <= MAX_A; ++a)
	for(unsigned long b=2; b <= MAX_B; ++b){
	    mpz_ui_pow_ui(res,a,b);
	    mpz_out_str(NULL,10,res);
	    std::cout << "\n";
    	}       
}
