#include <iostream>
using namespace std;
#include "Binary_tree.h"

int main()
{
	Binary_tree<char>* Bt = new Binary_tree<char>();        // ����һ�ö�����
	cout << "ǰ����� ";
	Bt->PreOrder();                             // ǰ�����
	cout << endl;
	cout << "�ǵݹ�ǰ����� ";
	Bt->Non_recursion_PreOrder();
	cout << endl;
	cout << "������������ ";
	Bt->ReverseLeftRightChild();				 // ������������
	Bt->PreOrder();
	cout << endl;            
	delete Bt;
	return 0;
}