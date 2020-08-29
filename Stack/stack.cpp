#include<iostream>
using namespace std;
#include<vector>


template<class T,int size=10>
class stack
{
private:
    T data[size];       /* 存储数据 */
    T top=-1;           /* 栈顶 */
public:
    stack(/* args */);  /* 初始化 */
    ~stack();           /* 清空 */

    T push(T);          /* 进栈 */
    T pop();            /* 退栈 */

    T empty();          /* 判断栈是否为空 */
    T getTop();         /* 获取栈顶 */
    T lengthStack();    /*返回栈的长度  */
    
    void  Traversal();  /* 遍历 */
};

template<class T,int size>
stack<T,size>::stack(/* args */)
{  
    top=-1;             /* 初始化 */
    
}

template<class T,int size>
stack<T,size>::~stack(){/* 清空 */}



template<class T,int size>
T stack<T,size>::push(T e)  /* 进栈 */
{
    if (top>=size-1)  return false;

    data[++top]=e;
    //cout<<e<<endl;
    return e;
}

template<class T,int size>  /* 退栈 */
T stack<T,size>::pop()
{
    if(top==-1) return false;

    return data[top--];
}


template<class T,int size>
T stack<T,size>::empty()    /*判断栈是否为空 */
{
    return top==-1;
}


template<class T,int size>
T stack<T,size>::getTop()    /* 获取栈顶 */
{
    return data[top];
}

template<class T,int size>  /*返回栈的长度  */
T stack<T,size>::lengthStack()
{
    return top++;
}

template<class T,int size>
void stack<T,size>::Traversal()
{
    while (!empty())    /* 若栈不为空 */
    {
        cout<<data[top--]<<" ";
    }
    cout<<endl;
}



int main()
{

    stack<int>s;

    for(int i=0;i<14;i++)
    {
        if(i<10)
        {
            cout<<s.push(i)<<endl;
        }
        else
        {
            cout<<"error"<<endl;
        }
        
    }

    cout<<"删除元素:"<<s.pop()<<endl;

    cout<<"Top:"<<s.getTop()<<endl;
    cout<<s.empty()<<endl;

    cout<<"size:"<<s.lengthStack()<<endl;
    s.Traversal();
    system("pause");
}