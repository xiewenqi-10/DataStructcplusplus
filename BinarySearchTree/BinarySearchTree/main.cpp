/*
 * @Author: your name
 * @Date: 2020-08-31 00:42:03
 * @LastEditTime: 2020-09-04 03:08:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \BinarySearchTree\main.cpp
 */
#include "binarySearchTree_recursion.h"

int main(int argc, char const *argv[])
{
    binarySearchTree b;
    TreeNode* root;
    vector<int>v{15,6,23,4,7,71,5};
    root=b.bstFromPreorder(v);
    
    root=b.insertIntoBST(root,10);
    root=b.deleteNode(root,10);
    vector<int>inorder=b.inorderTraversal(root);
    for(auto it=inorder.begin();it!=inorder.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    if(root=b.searchBST(root,10))
    {
        cout<<"T"<<endl;
    }
    else
    {
        cout<<"F"<<endl;
    }
    system("pause");
    return 0;
}
