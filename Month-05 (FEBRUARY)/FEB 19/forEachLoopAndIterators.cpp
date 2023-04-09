#include <iostream>
#include <vector>

using namespace std;

// HW list<int> l; 
int main()
{

    vector<int> C(10);

    for(int &x:C) cin>>x;

    vector<int> A = {3, 4, 10, 15};

    for (int i = 0; i < (int)A.size(); i++)
    {
        int x = A[i];
        cout << x << " ";
    }
    cout << endl;

    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : A)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<vector<int>> B =
        {{3, 4, 5},
         {6, 10, 11}};

    for(auto a:B)
    {
        for(int x:a) cout<<x<<" ";
        cout<<endl;
    }

    cout<<"---------------------------------"<<endl;
    cout<<"printing using iterators"<<endl;
    vector<int> ::iterator it;
    for(it=A.begin();it!=A.end();it++)
    {
        cout<<(*it)<<" ";
    }

    pair<int,string> p;
    p.first=5;
    p.second="abc";

    vector<pair<int,string>> ashok;

    ashok.push_back(make_pair(10,"ashok"));
    ashok.push_back({12,"manan"});

    vector<pair<int,string>>:: iterator it2;
    for(it2=ashok.begin();it2!=ashok.end();it2++)
    {
        pair<int,string> p=(*it2);
        cout<<"p.first: "<<p.first<<endl;
        cout<<"p.second: "<<p.second<<endl;
        cout<<(*it2).first<<endl;
    }

    for(pair<int,string> &p:ashok)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

    for(auto p:ashok)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

    return 0;
}