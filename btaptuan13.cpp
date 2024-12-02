#include <bits/stdc++.h>
#include <string>
#include <iomanip>
using namespace std;

struct products {
    string sanpham;
    int money, soluong_sp;
};

struct gio_hang {
    string khachhang;
    products* hang;
    int soluong_sp;
    gio_hang* next;
};

struct Queue {
    gio_hang* head;
};

// Tao node
gio_hang* makenode(string khachhang, products* hang, int soluong_sp) {
    gio_hang* newnode = new gio_hang();
    newnode->khachhang = khachhang;
    newnode->hang = hang;
    newnode->soluong_sp = soluong_sp;
    newnode->next = NULL;
    return newnode;
}

// Khoi tao hàng doi
void Init(Queue* Hang) {
    Hang->head = NULL;
}

// Kiem tra hàng rong
bool Empty(Queue* Hang) {
    return Hang->head == NULL;
}

// Thêm thông tin khách hàng vào hàng doi
void Push_info(Queue* Hang, string khachhang, products* hang, int soluong_sp) {
    gio_hang* newnode = makenode(khachhang, hang, soluong_sp);
    if (Empty(Hang)) {
        Hang->head = newnode;
        return;
    }
    gio_hang* temp = Hang->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Xóa thông tin khách hàng ra khoi hàng doi
void Pop_infor(Queue* Hang) {
    if (!Empty(Hang)) {
        gio_hang* temp = Hang->head;
        Hang->head = temp->next;
        delete temp;
    }
}

// Nhap thông tin
void nhap_thong_tin(Queue* Hang, int n) {
    cout << "Ten khach hang: ";
    string khachhang;
    cin >> khachhang;

    products* hang = new products[n];
    for (int i = 0; i < n; i++) {
        cout << "Ten san pham: ";
        cin >> hang[i].sanpham;
        cout << "Don gia: ";
        cin >> hang[i].money;
        cout << "So luong: ";
        cin >> hang[i].soluong_sp;
    }

    Push_info(Hang, khachhang, hang, n);
}

// Tính tong so tien nhan duoc sau mot luot mua hang
int tong_so_tien(gio_hang* khach) {
    int tong = 0;
    for (int i = 0; i < khach->soluong_sp; i++) {
        tong += khach->hang[i].money * khach->hang[i].soluong_sp;
    }
    return tong;
}

// Tính tong so san pham ban duoc sau mot luot mua hàng
int tong_so_san_pham(gio_hang* khach) {
    int tong = 0;
    for (int i = 0; i < khach->soluong_sp; i++) {
        tong += khach->hang[i].soluong_sp;
    }
    return tong;
}

// In hóa don và tính tong so tien và so san pham bán duoc sau mot ca làm
void in_hoa_don(Queue* Hang) {
    int tong_tien_ca_lam = 0;
    int tong_san_pham_ca_lam = 0;

    gio_hang* temp = Hang->head;
    while (temp != NULL) {
        cout << "Hoa don" << endl;
        cout << "Ten khach hang: " << temp->khachhang << endl;
        cout << left << setw(20) << "San pham" << setw(15) << "Don gia" << setw(10) << "So luong" << setw(15) << "Thanh tien" << endl;
        for (int i = 0; i < temp->soluong_sp; i++) {
            cout << left << setw(20) << temp->hang[i].sanpham << setw(15) << temp->hang[i].money << setw(10) << temp->hang[i].soluong_sp << setw(15) << temp->hang[i].money * temp->hang[i].soluong_sp << endl;
        }

        int tong_tien_khach_hang = tong_so_tien(temp);
        int tong_san_pham_khach_hang = tong_so_san_pham(temp);

        cout << "Tong so tien: " << tong_tien_khach_hang << endl;

        tong_tien_ca_lam += tong_tien_khach_hang;
        tong_san_pham_ca_lam += tong_san_pham_khach_hang;

        temp = temp->next;
    }

    cout << "\nTong ket sau mot ca lam:" << endl;
    cout << "Tong so tien: " << tong_tien_ca_lam << endl;
    cout << "Tong so san pham: " << tong_san_pham_ca_lam << endl;
}

int main() {
    Queue Hang;
    Init(&Hang);

    char choice;
    do {
        int n;
        cout << "Nhap so loai san pham: ";
        cin >> n;
        nhap_thong_tin(&Hang, n);

        cout << "Tiep tuc nhap thong tin khach hang? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Hoa don" << endl;
    in_hoa_don(&Hang);

    return 0;
}