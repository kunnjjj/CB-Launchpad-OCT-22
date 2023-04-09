#include<bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> A={3,2,1};
    sort(A.begin(),A.end());

    for(int x:A) cout<<x<<" ";
    cout<<endl;

    priority_queue<int> maxHeap(A.begin(),A.end()); // MAX HEAP

    // priority_queue<dataType,vector<dataType>,greater<dataType>> pq;

    priority_queue<int,vector<int>,greater<int>> minHeap(A.begin(),A.end());

    cout<<maxHeap.top()<<endl;
    cout<<minHeap.top()<<endl;


    return 0;
}