#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//表达式
template<class T>
class binaryTreeNode
{
public:    /* data */
    T data;
    binaryTreeNode*Left,*Right;
    
    binaryTreeNode(T data,binaryTreeNode*left,binaryTreeNode*right)
    {
        this->data=data;
        this->Left=left;
        this->Right=right;
    }
};
template<class T>
class BinTree
{
private:
    //外部接口区
    binaryTreeNode<T>*root; //根结点
    void create(binaryTreeNode<T>*&root);           //先序构建二叉树
    void preOrder(const binaryTreeNode<T>*root);
    void InOrder(const binaryTreeNode<T>*root);
    void postOrder(const binaryTreeNode<T>*root);   //中序遍历   
    void levelTraversal(binaryTreeNode<T>*root);    //层序遍历
    void InOrderstack(const binaryTreeNode<T>*root);
    
    
public:
    //main()函数调用区
    BinTree(){};
    ~BinTree(){};
    void createTree(){create(root);};
    void preOrderTree(){preOrder(root);};
    void InOrderTree(){InOrder(root);}              //调用中序遍历
    void postOrderTree(){postOrder(root);};
    void levelTraversal(){levelTraversal(root);};   //调用层序遍历

    void InOrderstack(){InOrderstack(root);};

};
template<class T>
void BinTree<T>::create(binaryTreeNode<T>*&root)
{
    T data;
    cin>>data;
    if(data=='#') root=NULL;
    else
    {
    root=new binaryTreeNode<T>(data,NULL,NULL);
    create(root->Left);
    create(root->Right);    
    }
}
template<class T>
void BinTree<T>::preOrder(const binaryTreeNode<T>*root)
{
    if(root!=NULL)
    {   cout<<'(';
        cout<<root->data<<" ";  //访问树根
        preOrder(root->Left);   //前序遍历左子树
        preOrder(root->Right);  //前序遍历右子树
        cout<<')';
    }
}
template<class T>
void BinTree<T>::InOrder(const binaryTreeNode<T>*root)
{
    if(root!=NULL)
    {   //cout<<'(';
        InOrder(root->Left);    //中序遍历左子树
        cout<<root->data<<" ";  //访问树根
        InOrder(root->Right);   //中序遍历右子树
        //cout<<')';
    }
}
template<class T>
void BinTree<T>::postOrder(const binaryTreeNode<T>*root)
{
    if(root!=NULL)
    {   cout<<'(';
        postOrder(root->Left);  //后序遍历左子树
        postOrder(root->Right); //后序遍历右子树
        cout<<root->data<<" ";  //访问树根
        cout<<')';
    }
}
template<class T>
void BinTree<T>::levelTraversal(binaryTreeNode<T>*root)
{
    queue<binaryTreeNode<T>*>q;
    if(root==NULL) return;         //若结点为空时，返回结束;否则，结点进队列。
    q.push(root);
    while (!q.empty())             //当队列不为空时(树不空),申请一个结点x获取队头，然后根结点出，左右孩子进;
    {
        binaryTreeNode<T>*x=q.front();
        cout<<x->data<<" ";
        q.pop();
        if(x->Left)                //若遍历到左孩子时，左孩子入队列
        q.push(x->Left);
        if(x->Right)
        q.push(x->Right);
    }
}


int  main()
{
    BinTree<char>B;
    cout<<"输入表达式："<<endl;
    B.createTree();
    cout<<"前序遍历表达式"<<endl;
    B.preOrderTree();cout<<endl;
    
    cout<<"中序遍历递归表达式"<<endl;
    B.InOrderTree();cout<<endl;
    cout<<"中序遍历迭代表达式"<<endl;
    B.InOrderstack();cout<<endl;

    cout<<"后序遍历表达式"<<endl;
    B.postOrderTree();cout<<endl;

    cout<<"层序遍历表达式"<<endl;
    B.levelTraversal();cout<<endl;
    system("pause");
    return 0;
}