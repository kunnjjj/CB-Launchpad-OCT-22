#include<bits/stdc++.h>
using namespace std;


#define dataType vector<int> 

int main()
{   
    int n,k; 
    cin>>k>>n;
    vector<vector<int>> A(k,vector<int> (n));
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++) cin>>A[i][j];
    }


    priority_queue<dataType,vector<dataType>,greater<dataType>> pq;

    // dataType=vector<int> (3)
    // dataType[0] val
    // dataType[1] row_no
    // dataType[2] col_no 0....

    for(int row=0;row<k;row++)
    {
        pq.push({A[row][0],row,0});
    }

    vector<int> ans;
    while(!pq.empty())
    {
        vector<int> bestVector=pq.top();
        // cout<<bestVector[0]<<" ";
        ans.push_back(bestVector[0]);
        int rowNo=bestVector[1];
        int colNo=bestVector[2];
        pq.pop();
        if(colNo+1<(int)A[rowNo].size())
        {
            vector<int> me(3);
            me[0]=A[rowNo][colNo+1];
            me[1]=rowNo;
            me[2]=colNo+1;
            pq.push(me);
        }
    }
    
    for(int x:ans) cout<<x<<" ";



    return 0;
}