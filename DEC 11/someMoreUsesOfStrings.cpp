#include <iostream>
#include<algorithm> // for reverse function
using namespace std;

int main()
{
    string A[2]; // int A[2]; datatype name[10];
    cin >> A[0]; // inputs complete string
    cin >> A[1];

    cout << (A[0][0]) << endl;

    string s1 = "abc";
    string s2 = "pqr";
    string c1 = s1 + s2; // concatenation
    string c2 = s2 + s1;

    cout << c1 << endl;
    cout << c2 << endl;

    string ab = "pqrstabc";
    cout << ab.substr(3, 2) << endl; // third index se length 2 uthao

    // cout<<ab.substr(3,0)<<endl; // avoid
    cout << ab.substr(3) << endl; // prints entire s[3....to the end]

    if (s1 == s2)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Unequal" << endl;
    }

    string k1="abc",k2="ABC";
    if(k1 < k2)
    {
        cout<<"k1 is smaller"<<endl;
    }
    else
    {
        cout<<"k2 is smaller"<<endl;
    }
    
    // int x=6;
    // x+=2;

    k1.append(k2); // k1="abc", k2="ABC" => k1="abcABC"
    // // O(sizeof(k2))

    // k1=k1 + k2;  // same results if both run independently
    // // O(sizeof(k1) + sizeof(k2))

    // k1+=k2; // this also gives same result 
    // // O(sizeof(k2))

    // k1.push_back('3'); // string ke last mein '3' append karana //O(1)
    // k1+='3'; // appending '3' char // O(1)
    // k1+="3";  // appending "3" string // O(len("3"))

    // cout<<k1.back()<<endl;

    int x; 
    for(int i=0;i<(int)k1.size();i++)
    {
        cout<<k1[i];
    }
    cout<<endl;
    // cout<<k1.front()<<endl;

    reverse(k1.begin(),k1.end());
    sort(k1.begin(),k1.begin()+3);

    cout<<k1<<endl;
    sort(k1.begin(),k1.end());
    
    return 0;
}