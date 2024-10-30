#include <iostream>
using namespace std;

struct Node_dt {
    float heso;
    int somu;
    Node_dt* next;
};

struct Danhsach {
    Node_dt* first;
    Node_dt* last;
};


void initDT(Danhsach* l) {
    l->first = l->last = NULL;
}


Node_dt* callNode(float hs, int sm) {
    Node_dt* p = new Node_dt;
    if (p == NULL) return NULL; 
    p->heso = hs;
    p->somu = sm;
    p->next = NULL; 
    return p;
}


void addNode(Danhsach* lDT, Node_dt* p) {
    if (lDT->first == NULL) { 
        lDT->first = lDT->last = p;
    } else {
        lDT->last->next = p; 
        lDT->last = p; 
    }
}


void attachNode(Danhsach* lDT, float hs, int sm) {
    Node_dt* pDT = callNode(hs, sm);
    if (pDT == NULL) return;
    addNode(lDT, pDT);
}

void taoDT(Danhsach* lDT) {
    float hs;
    int sm;
    int i = 0; 
    cout << "- Bắt đầu nhập đa thức (nhập hệ số 0 để kết thúc): " << endl;
    
    do {
        i++;
        cout << "Nhập số phần tử thứ " << i << endl;

        cout << "\nNhập hệ số = ";
        cin >> hs;
        
        if (hs == 0) break; 
        
        cout << "\nNhập số mũ = ";
        cin >> sm;

        attachNode(lDT, hs, sm); 
    } while (hs != 0);
    
    cout << "Kết thúc nhập" << endl;
}


void inDT(Danhsach* lDT) {
    Node_dt* current = lDT->first;
    if (current == NULL) {
        cout << "Da thuc rong." << endl;
        return;
    }

    while (current != NULL) {
        cout << current->heso << "x^" << current->somu;
        if (current->next != NULL) {
            cout << " + "; 
        }
        current = current->next;
    }
    cout << endl;
}

 
int main() {
    Danhsach lDT;
    initDT(&lDT);
    
    taoDT(&lDT);
    inDT(&lDT);

    return 0;
}
