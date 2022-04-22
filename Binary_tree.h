#include <iostream>
#include <stack>
using namespace std;
template <class T>
struct Node
{
	T data;				//������
	Node<T> *left_node;	//��ڵ���
	Node<T> *right_node;//�ҽڵ���
};

template<class T>
class Binary_tree
{
public:
	Binary_tree() { root = Creat_tree(root); }        // ���캯��������һ�Ŷ�����
	~Binary_tree() { Release(root); }
	void PreOrder() { PreOrder(root); }      // �ݹ�ǰ�����������
	void Non_recursion_PreOrder() { Non_recursion_PreOrder(root); }//�ǵݹ�ǰ�����
	void ReverseLeftRightChild() { ReverseLeftRightChild(root); }//�ݹ齻����������
private:
	Node<T>* root;                        // ָ����ڵ��ͷ�ڵ�
	Node<T>* Creat_tree(Node<T>* bt);	  // ������
	void Release(Node<T>* bt);            // �����
	void PreOrder(Node<T>* bt);           // ǰ�����
	void Non_recursion_PreOrder(Node<T> *bt);//�ǵݹ�ǰ�����
	void ReverseLeftRightChild(Node<T> *bt);//�ݹ齻����������
};

template<class T>
Node<T>* Binary_tree<T>::Creat_tree(Node<T>* bt)// �ݹ鹹����
{//��ǰ�����������
	T data;
	cin >> data;								// �������������Ϣ
	if (data == '#')							// ����#��÷�֧Ϊ��
		bt = NULL;
	else
	{
		bt = new Node<T>;						// ����һ����㣬�洢����
		bt->data = data;
		bt->left_node = Creat_tree(bt->left_node);	// �ݹ齨��������
		bt->right_node = Creat_tree(bt->right_node);	// �ݹ齨��������
	}
	return bt;
}

template<class T>
void Binary_tree<T>::Release(Node<T>* bt)	// �ݹ������
{
	if (bt != NULL)
	{
		Release(bt->left_node);				// �ͷ�������
		Release(bt->right_node);				// �ͷ�������
		delete bt;							// �ͷŸ��ڵ�
	}
}

template<class T>
void Binary_tree<T>::PreOrder(Node<T>* bt)	// ǰ�����
{
	if (bt == NULL)							// ��Ҷ�ӽڵ㣬��ݹ����
		return;
	cout << bt->data << " ";						// ���ʽڵ�data�����
	PreOrder(bt->left_node);					// ǰ��ݹ����bt������
	PreOrder(bt->right_node);					// ǰ��ݹ����bt������
}

template<class T>
void Binary_tree<T>::Non_recursion_PreOrder(Node<T> *bt)//ǰ������ķǵݹ��㷨
{
	stack<Node<T> *>s;
	Node<T> *temp = bt;
	while (temp != NULL || !s.empty())
	{
		while (temp != NULL)//�ȱ������ӣ��������
		{
			cout<<temp->data<<" ";
			s.push(temp);
			temp = temp->left_node;
		}
		if (!s.empty())//�����ӱ������ȡջ�������Һ���,�ٱ����������ӣ�ֱ��ȫ������������
		{
			temp = s.top();
			s.pop();
			temp = temp->right_node;
		}
	}
}

template<class T>
void Binary_tree<T>::ReverseLeftRightChild(Node<T> *bt)//�ݹ齻����������
{
	if (bt == NULL)// ��Ҷ�ӽڵ㣬��ݹ����
		return;
	swap(bt->left_node, bt->right_node); // �ݹ齻����������������
	ReverseLeftRightChild(bt->left_node);
	ReverseLeftRightChild(bt->right_node);
}
