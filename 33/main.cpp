#include <iostream>

using namespace std;

int main()
{
    int tot=0;

    for(int num=11; num < 100; num++){
        if((num%10)==0)
            continue;
        for(int den=num+1; den < 100; den++){
            if((den%10)==0)
                continue;
            register float temp = (float)num/den;
            if(((den/10 == num/10) && ((float)(num%10)/(den%10)==temp)) ||
               ((den/10 == num%10) && ((float)(num/10)/(den%10)==temp)) ||
               ((den%10 == num/10) && ((float)(num%10)/(den/10)==temp)) ||
               ((den%10 == num%10) && ((float)(num/10)/(den/10)==temp))){

                tot+=1;
                cerr << "Found one: " << num << '/' << den << '=' << temp
                    << endl;
            }
        }
    }
    cout << "Found a total of: " << tot << endl;
}
