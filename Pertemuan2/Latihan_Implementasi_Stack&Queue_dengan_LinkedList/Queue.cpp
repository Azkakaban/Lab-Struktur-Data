#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int n) {
    Node* newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << n << "berhasil di-enqueue ke queue.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue kosong, tidak bisa dequeue.\n";
        return;
    }
    Node* temp = front;
    cout << temp->value << " di-dequeue dari queue.\n";
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

void tampil() {
    if (front == NULL) {
        cout << "Queue kosong.\n";
        return;
    }
    cout << "Isi queue: ";
    Node* current = front;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    system("CLS");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    tampil();
    dequeue();
    dequeue();
    tampil();

    return 0;
}