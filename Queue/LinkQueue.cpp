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
    LinkQueue(/* args */);  /* 初始化 */
    ~LinkQueue();           /* 清空 */


    T EnQueue(T);           /* 进队 */
    T DeQueue();            /* 出队 */


    T empty();              /* 判断队列是否为空 */
    T QueueLength();        /* 求队列的长度 */

    T getfront();           /* 获取队头 */
    T getrear();            /* 获取队尾 */

    void traversal();       /* 遍历 */
};


template<class T>
LinkQueue<T>::LinkQueue(/* args */)     /* 初始化 */
{
    LinkQueueNode<T>*s=new LinkQueueNode<T>;
    s->next=NULL;
    this->front=this->rear=s;
}

template<class T>
LinkQueue<T>::~LinkQueue()              /* 清空 */
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
T LinkQueue<T>::EnQueue(T e)               /* 进队 */
{
    LinkQueueNode<T>*s=new LinkQueueNode<T>;
    s->data=e;
    s->next=NULL;
    rear->next=s;
    rear=s;

    return e;
}

template<class T>
T LinkQueue<T>::DeQueue()                 /* 出队 */
{
    LinkQueueNode<T>*p=this->front->next;
    T e=p->data;
    front->next=p->next;
    if(rear==p) {rear=front;}

    delete p;

    return e;
}



template<class T>
T LinkQueue<T>::empty()                 /* 判断队列是否为空 */
{
    return front==rear;
}

template<class T>
T LinkQueue<T>::QueueLength()           /* 求队列的长度 */
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
T LinkQueue<T>::getfront()              /* 获取队头 */
{
    return front->next->data;
}

template<class T>
T LinkQueue<T>::getrear()               /* 获取队尾 */
{
    return rear->data;
}


template<class T>
void LinkQueue<T>::traversal()          /* 遍历 */
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