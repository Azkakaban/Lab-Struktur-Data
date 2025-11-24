#include <iostream>
using namespace std;

int main(){
    system("cls");

    int n;
    cout<<"Masukkan jumlah pasien : "; 
    cin>>n;

    string *nama = new string[n];
    string *jenis = new string[n];
    int *umur = new int[n];
    int *tingkat = new int[n];

    for (int i = 0; i < n; i++){
        cout<<"\nPasien "<<i + 1<<" : "<<endl;
        cout<<"Nama Hewan : "; cin>>nama[i];
        cout<<"Jenis Hewan : "; cin>>jenis[i];
        cout<<"Umur : "; cin>>umur[i];
        cout<<"Tingkat Darurat (1-5) : "; cin>>tingkat[i];
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (tingkat[j] < tingkat[j + 1]){
                int temp = tingkat[j];
                tingkat[j] = tingkat[j+1];
                tingkat[j+1] = temp;

                temp = umur[j];
                umur[j] = umur[j+1];
                umur[j+1] = temp;

                string temp1 = nama[j];
                nama[j] = nama[j+1];
                nama[j+1] = temp1;

                string temp2 = jenis[j];
                jenis[j] = jenis[j+1];
                jenis[j+1] = temp2;
            }
        }
    }

    cout<<endl;
    for(int i = 0; i< n; i++){
        cout<<nama[i]<<" ( "<<umur[i]<<" Tahun) - Darurat "<<tingkat[i]<<endl;
    }

    delete[] nama;
    delete[] jenis;
    delete[] umur;
    delete[] tingkat;

    return 0;
}
