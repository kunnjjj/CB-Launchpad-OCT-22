#include<iostream>
using namespace std;


class Queue
{
    int *A;
    int cur_size,maxSize;
    int front;
    int rear;

    public:
    Queue(int max_size)
    {
        maxSize=max_size;
        A=new int [maxSize];
        front=0;
        rear=-1 ; // maxSize-1
    }
    // empty(), size(), 
    void push(int x)
    {
        if(cur_size==maxSize)
        {
            cout<<"overflow"<<endl;
            return ;
        }
        rear=(rear+1)%maxSize;
        A[rear]=x;
        cur_size++;
    }

    void pop()
    {
        if(cur_size==0)
        {
            cout<<"underflow"<<endl;
            return ;
        }
        cur_size--;
        front=(front+1)%maxSize;
    }

    int Front()
    {
        if(cur_size==0)
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return A[front];
    }

};

int main()
{
    Queue q(20);
    

    for(int i=0;i<13;i++)
    {
        q.push(i+1);
    }

    cout<<q.Front()<<endl;

    for(int i=0;i<5;i++)
    {
        cout<<"q.Front(): "<<q.Front()<<endl;
        q.pop();
    }

    return 0;
}