#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int value){
    if (top == MAX - 1){
        cout<<"Stack penuh !"<<endl;
    } else {
        top++;
        stack[top] = value;
        cout<<value<<" ditambahkan dalam stack."<<endl;
    }
}

void pop(){
    if (top == -1){
        cout<<"Stack kosong !"<<endl;
    } else {
        cout<<"\n"<<stack[top]<<" dihapus dari stack."<<endl;
        top--;
    }
}

void display(){
    if (top == -1){
        cout<<"Stack kosong."<<endl;
    } else {
        cout<<"Isi stack : \n";
        for (int i = top; i >= 0; i--){
            cout<<stack[i]<<" ";
        }
    }
}

int main(){

    push(50);
    push(40);
    push(30);
    push(20);
    push(10);

    display();
    pop();
    display();



    return 0;
}