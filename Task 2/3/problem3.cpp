#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int RandomValue (int min, int max){
return (int)(min+rand()%(max-min+1)); // random interval in c++ = min + (rand() % (max-min+1));
}
int main (){
int min, max;    
cin >> min>>max;
cout << RandomValue (min, max);
return 0;    
}