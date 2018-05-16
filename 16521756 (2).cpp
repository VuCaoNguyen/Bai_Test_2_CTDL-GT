#include <iostream>
using namespace std;

struct Node
{
	int Data; // Dữ liệu chứa trong Node.
	struct Node *pLeft;
	struct Node *pRight;
};
typedef struct Node NODE;
typedef NODE* Tree;

// Khởi tạo cây.
void Init(Tree &t)
{
	t = NULL;
}

// Thêm phần tử vào cây.
void InSert(Tree &t, int x)
{
	// Cây rỗng => x sẽ là Node gốc.
	if (t == NULL)
	{
		NODE *q = new NODE;
		q->Data = x;
		q->pLeft = q->pRight = NULL;
		t = q;
	}
	else
	{
		if (t->Data > x)
		{
			InSert(t->pLeft, x);
		}
		else if (t->Data < x)
		{
			InSert(t->pRight, x);
		}
	}
}

// Tạo cây.
void CreateTree(Tree &t)
{
	Init(t); // Khởi tạo cây.

	int LuaChon;

	do {
		cout << "\n======================Menu=======================";
		cout << "\n1. Them data";
		cout << "\n0. Ket thuc";
		cout << "\n=================================================";
		cout << "\nNhap vao lua chon cua ban: ";
		cin >> LuaChon;

		if (LuaChon == 1)
		{
			int x;
			cout << "\nNhap du lieu Node can them: ";
			cin >> x;

			InSert(t, x); // Thêm x vào cây.
		}
	} while (LuaChon != 0);
}


//Viết hàm RNL(TREE root) để in ra kết quả duyệt cây có gốc root theo thứ tự duyệt phải -> giữa -> trái.

void RNL(Tree root)
{
	if (root != NULL)
	{
		if (root->pLeft != NULL || root->pRight != NULL)
		{
			RNL(root->pRight);
			cout << root->Data << "   ";
			RNL(root->pLeft);
		}
		
	}
}

//Viết hàm SumEvenLeaf(TREE root) để tính tổng giá trị của các nốt lá chẵn
int Tong = 0;
void SumEvenLeaf(Tree root)
{
	if (root != NULL)
	{ 
		// Xử lý Node.
		if (root->pLeft == NULL && root->pRight == NULL) // Node la thi left right -> NULL
		{
			if (root->Data % 2 == 0)
			{
				Tong += root->Data;
			}
			
		}
		

		SumEvenLeaf(root->pLeft);
		SumEvenLeaf(root->pRight);
	}
}



int main()
{
	Tree root; // Khai báo cây.
	cout << "\nTao Tree voi node dau tien la node goc:";
	//Chỉ cần nhập node đầu tiên làm node gốc sau đó nhập toàn bộ dữ liệu vào sẽ tự động tạo cây
	CreateTree(root);

	//hàm RNL(TREE root) để in ra kết quả duyệt cây có gốc root theo thứ tự duyệt phải -> giữa -> trái.
	cout << "\nRNL\n";
	RNL(root);


	SumEvenLeaf(root);
	cout << "\nTong ca node la chan : " << Tong;
	system("pause");
	return 0;
}