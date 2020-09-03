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
 * @description:�����������ݹ� 
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
    TreeNode*bstFromPreorder(vector<int>&preorder);     //ǰ��������������������1008�⣩

    TreeNode*insertIntoBST(TreeNode*root,int val);      //�����������еĲ������������701�⣩
    TreeNode*deleteNode(TreeNode*root,int key);         //ɾ�������������еĽڵ㣨����450�⣩ 
    TreeNode*searchBST(TreeNode*root,int val);          //�����������е�����������700�⣩
    vector<int>inorderTraversal(TreeNode*root);         //���������������������94�⣩->�������
};

/**
 * @description: 
 * 1.ǰ���������ʼλ���Ǹ���㣻
 * ���Ӷȷ�����
 * ?ʱ�临�Ӷȣ�O(N)����ɨ��ǰ�����һ�Ρ�
 * ?�ռ临�Ӷȣ�O(N)�������洢������
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
 * �����ڵ�Ϊ�գ�����TreeNode(val);
 * ��root->left>val,���������ݹ���������� 
 * ��root->right<val,���������ݹ���������� 
 * ����root;
 * ?ʱ�临�Ӷȣ�O(H)������ H ָ�������ĸ߶ȡ�ƽ�������O(logN)����������O(N)��
 * ?�ռ临�Ӷȣ�ƽ�������O(H)������������O(N)�����ڵݹ�����ж�ջʹ�õĿռ䡣
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
TreeNode*binarySearchTree::deleteNode(TreeNode*root,int key)
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
        TreeNode*temp=root->right;
        delete(root);
        return temp;
    }
    if(root->right==nullptr)                        //��������ʱ������һ�����tempָ������������temp=root->left��
    {
        TreeNode*temp=root->left;
        delete(root);
        return temp;
    }
    TreeNode*temp=root->right;                  //����һ��ָ����tempָ��������;
    while (temp->left)temp=temp->left;          //����������Ϊ��ʱ�����tempָ��temp->left��
    swap(root->val,temp->val);                  //root->val��temp->val�໥���ӣ�Ȼ�����������ݹ�ɾ��
    root->right=deleteNode(root->right,key);
    return root;
}

/**
 * @description: 
 *������ڵ�Ϊ�� root == nullptr ,����nullptr��
 *������ڵ��ֵ��������ֵ val == root->val�����ظ��ڵ㡣
 *��� val < root->val��������ڵ���������ݹ���� searchBST(root->left, val)��
 *��� val > root->val��������ڵ���������ݹ���� searchBST(root->right, val)��
 *���ظ��ڵ㡣
 * ?ʱ�临�Ӷȣ�O(H)������ H ָ�������ĸ߶ȡ�ƽ�������O(logN)����������O(N)��
 * ?�ռ临�Ӷȣ�ƽ�������O(H)������������O(N)�����ڵݹ�����ж�ջʹ�õĿռ䡣
 */
TreeNode*binarySearchTree::searchBST(TreeNode*root,int val)
{
    if(root==nullptr||val==root->val)return root;       
    return root->val>val?searchBST(root->left,val):searchBST(root->right,val);
}

/**
 * @description: 
 * ��������������������������ǵ�����������С�
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
            temp=temp->left;       //��
        }
        temp=s.top();
        s.pop();
        v.push_back(temp->val);    //��
        temp=temp->right;          //��
    }
    return v;
}


#endif