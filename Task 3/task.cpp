#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;

class DynamicArray {
private:
    int* data;
    int capacity;
    int size;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() {
        data = new int[1];
        capacity = 1;
        size = 0;
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size <= capacity / 4) {
            resize(capacity / 2);
        }
    }

    int indexOf(int item) {
        for (int i = 0; i < size; i++) {
            if (data[i] == item) {
                return i;
            }
        }
        return -1;
    }

    int at(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int max() {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        int maxValue = data[0];
        for (int i = 1; i < size; i++) {
            maxValue = std::max(maxValue, data[i]);
        }
        return maxValue;
    }

    int min() {
        if (size == 0) {
            throw std::runtime_error("Array is empty");
        }
        int minValue = data[0];
        for (int i = 1; i < size; i++) {
            minValue = std::min(minValue, data[i]);
        }
        return minValue;
    }

    void remove(int item) {
        int index = indexOf(item);
        if (index != -1) {
            removeAt(index);
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    arr.insert(10);
    arr.insert(20);
    arr.insert(5);
    arr.insert(30);

    cout << "Array elements: ";
    arr.printArray();

    cout << "Max: " << arr.max() << endl;
    cout << "Min: " << arr.min() << endl;

    arr.remove(20);
    cout << "After removing 20: ";
    arr.printArray();

    return 0;
}
