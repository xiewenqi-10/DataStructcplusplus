/*
 * @Author: your name
 * @Date: 2020-09-03 17:29:45
 * @LastEditTime: 2020-09-04 05:21:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \BinarySearchTree\binarySearchTree_iteration.cpp
 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#include<algorithm>
#include<deque>
#include<queue>

template<class T>
class TreeNode
{
public:
    T val;
    TreeNode<T>*left,*right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(T key):val(key),left(nullptr),right(nullptr){}
};


template<class T>
class BST   //ԭ����binarySearchTree
{
private:
    TreeNode<T>*root;
public:
    BST(){}
    ~BST(){}
public:
    TreeNode<T>*bstFromPreorder(vector<T>&preorder);        //ǰ��������������������1008�⣩
    TreeNode<T>*insertIntoBST(TreeNode<T>*root,T);          //�����������еĲ������������701�⣩
    TreeNode<T>*deleteNode(TreeNode<T>*root,T);             //ɾ�������������еĽڵ㣨����450�⣩ 
    TreeNode<T>*searchBST(TreeNode<T>*root,T);              //�����������е�����������700�⣩
   
    vector<T>inorderTraversal(TreeNode<T>*root);            //�����������������94�⣩->�������
    vector<T>preorderTraversal(TreeNode<T>*root);           //����ǰ�����������144�⣩
    vector<T>postorderTraversal(TreeNode<T>*root);          //�����������������145�⣩
    vector<vector<T>>levelTreversal(TreeNode<T>*root);      //�������������102�⣩
};

/**
 * @description: 
 * 1.ǰ���������ʼλ���Ǹ���㣻
 *���Ӷȷ�����
 *  ?ʱ�临�Ӷȣ�O(N)O(N)����ɨ��ǰ�����һ�Ρ�
 *  ?�ռ临�Ӷȣ�O(N)O(N)�������洢������
 */
template<class T>
TreeNode<T>* BST<T>::bstFromPreorder(vector<T>&preorder)
{
    TreeNode<T>*root=new TreeNode<T>(preorder[0]);
    for(int i=1;i<preorder.size();i++)
        insertIntoBST(root,preorder[i]);
    return root;
}

/**
 * @description:
 * �����ö���������������
 * �� val > root->val,���뵽��������
 * �� val < toot>val�����뵽��������
 * ?ʱ�临�Ӷȣ�O(H)������ H ָ�������ĸ߶ȡ�ƽ�������O(logN)����������O(N)��
 * ?�ռ临�Ӷȣ�O(1)��
 */
template<class T>
TreeNode<T>* BST<T>::insertIntoBST(TreeNode<T>*root,T val)
{
    TreeNode<T>*temp=root;
    while (temp!=nullptr)
    {
        if(temp->val>val)
        {
            if(temp->left==nullptr){temp->left=new TreeNode<T>(val);return root;}
            else temp=temp->left;
        }
        else
        {
            if(temp->right==nullptr){temp->right=new TreeNode<T>(val);return root;}
            else temp=temp->right;
        }
    }
    return root;
}


/**
 * @description: 
 * ����ɾ������ʱ�����¼��������
 * 1.��root==nullptrʱ������nullptr;
 * 2.��root->val>keyʱ�����������ݹ�ɾ����
 * 3.��root->val<keyʱ�����������ݹ�ɾ����
 * 4.��root->left==nullptrʱ������һ�����tempָ������������temp=root->right��
 * 5.��root->right==nullptrʱ������һ�����tempָ������������temp=root->left��
 * 6.����һ��ָ����tempָ������������TreeNode*temp=root->right��
 * 7.����������Ϊ��ʱ�����tempָ��temp->left��root->val��temp->val�໥���ӣ�Ȼ�����������ݹ�ɾ����
 * 8.����root;
 */
template<class T>
TreeNode<T>* BST<T>::deleteNode(TreeNode<T>*root,T key)
{
    if(root==nullptr) return nullptr;               //��rootΪ��ʱ������nullptr;
    if(root->val>key)                               //��root->val>keyʱ�����������ݹ�ɾ����
    {
        root->left=deleteNode(root->left,key);
        return root;
    }
    if(root->val<key)                               //��root->val<keyʱ�����������ݹ�ɾ����
    {
        root->right=deleteNode(root->right,key);
        return root;
    }
    if(root->left==nullptr)                         //��������ʱ������һ�����tempָ������������temp=root->right��
    {
        TreeNode<T>*temp=root->right;
        delete(root);
        return temp;
    }
    if(root->right==nullptr)                        //��������ʱ������һ�����tempָ������������temp=root->left��
    {
        TreeNode<T>*temp=root->left;
        delete(root);
        return temp;
    }
    TreeNode<T>*temp=root->right;                  //����һ��ָ����tempָ��������;
    while (temp->left)temp=temp->left;          //����������Ϊ��ʱ�����tempָ��temp->left��
    swap(root->val,temp->val);                  //root->val��temp->val�໥���ӣ�Ȼ�����������ݹ�ɾ��
    root->right=deleteNode(root->right,key);
    return root;
}


/**
 * @description: 
 *�����ڵ㲻�� root != nullptr�Ҹ��ڵ㲻��Ŀ�Ľڵ� val != root->val��
 *   ��� root->val>val��������ڵ������������ root = root->left��
 *   ��� root->val<val��������ڵ������������ root = root->right��
 *���� root��
 
 *?ʱ�临�Ӷ�:O(H)������ H�����ߡ�ƽ��ʱ�临�Ӷ�Ϊ O(logN)���ʱ�临�Ӷ�Ϊ O(N)��
 *?�ռ临�Ӷ�:O(1)���㶨�Ķ���ռ䡣
 */
