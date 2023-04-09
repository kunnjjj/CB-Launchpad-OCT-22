#include<iostream>
using namespace std;

int main()
{

    string s; 
    // cin >> s;
    getline(cin,s); // doesnt ignore white space
   
 
    cout<<s.size()<<endl;
    cout<<s.length()<<endl;

    cout<<s[0]<<endl; // prints first character

    cout<<s<<endl;

  
    string a(5,'a');  // makes a string of size=5
    // allocates 'a' to all boxes

    for(int i=0;i<5;i++) cin>>a[i];


    

    return 0;
}