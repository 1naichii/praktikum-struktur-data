#include <iostream>
#include <string>
using namespace std;

typedef struct ElmList *address;

struct ElmList
{
    string name;
    int height;
    address next;
    address prev;
};

struct DoubleList
{
    address first;
    address last;
};

void createList(DoubleList &l)
{
    l.first = NULL;
    l.last = NULL;
}

address createElm(string name, int height)
{
    address p = new ElmList;
    p->name = name;
    p->height = height;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

bool isEmpty(DoubleList l)
{
    return (l.first == NULL) && (l.last == NULL);
}

void insertFirst(DoubleList &l, address p)
{
    if (isEmpty(l))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLast(DoubleList &l, address p)
{
    if (isEmpty(l))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

void insertAfter(DoubleList &l, address p, string name)
{
    if (!isEmpty(l))
    {
        address q = l.first;
        while ((q->next != NULL) && (q->name != name))
        {
            q = q->next;
        }
        if (q->name == name)
        {
            p->next = q->next;
            p->prev = q;
            if (q->next != NULL)
            {
                q->next->prev = p;
            }
            q->next = p;
            if (q == l.last)
            {
                l.last = p;
            }
        }
    }
}

void deleteFirst(DoubleList &l)
{
    if (!isEmpty(l))
    {
        address p = l.first;
        if (l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.first = p->next;
            l.first->prev = NULL;
        }
        delete p;
    }
}

void deleteLast(DoubleList &l)
{
    if (!isEmpty(l))
    {
        address p = l.last;
        if (l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.last = l.last->prev;
            l.last->next = NULL;
        }
        delete p;
    }
}

void deleteAfter(DoubleList &l, string name)
{
    if (!isEmpty(l))
    {
        address p = l.first;
        while ((p->next != NULL) && (p->name != name))
        {
            p = p->next;
        }
        if (p->name == name && p->next != NULL)
        {
            address q = p->next;
            p->next = q->next;
            if (q->next != NULL)
            {
                q->next->prev = p;
            }
            if (q == l.last)
            {
                l.last = p;
            }
            delete q;
        }
    }
}

void updateData(DoubleList &l, string name, int newHeight)
{
    address p = l.first;
    while (p != NULL && p->name != name)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        p->height = newHeight;
    }
}

void dataTertinggi(DoubleList l)
{
    if (!isEmpty(l))
    {
        address p = l.first;
        address max = p;
        while (p != NULL)
        {
            if (p->height > max->height)
            {
                max = p;
            }
            p = p->next;
        }
        cout << "Data tertinggi: " << max->name << " [" << max->height << "]" << endl;
    }
}

void tinggiRataRata(DoubleList l)
{
    if (!isEmpty(l))
    {
        address p = l.first;
        int sum = 0, count = 0;
        while (p != NULL)
        {
            sum += p->height;
            count++;
            p = p->next;
        }
        cout << "Tinggi rata-rata: " << (sum / count) << endl;
    }
}

void view(DoubleList l)
{
    cout << "Isi list: ";
    if (isEmpty(l))
    {
        cout << "[ ]";
    }
    else
    {
        address current = l.first;
        cout << "[";
        while (current != NULL)
        {
            cout << current->name << " [" << current->height << "]";
            if (current->next != NULL)
            {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "]";
    }
    cout << endl;
}

int main()
{
    DoubleList l;
    createList(l);
    int menu, height;
    string name, cari;

    do
    {
        system("cls");
        view(l);
        cout << "Menu" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Insert After" << endl;
        cout << "4. Delete First" << endl;
        cout << "5. Delete Last" << endl;
        cout << "6. Delete After" << endl;
        cout << "7. Update Data" << endl;
        cout << "8. Data Tertinggi" << endl;
        cout << "9. Tinggi Rata-rata" << endl;
        cout << "10. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> menu;
        switch (menu)
        {
        case 1:
            cout << "Masukkan nama: ";
            cin >> name;
            cout << "Masukkan tinggi: ";
            cin >> height;
            insertFirst(l, createElm(name, height));
            break;
        case 2:
            cout << "Masukkan nama: ";
            cin >> name;
            cout << "Masukkan tinggi: ";
            cin >> height;
            insertLast(l, createElm(name, height));
            break;
        case 3:
            cout << "Masukkan nama: ";
            cin >> name;
            cout << "Masukkan tinggi: ";
            cin >> height;
            cout << "Masukkan nama setelah: ";
            cin >> cari;
            insertAfter(l, createElm(name, height), cari);
            break;
        case 4:
            deleteFirst(l);
            system("pause");
            break;
        case 5:
            deleteLast(l);
            system("pause");
            break;
        case 6:
            cout << "Masukkan nama setelah: ";
            cin >> cari;
            deleteAfter(l, cari);
            system("pause");
            break;
        case 7:
            cout << "Masukkan nama yang ingin diupdate: ";
            cin >> name;
            cout << "Masukkan tinggi baru: ";
            cin >> height;
            updateData(l, name, height);
            break;
        case 8:
            dataTertinggi(l);
            system("pause");
            break;
        case 9:
            tinggiRataRata(l);
            system("pause");
            break;
        case 10:
            cout << "Terima kasih" << endl;
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (menu != 10);

    return 0;
}