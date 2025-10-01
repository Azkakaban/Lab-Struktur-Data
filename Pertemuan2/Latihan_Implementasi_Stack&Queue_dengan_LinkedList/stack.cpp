#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* top = NULL;

void push(int n) {
    Node* newNode = new Node;
    newNode->value = n;
    newNode->next = top;
    top = newNode;
    cout << n << "berhasil di-push ke stack.\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack kosong, tidak bisa pop.\n";
        return;
    }
    Node* temp = top;
    cout << temp->value << " di-pop dari stack.\n";
    top = top->next;
    delete temp;
}

void tampil() {
    if (top == NULL) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "Isi stack: ";
    Node* current = top;
    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    system("CLS");
    push(10);
    push(20);
    push(30);
    push(40);

    tampil();
    pop();
    pop();
    tampil();

    return 0;
}