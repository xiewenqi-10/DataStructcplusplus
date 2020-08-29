/*
 *ջ�������ϰ 
 */

#include<iostream>  
#include <stack>  
#include <cassert>  
#include<queue>
using  namespace std;
 
 /* 
 *������ջ:
    *1��ջ��stackdata�������¼����Ԫ�أ���һ��ջ��stackMin��������ѹ����һ������СԪ�ء�
    *2: ��stackdataѹ��һ������ʱ���ж� stackMin�Ƿ�Ϊ�գ�������Ԫ��ѹ�룬����ѹ��Ԫ�ص�Ԫ�غ�stackMin�е�topԪ����Ƚϣ���С��ѹ��stackMin��
    *3��ջ:������Ҫ��ջ��
    *4ջ��:����stackMin��ջ����
  */
  
class Stack{
    
    private:
        stack<int>stackdata;
        stack<int>stackmin;
    
    public:
        void puah(int data)
        {
            stackdata.push(data);
            if (stackmin.empty())
            {
                stackmin.push(data);
            }
            else
            {
                int e=stackmin.top();
                int min=e<data?e:data;
                stackmin.push(min);
            }
        }

        void pop()
        {
           //assert(!stackdata.empty()&&!stackmin.empty());
            stackdata.pop();
            stackmin.pop();
        }

        int getMin()
        {
            //assert(!stackmin.empty());
            return stackmin.top();
        }
};

//ջʵ�ֶ�
/*
 * 1����s1��Ϊ��ʱ����ɾ��ջ��Ԫ�أ����ε���s2�У�
 * 2��Ԫ�ؽ�s1��
 * 3����s2��Ϊ��ʱ����ɾ��s2��ջ��Ԫ�����ε���s1�У�
 * 4������s1�е�ջ��Ԫ�أ���ɾ��s1��
 * 5������s1ջ��Ԫ�أ�
 * 6������s1.empty();
 */
class MyQueue {

private:
    stack <int> s1;
    stack <int> s2;

public:
   
    MyQueue(){}
    void push(int x)
    {   
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop()
    {
        int top=s1.top();
        s1.pop();
        return top;
    }
   int peek()
   {
       return s1.top();
   }
   bool empty()
   {
       return s1.empty();
   }
};


class Soution
{

public:
    bool isVaid(string s)
    {
        stack<char>c;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            c.push(s[i]);
        
        else
        {
            if(c.size()==0)
            return false;
            int top=c.top();
            if(s[i]==')'&&top!='(')
            return false;
            
            else if (s[i]=='}'&&top!='{')
            return false;
            
            else if (s[i]==']'&&top!='[')
            return false;
            c.pop();    
            }
        }
        if (c.size()>0)
        {
            return false;
        }
        else
        {
            return true;
        } 
    }
};

class Mystack
{
    private:
        queue<int>q;
    
    public:
        void push(int x)
        {
            q.push(x);
        }

        int pop()
        {
            int size=q.size();
            for(int i=0;i<size-1;i++)
            {
                int e=q.front();
                q.pop();
                q.push(e);
            }
            int e=q.front();
            q.pop();
            return e;
        }

        int top()
        {
            int size=q.size();
            for(int i=0;i<size-1;i++)
            {
                int e=q.front();
                q.pop();
                q.push(e);
            }
            int e=q.front();
            q.pop();
            q.push(e);
            return e;
        }
        
        bool empty(){
            return q.empty();
        }

};
class BinaryConversion
{
    stack<int>s;

public:
    BinaryConversion(){};
    ~BinaryConversion(){};
    BinaryConversion(int number,int n)
    {
        while (number)
        {
            s.push(number%n);
            number/=n;
        }
        for(int i=s.size()-1;i>=0;i--)
        {  
            cout<< s.top();
            s.pop();
        }
    }
};

void convert(int num,int n)
{
    stack<char>s;
    static char digit[]={'1','2','3','4','5','6','7','8','9','A',
    'B','C','D','E','F',};
    while (num)
    {
        /* code */
        s.push(digit[num/n]);
        num/=n;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        
        cout<<s.top();
        s.pop();
       
    }
}

int main()
{

    
    convert(9,2);
    //BinaryConversion b(9,2);
    // Stack s;
    // s.puah(100);
    // s.puah(1);
    // s.puah(0);
    // s.puah(77);
    // cout<<"��ջ��������Сֵ��"<<s.getMin()<<endl;
//     MyQueue q;
   
//   for(int i=0;i<6;i++)
//   {
//       q.push(i);
//       cout<<i<<' ';
      
//   }
//   cout<<endl;
//   cout<<q.pop()<<endl;
//   cout<<q.pop()<<endl;
//   cout<<q.peek()<<endl;
    // Soution s;  
    // cout<<s.isVaid("{}()[]((((((");

//     Mystack q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     cout<<q.top()<<endl;
     system("pause");
}
