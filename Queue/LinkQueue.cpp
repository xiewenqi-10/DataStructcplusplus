#include<iostream>
using namespace std;


template<class T>
class LinkQueueNode
{
public:
    T data;
    LinkQueueNode<T>*next;
};

template<class T>
class LinkQueue
{
private:
    LinkQueueNode<T>*front;
    LinkQueueNode<T>*rear;
public:
    LinkQueue(/* args */);  /* ��ʼ�� */
    ~LinkQueue();           /* ��� */


    T EnQueue(T);           /* ���� */
    T DeQueue();            /* ���� */


    T empty();              /* �ж϶����Ƿ�Ϊ�� */
    T QueueLength();        /* ����еĳ��� */

    T getfront();           /* ��ȡ��ͷ */
    T getrear();            /* ��ȡ��β */

    void traversal();       /* ���� */
};


template<class T>
LinkQueue<T>::LinkQueue(/* args */)     /* ��ʼ�� */
{
    LinkQueueNode<T>*s=new LinkQueueNode<T>;
    s->next=NULL;
    this->front=this->rear=s;
}

template<class T>
LinkQueue<T>::~LinkQueue()              /* ��� */
{
    LinkQueueNode<T>*p=this->front;
    while (p)
    {
        LinkQueueNode<T>*q=p;
        p=p->next;
        delete q;
    }
}


template<class T>
T LinkQueue<T>::EnQueue(T e)               /* ���� */
{
    LinkQueueNode<T>*s=new LinkQueueNode<T>;
    s->data=e;
    s->next=NULL;
    rear->next=s;
    rear=s;

    return e;
}

template<class T>
T LinkQueue<T>::DeQueue()                 /* ���� */
{
    LinkQueueNode<T>*p=this->front->next;
    T e=p->data;
    front->next=p->next;
    if(rear==p) {rear=front;}

    delete p;

    return e;
}



template<class T>
T LinkQueue<T>::empty()                 /* �ж϶����Ƿ�Ϊ�� */
{
    return front==rear;
}

template<class T>
T LinkQueue<T>::QueueLength()           /* ����еĳ��� */
{
    LinkQueueNode<T>* p=front->next;
    int i=0;
    while (p)
    {
        p=p->next;
        i++;
    }
    return i;
}


template<class T>
T LinkQueue<T>::getfront()              /* ��ȡ��ͷ */
{
    return front->next->data;
}

template<class T>
T LinkQueue<T>::getrear()               /* ��ȡ��β */
{
    return rear->data;
}


template<class T>
void LinkQueue<T>::traversal()          /* ���� */
{
    LinkQueueNode<T>*p=front->next;
    while (p!=NULL)
    {
        int e=p->data;
        cout<<e<<' ';
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    LinkQueue<int>q;
    cout<<q.EnQueue(100)<<endl;
    cout<<q.EnQueue(200)<<endl;
    cout<<q.EnQueue(300)<<endl;

    cout<<"pop:"<<q.DeQueue()<<endl;

    cout<<"empty?"<<q.empty()<<endl;
    cout<<"Length:"<<q.QueueLength()<<endl;
    
    cout<<"front:"<<q.getfront()<<endl;
    cout<<"rear:"<<q.getrear()<<endl;
    
    q.traversal();
    system("pause");

}