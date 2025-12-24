#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class khachhang {
    string ten, tuoi, id, sophong;
    fstream file;
public:
    void tao_kh();
    void xem_kh();
};

void khachhang::tao_kh() {
    cin.ignore();
    cout << "Nhap ten khach hang: ";
    getline(cin, ten);
    cout << "Nhap tuoi khach hang: ";
    getline(cin, tuoi);
    cout << "Nhap id khach hang: ";
    getline(cin, id);
    cout << "Nhap so phong: ";
    getline(cin, sophong);

    file.open("khachhang.txt", ios::out | ios::app);
    file << ten << "*" << tuoi << "*" << id << "*" << sophong << "\n";
    cout << "\n>>> Dat phong thanh cong cho khach hang: " << ten << " <<<\n";
    file.close();
}

void khachhang::xem_kh() {
    file.open("khachhang.txt", ios::in);
    cout << "Ten    " << "Tuoi    " << "ID    " << "So phong    " << "\n";
    while (getline(file, ten, '*') &&
        getline(file, tuoi, '*') &&
        getline(file, id, '*') &&
        getline(file, sophong, '\n')) {
        cout << ten << "    ";
        cout << tuoi << "    ";
        cout << id << "    ";
        cout << sophong << "    "<< "\n";
    }
    file.close();
}

int main() {
    khachhang kh1;
    while (true) {
        cout << "Menu\n";
        cout << "1. Them khach hang moi\n";
        cout << "2. Hien thi danh sach khach hang\n";
        cout << "3. Exit\n";
        cout << "Lua chon: ";

        int luachon;
        cin >> luachon;

        switch (luachon) {
        case 1:
            kh1.tao_kh();
            break;
        case 2:
            kh1.xem_kh();
            break;
        case 3:
            return 0;
        default:
            cout << "Lua chon khong hop le";
        }
    }
    return 0;
}
