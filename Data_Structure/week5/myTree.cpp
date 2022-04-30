#include"myTree.h"
using namespace std;

NodeTag ss;

TreeNode *nownode=new TreeNode;
TreeNode *Node=new TreeNode;

TreeNode::TreeNode()
{
	this->data='@';
}

TreeNode::TreeNode
(char A,TreeNode* B, TreeNode* C, NodeTag D,NodeTag E)
{

}

TreeNode::~TreeNode()
{

}

void TreeNode::printNode()
{
	cout<<Node->data;
}


//...............................

MyTree::MyTree()
{
	NodeNum=0;
	flag=0;//不是线索二叉树

	root=new TreeNode;//初始化根节点
	root->data='@';//根节点为空

	TreeNode *left=new TreeNode;
	TreeNode *right=new TreeNode;

	// left->data='@';
	// right->data='@';
	
	root->leftChild=left;
	root->rightChild=right;
}

MyTree::MyTree(const char *a)
{
	int j=0;
	while(a[j]!='\0')
	{
		node[j]=a[j];
		j++;
	}
	//暂存
	flag=0;

	root=new TreeNode;

	TreeNode *left=new TreeNode;
	TreeNode *right=new TreeNode;

	root->leftChild=left;
	root->rightChild=right;

	// left->data='@';//空
	// right->data='@';//空

	root->data=a[0];//根节点赋初值

	int i=1;

	TreeNode *p=new TreeNode;
	p=root;

	NodeNum=1;
	while(a[i]!='\0')
	{
		while
		(
		 (p->leftChild->data!='@'&&p->rightChild->data!='@')||
		 (p->leftChild->ifNull==1&&p->rightChild->ifNull==1)||
		 (p->rightChild->data!='@')
		)
		{
			p=p->father;//回溯
		}

		if(a[i]!='@')
		{
			if
			(p->leftChild->data=='@'&&p->leftChild->ifNull!=1)
			{
				//结点插入左子树
			    TreeNode *q=new TreeNode;
			    q->data=a[i];
				q->ifNull=0;
    			p->leftChild=q;

	    		TreeNode *left=new TreeNode;
		    	TreeNode *right=new TreeNode;
    			// left->data='@';
	    		// right->data='@';
		    	
				q->father=p;
    			q->leftChild=left;
	    		q->rightChild=right;

		    	p=q;
			    i++;
    			NodeNum++;
	    		continue;
		    }
    		if(p->rightChild->data=='@'&&p->rightChild->ifNull!=1)
			{
				//结点插入右子树
	    		TreeNode *q=new TreeNode;
		    	q->data=a[i];
				q->ifNull=0;
			    p->rightChild=q;
				
    			TreeNode *left=new TreeNode;
	    		TreeNode *right=new TreeNode;
		    	// left->data='@';
			    // right->data='@';
				
    			q->father=p;
	    		q->leftChild=left;
		    	q->rightChild=right;
			    p=q;
    			i++;
	    		NodeNum++;
		    	continue;
		    }
		}

		if(p->leftChild->ifNull==0&&p->leftChild->data=='@')
		{//左子树记为空
			p->leftChild->ifNull=1;
			i++;
			continue;
		}
		else
		{
			//右子树记为空
			p->rightChild->ifNull=1;
			i++;
			continue;
		}
	}
}

MyTree::MyTree(const MyTree &COPY)
{
	flag=0;
	root=new TreeNode;
	TreeNode *left=new TreeNode;
	TreeNode *right=new TreeNode;
	root->leftChild=left;
	root->rightChild=right;
	root->data=COPY.node[0];

	// left->data='@';//空
	// right->data='@';//空
	int i=1;

	TreeNode *p=new TreeNode;
	p=root;

	NodeNum=1;
	//结点个数
	while(COPY.node[i]!='\0'){
		while((p->leftChild->data!='@'&&p->rightChild->data!='@')||(p->leftChild->ifNull==1&&p->rightChild->ifNull==1)||(p->rightChild->data!='@')){
			p=p->father;//回溯
		}
		if(COPY.node[i]!='@'){
			if(p->leftChild->data=='@'&&p->leftChild->ifNull!=1){//结点插入左子树
			    TreeNode *q=new TreeNode;
			    q->data=COPY.node[i];
				q->ifNull=0;
    			p->leftChild=q;
	    		TreeNode *left=new TreeNode;
		    	TreeNode *right=new TreeNode;
    			// left->data='@';
	    		// right->data='@';
		    	q->father=p;
    			q->leftChild=left;
	    		q->rightChild=right;
		    	p=q;
			    i++;
    			NodeNum++;
	    		continue;
		    }
    		if(p->rightChild->data=='@'&&p->rightChild->ifNull!=1){//结点插入右子树
	    		TreeNode *q=new TreeNode;
		    	q->data=COPY.node[i];
				q->ifNull=0;
			    p->rightChild=q;
    			TreeNode *left=new TreeNode;
	    		TreeNode *right=new TreeNode;
		    	// left->data='@';
			    // right->data='@';
    			q->father=p;
	    		q->leftChild=left;
		    	q->rightChild=right;
			    p=q;
    			i++;
	    		NodeNum++;
		    	continue;
		    }
		}
		if(p->leftChild->ifNull==0&&p->leftChild->data=='@'){//左子树记为空
			p->leftChild->ifNull=1;
			i++;
			continue;
		}
		else{//右子树记为空
			p->rightChild->ifNull=1;
			i++;
			continue;
		}
	}
}


