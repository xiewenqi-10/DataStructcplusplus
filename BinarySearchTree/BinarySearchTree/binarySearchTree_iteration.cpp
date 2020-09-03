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
class BST   //原名：binarySearchTree
{
private:
    TreeNode<T>*root;
public:
    BST(){}
    ~BST(){}
public:
    TreeNode<T>*bstFromPreorder(vector<T>&preorder);        //前序遍历构造二叉树（力扣1008题）
    TreeNode<T>*insertIntoBST(TreeNode<T>*root,T);          //二叉搜索树中的插入操作（力扣701题）
    TreeNode<T>*deleteNode(TreeNode<T>*root,T);             //删除二叉搜索树中的节点（力扣450题） 
    TreeNode<T>*searchBST(TreeNode<T>*root,T);              //二叉搜索树中的搜索（力扣700题）
   
    vector<T>inorderTraversal(TreeNode<T>*root);            //迭代中序遍历（力扣94题）->升序操作
    vector<T>preorderTraversal(TreeNode<T>*root);           //迭代前序遍历（力扣144题）
    vector<T>postorderTraversal(TreeNode<T>*root);          //迭代后序遍历（力扣145题）
    vector<vector<T>>levelTreversal(TreeNode<T>*root);      //层序遍历（力扣102题）
};

/**
 * @description: 
 * 1.前序遍历的起始位置是根结点；
 *复杂度分析：
 *  ?时间复杂度：O(N)O(N)，仅扫描前序遍历一次。
 *  ?空间复杂度：O(N)O(N)，用来存储二叉树
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
 * 纯利用二叉搜索树的性质
 * 若 val > root->val,插入到右子树。
 * 若 val < toot>val，插入到左子树。
 * ?时间复杂度：O(H)，其中 H 指的是树的高度。平均情况下O(logN)，最坏的情况下O(N)。
 * ?空间复杂度：O(1)。
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
 * 进行删除操作时有以下几种情况：
 * 1.当root==nullptr时，返回nullptr;
 * 2.当root->val>key时，向左子树递归删除；
 * 3.当root->val<key时，向右子树递归删除；
 * 4.当root->left==nullptr时，申请一个结点temp指向右子树，即temp=root->right；
 * 5.当root->right==nullptr时，申请一个结点temp指向左子树，即temp=root->left；
 * 6.申请一个指针结点temp指向右子树，即TreeNode*temp=root->right；
 * 7.当左子树不为空时，结点temp指向temp->left；root->val与temp->val相互交接；然后向右子树递归删除；
 * 8.返回root;
 */
template<class T>
TreeNode<T>* BST<T>::deleteNode(TreeNode<T>*root,T key)
{
    if(root==nullptr) return nullptr;               //若root为空时，返回nullptr;
    if(root->val>key)                               //若root->val>key时，向左子树递归删除；
    {
        root->left=deleteNode(root->left,key);
        return root;
    }
    if(root->val<key)                               //若root->val<key时，向右子树递归删除；
    {
        root->right=deleteNode(root->right,key);
        return root;
    }
    if(root->left==nullptr)                         //若左子树时，申请一个结点temp指向右子树，即temp=root->right；
    {
        TreeNode<T>*temp=root->right;
        delete(root);
        return temp;
    }
    if(root->right==nullptr)                        //若右子树时，申请一个结点temp指向左子树，即temp=root->left；
    {
        TreeNode<T>*temp=root->left;
        delete(root);
        return temp;
    }
    TreeNode<T>*temp=root->right;                  //申请一个指针结点temp指向右子树;
    while (temp->left)temp=temp->left;          //当左子树不为空时，结点temp指向temp->left；
    swap(root->val,temp->val);                  //root->val与temp->val相互交接；然后向右子树递归删除
    root->right=deleteNode(root->right,key);
    return root;
}


/**
 * @description: 
 *当根节点不空 root != nullptr且根节点不是目的节点 val != root->val：
 *   如果 root->val>val，进入根节点的左子树查找 root = root->left。
 *   如果 root->val<val，进入根节点的右子树查找 root = root->right。
 *返回 root。
 
 *?时间复杂度:O(H)，其中 H是树高。平均时间复杂度为 O(logN)，最坏时间复杂度为 O(N)。
 *?空间复杂度:O(1)，恒定的额外空间。
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
 * 二叉搜索树的中序遍历的序列是递增排序的序列。
 * 时间复杂度：访问每个节点是一次，为 O(N) ，其中 N是节点的个数，也就是树的大小
 * 空间复杂度：取决于树的结构，最坏情况存储整棵树，因此是O(N)。
 */
