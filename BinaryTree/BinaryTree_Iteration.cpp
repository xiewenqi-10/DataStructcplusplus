
// #include<iostream>
// using namespace std;
// #include<stack>
// #include<queue>
// #include<vector>
// #include<algorithm>

// template<class T>
// class TreeNode          //�������洢�ṹ
// {
// public:
//     T val;
//     TreeNode<T>*left;
//     TreeNode<T>*right;
//     TreeNode(T x):val(x),left(nullptr),right(nullptr){}
// };

/**
 * @description: ����������
 * @param {type} 
 * @return {type} 
 */

#include"TreeNode.h"

template<class T>
class Solution          //��������
{
private:
    TreeNode<T>*root;   //�����

    TreeNode<T>*pre_in_create(vector<T>&,T ,T ,vector<T>&,T,T); //ǰ�����������������������
    TreeNode<T>*in_post_create(vector<T>&,T,T, vector<T>&,T,T); //������������������������
    TreeNode<T>*pre_post_create(vector<T>&,T,T,vector<T>&,T,T); //������������������������(����889��)
public:

    TreeNode<T>*buildTree(vector<T>&,vector<T>&);               //����ǰ����������Ķ�����
    TreeNode<T>*buildTree1(vector<T>&,vector<T>&);              //���������������Ķ�����
    TreeNode<T>*buildTree2(vector<T>&,vector<T>&);              //����ǰ���������Ķ�����(����889��)

    vector<T> levelTraversal(TreeNode<T>*);                     //�������1
    vector<vector<T>>levelTraversals(TreeNode<T>*);             //�������2(����102��)
    vector<T> preorderTraversal(TreeNode<T>*);                  //����ǰ�����
    vector<T> inorderTraversal(TreeNode<T>*);                   //�����������
    vector<T> postorderTraversal(TreeNode<T>*);                 //�����������
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
    TreeNode<T>* root=new TreeNode<T>(preorder[pre_begin]);//ǰ��������������ʼλ��

    T index=in_begin;                                      //����������������ĸ����
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
    TreeNode<T>* root=new TreeNode<T>(postorder[post_end]);//��������������ĩβλ��

    T index=in_begin;                                      //����������������ĸ����
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
    TreeNode<T>*root=new TreeNode<T>(preorder[pre_begin]);   //ǰ���������������λ��

    if(pre_begin==pre_end){return root;}                //�ҳ������
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
    if(root==nullptr) return v;     //�����Ϊ��ʱ�����ؽ��v
    
    q.push(root);
    while (!q.empty())              //�����в�Ϊ�գ������� "x"��ȡ��ͷ��Ȼ��������Һ��ӽ�
    {
        TreeNode<T>*x=q.front();
        v.push_back(x->val);
        q.pop();

        if(x->left!=nullptr) {q.push(x->left);} //������������ʱ�����������

        if(x->right!=nullptr){q.push(x->right);}//���������Һ���ʱ���Һ��������   
    }
    return v;
}

/* ���۵�102�� */
template<class T>
vector<vector<T>> Solution<T>::levelTraversals(TreeNode<T>*root)
{
    vector<vector<T>>v;
    queue<TreeNode<T>*>q;
    if(root==nullptr) return v; //�����Ϊ��ʱ�����ؽ��v

    q.push(root);
    while (!q.empty())          //�����в�Ϊ�գ������� "x"��ȡ��ͷ��Ȼ��������Һ��ӽ�
    {
        vector<T>temp;
        T len=q.size();
        for(T i=0;i<len;i++)            /*  */
        {   
            TreeNode<T>*x=q.front();
            q.pop();
            temp.push_back(x->val);

            if(x->left!=nullptr)  q.push(x->left); //������������ʱ�����������
            if(x->right!=nullptr) q.push(x->right);//���������Һ���ʱ���Һ��������   
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
            v.push_back(temp->val); //��
            temp=temp->left;        //��
        }
        temp=s.top();
        s.pop();
        temp=temp->right;           //��
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
            temp=temp->left;        //��
        }
        temp=s.top();
        s.pop();
        v.push_back(temp->val);     //��
        temp=temp->right;           //��
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
            v.push_back(temp->val);  //��
            temp=temp->right;        //��
        }
        temp=s.top();
        s.pop();
        temp=temp->left;             //��
    }
    std::reverse(v.begin(),v.end()); //��ת->���Ҹ�
    return v;       
}

int main(int argc, char const *argv[])
{
    TreeNode<int>*root;
    Solution<int> s;
    vector<int>preorder{3,9,2,20,15,7};           //ǰ�����
    //vector<int>inorder{9,3,15,20,7};            //�������
    vector<int>postorder{2,9,15,7,20,3};     //�������
    //root=s.buildTree(preorder,inorder);         //����ǰ����������Ķ�����
    // root=s.buildTree1(inorder,postorder);
    root=s.buildTree2(preorder,postorder);
    vector<int>level_data=s.levelTraversal(root);
    cout<<"�������:";
    for(int i=0;i<level_data.size();i++)
        cout<<level_data[i]<<" ";cout<<endl;

    vector<int>pre_data=s.preorderTraversal(root);
    cout<<"ǰ�����:";
    for(int i=0;i<pre_data.size();i++)
        cout<<pre_data[i]<<" ";cout<<endl;

    cout<<"�������:";
    vector<int>in_data=s.inorderTraversal(root);
    for(int i=0;i<in_data.size();i++)
        cout<<in_data[i]<<" ";cout<<endl;

    cout<<"�������";
    vector<int>post_data=s.postorderTraversal(root);
    for(int i=0;i<post_data.size();i++)
        cout<<post_data[i]<<" ";cout<<endl;

    system("pause");
}
