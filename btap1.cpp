  /*Bài 1:Định nghĩa một cấu trúc danh sách liên kết đơn để lưu trữ các file trong một thư mục D>Document trên máy tính. 
  Các file được sắp xếp theo trật tự thời gian. 
  Sau đó thực hiện tao tác:  

Khai báo cấu trúc của danh sách liên kết. Các thông tin chứa ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được thực hiện 
Copy paste một file từ thư mục khác sang thư mục trên sao do file luôn được chèn vào theo trật tự thời gian  
Thực hiện tính toán kích thước các file trong thư mục 
Người ta muốn sao lưu các file trong thư mục trên vào một ổ USB có kích thước 32G. Hãy thực hiện loại bỏ dần nếu cần một số file có kích thước nhỏ nhất để có thể thực hiện được thao tác trên.  */
#include<iostream>
using namespace std;
struct file_node{
    string file_name;
    int fileSize;
    string fileTime; 
    file_node*next;
};
struct List_file{
    file_node* head;
};
//Hàm khởi tạo danh sách file
void init_file(List_file*list){
    list->head=NULL;
}
// Hàm tạo file node
file_node*makeFile(string ten,int size,string time ){
 file_node*newNode= new file_node();
 if(newNode=NULL) return NULL;
 newNode->file_name = ten;
 newNode->fileSize = size;
 newNode->fileTime = time;
 newNode->next=NULL;
 return newNode;
}
void addFile(List_file*file,string ten,int size, string time){
   file_node* newNode= makeFile(ten,size,time);
   newNode->next=file->head;
   file->head=newNode;
   cout<< "File: "<<ten<<" Date modfifate: "<<time<< " Size: "<<size<<endl;
}