void MyTree::preOrderTraverse()
{
	stack<TreeNode*>s;
	TreeNode *p=root;

	while(p->data!='@'||!s.empty())
	{
		//遍历子树的实现不一定要靠递归

		while(p->data!='@')
		{//向左遍历
			cout<<p->data;
			pre+=p->data;
			s.push(p);
			p=p->leftChild;
		}
		if(!s.empty())
		{//回溯
			p=s.top();
			s.pop();
			p=p->rightChild;
		}
	}
}
void MyTree::inOrderTraverse(){
	stack<TreeNode*>s;
	TreeNode *p=root;
	while(p->data!='@'||!s.empty()){
		//向左遍历
		while(p->data!='@'){
			s.push(p);
			p=p->leftChild;
		}
		if(!s.empty())
		{
			//回溯
			p=s.top();
			cout<<p->data;
			ino+=p->data;
			s.pop();
			p=p->rightChild;
		}
	}
}
void MyTree::post(int ileft1,int iright1,int ileft2,int iright2)
{
	//post call
    int mid=ino.find(pre[ileft1]);//根节点
    if(mid>ileft2)post(ileft1+1,ileft1+mid-ileft2,ileft2,mid-1);//向左遍历
    if(mid<iright2)post(ileft1+mid-ileft2+1,iright1,mid+1,iright2);//向右遍历
    cout<<pre[ileft1];//输出根节点
}
void MyTree::postOrderTraverse()
{
	post(0,NodeNum-1,0,NodeNum-1);//调用post函数
}
int MyTree::countLeaf()
{
	stack<TreeNode*>s;
	TreeNode *p=root;
	int count=0;
	while(p->data!='@'||!s.empty())
	{
		while(p->data!='@')
		{//向左遍历
			if(p->leftChild->ifNull==1&&
			   p->rightChild->ifNull==1)
			{
				count++;
			}
			s.push(p);
			p=p->leftChild;
		}
		if(!s.empty()){//回溯
			p=s.top();
			s.pop();
			p=p->rightChild;
		}
	}
	/////////////////////@@@@@@@@@@@
	return count;
}

int MyTree::height(const TreeNode *root)
{
	int m,n;
	if(root->data=='@')return 0;
	else{
		m=height(root->leftChild);//左子树高度
		n=height(root->rightChild);//右子树高度
	}
	return ((m>n)?m:n)+1;//取高的加1
}

int MyTree::countHeight()
{
	return height(root);//求高度
}

bool MyTree::isThreadedTree()
{
	if(flag)return true;//已经线索化
	else return false;//未线索化
}

bool MyTree::inOrderThreading()
{
	flag=1;//线索化
	return true;
}

TreeNode& MyTree::locateNode(const char& v){
	nownode->data=v;//保存v值
	Node->data=v;//保存v值
	return *nownode;
}
TreeNode& MyTree::preNode(const TreeNode& n)
{
	int i=ino.find(nownode->data);//在中序遍历中找到n的位置
	Node->data=ino[i-1];//将n的前驱节点的值保存
	return *Node;
}
TreeNode& MyTree::nextNode(const TreeNode& n)
{
	int i=ino.find(nownode->data);//在中序遍历中找到n的位置
	Node->data=ino[i+1];//将n的后继节点的值保存
	return *Node;
}
/*
TreeNode& MyTree::nextNode(const TreeNode& n)
{
	int i=ino.find(nownode->data);//在中序遍历中找到n的位置
	Node->data=ino[i+1];//将n的后继节点的值保存
	return *Node;
}
*/
//可改为（遍历、递归）；




//.......................

HuffmanTree::HuffmanTree(const int& n, const int *a)
{
	NodeNum=n;

	weight=new int[n];
	for(int i=0;i<n;i++)
	{
		weight[i]=a[i];
	}
	sort(weight,weight+n);

	array=new HTNode[2*n-1];
	for(int i=0;i<n;i++)
	{
		array[i].weight=weight[i];//对权重赋初值
	}


	//模拟过程
	for(int i=n;i<2*n-1;i++)
	{
		int min1,min2;
		min1=99;
		min2=99;
		int pos1,pos2;
		for(int j=0;j<i;j++)
		{
		    if(array[j].parent==-1)//未参与构成霍夫曼树
			    if(array[j].weight<min1)
				{//选择两个最小的权重成树
					pos2=pos1;
					min2=min1;
					pos1=j;
					min1=array[j].weight;
				}
				else if(array[j].weight<min2)
				{
					pos2=j;
					min2=array[j].weight;
				}
		}
		//加入合成后的元素
	    array[i].leftChild=pos1;
		array[i].rightChild=pos2;
		array[i].weight=array[pos1].weight+array[pos2].weight;
		array[pos1].parent=i;
		array[pos2].parent=i;
	}
}


void HuffmanTree::printHuffmanCodes()
{
	for(int i=0;i<NodeNum;i++)
	{
		cout<<weight[NodeNum-i-1]<<":";//降序排列
		stack<int>s;
		int pos=NodeNum-i-1;
		while(array[pos].parent!=-1){//取到根节点
			int poss=pos;
			pos=array[pos].parent;
			if(array[pos].leftChild==poss){//当前为左子树
				s.push(0);
			}
			else if(array[pos].rightChild==poss){//当前为右子树
				s.push(1);
			}
		}
		while(!s.empty()){
			int top=s.top();
			cout<<top;
			s.pop();
		}
		cout<<endl;
	}
}