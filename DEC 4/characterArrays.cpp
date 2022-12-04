#include<iostream>
using namespace std;


int main()
{

    int A[]={3,2,1,10};
    char myCharArray[]={'A','B','C','2'};

    for(int i=0;i<4;i++) cout<<myCharArray[i];
    cout<<endl;



    char secondCharArray[]={'P','Q','R','D','E','F','\0'};

    // try to print address of first box of "secondCharArray"

    cout<<&secondCharArray[0]<<endl;
    cout<<"&secondCharArray[1]: "<<&secondCharArray[1]<<endl;
    cout<<"secondCharArray: "<<secondCharArray<<endl;

    char thirdCharArray[]="My Name is Kunj";

    for(int i=0;i<5;i++)
    {
        cout<<thirdCharArray[i]<<" ";
    }
    cout<<endl;
    cout<<thirdCharArray<<endl;

    char *ptr=&secondCharArray[0];

    cout<<(int*)ptr<<endl;

    return 0;
}