#include <iostream>
#include <string>
using namespace std;

struct node {
    string judul;
    int tahun;
    int rating;
    node* next;
};

node *head = NULL;
node *tail = NULL;

// Fungsi untuk menambahkan film di depan
void insertFirst(string judul, int tahun, int rating) {
    node  *newNode = new node;
    newNode->judul = judul;
    newNode->tahun = tahun;
    newNode->rating = rating;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        tail = head;
    } else{
        newNode -> next = head;
        head = newNode;
    }
}

// Fungsi untuk menambahkan film di belakang
void insertLast(string judul, int tahun, int rating) {
    node  *newNode = new node;
    newNode->judul = judul;
    newNode->tahun = tahun;
    newNode->rating = rating;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        tail = head;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

// Fungsi untuk menambahkan film di tengah
void insertAfter(string setelahJudul, string judulBaru, int tahun, int rating) {
    if(head == NULL){
        cout<<"List kosong, insert di depan dulu"<<endl;
        return;
    }

    node  *newNode = new node;
    newNode->judul = judulBaru;
    newNode->tahun = tahun;
    newNode->rating = rating;
    newNode->next = NULL;

    node* temp = head;
    while (temp != NULL && temp->judul != setelahJudul) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Judul \"" << setelahJudul << "\" tidak ditemukan. Film ditambahkan di belakang.\n";
        delete newNode;
    } else {
        newNode -> next = temp -> next;
        temp-> next = newNode;
        if (temp == tail){
            tail = newNode;
        }
    }
}


// Fungsi hapus film berdasarkan judul
void hapusFilm(string judul) {
    if (head == NULL) {
        cout << "Daftar film kosong!" << endl;
        return;
    }
    
    if (head->judul == judul) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    node* temp = head;
    while (temp->next != NULL && temp->next->judul != judul) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
       cout<<"Error";
    } else {
        node* p = temp->next;
        temp->next = temp->next->next;
        delete p;
    }
}

// Fungsi untuk menampilkan daftar film
void printList() {
    node* temp = head;
    int jumlah = 0;
    while (temp != NULL) {
        cout << temp->judul << " (" << temp->tahun << ") - " << temp->rating << endl;
        temp = temp->next;
        jumlah++;
    }
    cout << "\nTotal film tersisa: " << jumlah << endl;
}

int main() {
    system("cls");

    int n;
    cout << "Masukkan jumlah film awal: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cin.ignore();
        string judul;
        int tahun, rating;
        cout << "\nFilm " << i+1 << ":\n";
        cout << "Judul: "; getline(cin, judul);
        cout << "Tahun: "; cin >> tahun;
        cout << "Rating: "; cin >> rating;

        insertLast(judul, tahun, rating);
    }

    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): "; cin >> hapus;
    if (hapus == 'y' || hapus == 'Y') {
        cin.ignore();
        string judulHapus;
        cout << "Masukkan judul film yang sudah ditonton: "; getline(cin, judulHapus);
        hapusFilm(judulHapus);
    }

    cout<<endl;
    printList();

    return 0;
}
