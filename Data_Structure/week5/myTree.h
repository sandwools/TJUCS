#include<iostream>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;

typedef 
enum
{
	Link, 
	Thread
} NodeTag;


string pre;//保留前序遍历结果
string ino;//保留中序遍历结果

class TreeNode
{
public:
	int lifTreeNode;//左线索
	int rifTreeNode;//右线索
	char data;

	TreeNode *leftChild;//左孩子
	TreeNode *rightChild;//右孩子
	TreeNode *father;//父节点

    TreeNode();
    TreeNode(char, TreeNode*, TreeNode*, NodeTag, NodeTag);
    ~TreeNode();

	int tag=0;//是否为空
    int code;
	void printNode();
};



class MyTree
{
public:
    TreeNode *root;//根节点
    int flag;//是否为线索二叉树
    int NodeNum;//结点个数
	char node[100];//记录元素数组
    MyTree();
    MyTree(const char *a);
    MyTree(const MyTree &T);
    void preOrderTraverse();
    void inOrderTraverse();
	void post(int ileft1,int iright1,int ileft2,int iright2);
    void postOrderTraverse();
    int countLeaf();
	int height(const TreeNode *root);
    int countHeight();
    bool isThreadedTree();
    bool inOrderThreading();
    TreeNode& locateNode(const char& v);
    TreeNode& preNode(const TreeNode& n);
    TreeNode& nextNode(const TreeNode& n);
};
class HuffmanTree
{
public:
	struct HTNode{
		int weight;
		int parent=-1;
		int leftChild=-1;
		int rightChild=-1;
	};
	HTNode *array;
	int *w;
	int NodeNum;
	HuffmanTree(const int& n, const int *a);
	void printHuffmanCodes();
};