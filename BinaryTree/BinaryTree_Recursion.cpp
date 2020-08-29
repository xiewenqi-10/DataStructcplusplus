
/**
 * @description: 递归二叉树
 * @param {type} 
 * @return {type} 
 */

#include<iostream>
using namespace std;
#include<stack>
#include<queue>
#include<vector>

template<class T>
class binaryTreeNode
{
public:
    T val;
    binaryTreeNode<T>*left,*right;
    binaryTreeNode<T>(T x):val(x),left(nullptr),right(nullptr){}
};


template<class T>
class binaryTree
{

protected:
    //外部接口区
    binaryTreeNode<T>*root;                                          //根结点
    void create(binaryTreeNode<T>*&root,string& s,T& i);             //前序遍历构建二叉树

    void preOrder(binaryTreeNode<T>*root);                           //前序遍历
    void inOrder(binaryTreeNode<T>*root);                            //中序遍历
    void postOrder(binaryTreeNode<T>*root);                          //后序遍历
    void levelTraversal(binaryTreeNode<T>*root);                     //层序遍历


public:
    binaryTree(){this->root=nullptr;}
    void createTree(string s){ T i=0;create(root,s,i);}              //调用前序遍历构建二叉树

    void preOrderTree()         {preOrder(root);         cout<<endl;}//调用前序遍历
    void inOrderTree()          {inOrder(root);          cout<<endl;}//调用中序遍历
    void postOrderTree()        {postOrder(root);        cout<<endl;}//调用后序遍历
    void levelTraversalTree()   {levelTraversal(root);   cout<<endl;}//调用层序遍历
};

template<class T>
void binaryTree<T>::create(binaryTreeNode<T>*&root,string& s,T& i)
{
    if(s[i]=='#') root=nullptr;

    else
    {
        root=new binaryTreeNode<T>(s[i]);
        create(root->left,s,++i);
        create(root->right,s,++i);
    }
}

template<class T> 
void binaryTree<T>::preOrder(binaryTreeNode<T>*root)
{
    if(root!=nullptr)
    {
        cout<<root->val<<" ";  //访问树根
        preOrder(root->left);  //前序遍历左子树
        preOrder(root->right); //前序遍历右子树
    }
}


template<class T>
void binaryTree<T>::inOrder(binaryTreeNode<T>*root)
{
    if(root!=nullptr)
    {
        inOrder(root->left);  //中序遍历左子树
        cout<<root->val<<" "; //访问树根
        inOrder(root->right); //中序遍历右子树
    }
}



template<class T>
void binaryTree<T>::postOrder(binaryTreeNode<T>*root)
{
    if(root!=nullptr)
    {
        inOrder(root->left);  //后序遍历左子树
        inOrder(root->right); //后序遍历右子树
        cout<<root->val<<" "; //访问树根
    }
}


template<class T>
void binaryTree<T>::levelTraversal(binaryTreeNode<T>*root)
{
    queue<binaryTreeNode<T>*>q;
    q.push(root);                               //树进入队列。
    while (!q.empty())                          
    {
        binaryTreeNode<T>*x=q.front();          //当队列为空时,申请一个结点“x”获取队头，然后根出，左右孩进;
        q.pop();
        cout<<x->val<<" ";       
        if(x->left!=nullptr) q.push(x->left);   //若遍历到左孩子时，左孩子入队列

        if(x->right!=nullptr) q.push(x->right); //若遍历到右孩子时，右孩子入队列
    }
}

int main()
{   
    binaryTree<char>b;
    b.createTree("-+a##*b##-c##d##/e##f##");
  //  b.createTree("");
    b.preOrderTree();
    b.inOrderTree();
    b.postOrderTree();
    b.levelTraversalTree();


    system("pause");
}