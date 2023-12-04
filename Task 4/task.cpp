#include <iostream>
#include <limits>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Add value at the front of the list - O(1)
    void addFirst(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    // Add value at the end of the list - O(1)
    void addLast(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // Remove first element - O(1)
    void removeFirst() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        size--;
    }

    // Remove last element - O(n)
    void removeLast() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    // Get index of value - O(n)
    int indexOf(int value) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    // Check if value exists - O(n)
    bool contains(int value) {
        return indexOf(value) != -1;
    }

    // Get size of the list - O(1)
    int getSize() {
        return size;
    }

    // Print all elements - O(n)
    void printElements() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Find max element - O(n)
    int max() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return numeric_limits<int>::min(); // Return minimum int value
        }

        int maxVal = head->value;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->value > maxVal) maxVal = current->value;
            current = current->next;
        }
        return maxVal;
    }

    // Find min element - O(n)
    int min() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return numeric_limits<int>::max(); // Return maximum int value
        }

        int minVal = head->value;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->value < minVal) minVal = current->value;
            current = current->next;
        }
        return minVal;
    }

private:
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    LinkedList list;
    list.addFirst(10);
    list.addLast(20);
    list.addFirst(5);
    list.printElements(); // Should print 5 10 20
    cout << "Max: " << list.max() << endl; // Max: 20
    cout << "Min: " << list.min() << endl; // Min: 5
    return 0;
}
