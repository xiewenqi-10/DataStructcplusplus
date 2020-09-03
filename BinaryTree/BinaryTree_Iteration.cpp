
#include<iostream>
using namespace std;
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

template<class T>
class TreeNode          //二叉树存储结构
{
public:
    T val;
    TreeNode<T>*left;
    TreeNode<T>*right;
    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
};

/**
 * @description: 迭代二叉树
 * @param {type} 
 * @return {type} 
 */

#include"TreeNode.h"

template<class T>
class Solution          //二叉树类
{
private:
    TreeNode<T>*root;   //根结点

    TreeNode<T>*pre_in_create(vector<T>&,T ,T ,vector<T>&,T,T); //前序遍历与中序遍历构造二叉树
    TreeNode<T>*in_post_create(vector<T>&,T,T, vector<T>&,T,T); //中序遍历与后序遍历构造二叉树
    TreeNode<T>*pre_post_create(vector<T>&,T,T,vector<T>&,T,T); //中序遍历与后序遍历构造二叉树(力扣889题)
public:

    TreeNode<T>*buildTree(vector<T>&,vector<T>&);               //调用前序与中序构造的二叉树
    TreeNode<T>*buildTree1(vector<T>&,vector<T>&);              //调用中序与后序构造的二叉树
    TreeNode<T>*buildTree2(vector<T>&,vector<T>&);              //调用前序与后序构造的二叉树(力扣889题)

    vector<T> levelTraversal(TreeNode<T>*);                     //层序遍历1
    vector<vector<T>>levelTraversals(TreeNode<T>*);             //层序遍历2(力扣102题)
    vector<T> preorderTraversal(TreeNode<T>*);                  //迭代前序遍历
    vector<T> inorderTraversal(TreeNode<T>*);                   //迭代中序遍历
    vector<T> postorderTraversal(TreeNode<T>*);                 //迭代后序遍历
};


