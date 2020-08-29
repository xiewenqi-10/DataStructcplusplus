#include<iostream>
using namespace std;
#include<vector>


template<class T,int size=10>
class stack
{
private:
    T data[size];       /* �洢���� */
    T top=-1;           /* ջ�� */
public:
    stack(/* args */);  /* ��ʼ�� */
    ~stack();           /* ��� */

    T push(T);          /* ��ջ */
    T pop();            /* ��ջ */

    T empty();          /* �ж�ջ�Ƿ�Ϊ�� */
    T getTop();         /* ��ȡջ�� */
    T lengthStack();    /*����ջ�ĳ���  */
    
    void  Traversal();  /* ���� */
};

template<class T,int size>
stack<T,size>::stack(/* args */)
{  
    top=-1;             /* ��ʼ�� */
    
}

template<class T,int size>
stack<T,size>::~stack(){/* ��� */}



template<class T,int size>
T stack<T,size>::push(T e)  /* ��ջ */
{
    if (top>=size-1)  return false;

    data[++top]=e;
    //cout<<e<<endl;
    return e;
}

template<class T,int size>  /* ��ջ */
T stack<T,size>::pop()
{
    if(top==-1) return false;

    return data[top--];
}


template<class T,int size>
T stack<T,size>::empty()    /*�ж�ջ�Ƿ�Ϊ�� */
{
    return top==-1;
}


template<class T,int size>
T stack<T,size>::getTop()    /* ��ȡջ�� */
{
    return data[top];
}

template<class T,int size>  /*����ջ�ĳ���  */
T stack<T,size>::lengthStack()
{
    return top++;
}

template<class T,int size>
void stack<T,size>::Traversal()
{
    while (!empty())    /* ��ջ��Ϊ�� */
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

    cout<<"ɾ��Ԫ��:"<<s.pop()<<endl;

    cout<<"Top:"<<s.getTop()<<endl;
    cout<<s.empty()<<endl;

    cout<<"size:"<<s.lengthStack()<<endl;
    s.Traversal();
    system("pause");
}