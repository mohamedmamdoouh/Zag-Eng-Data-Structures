#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class General {
public:
    // Reverse a number
    static string reversedNum(int originalNumber) {
        string reversedNum = to_string(originalNumber);
        reverse(reversedNum.begin(), reversedNum.end());
        return reversedNum;
    }

    // Generate a random number between 0 and n
    static int randomValue(int n) {
        return rand() % n;
    }

    // Generate a random integer between min and max
    static int randomValue(int min, int max) {
        return min + rand() % (max - min + 1);
    }

    // Generate a random character
    static char randomChar() {
        int index = rand() % 26;
        char indexToChar = 'a' + index;
        return indexToChar;
    }

    // Print elements of a generic array
    template <typename T>
    static void genericsArray(T array[], int size) {
        for (int i = 0; i < size; i++) {
            cout << array[i];
        }
    }
};

int main() {
    int n;

    // Test reversedNum
    cout << "Enter a number to be reversed: ";
    cin >> n;
    string reversed = General::reversedNum(n);
    cout << "Reversed number is: " << reversed << endl;

    // Test randomValue (int)
    cout << "Enter a number for randomValue (int): ";
    cin >> n;
    int randomInt = General::randomValue(n);
    cout << "Random integer: " << randomInt << endl;

    // Test randomValue (int, int)
    int min, max;
    cout << "Enter min and max for randomValue: ";
    cin >> min >> max;
    int randomRangeInt = General::randomValue(min, max);
    cout << "Random integer is " << randomRangeInt << endl;

    // Test randomChar
    char randomCharacter = General::randomChar();
    cout << "Random character: " << randomCharacter << endl;

    // Test genericsArray
    int arr1[] = { 1, 3, 5, 2 };
    char arr2[] = { 'd', 'g', 'e', 't', 'g' };

    cout << "Elements of arr1: ";
    General::genericsArray(arr1, 4);
    cout << endl;

    cout << "Elements of arr2: ";
    General::genericsArray(arr2, 5);
    cout << endl;

    return 0;
}
