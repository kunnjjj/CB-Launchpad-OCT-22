#include<iostream>
#include<vector>


using namespace std;


void print(vector<int> &A)
{
    cout<<"changed"<<endl;
    cout<<"size of vector: "<<A.size()<<endl;
    cout<<"capacity of vector: "<<A.capacity()<<endl;
    cout<<endl;
}


int main()
{
    vector<int> A;

    print(A);

    int x; 
    cin>>x;
    while(x!=-1)
    {
        A.push_back(x);
        print(A);

        cin>>x;
    }



    return 0;
}