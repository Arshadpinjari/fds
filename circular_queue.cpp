#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, maxSize, *orders;

public:
    CircularQueue(int size) : maxSize(size), front(-1), rear(-1), orders(new int[maxSize]) {}
    ~CircularQueue() { delete[] orders; }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (front == 0 && rear == maxSize - 1) || (front == rear + 1); }

    void placeOrder(int orderNumber) {
        if (isFull()) cout << "Queue full. Cannot accept more orders." << endl;
        else {
            if (isEmpty()) front = rear = 0;
            else rear = (rear + 1) % maxSize;
            orders[rear] = orderNumber;
            cout << "Order " << orderNumber << " placed successfully." << endl;
        }
    }

    void serveOrder() {
        if (isEmpty()) cout << "No orders to serve. Queue is empty." << endl;
        else {
            int servedOrder = orders[front];
            cout << "Serving order " << servedOrder << "." << endl;
            (front == rear) ? front = rear = -1 : front = (front + 1) % maxSize;
        }
    }

    void displayOrders() {
        if (isEmpty()) cout << "No orders in the queue." << endl;
        else {
            cout << "Orders in the queue: ";
            int i = front;
            do {
                cout << orders[i] << " ";
                i = (i + 1) % maxSize;
            } while (i != (rear + 1) % maxSize);
            cout << endl;
        }
    }
};

int main() {
    int maxSize, choice, orderNumber = 1;
    cout << "Enter the maximum number of orders the pizza parlor can accept (M): ";
    cin >> maxSize;

    CircularQueue pizzaQueue(maxSize);

    do {
        cout << "\nMenu:\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: pizzaQueue.placeOrder(orderNumber++); break;
            case 2: pizzaQueue.serveOrder(); break;
            case 3: pizzaQueue.displayOrders(); break;
            case 4: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}

