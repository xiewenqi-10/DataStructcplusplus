/*
 * @Author: your name
 * @Date: 2020-08-31 00:44:11
 * @LastEditTime: 2020-09-04 03:27:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \BinarySearchTree\binarySearchTree.cpp
 */

#ifndef _binarySearchTree_recursion
#define _binarySearchTree_recursion
/**
 * @description:二叉搜索树递归 
 * @param {type} 
 * @return {type} 
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode*left,*right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class binarySearchTree
{
protected:
    TreeNode*root;
public:
    binarySearchTree(){}
    ~binarySearchTree(){}
public:
    void insert(TreeNode*root,int val);
    TreeNode*bstFromPreorder(vector<int>&preorder);     //前序遍历构造二叉树（力扣1008题）

    TreeNode*insertIntoBST(TreeNode*root,int val);      //二叉搜索树中的插入操作（力扣701题）
    TreeNode*deleteNode(TreeNode*root,int key);         //删除二叉搜索树中的节点（力扣450题） 
    TreeNode*searchBST(TreeNode*root,int val);          //二叉搜索树中的搜索（力扣700题）
    vector<int>inorderTraversal(TreeNode*root);         //二叉树的中序遍历（力扣94题）->升序操作
};

/**
 * @description: 
 * 1.前序遍历的起始位置是根结点；
 * 复杂度分析：
 * ?时间复杂度：O(N)，仅扫描前序遍历一次。
 * ?空间复杂度：O(N)，用来存储二叉树
 */
TreeNode* binarySearchTree::bstFromPreorder(vector<int>&preorder)
{
    TreeNode*root=new TreeNode(preorder[0]);
    for(int i=0;i<preorder.size();i++)  
    {   
         insertIntoBST(root,preorder[i]);
    }
    return root;
}
/**
 * @description:
 * 若根节点为空，返回TreeNode(val);
 * 若root->left>val,向左子树递归插入左子树 
 * 若root->right<val,向右子树递归插入右子树 
 * 返回root;
 * ?时间复杂度：O(H)，其中 H 指的是树的高度。平均情况下O(logN)，最坏的情况下O(N)。
 * ?空间复杂度：平均情况下O(H)。最坏的情况下是O(N)，是在递归过程中堆栈使用的空间。
 */
TreeNode*binarySearchTree::insertIntoBST(TreeNode*root,int val)
{
    if(root==nullptr){return new TreeNode(val);}    
    if(root->val>val) root->left=insertIntoBST(root->left,val);
    if(root->val<val) root->right=insertIntoBST(root->right,val);
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
TreeNode*binarySearchTree::deleteNode(TreeNode*root,int key)
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
        TreeNode*temp=root->right;
        delete(root);
        return temp;
    }
    if(root->right==nullptr)                        //若右子树时，申请一个结点temp指向左子树，即temp=root->left；
    {
        TreeNode*temp=root->left;
        delete(root);
        return temp;
    }
    TreeNode*temp=root->right;                  //申请一个指针结点temp指向右子树;
    while (temp->left)temp=temp->left;          //当左子树不为空时，结点temp指向temp->left；
    swap(root->val,temp->val);                  //root->val与temp->val相互交接；然后向右子树递归删除
    root->right=deleteNode(root->right,key);
    return root;
}

/**
 * @description: 
 *如果根节点为空 root == nullptr ,返回nullptr。
 *如果根节点的值等于搜索值 val == root->val，返回根节点。
 *如果 val < root->val，进入根节点的左子树递归查找 searchBST(root->left, val)。
 *如果 val > root->val，进入根节点的右子树递归查找 searchBST(root->right, val)。
 *返回根节点。
 * ?时间复杂度：O(H)，其中 H 指的是树的高度。平均情况下O(logN)，最坏的情况下O(N)。
 * ?空间复杂度：平均情况下O(H)。最坏的情况下是O(N)，是在递归过程中堆栈使用的空间。
 */
TreeNode*binarySearchTree::searchBST(TreeNode*root,int val)
{
    if(root==nullptr||val==root->val)return root;       
    return root->val>val?searchBST(root->left,val):searchBST(root->right,val);
}

/**
 * @description: 
 * 二叉搜索树的中序遍历的序列是递增排序的序列。
 */
vector<int> binarySearchTree::inorderTraversal(TreeNode*root)
{
    vector<int>v;
    stack<TreeNode*>s;
    TreeNode*temp=root;
    if(root==nullptr) return v;

    while (temp||s.size())
    {
        while (temp)
        {
            s.push(temp);
            temp=temp->left;       //左
        }
        temp=s.top();
        s.pop();
        v.push_back(temp->val);    //根
        temp=temp->right;          //右
    }
    return v;
}


#endif