#include<bits/stdc++.h>
using namespace std;

class Heap
{   
    vector<int> PQ;
    public:
    Heap()
    {

    }   

    int left_child(int i)
    {
        return 2*i+1; // 1Based: 2*i
    }
    
    int right_child(int i)
    {
        return 2*i+2; //1Based: 2*i+1
    }

    int parent(int i)
    {
        return (i-1)/2; //1Based: (i/2)
    }

    void push(int x)
    {
        PQ.push_back(x);
        int idx=(int)PQ.size()-1;

        while(idx>0 && PQ[idx] < PQ[parent(idx)]) // priority(idx) > priority(parent(idx)) swap
        {
            swap(PQ[idx],PQ[parent(idx)]);
            idx=parent(idx);
        }
    }

    void heapify(int i)
    {
        int smallest=i; // idx of smallest element 
        int leftChild=left_child(i);
        int rightChild=right_child(i);
        if(leftChild < (int)PQ.size() && PQ[smallest] > PQ[leftChild]) // Priority(root) < Priority(leftChild)
        {
            smallest=leftChild;
        }
        if(rightChild < (int)PQ.size() && PQ[smallest] > PQ[rightChild])
        {
            smallest=rightChild;
        }

        if(smallest!=i)
        {
            swap(PQ[i],PQ[smallest]);
            heapify(smallest);
        }    
    }

    void pop()
    {
        if(PQ.empty())
        {
            cout<<"Underflow"<<endl;
            return ;
        }
        int last_idx=(int)PQ.size()-1;
        swap(PQ[0],PQ[last_idx]);
        PQ.pop_back();

        heapify(0);
    }

    int top() // get element of highest priority
    {
        if(PQ.empty())
        {
            cout<<"underflow"<<endl;
            return -1;
        }
        return PQ[0];
    }

    void print()
    {
        for(int x:PQ) cout<<x<<" ";
        cout<<endl;
    }
};

int main()
{
    
    Heap H;
    H.push(6);
    H.push(3);
    H.push(10);
    H.push(12);

    cout<<H.top()<<endl;

    H.print();

    H.push(2);
    cout<<H.top()<<endl;

    H.print();

    H.pop();
    H.pop();
    H.pop();

    cout<<H.top()<<endl;
    H.print();

    return 0;
}