#include<bits/stdc++.h>
using namespace std;

void _print(string x)
{
    cout<<x<<endl;
}
void _print(vector<int> &A)
{
    for(int x:A) cout<<x<<" ";
    cout<<endl;
}
void _print(int x)
{
    cout<<x<<endl;
}


#define deb(x) 5;

// void heapify(int i)
//     {
//         int smallest=i; // idx of smallest element 
//         int leftChild=left_child(i);
//         int rightChild=right_child(i);
//         if(leftChild < (int)PQ.size() && PQ[smallest] > PQ[leftChild]) // Priority(root) < Priority(leftChild)
//         {
//             smallest=leftChild;
//         }
//         if(rightChild < (int)PQ.size() && PQ[smallest] > PQ[rightChild])
//         {
//             smallest=rightChild;
//         }

//         if(smallest!=i)
//         {
//             swap(PQ[i],PQ[smallest]);
//             heapify(smallest);
//         }    
//     }

void heapify(vector<int> &A,int i,int N)
{
    // if(i>=N) return ;
    int smallest=i;
    // cout<<"inside func"<<endl;
    // deb(i);
    // deb(N);
    // deb(smallest);
    
    int left_child=(2*i+1),right_child=(2*i+2);
    if(left_child<N && A[smallest] > A[left_child])
    {
        smallest=left_child;
    }

    // deb(smallest);
    if(right_child<N && A[smallest] > A[right_child])
    {
        smallest=right_child;
    }

    // deb(smallest);
    if(smallest!=i)
    {
        swap(A[i],A[smallest]);
        heapify(A,smallest,N);
    }
}

void print(vector<int> &A)
{
    for(int i=0;i<(int)A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int n; cin>>n;

    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    deb(A);

    // BUILD HEAP
    for(int i=(n/2)-1;i>=0;i--) 
    {
        deb(i);
        heapify(A,i,n);
        deb(A);
    }
    //HW: build heap in O(N)

    // deb(A);
    // minElement
    int N=n;
    while(N>1)
    {
        swap(A[0],A[N-1]);
        // cout<<"A after heapify N: "<<n<<endl;
        deb(A);
        --N;
        heapify(A,0,N);
    }

    // deb(A);
    for(int i=n-1;i>=0;i--) cout<<A[i]<<" ";

    
    return 0;
}