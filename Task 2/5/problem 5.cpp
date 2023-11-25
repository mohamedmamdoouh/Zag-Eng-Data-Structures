#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

template <typename T>

void GenericsArray (T array[], int size){
for (int i=0; i<size; i++){
cout << array[i];    
}
}

int main (){
int arr1[] = {1,3,5,2};
char arr2[] = {'d','g','e','t','g'};

GenericsArray (arr1, 4); 
cout << endl;
GenericsArray (arr2, 5);
return 0;    
}