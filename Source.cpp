#include <iostream>
using namespace std;
#include <string>


struct Node
{
	int Data;
	struct Node *pLeft;
	struct Node * pRight;
};
typedef Node* TREE;

void InIt(TREE &root)
{
	root = NULL;
}

// Đưa Data vao Node
Node * CreateNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		return NULL;
	}
	p->Data = x;
	p->pRight = p->pLeft = NULL;
	return p;
}
// Them Phan tu vao cay
void InSert(TREE &root, int x)
{
	if (root == NULL)
	{
		Node * q = new Node;
		q->Data = x; // Đưa dữ liệu vào Node
		q->pLeft = q->pRight = NULL;
		root = q;

	}
	else 
	{
		if (root->Data > x)
		{
			InSert(root->pLeft, x);
		}
		
		else if (x > root->Data)
		{
			InSert(root->pRight, x);
		}

	}
	
}
TREE CreateTree(int a[], int n)
{
	TREE root;
	InIt(root);
	for (int i = 0; i < n; i++)
	{
		
		InSert(root, a[i]);
	}

	return root;

}

void NLR(TREE root)
{
	if (root != NULL)
	{
		cout << "    " << root->Data;
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}

void LNR(TREE root)
{
	if (root != NULL)
	{
		LNR(root->pLeft);
		cout << "    " << root->Data;
		LNR(root->pRight);
	}
}

//Viết hàm TREE Search(TREE root, int k) tìm một nút trên cây nhị phân tìm kiếm có gốc root có giá trị khóa là k.

TREE Search(TREE root, int k)
{
	if (root != NULL)
	{
		if (root->pLeft != NULL || root->pRight != NULL)
		{
			if (root->Data == k)
			{
				return root;
			}
		}

		Search(root->pLeft, k);
		Search(root->pRight, k);
	}
}

//Viết hàm DelOdd(TREE &root) xóa tất cả các nút lẻ trên cây có gốc root


void DelOdd(TREE &root)
{
	if (root != NULL)
	{
		//Xu Ly
		if (root->Data % 2 != 0)
		{

		}


		DelOdd(root->pLeft);
		DelOdd(root->pRight);
	}
	
}



int main()
{
	int a[6] = { 3, 2, 1, 5, 4, 6 };
	int n = 6;
	TREE root;
	// Tao cây với Mang a[] có n phần tử
	root = CreateTree(a, n);
	
	// Duyệt cây
	cout << "\nNLR: ";
	NLR(root);
	cout << "\nLNR: ";
	LNR(root);

	//Search(TREE root, int k) tìm một nút trên cây nhị phân tìm kiếm có gốc root có giá trị khóa là k.
	TREE p;
	p = Search(root, 0);
	if (p == NULL)
	{
		cout << "\nKhong tim thay phan tu k!";
	}
	else
	{
		cout << "\nTim thay phan tu k trong tree";
	}

	//Viết hàm DelOdd(TREE &root) xóa tất cả các nút lẻ trên cây có gốc root


	system("color e");
	system("pause");
	return 0;
}