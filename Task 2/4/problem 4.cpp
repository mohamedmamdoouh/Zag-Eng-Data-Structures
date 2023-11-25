#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

char RandomChar (){
int index = rand()%26;
char indexToChar = 'a' + index;
return indexToChar;
}
int main (){
char result = RandomChar();     
cout << result;
return 0;    
}