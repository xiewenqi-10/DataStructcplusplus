
/**
 * @description: �ݹ������
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
    //�ⲿ�ӿ���
    binaryTreeNode<T>*root;                                          //�����
    void create(binaryTreeNode<T>*&root,string& s,T& i);             //ǰ���������������

    void preOrder(binaryTreeNode<T>*root);                           //ǰ�����
    void inOrder(binaryTreeNode<T>*root);                            //�������
    void postOrder(binaryTreeNode<T>*root);                          //�������
    void levelTraversal(binaryTreeNode<T>*root);                     //�������


public:
    binaryTree(){this->root=nullptr;}
    void createTree(string s){ T i=0;create(root,s,i);}              //����ǰ���������������

    void preOrderTree()         {preOrder(root);         cout<<endl;}//����ǰ�����
    void inOrderTree()          {inOrder(root);          cout<<endl;}//�����������
    void postOrderTree()        {postOrder(root);        cout<<endl;}//���ú������
    void levelTraversalTree()   {levelTraversal(root);   cout<<endl;}//���ò������
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
        cout<<root->val<<" ";  //��������
        preOrder(root->left);  //ǰ�����������
        preOrder(root->right); //ǰ�����������
    }
}


template<class T>
void binaryTree<T>::inOrder(binaryTreeNode<T>*root)
{
    if(root!=nullptr)
    {
        inOrder(root->left);  //�������������
        cout<<root->val<<" "; //��������
        inOrder(root->right); //�������������
    }
}



template<class T>
void binaryTree<T>::postOrder(binaryTreeNode<T>*root)
{
    if(root!=nullptr)
    {
        inOrder(root->left);  //�������������
        inOrder(root->right); //�������������
        cout<<root->val<<" "; //��������
    }
}


template<class T>
void binaryTree<T>::levelTraversal(binaryTreeNode<T>*root)
{
    queue<binaryTreeNode<T>*>q;
    q.push(root);                               //��������С�
    while (!q.empty())                          
    {
        binaryTreeNode<T>*x=q.front();          //������Ϊ��ʱ,����һ����㡰x����ȡ��ͷ��Ȼ����������Һ���;
        q.pop();
        cout<<x->val<<" ";       
        if(x->left!=nullptr) q.push(x->left);   //������������ʱ�����������

        if(x->right!=nullptr) q.push(x->right); //���������Һ���ʱ���Һ��������
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