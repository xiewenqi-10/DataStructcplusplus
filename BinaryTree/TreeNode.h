/*
 * @Author: your name
 * @Date: 2020-08-13 05:45:51
 * @LastEditTime: 2020-08-26 22:02:40
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \BinaryTree\TreeNode.h
 */
#ifndef _TreeNode
#define _TreeNode


#include<iostream>
using namespace std;
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

template<class T>
class TreeNode          //½Úµã
{
public:
    T val;
    TreeNode<T>*left;
    TreeNode<T>*right;
    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
};

#endif