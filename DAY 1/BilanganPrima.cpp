#include <iostream>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= num; i = i + 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int num;

    cout << "Masukkan bilangan: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " adalah bilangan prima." << endl;
    } else {
        cout << num << " bukan bilangan prima." << endl;
        cout << "Faktor pembagi: ";
        for (int i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                cout << i << " ";
            }
        }
        
        cout << endl;
    }
    system("pause");
    return 0;
}