#include<iostream>
using namespace std;



int areaOfSquare(int side)
{
    return side * side;
}


int main()
{

    int numberOfGirlfriends=10;
    if(numberOfGirlfriends==0)
    {
        cout<<"Btech"<<endl;
    }
    else if(numberOfGirlfriends==1)
    {
        cout<<"DU"<<endl;
    }
    else if(numberOfGirlfriends>=2)
    {
        cout<<"Kunj Bhaiya"<<endl;
    }
    else if(numberOfGirlfriends>=5)
    {
        cout<<"Mechanical"<<endl;
    }

    // if(numberOfGirlfriends >0)
    // {
    //     cout<<"greater than 0"<<endl;
    // }

    if(numberOfGirlfriends >0) cout<<"greater than 0"<<endl;
    else cout<<"Less than 0"<<endl;

    // int i=1;
    // while(i<=10) i=i+1;
    // for(int i=1;i<=10;i++) cout<<"Hello"<<endl;

    // (condition? Yadi true hai: Yadi false hai);

    (numberOfGirlfriends>0 ? cout<<areaOfSquare(4)<<endl : cout<<"less than 0"<<endl); 

    int var=(numberOfGirlfriends > 0? 10 : 2);
    // int var;

    // if(numberOfGirlfriends >0)
    // {
    //     var=10;
    // }
    // else
    // {
    //     var=2;
    // }

    if(numberOfGirlfriends >0)
    {
        if(numberOfGirlfriends >=2)
        {
            cout<<"Playboy"<<endl;
        }
        else
        {
            cout<<"good boy"<<endl;
        }
    }
    else
    {
        cout<<"kuch nai"<<endl;
    }
    

    (numberOfGirlfriends > 0? (numberOfGirlfriends>=2? cout<<"Playboy"<<endl: cout<<"goodboy"<<endl): (cout<<"kuch nai"<<endl));
    
    return 0;
}