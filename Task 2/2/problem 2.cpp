#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int RandomValue (int n){
return (int)rand()%n;

}

int main (){
int n;    
cin >> n;
cout << RandomValue (n);
return 0;    
}