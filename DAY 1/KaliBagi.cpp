#include <iostream>

using namespace std;

int main() {
    int angka1, angka2, hasil_kali = 0, hasil_bagi = 0;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    // Perkalian
    for (int i = 1; i <= angka2; i++) {
        hasil_kali += angka1;
    }
    cout << "Hasil perkalian: " << hasil_kali << endl;

    // Pembagian
    int sementara = angka1;
    while (sementara >= angka2) {
        sementara -= angka2;
        hasil_bagi++;
    }
    cout << "Hasil pembagian: " << hasil_bagi << endl;

    system("pause");
    return 0;
}