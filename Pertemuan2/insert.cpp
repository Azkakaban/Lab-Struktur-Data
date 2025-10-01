#include <iostream>
using namespace std;

//deklarasi sebuah struktur node

struct node{
    int value;
    node *next;
};

node *head = NULL;
node *tail = NULL;

//insert di depan

void insertFirst(int n){
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;
    
    if(head == NULL){
        head = newNode;
        tail = head;
    } else{
        newNode -> next = head;
        head = newNode;
    }
}

//insert di belakang

void insertLast(int n){
    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
    
}

//insert dengan nilai tertentu

void insertAfter(int n, int check){
    if(head == NULL){
        cout<<"List kosong, insert di depan dulu"<<endl;
        return;
    }

    node *newNode = new node;
    newNode -> value = n;
    newNode -> next = NULL;

    node *p = head;
    while( p != NULL && p -> value != check){
        p = p -> next;
    }

    if (p == NULL){
        cout<<"Node dengan nilai "<<check<<" tidak ditemukan"<<endl;
        delete newNode;
    } else {
        newNode -> next = p -> next;
        p-> next = newNode;
        if (p == tail){
            tail = newNode;
        }
    }
}

//cetal linked list

void printList(){
    node *temp = head;
    cout<<"Isi dari Linked list : ";
    while(temp != NULL){
        cout<<temp -> value <<" -> ";
        temp= temp -> next;
    }
    cout<<"NULL"<<endl;
}

int main () {
    insertFirst(10);
    insertLast(20);
    insertLast(20);
    insertLast(30);
    insertAfter(25, 20);
    insertFirst(5);

    printList();
    return 0;
}