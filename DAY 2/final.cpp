#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 50

struct mobil {
    string merk;
    string warna;
    int tahun;
};

struct Stack {
    mobil data[MAX_SIZE];
    int top;
};

// Inisialisasi stack
void initStack(Stack &s) {
    s.top = -1;
}

// Mengecek apakah stack kosong
bool isEmpty(Stack s) {
    return s.top == -1;
}

// Mengecek apakah stack penuh
bool isFull(Stack s) {
    return s.top == MAX_SIZE - 1;
}

// Menambahkan data ke dalam stack
void push(Stack &s, mobil x) {
    if (isFull(s)) {
        cout << "Stack penuh, tidak bisa menambah mobil!" << endl;
    } else {
        s.data[++s.top] = x;
        cout << "Mobil " << x.merk << " berhasil ditambahkan." << endl;
    }
}

// Menghapus data dari stack
mobil pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack kosong, tidak ada mobil untuk di-pop." << endl;
        return {};
    } else {
        return s.data[s.top--];
    }
}

// Melihat data mobil paling atas di stack
mobil peek(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack kosong, tidak ada mobil." << endl;
        return {};
    } else {
        return s.data[s.top];
    }
}

// Menampilkan semua mobil dalam stack
void showMobil(Stack s) {
    if (isEmpty(s)) {
        cout << "Stack kosong, tidak ada mobil yang ditampilkan." << endl;
    } else {
        cout << "Daftar mobil dalam stack:" << endl;
        for (int i = s.top; i >= 0; i--) {
            cout << "Merk: " << s.data[i].merk
                 << ", Warna: " << s.data[i].warna
                 << ", Tahun: " << s.data[i].tahun << endl;
        }
    }
}

// Mencari mobil berdasarkan merk
int searchMobil(Stack s, string merk) {
    for (int i = s.top; i >= 0; i--) {
        if (s.data[i].merk == merk) {
            return i;  // Mengembalikan indeks mobil
        }
    }
    return -1;  // Mengembalikan -1 jika mobil tidak ditemukan
}

int main() {
    Stack s;
    initStack(s);

    mobil m1 = {"Subaru", "Biru", 2020};
    mobil m2 = {"Honda", "Kuning", 2018};
    mobil m3 = {"Mazda", "Merah", 2019};
    mobil m4 = {"Toyota", "Hijau", 2022};
    mobil m5 = {"Nissan", "Putih", 2022};

    push(s, m1);
    push(s, m2);
    push(s, m3);
    push(s, m4);
    push(s, m5);

    // Menampilkan semua mobil
    showMobil(s);

    // Mencari mobil berdasarkan merk
    string merk;
    cout << "Masukkan merk mobil yang ingin dicari: ";
    cin >> merk;
    int index = searchMobil(s, merk);
    if (index != -1) {
        cout << "Mobil dengan merk " << merk << " ditemukan pada posisi " << index + 1 << endl;
    } else {
        cout << "Mobil dengan merk " << merk << " tidak ditemukan." << endl;
    }

    // Mengambil mobil paling atas dari stack
    mobil poppedMobil = pop(s);
    cout << "Mobil " << poppedMobil.merk << " di-pop dari stack." << endl;

    // Menampilkan stack setelah pop
    showMobil(s);

    return 0;
}
