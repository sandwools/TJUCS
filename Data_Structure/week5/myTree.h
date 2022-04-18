#include<iostream>
#include<stack>
#include<algorithm>
#include<string.h>
using namespace std;
extern string pre;//保留前序遍历结果
extern string ino;//保留中序遍历结果

class TreeNode{
	public:
	int lifTreeNode;//左线索
	int rifTreeNode;//右线索
	char data;//数据
	TreeNode *lchild;//左孩子
	TreeNode *rchild;//右孩子
	TreeNode *father;//父节点
	int tag=0;//是否为空
    int code;
	void printNode();
};

// extern TreeNode *nownode;
// extern TreeNode *Node;

TreeNode *nownode=new TreeNode;
TreeNode *Node=new TreeNode;

class MyTree{
    public:
    TreeNode *Tree;//根节点
    int flag;//是否为线索二叉树
    int num;//结点个数
	char node[100];//记录元素数组
    MyTree();
    MyTree(const char *a);
    MyTree(const MyTree &T);
    void preOrderTraverse();
    void inOrderTraverse();
	void post(int ileft1,int iright1,int ileft2,int iright2);
    void postOrderTraverse();
    int countLeaf();
	int height(const TreeNode *Tree);
    int countHeight();
    bool isThreadedTree();
    bool inOrderThreading();
    TreeNode& locateNode(const char& v);
    TreeNode& preNode(const TreeNode& n);
    TreeNode& nextNode(const TreeNode& n);
};
class HuffmanTree{
	public:
	struct HTNode{
		int weight;
		int parent=-1;
		int lchild=-1;
		int rchild=-1;
	};
	HTNode *array;
	int *w;
	int num;
	HuffmanTree(const int& n, const int *a);
	void printHuffmanCodes();
};