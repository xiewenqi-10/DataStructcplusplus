#include<iostream>
using namespace std;

template<class T,int size=10>
class Queue
{
private:
    T data[size];   /* 存储数据 */
    T front;        /* 队头 */
    T rear;         /* 队尾 */
    T count;        /* 计数器 */
public:
    Queue(/* args */);  /* 初始化 */
    ~Queue();           /* 清空 */

    T EnQueue(T);       /* 进队 */
    T DeQueue();        /* 出队 */

    T empty();          /* 判断队列是否为空 */
    T QueueLength();    /* 求队列的长度 */

    T getfront();       /* 获取队头 */
    T getrear();        /* 获取队尾 */

    void traversal();   /* 遍历 */
};

template<class T,int size>
Queue<T,size>::Queue(/* args */)
{
    this->front=0;
    this->rear=0;
    this->count=0;
}

/* 清空队列：让队头、队尾、计数器为0即可 */
template<class T,int size>
Queue<T,size>::~Queue()
{
    this->front=this->rear=0;
}


/*
*进队前需要判断队列是否已满，若满则弹出错误；
*否则将元素的数值插入队列，队尾指针移动。同时，将计数器加一 
*进队：rear=(rear+1)%arraysize;
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
*出队时需要判断队列是否为空，若空则弹出异常；
*否则，将队首指针向前移动。同时，计数器减一： 
*出队：front=(front+1)%arraysize;
*/
template<class T,int size>
T Queue<T,size>::DeQueue()
{
    if(this->front==this->rear) return false;

    //T e=this->data[this->front];      /* 获取详细的出队数字 */
    this->front=(this->front+1)%size;
    this->count--;

    return true;//e;
}

/* 
*队空front==rear 
*/
template<class T,int size>
T Queue<T,size>::empty()
{
    return (this->front==this->rear);
}


/* 
*获取队列的大小：(rear-front+arraysize)%arraysize;
 */ 
template<class T,int size>
T Queue<T,size>::QueueLength()
{
    return (this->rear-this->front+size)%size;
}


/*
*在获取队头前需要判断队列是否为空，若空弹出异常。
*否则返回数组队头的元素 
*/
template<class T,int size>
T Queue<T,size>::getfront()
{
    return this->data[this->front];
}


/* 
*获取队尾：rear=(front+count-1)%arraysize;
*/
template<class T,int size>
T Queue<T,size>::getrear()
{
    T x=(this->front+this->count-1)%size;

    return this->data[x];
}


/* 
*当rear!=front时，遍历队列;
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
