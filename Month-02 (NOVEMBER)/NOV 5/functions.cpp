#include<iostream>
using namespace std;


// returnType NameOfFunc(dataType param1,dataType param2,.....)
// {




//     return val;
// }

int areaOfRectangle(int length, int breadth)
{
    int area= length * breadth;
    return area;
}

int areaOfSquare(int side)
{
    return side * side;
}

float areaOfTriangle(int base,int height)
{
    cout<<"calculating area of triangle"<<endl;
    return 0.5 * base * height;
}



void printVipin(int &n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Vipin"<<endl;
    }
}

void printDev(int n=10)
{
    for(int i=1;i<=n;i++)
    {
        cout<<"Dev"<<endl;
    }
}

void printManavManan(int n,int m=(areaOfSquare(2)))
{
    for(int i=0;i<n;i++)
    {
        cout<<"Manav"<<endl;
    }
    
    if(n>10) 
    {
        return ;
    }
    int area=areaOfSquare(2);
    cout<<area<<endl;
    for(int i=0;i<m;i++)
    {
        cout<<"Manan"<<endl;
    }
    
}




int main()
{

    int square=areaOfSquare(5);
    cout<<"square is: "<<square<<endl;


    int square2=areaOfSquare(6);
    cout<<"square2: "<<square2<<endl;

    int rectangle=areaOfRectangle(5,4);
    cout<<"rectangle is: "<<rectangle<<endl;

    float triangle=areaOfTriangle(2,3);
    cout<<"triangle: "<<triangle<<endl;


    areaOfTriangle(4,10);
    

    int n=4;
    printVipin(n);
    cout<<"n is: "<<n<<endl;


    printDev(); 
    printManavManan(11);
    return 0;
}