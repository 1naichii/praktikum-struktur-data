#include <iostream>
#include <iomanip> // for setw
#include <string>

using namespace std;

typedef struct ElmList *ElmAddress;

struct ElmList {
    string name;
    int NIM;
    int age;
    ElmAddress next;
};

struct List {
    ElmAddress first;
};

void createList(List &list) {
    list.first = NULL;
}

ElmAddress createElm(string name, int NIM, int age) {
    ElmAddress p = new ElmList;
    p->name = name;
    p->NIM = NIM;
    p->age = age;
    p->next = NULL;
    return p;
}

void insertFirst(List &list, ElmAddress p) {
    if (list.first == NULL) {
        list.first = p;
    } else {
        p->next = list.first;
        list.first = p;
    }
}

void insertLast(List &list, ElmAddress p) {
    if (list.first == NULL) {
        list.first = p;
    } else {
        ElmAddress q = list.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void deleteByNIM(List &list, int NIM) {
    if (list.first == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    ElmAddress temp = list.first;
    ElmAddress prev = NULL;

    if (temp != NULL && temp->NIM == NIM) {
        list.first = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->NIM != NIM) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void updateByNIM(List &list, int NIM) {
    ElmAddress temp = list.first;
    while (temp != NULL && temp->NIM != NIM) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data tidak ditemukan!" << endl;
    } else {
        cout << "Masukkan data baru" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, temp->name);
        cout << "Umur: ";
        cin >> temp->age;
    }
}

void view(List list) {
    if (list.first == NULL) {
        cout << "List kosong!" << endl;
    } else {
        // Variables to hold the maximum lengths for each field
        int maxNamaLength = 4;  // Initial length of "Nama"
        int maxNIMLength = 3;   // Initial length of "NIM"
        int maxUmurLength = 4;  // Initial length of "Umur"

        // Determine the maximum length for each field by checking the data
        ElmAddress temp = list.first;
        while (temp != NULL) {
            if (temp->name.length() > maxNamaLength) {
                maxNamaLength = temp->name.length();
            }
            if (to_string(temp->NIM).length() > maxNIMLength) {
                maxNIMLength = to_string(temp->NIM).length();
            }
            if (to_string(temp->age).length() > maxUmurLength) {
                maxUmurLength = to_string(temp->age).length();
            }
            temp = temp->next;
        }

        // Define the format for the top border and column headers
        cout << "+" << string(maxNamaLength + 2, '-') << "+"
        << string(maxNIMLength + 2, '-') << "+"
        << string(maxUmurLength + 2, '-') << "+" << endl;

        cout << "| " << left << setw(maxNamaLength) << "Nama" << " | "
        << setw(maxNIMLength) << "NIM" << " | "
        << setw(maxUmurLength) << "Umur" << " |" << endl;

        cout << "+" << string(maxNamaLength + 2, '-') << "+"
        << string(maxNIMLength + 2, '-') << "+"
        << string(maxUmurLength + 2, '-') << "+" << endl;

        // Display the data
        temp = list.first;
        while (temp != NULL) {
            cout << "| " << left << setw(maxNamaLength) << temp->name << " | "
            << setw(maxNIMLength) << temp->NIM << " | "
            << setw(maxUmurLength) << temp->age << " |" << endl;
            temp = temp->next;
        }

        // Print the bottom border
        cout << "+" << string(maxNamaLength + 2, '-') << "+"
        << string(maxNIMLength + 2, '-') << "+"
        << string(maxUmurLength + 2, '-') << "+" << endl;
    }
}

int main() {
    List L;
    ElmAddress p;
    createList(L);

    int menu, NIM, age, searchNIM;
    string name;

    do {
        system("cls");
        view(L);
        cout << "*** Menu ***" << endl;
        cout << "1. Masukan data" << endl;
        cout << "2. Hapus data tertentu" << endl;
        cout << "3. Cari data" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan Pilihan: ";
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "Masukkan Nama: ";
            cin.ignore();
            getline(cin, name);
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cout << "Masukkan Umur: ";
            cin >> age;
            p = createElm(name, NIM, age);
            insertLast(L, p);
            break;

        case 2:
            cout << "Masukkan NIM yang ingin dihapus: ";
            cin >> NIM;
            deleteByNIM(L, NIM);
            break;

        case 3:
            cout << "Masukkan NIM yang ingin dicari: ";
            cin >> searchNIM;
            p = L.first;
            while (p != NULL && p->NIM != searchNIM) {
                p = p->next;
            }
            if (p == NULL) {
                cout << "Data tidak ditemukan!" << endl;
            } else {
                cout << "Data ditemukan: " << p->name << ", Umur: " << p->age << endl;
            }
            system("pause");
            break;

        case 4:
            cout << "Masukkan NIM yang ingin diupdate: ";
            cin >> NIM;
            updateByNIM(L, NIM);
            break;
        }
    } while (menu != 5);

    return 0;
}