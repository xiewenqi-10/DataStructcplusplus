#include<iostream>
using namespace std;

template<class T,int size=10>
class Queue
{
private:
    T data[size];   /* �洢���� */
    T front;        /* ��ͷ */
    T rear;         /* ��β */
    T count;        /* ������ */
public:
    Queue(/* args */);  /* ��ʼ�� */
    ~Queue();           /* ��� */

    T EnQueue(T);       /* ���� */
    T DeQueue();        /* ���� */

    T empty();          /* �ж϶����Ƿ�Ϊ�� */
    T QueueLength();    /* ����еĳ��� */

    T getfront();       /* ��ȡ��ͷ */
    T getrear();        /* ��ȡ��β */

    void traversal();   /* ���� */
};

template<class T,int size>
Queue<T,size>::Queue(/* args */)
{
    this->front=0;
    this->rear=0;
    this->count=0;
}

/* ��ն��У��ö�ͷ����β��������Ϊ0���� */
template<class T,int size>
Queue<T,size>::~Queue()
{
    this->front=this->rear=0;
}


/*
*����ǰ��Ҫ�ж϶����Ƿ������������򵯳�����
*����Ԫ�ص���ֵ������У���βָ���ƶ���ͬʱ������������һ 
*���ӣ�rear=(rear+1)%arraysize;
*/
template<class T,int size>
T Queue<T,size>::EnQueue(T e)
{
    if(this->count==(size-1)) return false;

    this->data[this->rear]=e;
    this->rear=(this->rear+1)%size;
    this->count++;   

    return e;
}

/*
*����ʱ��Ҫ�ж϶����Ƿ�Ϊ�գ������򵯳��쳣��
*���򣬽�����ָ����ǰ�ƶ���ͬʱ����������һ�� 
*���ӣ�front=(front+1)%arraysize;
*/
template<class T,int size>
T Queue<T,size>::DeQueue()
{
    if(this->front==this->rear) return false;

    //T e=this->data[this->front];      /* ��ȡ��ϸ�ĳ������� */
    this->front=(this->front+1)%size;
    this->count--;

    return true;//e;
}

/* 
*�ӿ�front==rear 
*/
template<class T,int size>
T Queue<T,size>::empty()
{
    return (this->front==this->rear);
}


/* 
*��ȡ���еĴ�С��(rear-front+arraysize)%arraysize;
 */ 
template<class T,int size>
T Queue<T,size>::QueueLength()
{
    return (this->rear-this->front+size)%size;
}


/*
*�ڻ�ȡ��ͷǰ��Ҫ�ж϶����Ƿ�Ϊ�գ����յ����쳣��
*���򷵻������ͷ��Ԫ�� 
*/
template<class T,int size>
T Queue<T,size>::getfront()
{
    return this->data[this->front];
}


/* 
*��ȡ��β��rear=(front+count-1)%arraysize;
*/
template<class T,int size>
T Queue<T,size>::getrear()
{
    T x=(this->front+this->count-1)%size;

    return this->data[x];
}


/* 
*��rear!=frontʱ����������;
*front=(front+1)%arraysize;
*/
template<class T,int size>
void Queue<T,size>::traversal()
{

    T p=this->front;
    while (this->rear!=p)
    {
        cout<<this->data[p]<<" ";
        p=(p+1)%size;
    }

    cout<<endl; 
}

int main()
{
    Queue<int>q;
    cout<<q.EnQueue(10)<<endl;
    cout<<q.EnQueue(20)<<endl;
    cout<<q.EnQueue(30)<<endl;
    
    cout<<q.DeQueue()<<endl;

    cout<<"empty?"<<q.empty()<<endl;
    cout<<"Length:"<<q.QueueLength()<<endl;

    cout<<"front:"<<q.getfront()<<endl;
    cout<<"rear:"<<q.getrear()<<endl;
    q.traversal();
    system("pause");
}
