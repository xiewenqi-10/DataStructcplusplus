#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//���ʽ
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
    //�ⲿ�ӿ���
    binaryTreeNode<T>*root; //�����
    void create(binaryTreeNode<T>*&root);           //���򹹽�������
    void preOrder(const binaryTreeNode<T>*root);
    void InOrder(const binaryTreeNode<T>*root);
    void postOrder(const binaryTreeNode<T>*root);   //�������   
    void levelTraversal(binaryTreeNode<T>*root);    //�������
    void InOrderstack(const binaryTreeNode<T>*root);
    
    
public:
    //main()����������
    BinTree(){};
    ~BinTree(){};
    void createTree(){create(root);};
    void preOrderTree(){preOrder(root);};
    void InOrderTree(){InOrder(root);}              //�����������
    void postOrderTree(){postOrder(root);};
    void levelTraversal(){levelTraversal(root);};   //���ò������

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
        cout<<root->data<<" ";  //��������
        preOrder(root->Left);   //ǰ�����������
        preOrder(root->Right);  //ǰ�����������
        cout<<')';
    }
}
template<class T>
void BinTree<T>::InOrder(const binaryTreeNode<T>*root)
{
    if(root!=NULL)
    {   //cout<<'(';
        InOrder(root->Left);    //�������������
        cout<<root->data<<" ";  //��������
        InOrder(root->Right);   //�������������
        //cout<<')';
    }
}
template<class T>
void BinTree<T>::postOrder(const binaryTreeNode<T>*root)
{
    if(root!=NULL)
    {   cout<<'(';
        postOrder(root->Left);  //�������������
        postOrder(root->Right); //�������������
        cout<<root->data<<" ";  //��������
        cout<<')';
    }
}
template<class T>
void BinTree<T>::levelTraversal(binaryTreeNode<T>*root)
{
    queue<binaryTreeNode<T>*>q;
    if(root==NULL) return;         //�����Ϊ��ʱ�����ؽ���;���򣬽������С�
    q.push(root);
    while (!q.empty())             //�����в�Ϊ��ʱ(������),����һ�����x��ȡ��ͷ��Ȼ������������Һ��ӽ�;
    {
        binaryTreeNode<T>*x=q.front();
        cout<<x->data<<" ";
        q.pop();
        if(x->Left)                //������������ʱ�����������
        q.push(x->Left);
        if(x->Right)
        q.push(x->Right);
    }
}


int  main()
{
    BinTree<char>B;
    cout<<"������ʽ��"<<endl;
    B.createTree();
    cout<<"ǰ��������ʽ"<<endl;
    B.preOrderTree();cout<<endl;
    
    cout<<"��������ݹ���ʽ"<<endl;
    B.InOrderTree();cout<<endl;
    cout<<"��������������ʽ"<<endl;
    B.InOrderstack();cout<<endl;

    cout<<"����������ʽ"<<endl;
    B.postOrderTree();cout<<endl;

    cout<<"����������ʽ"<<endl;
    B.levelTraversal();cout<<endl;
    system("pause");
    return 0;
}