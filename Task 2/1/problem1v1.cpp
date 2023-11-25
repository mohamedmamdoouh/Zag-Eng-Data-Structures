#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reversedNum (int originalNumber){
string reversedNum = to_string(originalNumber);

reverse (reversedNum.begin(), reversedNum.end());
return reversedNum;
}


int main (){
int n;
cout << "please enter a number to be reversed" << endl;
cin >> n;
string result = reversedNum (n);
cout << "reversed number is " << result;
return 0;    
}
