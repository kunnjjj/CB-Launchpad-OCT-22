#include<iostream>
#include<vector>

using namespace std;

int main()
{
    
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    // vector<int> suffixSum(n+1);
    // vector<int> sumOfProductOfPairs(n+1);
    int oldSuffixSum=0;
    int oldSumOfProd=0;
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        // suffixSum[i]=A[i] + suffixSum[i+1];
        int nowSuffixSum=A[i] + oldSuffixSum;
        // sumOfProductOfPairs[i]=A[i] * suffixSum[i+1] + sumOfProductOfPairs[i+1];
        int nowSumOfProdOfPair=A[i] * oldSuffixSum + oldSumOfProd;
        // ans+=A[i]*sumOfProductOfPairs[i+1];
        ans+=A[i] * oldSumOfProd;
        oldSuffixSum=nowSuffixSum;
        oldSumOfProd=nowSumOfProdOfPair;
    }
    cout<<ans<<endl;




    return 0;
}