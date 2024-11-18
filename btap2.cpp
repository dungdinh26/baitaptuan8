/*
Bài 2:  Một câu tiếng việt cấu thành từ nhiều từ khác nhau. Mỗi từ được lưu thành một node trong một danh sách liên kết đơn  

1.Khai báo cấu trúc danh sách liên kết. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện. 
2.Xác định từ xuất hiện nhiều nhất trong câu  
3.Nếu xuất hiện từ láy (cấu thành từ hai từ giống nhau ví dụ: xanh xanh), thực hiện loại bỏ một từ .
4.Thực hiện đếm số từ vựng xuất hiện trong câu. 
*/
#include<iostream>
#include<string>
using namespace std;
struct node_tu {
  string tu;
  node_tu*next;
};
struct Cau{
    node_tu*head;
};
void cauTiengViet(Cau*Tu){
    Tu->head=NULL;
}
//Tao từ 
node_tu*tao_tu(string tuMoi){
    node_tu*tu_moi= new node_tu();
    if(tu_moi==NULL) return NULL;
    tu_moi->tu = tuMoi;
    tu_moi->next=NULL;
    return tu_moi;
}
// Hàm tạo câu theo trình tự từ từ nhập trước sẽ ở vị trí trước từ nhập sau
void tao_cau(Cau* Tu, string tuMoi) {
    node_tu* tu_moi = tao_tu(tuMoi);
    node_tu* temp = Tu->head;
    if (Tu->head == NULL) {
        Tu->head = tu_moi;
        return;
    }
    
    while (temp->next != NULL) {  // Dừng khi đến phần tử cuối cùng
        temp = temp->next;
    }
    temp->next = tu_moi;  // Gắn nút mới vào cuối
}
   
//Hàm nhap tu 
void nhap_tu(Cau*Tu){
    string tumoi;
   while(cin>>tumoi ){
   	cout<<endl;
   	if(tumoi=="stop") break;
    tao_cau(Tu,tumoi);
    
   }
}
//Hàm duyệt in 
void duyet_cau(Cau*Tu) {
    node_tu*temp= Tu->head;
    while (temp!= NULL) {
        cout << temp->tu<< " ";
       temp = temp->next;
    }
    cout << endl;
}

// Hàm tìm từ xuất hiện nhiều nhất
void tim_tu_xuat_hien_nhieu_nhat(Cau* Tu) {
    node_tu* temp1 = Tu->head;
    string tu_nhieu_nhat;
    int max_count = 0;

    while (temp1 != NULL) {
        int count = 1;
        node_tu* temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->tu == temp2->tu) {
                count++;
            }
            temp2 = temp2->next;
        }
        if (count > max_count) {
            max_count = count;
            tu_nhieu_nhat = temp1->tu;
        }
        temp1 = temp1->next;
    }

    if (max_count > 1) {
        cout << "Tu xuat hien nhieu nhat: " << tu_nhieu_nhat << " (" << max_count << " lan )" << endl;
    } else {
        cout << "Moi tu chi xuat hien mot lan." << endl;
    }
}

//Hàm loại bỏ từ xuất hiện trung lập liên tiếp
void loai_bo_tu(Cau* Tu) {
    node_tu* temp = Tu->head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->tu == temp->next->tu) {
            node_tu* tu_lay = temp->next;
            temp->next = tu_lay->next;
            delete tu_lay;
        } else {
            temp = temp->next;
        }
    }
}
int dem_so_tu_vung(Cau* Tu) {
    int count = 0;
    node_tu* temp = Tu->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main(){
    Cau Tu;
    cauTiengViet(&Tu);
    nhap_tu(&Tu);
    cout<<"Cau ban dau: ";
    duyet_cau(&Tu);
    tim_tu_xuat_hien_nhieu_nhat(&Tu);
    loai_bo_tu(&Tu);
    cout<<"Cau sau khi duoc loai bo tu lap: ";
    duyet_cau(&Tu);
    cout<<"So tu vung trong cau: ";
    cout<< dem_so_tu_vung(&Tu);
return 0;
}

