#include <iostream>
#include <iostream>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> A(3,-1);
    // vector<datatype> Name (initialSize);
    A[0]=-12;
    A[1]=10;
    A[2]=12;
    for(int i=0;i<(int)A.size();i++) cin>>A[i];
    
    cout << A.capacity() << endl;
    for (int i = 0; i < (int)A.size(); i++)
        cout << A[i] << " ";
    cout<<endl;
    A.push_back(5);
    for (int i = 0; i < (int)A.size(); i++)
        cout << A[i] << " ";
    cout<<endl;

    A.pop_back();

    for (int i = 0; i < (int)A.size(); i++)
        cout << A[i] << " ";
    cout<<endl;


    vector<vector<int> > B(3,vector<int> (4,-1));

    cout<<"printing 2D vector: "<<endl;

    for(int i=0;i<(int)B.size();i++)
    {
        for(int j=0;j<(int)B[i].size();j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    B[1].push_back(4);
    for(int i=0;i<(int)B.size();i++)
    {
        for(int j=0;j<(int)B[i].size();j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }




    vector<int> C(3,-1);
    vector<int> D(4,-1);
    if(C==D)
    {
        cout<<"vectors are equal"<<endl;
    }
    else
    {
        cout<<"unequal"<<endl;
    }

    B.push_back(C);
    B.push_back(D);
    cout<<"B here is: "<<endl;
    for(int i=0;i<(int)B.size();i++)
    {
        for(int j=0;j<(int)B[i].size();j++)
        {
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }




    return 0;
}