#include<iostream>
using namespace std;
#include<forward_list>
#include<string>

template<class T>
class LinkstackNode
{
public:
    T data;                 /* 数据域 */
    LinkstackNode<T>*next;  /* 指针域 */
};

template<class T>
class Linkstack:protected LinkstackNode<T>
{
private:
    LinkstackNode<T>*top;   /* 栈顶指针 */
public:
    Linkstack(/* args */);  /* 初始化 */
    ~Linkstack();           /* 清空 */

    T push(T);              /* 进栈 */
    T pop();                /* 退栈 */

    T empty();              /* 判断栈是否为空 */
    T getTop();
    T lengthLinkstack();    /* 返回栈的长度 */
    void Traversal();       /* 遍历 */
};


template<class T>
Linkstack<T>::Linkstack(/* args */)
{
    top=new LinkstackNode<T>;
    top->next=NULL;
}

template<class T>
Linkstack<T>::~Linkstack()
{
    delete top;
}


template<class T>
T Linkstack<T>::push(T e)   /* 进栈 */
{
    LinkstackNode<T>*s=new LinkstackNode<T>;
    if(!s) return false;
    
    s->data=e;
    s->next=top->next;
    top->next=s;

    return e;    
}

template<class T>
T Linkstack<T>::pop()       /* 退栈 */
{
    LinkstackNode<T>*p=new LinkstackNode<T>;

    if(top->next==NULL) return false;

    p=top->next;
    T e=p->data;
    top->next=p->next;
    delete p;   /* 释放 */

    return e;
}

template<class T>
T Linkstack<T>::empty()             /*判断栈是否为空 */
{
    return top->next==NULL;
}

template<class T>
T Linkstack<T>::getTop()            /* 获取顶 */
{
    return top->next->data;
}

template<class T>
T Linkstack<T>::lengthLinkstack()   /*返回栈的长度  */
{
    int i;
    LinkstackNode<T>*p=top->next;
    while (p)
    {
        p=p->next;
        i++;
    }
    return i;
}

template<class T>
void Linkstack<T>::Traversal()
{
    LinkstackNode<T>*p=top->next;
    while (p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{

    Linkstack<int>s;
    cout<<s.push(1)<<endl;
    cout<<s.push(1)<<endl;

    cout<<"pop:"<<s.pop()<<endl;
    int a=s.empty()>0?1:0;
    cout<<"empty?"<<a<<endl;
    cout<<"gettop:"<<s.getTop()<<endl;
    cout<<"length:"<<s.lengthLinkstack()<<endl;
    s.Traversal();
    system("pause");
}