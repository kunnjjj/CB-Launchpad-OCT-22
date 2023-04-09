#include<iostream>
#include<stack>

using namespace std;

template <typename T>
class Queue
{
    stack<T> s1,s2;
    public:
    void enQueue(T x)
    {
        s1.push(x);
    }
    void deQueue()
    {
        if(s1.empty())
        {
            cout<<"underflow"<<endl;
            return ;
        }
        while((int)s1.size()>1)
        {
            T topEle=s1.top();
            s1.pop();
            s2.push(topEle);
        }

        s1.pop(); // queue ka topMost element is popped

        while(!s2.empty())
        {
            T topEle=s2.top();
            s2.pop();
            s1.push(topEle);
        }
    }

    T topElement()
    {
       if(s1.empty())
        {
            cout<<"underflow"<<endl;
            return -1;
        } 
        while((int)s1.size()>1)
        {
            T topEle=s1.top();
            s1.pop();
            s2.push(topEle);
        }

        T toReturn = s1.top();

        while(!s2.empty())
        {
            T topEle=s2.top();
            s2.pop();
            s1.push(topEle);
        }   
        return toReturn;
    }
    bool is_empty()
    {
        return s1.empty();
    }
};
int main()
{

    Queue<int> q;

    Queue<float> qFloat;

    q.enQueue(5);
    q.enQueue(10);


    qFloat.enQueue(12.34);
    qFloat.enQueue(10.96);

    while(!q.is_empty())
    {
        cout<<q.topElement()<<" ";
        q.deQueue();
    }


    return 0;
}