#include<bits/stdc++.h>
using namespace std;

int sumOfDigit(int x)
{
    int sum=0;
    while(x>0)
    {
        sum+=(x%10);
        x/=10;
    }
    return sum;
}
bool compare(int a,int b)
{
    // if(a > b) return true;
    // else return false;
    int sumA=sumOfDigit(a),sumB=sumOfDigit(b);
    return sumA< sumB;
    // if(sumA < sumB)
    // {
    //     return true;
    // }
    // else 
    //     return false;
}

// bool compare(int x)
// {
//     return (x==5) return ;
// }

int main()
{
    vector<int> A={10,12,18,21,8,9,10};
    sort(A.begin(),A.end(),compare);
    for(int x:A) cout<<x<<" ";

    return 0;
}