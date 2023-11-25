#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ReversedNum (int OriginalNum){
int reversed = 0;
int digit;

while (OriginalNum !=0){    //as every time we devide by 10, number is cut until it's finished (=0)
digit = OriginalNum % 10;   // we get the last digit
reversed = reversed * 10 + digit; // to add the last digit in its correponding position
OriginalNum /= 10;   //to get rid of last digit after we stored it (avoid repeated number)
}
return reversed;
}


int main (){
int n;
cout << "please enter a number to be reversed" << endl;
cin >> n;
int result = ReversedNum (n);
cout << "reversed number is " << result;
return 0;    
}