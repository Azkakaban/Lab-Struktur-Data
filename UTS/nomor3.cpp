#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices; // Jumlah simpul/vertex di graf
    vector<vector<int>> adjMatrix; // Matriks ketetanggaan (adjacency matrix)

public:
    Graph(int V) {
        numVertices = V;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0)); // Inisialisasi matriks ketetanggaan dengan 0
    }

    void addEdge(int i, int j, int bobot) {
        i--;
        j--;
        adjMatrix[i][j] = bobot;
        adjMatrix[j][i] = bobot;
    }

    void dfs(int startVertex) {
        vector<bool> visited(numVertices, false); // Tandai semua simpul belum dikunjungi
        cout << "PENJELAJAHAN PARUL (DFS dari A):\n";
        dfsUtil(startVertex, visited);
        cout << endl << endl;
    }

    void dfsUtil(int currentVertex, vector<bool>& visited) {
        visited[currentVertex] = true; // Tandai simpul sekarang sudah dikunjungi
        cout << char('A' + currentVertex);
        bool lanjut = false; // Cek apakah masih ada tetangga yang bisa dikunjungi
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                lanjut = true;
                break;
            }
        }
        if (lanjut) cout << "->";

        // Pilih tetangga dengan bobot terkecil
        int next = -1;
        int minBobot = 5; 
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i] && adjMatrix[currentVertex][i] < minBobot) {
                minBobot = adjMatrix[currentVertex][i];
                next = i;
            }
        }
        if (next != -1) dfsUtil(next, visited);

        // Kunjungi tetangga lain yang belum dikunjungi
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] != 0 && !visited[i]) {
                cout << "->";
                dfsUtil(i, visited);
            }
        }
    }

    // BFS untuk mencari jalur terpendek dari startVertex ke end
    void bfs(int startVertex, int end) {
        vector<int> jarak(numVertices, 100);
        vector<int> asal(numVertices, -1);
        queue<int> q;

        jarak[startVertex] = 0;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            for (int i = 0; i < numVertices; i++) { // Cek semua tetangga simpul sekarang
                if (adjMatrix[currentVertex][i] != 0) {
                    int newJarak = jarak[currentVertex] + adjMatrix[currentVertex][i];
                    if (newJarak < jarak[i]) { // Jika jarak baru lebih kecil
                        jarak[i] = newJarak;
                        asal[i] = currentVertex;
                        q.push(i);
                    }
                }
            }
        }

        // Buat jalur dari end ke start
        vector<int> jalur;
        int total = 0;
        int currentVertex = end;
        while (currentVertex != -1) {
            jalur.insert(jalur.begin(), currentVertex);
            if (asal[currentVertex] != -1) total++;
            currentVertex = asal[currentVertex];
        }

        // Output jalur dan jarak
        cout << "JALUR TERCEPAT PARUL (BFS):\n\n";
        for (int i = 0; i < jalur.size(); i++) {
            char kota = 'A' + jalur[i];
            string lokasi;
            int jarak = 0;
            switch(kota) {
                case 'A': lokasi = "Ikan Bakar Pak Harry"; break;
                case 'B': lokasi = "Gudang Kaleng Bekas"; break;
                case 'C': lokasi = "Sushi Kucing Alya"; break;
                case 'D': lokasi = "Kedai IKLC"; break;
                case 'E': lokasi = "Pasar Ikan Tengah Malam"; break;
            }
            if (i > 0) jarak = adjMatrix[jalur[i-1]][jalur[i]];
            cout << lokasi << " (" << kota << ")\n";
            if (i > 0) cout << jarak << "m\n"; else cout << endl;
        }

        cout << "Jalur terpendek: ";
        for (int i = 0; i < jalur.size(); i++) {
            cout << char('A' + jalur[i]);
            if (i < jalur.size() - 1) cout << "->";
        }
        cout << "\nTotal langkah: " << total << " edge\n";
        cout << "Total jarak: " << jarak[end] << " meter\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(1,2,5); // A-B
    g.addEdge(1,3,2); // A-C
    g.addEdge(2,4,4); // B-D
    g.addEdge(3,4,1); // C-D
    g.addEdge(4,5,3); // D-E

    g.dfs(0);      // DFS dari A
    g.bfs(0,4);    // BFS terpendek dari A ke E

    return 0;
}
