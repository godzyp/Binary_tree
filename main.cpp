#include <iostream>
using namespace std;
#include "Binary_tree.h"

int main()
{
	Binary_tree<char>* Bt = new Binary_tree<char>();        // 创建一棵二叉树
	cout << "前序遍历 ";
	Bt->PreOrder();                             // 前序遍历
	cout << endl;
	cout << "非递归前序遍历 ";
	Bt->Non_recursion_PreOrder();
	cout << endl;
	cout << "交换左右子树 ";
	Bt->ReverseLeftRightChild();				 // 交换左右子树
	Bt->PreOrder();
	cout << endl;            
	delete Bt;
	return 0;
}