template<class T>
TreeNode<T>*Solution<T>::buildTree(vector<T>&preorder,vector<T>&inorder)
{
    return pre_in_create(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}
template<class T>
TreeNode<T>*Solution<T>::pre_in_create(vector<T>&preorder,T pre_begin,T pre_end,vector<T>&inorder,T in_begin,T in_end)
{
    if(pre_end<pre_begin) return nullptr;
    TreeNode<T>* root=new TreeNode<T>(preorder[pre_begin]);//前序遍历根结点在起始位置

    T index=in_begin;                                      //用来查找中序遍历的根结点
    while (preorder[pre_begin]!=inorder[index])
    {
        ++index;
    }
    
    root->left=pre_in_create(preorder,pre_begin+1,pre_begin+index-in_begin,inorder,in_begin,index-1);
    root->right=pre_in_create(preorder,pre_begin+index-in_begin+1,in_end,inorder,index+1,in_end);
    return root;
}

template<class T>
TreeNode<T>*Solution<T>::buildTree1(vector<T>&inorder,vector<T>&postorder)
{
    return in_post_create(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
}
template<class T>
TreeNode<T>*Solution<T>::in_post_create(vector<T>&inorder,T in_begin,T in_end,vector<T>&postorder,T post_begin,T post_end)
{
    if(in_end<in_begin) return nullptr;
    TreeNode<T>* root=new TreeNode<T>(postorder[post_end]);//后序遍历根结点在末尾位置

    T index=in_begin;                                      //用来查找中序遍历的根结点
    while (postorder[post_end]!=inorder[index])
    {
        ++index;
    }

    root->left=in_post_create(inorder,in_begin+1,index-1,postorder,post_begin,post_begin+index-1-in_begin);
    root->right=in_post_create(inorder,index+1,in_end,postorder,post_begin+index-in_begin,post_end-1);
    return root;
}


template<class T>
TreeNode<T>*Solution<T>::buildTree2(vector<T>&preorder,vector<T>&postorder)
{
    return pre_post_create(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
}
template<class T>
TreeNode<T>*Solution<T>::pre_post_create(vector<T>&preorder,T pre_begin,T pre_end,vector<T>&postorder,T post_begin,T post_end)
{
    if(pre_begin>pre_end) return nullptr;
    TreeNode<T>*root=new TreeNode<T>(preorder[pre_begin]);   //前序遍历根结点在起点位置

    if(pre_begin==pre_end){return root;}                //找出根结点
    T index=post_begin;
    while (preorder[pre_begin+1]!=postorder[index])
    {
        index++;
    }

    root->left=pre_post_create(preorder,pre_begin+1,pre_begin+1+index-post_begin,postorder,post_begin,index);
    root->right=pre_post_create(preorder,pre_begin+1+index-post_begin+1,pre_end,postorder,index+1,post_end-1);
    return root;
}


template<class T>
vector<T> Solution<T>::levelTraversal(TreeNode<T>*root)
{
    vector<T>v;
    queue<TreeNode<T>*>q;
    if(root==nullptr) return v;     //若结点为空时，返回结点v
    
    q.push(root);
    while (!q.empty())              //若队列不为空，申请结点 "x"获取队头，然后根出左右孩子进
    {
        TreeNode<T>*x=q.front();
        v.push_back(x->val);
        q.pop();

        if(x->left!=nullptr) {q.push(x->left);} //若遍历到左孩子时，左孩子入队列

        if(x->right!=nullptr){q.push(x->right);}//若遍历到右孩子时，右孩子入队列   
    }
    return v;
}

/* 力扣第102题 */
template<class T>
vector<vector<T>> Solution<T>::levelTraversals(TreeNode<T>*root)
{
    vector<vector<T>>v;
    queue<TreeNode<T>*>q;
    if(root==nullptr) return v; //若结点为空时，返回结点v

    q.push(root);
    while (!q.empty())          //若队列不为空，申请结点 "x"获取队头，然后根出左右孩子进
    {
        vector<T>temp;
        T len=q.size();
        for(T i=0;i<len;i++)            /*  */
        {   
            TreeNode<T>*x=q.front();
            q.pop();
            temp.push_back(x->val);

            if(x->left!=nullptr)  q.push(x->left); //若遍历到左孩子时，左孩子入队列
            if(x->right!=nullptr) q.push(x->right);//若遍历到右孩子时，右孩子入队列   
        }
        v.push_back(temp);
    }
    return v;
}

template<class T>
vector<T> Solution<T>::preorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;    

    while (temp||s.size())
    {
        while (temp)
        {
            s.push(temp);
            v.push_back(temp->val); //根
            temp=temp->left;        //左
        }
        temp=s.top();
        s.pop();
        temp=temp->right;           //右
    }
    return v;
}


template<class T>
vector<T>Solution<T>::inorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;    

    while (temp||s.size())
    {
        while (temp)
        {
            s.push(temp);
            temp=temp->left;        //左
        }
        temp=s.top();
        s.pop();
        v.push_back(temp->val);     //根
        temp=temp->right;           //右
    }
    return v;
}


template<class T>
vector<T>Solution<T>::postorderTraversal(TreeNode<T>*root)
{
    vector<T>v;
    stack<TreeNode<T>*>s;
    TreeNode<T>*temp=root;
    if(root==nullptr) return v;      

    while (temp||s.size())
    {
        while (temp)
        {
            s.push(temp);
            v.push_back(temp->val);  //根
            temp=temp->right;        //右
        }
        temp=s.top();
        s.pop();
        temp=temp->left;             //左
    }
    std::reverse(v.begin(),v.end()); //反转->左右根
    return v;       
}

int main(int argc, char const *argv[])
{
    TreeNode<int>*root;
    Solution<int> s;
    vector<int>preorder{3,9,2,20,15,7};           //前序遍历
    //vector<int>inorder{9,3,15,20,7};            //中序遍历
    vector<int>postorder{2,9,15,7,20,3};     //后序遍历
    //root=s.buildTree(preorder,inorder);         //调用前序与中序构造的二叉树
    // root=s.buildTree1(inorder,postorder);
    root=s.buildTree2(preorder,postorder);
    vector<int>level_data=s.levelTraversal(root);
    cout<<"层序遍历:";
    for(int i=0;i<level_data.size();i++)
        cout<<level_data[i]<<" ";cout<<endl;

    vector<int>pre_data=s.preorderTraversal(root);
    cout<<"前序遍历:";
    for(int i=0;i<pre_data.size();i++)
        cout<<pre_data[i]<<" ";cout<<endl;

    cout<<"中序遍历:";
    vector<int>in_data=s.inorderTraversal(root);
    for(int i=0;i<in_data.size();i++)
        cout<<in_data[i]<<" ";cout<<endl;

    cout<<"后序遍历";
    vector<int>post_data=s.postorderTraversal(root);
    for(int i=0;i<post_data.size();i++)
        cout<<post_data[i]<<" ";cout<<endl;

    system("pause");
}