template<class T>
vector<T> BST<T>::inorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())   //当结点不为空或栈非空时 temp!=nullptr||!s.size();
    {
        while (temp)         //当结点temp不空时，进行入栈操作;
        {
            s.push(temp);    //入栈
            temp=temp->left; //(左进栈)-遍历
        }
        temp=s.top();        //从最底层左子树弹出，然后删除;
        s.pop();
        
        v.push_back(temp->val);    //(根)-尾插操作
        temp=temp->right;          //(右进栈)-遍历
    }
    return v;
}

/**
 * @description: 
 * 时间复杂度：访问每个节点是一次，为 O(N) ，其中 N是节点的个数，也就是树的大小。
 * 空间复杂度：取决于树的结构，最坏情况存储整棵树，因此是O(N)。
 */
template<class T>
vector<T> BST<T>::preorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())  //当结点不为空或栈非空时 temp!=nullptr||!s.size();
    {
        while (temp)        //当结点temp不空时，进行入栈操作;
        {
            s.push(temp);   //入栈
            v.push_back(temp->val); //(根)-尾插操作
            temp=temp->left;        //(左进栈)-遍历
        }
        temp=s.top();               //从最底层左子树弹出，然后删除;
        s.pop();
        temp=temp->right;           //(右进栈)-遍历
    }
    return v;
}

/**
 * @description: 
 *时间复杂度：访问每个节点是一次，为 O(N) ，其中 N是节点的个数，也就是树的大小。
 *空间复杂度：取决于树的结构，最坏情况存储整棵树，因此是O(N)。
 */
template<class T>
vector<T> BST<T>::postorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())   //当结点不为空或栈非空时 temp!=nullptr||!s.size();
    {
        while (temp)         //当结点temp不空时，进行入栈操作;
        {
            s.push(temp);   //入栈
            v.push_back(temp->val); //(根)-尾插操作
            temp=temp->right;
        }
        temp=s.top();               //从最底层右子树弹出，然后删除;
        s.pop();
        temp=temp->left;            //(左进栈)-遍历
    }
    reverse(v.begin(),v.end());     //将根->右->左 整个反转变为 左->右->根
    return v;
}

/**
 * @description: 
 *时间复杂度：每个点进队出队各一次，故为 O(n)。
 *空间复杂度：队列中元素的个数不超过 n个，故为O(n)。
 */
template<class T>
vector<vector<T>> BST<T>::levelTreversal(TreeNode<T>*root)
{
    vector<vector<T>>v;
    queue<TreeNode<T>*>q;
    if(root==nullptr) return v; //若结点为空时，返回结点v
    q.push(root);
    while (!q.empty())          //当队列不为空的时
    {
        vector<T>temp;
        T len=q.size();         //求当前队列的长度
        for(T i=0;i<len;i++)    //获取队列中所有元素的第i层的所有元素，并且按照从左向右的顺序排列
        {
            TreeNode<T>*x=q.front();
            q.pop();
            temp.push_back(x->val);
            if(x->left!=nullptr)  q.push(x->left);  //若遍历到左孩子时，左孩子入队列
            if(x->right!=nullptr) q.push(x->right); //若遍历到右孩子时，右孩子入队列 
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
    root=b->bstFromPreorder(v);         //前序遍历构造二叉树
    
    // root=b->insertIntoBST(root,8);   //二叉搜索树中的插入操作
    // root=b->deleteNode(root,71);     //二叉搜索树中的删除操作
    cout<<"中序遍历：";
    vector<int>inorder=b->inorderTraversal(root);
    for(auto it=inorder.begin();it!=inorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"前序遍历：";
    vector<int>preorder=b->preorderTraversal(root);
    for(auto it=preorder.begin();it!=preorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;
    
    cout<<"后序遍历：";
    vector<int>postorder=b->postorderTraversal(root);
    for(auto it=postorder.begin();it!=postorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    cout<<"层序遍历：";
    vector<vector<int>>level=b->levelTreversal(root);
    for(auto it=level.begin();it!=level.end();it++)
    {
        vector<int>v=*it;
        for(auto It=v.begin();It!=v.end();It++)
        {
            cout<<*It<<" ";
        }
    } cout<<endl;


    if(root=b->searchBST(root,5)){//二叉搜索树中的搜索操作
        cout<<"T";
    }
    else{
        cout<<"f";
    }

    system("pause");
    return 0;
}
