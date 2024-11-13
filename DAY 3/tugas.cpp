#include <iostream>
using namespace std;

const int MAX = 10; // Ukuran maksimal antrian

// Struktur data Queue
struct Queue {
    int data[MAX];
    int head, tail;
};

// Fungsi untuk membuat antrian kosong
void createEmpty(Queue &q) {
    q.head = -1;
    q.tail = -1;
}

// Fungsi untuk mengecek apakah antrian kosong
bool isEmpty(Queue q) {
    return q.head == -1 && q.tail == -1;
}

// Fungsi untuk mengecek apakah antrian penuh
bool isFull(Queue q) {
    return q.tail == MAX - 1;
}

// Fungsi untuk menambahkan mobil ke antrian
void enQueue(Queue &q, int mobil) {
    if (isFull(q)) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty(q)) {
            q.head = 0;
            q.tail = 0;
        } else {
            q.tail++;
        }
        q.data[q.tail] = mobil;
        cout << "Mobil " << mobil << " telah ditambahkan ke antrian." << endl;
    }
}

// Fungsi untuk menghapus mobil dari antrian
void deQueue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Antrian Kosong" << endl;
    } else {
        if (q.head == q.tail) {
            createEmpty(q);
        } else {
            for (int i = 0; i < q.tail; i++) {
                q.data[i] = q.data[i + 1];
            }
            q.tail--;
        }
    }
}

// Fungsi untuk menampilkan elemen depan antrian
void viewFront(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrian Kosong" << endl;
    } else {
        cout << q.data[q.head] << endl;
    }
}

// Fungsi untuk menampilkan jumlah antrian
void showQueueSize(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrian Kosong" << endl;
    } else {
        cout << q.tail - q.head + 1 << endl;
    }
}

// Fungsi untuk menampilkan semua elemen antrian
void viewAll(Queue q) {
    if (isEmpty(q)) {
        cout << "Antrian Kosong" << endl;
    } else {
        for (int i = q.head; i <= q.tail; i++) {
            cout << q.data[i] << " | ";
        }
        cout << endl;
    }
}

// Program utama
int main() {

    Queue q;
    createEmpty(q);

    while (true) {
        system("cls");

        cout << "Jumlah Antrian : ";
        showQueueSize(q);
        cout << "Antrian Terdepan : ";
        viewFront(q);
        cout << "Semua Antrian : ";
        viewAll(q);

        int choose;
        cout << "\nMenu Antrian Rental Mobil:" << endl;
        cout << "1. Tambahkan Mobil Ke Antrian" << endl;
        cout << "2. Hapus Mobil Terdepan Dari Antrian" << endl;
        cout << "3. Keluar Dari Program" << endl;
        cout << "Pilih opsi: ";
        cin >> choose;
        switch (choose) {
            case 1:
                cout << "Input Data: ";
                cin >> choose;
                enQueue(q, choose);
                break;
            case 2:
                deQueue(q);
                break;
            case 3:
                exit(0);
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    }
}