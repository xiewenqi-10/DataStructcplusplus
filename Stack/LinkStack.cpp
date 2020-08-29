#include<iostream>
using namespace std;
#include<forward_list>
#include<string>

template<class T>
class LinkstackNode
{
public:
    T data;                 /* ������ */
    LinkstackNode<T>*next;  /* ָ���� */
};

template<class T>
class Linkstack:protected LinkstackNode<T>
{
private:
    LinkstackNode<T>*top;   /* ջ��ָ�� */
public:
    Linkstack(/* args */);  /* ��ʼ�� */
    ~Linkstack();           /* ��� */

    T push(T);              /* ��ջ */
    T pop();                /* ��ջ */

    T empty();              /* �ж�ջ�Ƿ�Ϊ�� */
    T getTop();
    T lengthLinkstack();    /* ����ջ�ĳ��� */
    void Traversal();       /* ���� */
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
T Linkstack<T>::push(T e)   /* ��ջ */
{
    LinkstackNode<T>*s=new LinkstackNode<T>;
    if(!s) return false;
    
    s->data=e;
    s->next=top->next;
    top->next=s;

    return e;    
}

template<class T>
T Linkstack<T>::pop()       /* ��ջ */
{
    LinkstackNode<T>*p=new LinkstackNode<T>;

    if(top->next==NULL) return false;

    p=top->next;
    T e=p->data;
    top->next=p->next;
    delete p;   /* �ͷ� */

    return e;
}

template<class T>
T Linkstack<T>::empty()             /*�ж�ջ�Ƿ�Ϊ�� */
{
    return top->next==NULL;
}

template<class T>
T Linkstack<T>::getTop()            /* ��ȡ�� */
{
    return top->next->data;
}

template<class T>
T Linkstack<T>::lengthLinkstack()   /*����ջ�ĳ���  */
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