#include <iostream>
using namespace std;

class car
{
private:
    float discount;
    int price;
    string model;
public:
    char col;
    // float discount;
    // int price;
    // string model;
    car() // default constructor
    {
        model="BMW";
        price=90000000;
        discount=500;
        col='B';
    }
    car(string MODEL,float DISCOUNT,int PRICE,char COL) // parameterized constructor
    {
        model=MODEL;
        discount=DISCOUNT;
        price=PRICE;
        col=COL;
    }

    void print()
    {
        cout<<"model of Car: "<<model<<endl;
        cout<<"price of Car: "<<price<<endl;
        cout<<"col of car: "<<col<<endl;
        cout<<endl;
    }
};

int main()
{
    car C;
  

    car C1;

    C.print();
    C1.print();

    C1 = C; // shallow copy
    C1.print(); 


    // C.price = 6000000;
    // C.model = "BMW";
    // these attributes are private and hence cant be accessed from main
    // C.col = 'B';
    // color is a public attribute hence can be accessed

    // cout << sizeof(C) << endl;
    // cout << sizeof(car) << endl;
    // int x;
    // cout << sizeof(int) << endl;
    // cout << sizeof(x) << endl;

    // cout << sizeof(float) << endl;
    // cout << sizeof(char) << endl;
    // cout << sizeof(string) << endl;

    return 0;
}