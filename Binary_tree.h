#include <iostream>
#include <stack>
using namespace std;
template <class T>
struct Node
{
	T data;				//数据域
	Node<T> *left_node;	//左节点域
	Node<T> *right_node;//右节点域
};

template<class T>
class Binary_tree
{
public:
	Binary_tree() { root = Creat_tree(root); }        // 构造函数，建立一颗二叉树
	~Binary_tree() { Release(root); }
	void PreOrder() { PreOrder(root); }      // 递归前序遍历二叉树
	void Non_recursion_PreOrder() { Non_recursion_PreOrder(root); }//非递归前序遍历
	void ReverseLeftRightChild() { ReverseLeftRightChild(root); }//递归交换左右子树
private:
	Node<T>* root;                        // 指向根节点的头节点
	Node<T>* Creat_tree(Node<T>* bt);	  // 构造树
	void Release(Node<T>* bt);            // 清空树
	void PreOrder(Node<T>* bt);           // 前序遍历
	void Non_recursion_PreOrder(Node<T> *bt);//非递归前序遍历
	void ReverseLeftRightChild(Node<T> *bt);//递归交换左右子树
};

template<class T>
Node<T>* Binary_tree<T>::Creat_tree(Node<T>* bt)// 递归构造树
{//按前序遍历构建树
	T data;
	cin >> data;								// 输入结点的数据信息
	if (data == '#')							// 输入#则该分支为空
		bt = NULL;
	else
	{
		bt = new Node<T>;						// 生成一个结点，存储数据
		bt->data = data;
		bt->left_node = Creat_tree(bt->left_node);	// 递归建立左子树
		bt->right_node = Creat_tree(bt->right_node);	// 递归建立右子树
	}
	return bt;
}

template<class T>
void Binary_tree<T>::Release(Node<T>* bt)	// 递归清空树
{
	if (bt != NULL)
	{
		Release(bt->left_node);				// 释放左子树
		Release(bt->right_node);				// 释放右子树
		delete bt;							// 释放根节点
	}
}

template<class T>
void Binary_tree<T>::PreOrder(Node<T>* bt)	// 前序遍历
{
	if (bt == NULL)							// 是叶子节点，则递归结束
		return;
	cout << bt->data << " ";						// 访问节点data并输出
	PreOrder(bt->left_node);					// 前序递归遍历bt左子树
	PreOrder(bt->right_node);					// 前序递归遍历bt右子树
}

template<class T>
void Binary_tree<T>::Non_recursion_PreOrder(Node<T> *bt)//前序遍历的非递归算法
{
	stack<Node<T> *>s;
	Node<T> *temp = bt;
	while (temp != NULL || !s.empty())
	{
		while (temp != NULL)//先遍历左孩子，并输出。
		{
			cout<<temp->data<<" ";
			s.push(temp);
			temp = temp->left_node;
		}
		if (!s.empty())//当左孩子遍历完后，取栈顶，找右孩子,再遍历它的左孩子，直至全部遍历结束。
		{
			temp = s.top();
			s.pop();
			temp = temp->right_node;
		}
	}
}

template<class T>
void Binary_tree<T>::ReverseLeftRightChild(Node<T> *bt)//递归交换左右子树
{
	if (bt == NULL)// 是叶子节点，则递归结束
		return;
	swap(bt->left_node, bt->right_node); // 递归交换左子树和右子树
	ReverseLeftRightChild(bt->left_node);
	ReverseLeftRightChild(bt->right_node);
}
