
#include<iostream>  
#include <stack>  
#include <cassert>  
#include<queue>
using  namespace std;
 
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