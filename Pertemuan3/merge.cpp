#include <iostream>   // Library standar untuk input dan output
#include <vector>     // Library untuk menggunakan tipe data vector
using namespace std;  // Agar tidak perlu menulis std:: di setiap penggunaan standar library

// ===== Fungsi untuk menggabungkan dua bagian array yang sudah terurut =====
void merge(vector<int>& arr, int left, int mid, int right) {
    // Hitung jumlah elemen di setiap bagian (kiri dan kanan)
    int n1 = mid - left + 1;  // banyak elemen di bagian kiri
    int n2 = right - mid;     // banyak elemen di bagian kanan

    // Buat dua vector sementara untuk menampung nilai kiri (L) dan kanan (R)
    vector<int> L(n1), R(n2);

    // Salin data dari array utama ke array sementara (bagian kiri)
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Salin data dari array utama ke array sementara (bagian kanan)
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisialisasi indeks:
    // i → untuk melacak posisi di L
    // j → untuk melacak posisi di R
    // k → untuk melacak posisi di array utama arr
    int i = 0;   
    int j = 0;      
    int k = left;

    // ===== Proses menggabungkan dua array yang sudah terurut =====
    // Bandingkan elemen-elemen dari L dan R satu per satu
    // lalu masukkan yang lebih kecil ke dalam arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {   // jika elemen kiri lebih kecil atau sama
            arr[k] = L[i];    // ambil dari kiri
            i++;              // pindah ke elemen berikutnya di kiri
        } else {              // jika elemen kanan lebih kecil
            arr[k] = R[j];    // ambil dari kanan
            j++;              // pindah ke elemen berikutnya di kanan
        }
        k++;  // pindah ke posisi berikutnya di array utama
    }

    // Jika masih ada sisa elemen di L (kiri), masukkan semuanya ke arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Jika masih ada sisa elemen di R (kanan), masukkan semuanya ke arr
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// ===== Fungsi utama untuk melakukan merge sort secara rekursif =====
void mergeSort(vector<int>& arr, int left, int right) {
    // Basis = jika hanya ada satu elemen atau tidak ada, hentikan rekursi
    if (left >= right)
        return;

    // Cari titik tengah dari array
    int mid = left + (right - left) / 2;

    // Pisahkan array menjadi dua bagian:
    // Bagian kiri dari left sampai mid
    mergeSort(arr, left, mid);

    // Bagian kanan dari mid+1 sampai right
    mergeSort(arr, mid + 1, right);
   
    // Setelah keduanya terurut, gabungkan keduanya
    merge(arr, left, mid, right);
}

// ===== Fungsi untuk menampilkan isi array =====
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Tampilkan elemen
    }
    cout << endl;
}

int main() {
    int n;  // variabel untuk menampung jumlah elemen array
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;  // input jumlah elemen
   
    // Buat vector dengan ukuran n
    vector<int> data(n);
    cout << "Masukkan elemen-elemen data: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];  // input setiap elemen array
    }
   
    // Tampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);
   
    // Panggil fungsi mergeSort untuk mengurutkan array
    mergeSort(data, 0, n - 1);
   
    // Tampilkan array setelah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);
   
    return 0;  // Program selesai
}
