#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Deque {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Deque() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void addFront(int element) {
        if (isFull()) cout << "Deque full. Cannot add at front." << endl;
        else {
            front = isEmpty() ? 0 : (front - 1 + MAX_SIZE) % MAX_SIZE;
            arr[front] = element;
            cout << "Added " << element << " at front." << endl;
        }
    }

    void addRear(int element) {
        if (isFull()) cout << "Deque full. Cannot add at rear." << endl;
        else {
            rear = isEmpty() ? 0 : (rear + 1) % MAX_SIZE;
            arr[rear] = element;
            cout << "Added " << element << " at rear." << endl;
        }
    }

    void deleteFront() {
        if (isEmpty()) cout << "Deque empty. Cannot delete from front." << endl;
        else {
            cout << "Deleted " << arr[front] << " from front." << endl;
            front = (front == rear) ? -1 : (front + 1) % MAX_SIZE;
        }
    }

    void deleteRear() {
        if (isEmpty()) cout << "Deque empty. Cannot delete from rear." << endl;
        else {
            cout << "Deleted " << arr[rear] << " from rear." << endl;
            rear = (front == rear) ? -1 : (rear - 1 + MAX_SIZE) % MAX_SIZE;
        }
    }

    void displayDeque() {
        if (isEmpty()) cout << "Deque empty." << endl;
        else {
            cout << "Deque elements: ";
            int i = front;
            do {
                cout << arr[i] << " ";
                i = (i + 1) % MAX_SIZE;
            } while (i != (rear + 1) % MAX_SIZE);
            cout << endl;
        }
    }
};

int main() {
    Deque deque;
    deque.addFront(5);
    deque.addRear(10);
    deque.addRear(15);
    deque.displayDeque();

    deque.deleteFront();
    deque.displayDeque();

    deque.addFront(20);
    deque.addFront(25);
    deque.displayDeque();

    deque.deleteRear();
    deque.displayDeque();

    return 0;
}

