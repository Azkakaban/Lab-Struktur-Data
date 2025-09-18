#include <iostream>
using namespace std;

#define MAX 6
int queue[MAX];
int front = -1 , rear = -1;


void enqueue(int value){
    if (rear == MAX - 1){
        cout<<"Queue penuh."<<endl;
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        cout<<value<<" masuk ke queue."<<endl;
    }
}

void dequeue(){
    if (front == -1 || front > rear){
        cout<<"Queue kosong."<<endl;
    } else {
        cout<<queue[front]<<" keluar dari queue."<<endl;
        front++;
    }
}

void display(){
    if (front == -1){
        cout<<"Queue kosong."<<endl;
    } else {
        cout<<"Isi Queue : "<<endl;
        for (int i = front; i <= rear; i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }
}




int main(){
    system("cls");

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    enqueue(6);
    display();

    dequeue();
    display();

    return 0;
}