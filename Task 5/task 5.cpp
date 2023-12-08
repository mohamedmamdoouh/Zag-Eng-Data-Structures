#include <iostream>
#include <limits>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node* next;

    Node(T value) {
        this->value = value;
        this->next = nullptr;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~LinkedList() {
        while (head != nullptr) {
            removeFirst();
        }
    }

    void addFirst(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addLast(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void removeFirst() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        size--;
    }

    void removeLast() {
        if (isEmpty()) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    int indexOf(T value) {
        Node<T>* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    bool contains(T value) {
        return indexOf(value) != -1;
    }

    int getSize() {
        return size;
    }

    void printElements() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverse() {
    }

private:
    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    LinkedList<int> intList;
    intList.addFirst(10);
    intList.addLast(20);
    intList.addFirst(5);
    intList.printElements();

    LinkedList<string> stringList;
    stringList.addFirst("Hello");
    stringList.addLast("World");
    stringList.addFirst("C++");
    stringList.printElements();

    return 0;
}
