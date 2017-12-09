/* 
 * File:   main.cpp
 * Author: bobo
 *
 * Created on July 25, 2017, 10:30 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "euler.h"

using namespace std;
const unsigned long MAX = 99999999;

string ultos(unsigned long x){
    stringstream ss;
    ss << x;
    return ss.str();
}

void Search(vector<unsigned long> *pairList,unsigned long lastIndex,int MaxDepth,int CurrentDepth, primesieve *ps,unsigned long MAXPRIME){
    if (CurrentDepth >= MaxDepth){return;}
    for(unsigned long i=lastIndex+1; i < MAXPRIME; i++){
        if(!ps->isprime(i)){continue;}
        for(int j=0; j < pairList->size(); j++){
            unsigned long a = atol((ultos(pairList->at(j)) + ultos(i)).c_str());
            unsigned long b = atol((ultos(i) + ultos(pairList->at(j))).c_str());
            if(a>MAX or b>MAX or !ps->isprime(a) or !ps->isprime(b)){goto label;}
        }
        pairList->push_back(i);
        if(pairList->size() >= MaxDepth){
            for(int j=0; j < pairList->size(); j++){
                cout << pairList->at(j) << " ";
            }
            cout << "-- " << lastIndex << " " << MaxDepth << " " << CurrentDepth << endl;
        }
        if(CurrentDepth < MaxDepth){
            Search(pairList,i,MaxDepth,CurrentDepth+1,ps,MAXPRIME);
        }
        pairList->pop_back();
label:  cout << "";
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    primesieve p(MAX,true,false);
    unsigned long MAXPRIME;
    for(unsigned long i=MAX-1; i > 0; i--){
        if(p.isprime(i) and (ultos(i).size() <= (ultos(MAX).size()-2))){
            MAXPRIME = i;
            cout << MAXPRIME << endl;
            break;
        }
    }
    cout << "Done with table" << endl;
    for(unsigned long i=0; i < MAX; i++){
        if(!p.isprime(i)) continue;
        vector<unsigned long> *start = new vector<unsigned long>();
        start->push_back(i);
        Search(start,i,5,1,&p,MAXPRIME);
        delete(start);
    }
    
    return 0;
}

