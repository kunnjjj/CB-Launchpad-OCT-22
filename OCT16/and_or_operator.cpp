#include<iostream>
using namespace std;

int main()
{
    int age=13;
    int number_of_girlfriends=1;

    if(number_of_girlfriends>=2 && age>=20)
    {
        cout<<"playboy"<<endl;
    }
    else
    {
        cout<<"goodboy"<<endl;
    }


    bool doing_btech=false;
    if(number_of_girlfriends==1 || doing_btech )
    {
        cout<<"single marega"<<endl;
    }
    else
    {
        cout<<"bandi hai"<<endl;
    }

    if(-1) // non zero expression
    {
        cout<<"chalega"<<endl;
    }
    else
    {
        cout<<"nahi chalega"<<endl;
    }

    int var=7;
    if(var==5)
    {
        cout<<"var is 5"<<endl;
    }
    else
    {
        cout<<"not 5"<<endl;
    }



    return 0;
}