template<class T>
TreeNode<T>*BST<T>::searchBST(TreeNode<T>*root,T val)
{
    while (root!=nullptr&&val!=root->val)
    {
        root=val<root->val?root->left:root->right;
    }
    return root;

    //  while(root!=nullptr&&val!=root->val)
    //  {
    //     if(root->val>val) root=root->left;
       
    //     if(root->val<val) root=root->right;   
    //  }
    // return root;
}


/**
 * @description: 
 * ��������������������������ǵ�����������С�
 * ʱ�临�Ӷȣ�����ÿ���ڵ���һ�Σ�Ϊ O(N) ������ N�ǽڵ�ĸ�����Ҳ�������Ĵ�С
 * �ռ临�Ӷȣ�ȡ�������Ľṹ�������洢�������������O(N)��
 */
template<class T>
vector<T> BST<T>::inorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())   //����㲻Ϊ�ջ�ջ�ǿ�ʱ temp!=nullptr||!s.size();
    {
        while (temp)         //�����temp����ʱ��������ջ����;
        {
            s.push(temp);    //��ջ
            temp=temp->left; //(���ջ)-����
        }
        temp=s.top();        //����ײ�������������Ȼ��ɾ��;
        s.pop();
        
        v.push_back(temp->val);    //(��)-β�����
        temp=temp->right;          //(�ҽ�ջ)-����
    }
    return v;
}

/**
 * @description: 
 * ʱ�临�Ӷȣ�����ÿ���ڵ���һ�Σ�Ϊ O(N) ������ N�ǽڵ�ĸ�����Ҳ�������Ĵ�С��
 * �ռ临�Ӷȣ�ȡ�������Ľṹ�������洢�������������O(N)��
 */
template<class T>
vector<T> BST<T>::preorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())  //����㲻Ϊ�ջ�ջ�ǿ�ʱ temp!=nullptr||!s.size();
    {
        while (temp)        //�����temp����ʱ��������ջ����;
        {
            s.push(temp);   //��ջ
            v.push_back(temp->val); //(��)-β�����
            temp=temp->left;        //(���ջ)-����
        }
        temp=s.top();               //����ײ�������������Ȼ��ɾ��;
        s.pop();
        temp=temp->right;           //(�ҽ�ջ)-����
    }
    return v;
}

/**
 * @description: 
 *ʱ�临�Ӷȣ�����ÿ���ڵ���һ�Σ�Ϊ O(N) ������ N�ǽڵ�ĸ�����Ҳ�������Ĵ�С��
 *�ռ临�Ӷȣ�ȡ�������Ľṹ�������洢�������������O(N)��
 */
template<class T>
vector<T> BST<T>::postorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())   //����㲻Ϊ�ջ�ջ�ǿ�ʱ temp!=nullptr||!s.size();
    {
        while (temp)         //�����temp����ʱ��������ջ����;
        {
            s.push(temp);   //��ջ
            v.push_back(temp->val); //(��)-β�����
            temp=temp->right;
        }
        temp=s.top();               //����ײ�������������Ȼ��ɾ��;
        s.pop();
        temp=temp->left;            //(���ջ)-����
    }
    reverse(v.begin(),v.end());     //����->��->�� ������ת��Ϊ ��->��->��
    return v;
}

/**
 * @description: 
 *ʱ�临�Ӷȣ�ÿ������ӳ��Ӹ�һ�Σ���Ϊ O(n)��
 *�ռ临�Ӷȣ�������Ԫ�صĸ��������� n������ΪO(n)��
 */
template<class T>
vector<vector<T>> BST<T>::levelTreversal(TreeNode<T>*root)
{
    vector<vector<T>>v;
    queue<TreeNode<T>*>q;
    if(root==nullptr) return v; //�����Ϊ��ʱ�����ؽ��v
    q.push(root);
    while (!q.empty())          //�����в�Ϊ�յ�ʱ
    {
        vector<T>temp;
        T len=q.size();         //��ǰ���еĳ���
        for(T i=0;i<len;i++)    //��ȡ����������Ԫ�صĵ�i�������Ԫ�أ����Ұ��մ������ҵ�˳������
        {
            TreeNode<T>*x=q.front();
            q.pop();
            temp.push_back(x->val);
            if(x->left!=nullptr)  q.push(x->left);  //������������ʱ�����������
            if(x->right!=nullptr) q.push(x->right); //���������Һ���ʱ���Һ�������� 
        }
        v.push_back(temp);
    }
    return v;
}

int main(int argc, char const *argv[])
{
    TreeNode<int>*root;
    BST<int>*b;
    vector<int>v{8,5,1,7,10,12};
    root=b->bstFromPreorder(v);         //ǰ��������������
    
    // root=b->insertIntoBST(root,8);   //�����������еĲ������
    // root=b->deleteNode(root,71);     //�����������е�ɾ������
    cout<<"���������";
    vector<int>inorder=b->inorderTraversal(root);
    for(auto it=inorder.begin();it!=inorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"ǰ�������";
    vector<int>preorder=b->preorderTraversal(root);
    for(auto it=preorder.begin();it!=preorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    
    cout<<"���������";
    vector<int>postorder=b->postorderTraversal(root);
    for(auto it=postorder.begin();it!=postorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"���������";
    vector<vector<int>>level=b->levelTreversal(root);
    for(auto it=level.begin();it!=level.end();it++)
    {
        vector<int>v=*it;
        for(auto It=v.begin();It!=v.end();It++)
        {
            cout<<*It<<" ";
        }
    } cout<<endl;


    if(root=b->searchBST(root,5)){//�����������е���������
        cout<<"T";
    }
    else{
        cout<<"f";
    }

    system("pause");
    return 0;
}
