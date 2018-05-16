/*
7 bước căn bản luôn phải có trên danh sách liên kết đơn

Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết
Bước 2: Khởi tạo danh sách liên kết
Bước 3: Tạo Node trong danh sách liên kết
Bước 4: Thêm đầu/Thêm cuối trong danh sách liên kết
Bước 5: Viết hàm InPut/OutPut
Bước 6: Những xử lý yêu cầu cần có trên danh sách liên kết
Bước 7: Giải phóng danh sách liên kết

Làm demo trên danh sách liên kết đơn các số nguyên

*/
#include <iostream>
using namespace std;
#include <math.h>


/* Bước 1: Khai báo cấu trúc dữ liệu danh sách liên kết */
struct Node
{
	int data;
	struct Node *pNext;
	struct Node *pRev; // đây là điều khác biệt với dslk đơn
};
typedef struct Node NODE;

struct List
{
	NODE *pHead, *pTail;
};
typedef struct List LIST;
/* ---------------------------------------------------- */

// Bước 2: Khởi tạo danh sách liên kết
void Init(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

// Bước 3: Tạo Node trong danh sách liên kết
NODE* GetNode(int DATA)
{
	NODE *p = new NODE; // Khởi tạo con trỏ p

						// Nếu trường hợp máy tính hết bộ nhớ.
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat con tro");
		system("pause");
		return NULL; // trả về rỗng.
	}
	p->data = DATA; // Đưa data vào trong Node.
	p->pNext = NULL; // Khởi tạo mối liên kết
	p->pRev = NULL; // Khởi tạo mối liên kết - đây là điều khác biệt với dslk đơn
	return p; // Trả Node p về.
}

// Bước 4: Thêm Node p vào đầu/Thêm Node p vào cuối trong danh sách liên kết
void AddHead(LIST &l, NODE *p)
{
	// danh sách rỗng.
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p; // p vừa là đầu vừa là cuối.
	}
	else
	{
		p->pNext = l.pHead; // Cho p trỏ tới đầu danh sách
		l.pHead->pRev = p; // đây là điều khác biệt với dslk đơn
		l.pHead = p; // Cập nhật lại đầu danh sách
	}
}

void AddTail(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p; // pTail trỏ Next tới p
		p->pRev = l.pTail; // đây là điều khác biệt với dslk đơn
		l.pTail = p; // Cập nhật pTail chính là p
	}
}
/* ------------------------------------------------ */

/* Bước 5: Viết hàm InPut/OutPut */

void InPut(LIST &l, int n)
{
	Init(l); // Khởi tạo danh sách.


	// Vòng lặp chạy n lần, mỗi lần nhập dữ liệu cho 1 Node
	for (int i = 1; i <= n; i++)
	{
		int data;
		cout << "\nNhap vao data: ";
		cin >> data;

		// Đóng gói data vào Node
		NODE *p; // Khai báo
		p = GetNode(data); // Cho con trỏ p trỏ tới Node được tạo ra.
						   //AddHead(l, p); // Thêm  Node p vào đầu danh sách
		AddTail(l, p);
	}
}

// 3 4 5 7

void OutPut(LIST l)
{
	// for(int i = 0; i < n; i++)
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
		//for(NODE *p = l.pTail; p != NULL; p = p ->pRev)
	{
		cout << "  " << p->data;
	}
}

/* ------------------------------------------------------ */

/* Bước 6: Những xử lý yêu cầu cần có trên danh sách liên kết */
int XuLySoCong1(LIST l, int n)
{
	int SoCong1 = 0;
	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
		//for(NODE *p = l.pTail; p != NULL; p = p ->pRev)
	{
		SoCong1 += p->data * ((n * (pow(10,n)/n));
		n--;
	}
	return SoCong1 += 1;
}

//

void GiaiPhong(LIST &l)
{
	NODE *p;
	while (l.pHead != NULL)
	{
		p = l.pHead; // Cho con trỏ p trỏ vào pHead
		l.pHead = l.pHead->pNext; // pHead được trỏ sang Node bên cạnh
		delete p; // giải phóng con trỏ
	}
}

int main()
{
	LIST l; 
	int n;
	cout << "\nNhap vao so luong phan tu trong danh sach: ";
	cin >> n;

	InPut(l, n);
	OutPut(l);
	int SoCong1;
	SoCong1 = XuLySoCong1(l, n);
	cout << "\nSo trong List + them 1 la: " << SoCong1;
	GiaiPhong(l); 
	
				  
	

	system("pause");
	return 0;
}