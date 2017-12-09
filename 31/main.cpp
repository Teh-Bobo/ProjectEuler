#include <iostream>
using namespace std;
int main()
{
    unsigned int ret=1;//for the two pound note 
    for(int pound1=200;pound1>=0;pound1-=100)
        for(int p50=pound1;p50>=0;p50-=50)
            for(int p20=p50;p20>=0;p20-=20)
                for(int p10=p20;p10>=0;p10-=10)
                    for(int p5=p10;p5>=0;p5-=5)
                        for(int p2=p5;p2>=0;----p2)
                                    ++ret;
    cout << ret << endl;
}

