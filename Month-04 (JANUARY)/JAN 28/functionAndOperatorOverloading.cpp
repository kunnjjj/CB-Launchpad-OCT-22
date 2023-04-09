
#include<iostream>
using namespace std;

class complex_no
{
    int real;
    int img;

    public:
    complex_no()
    {
        
    }
    complex_no(int REAL,int IMG)
    {
        real=REAL;
        img=IMG;
    }
    void setReal(int REAL)
    {
        real=REAL;
    }
    int getReal()
    {
        cout<<"real: "<<real<<endl;
        return real;
    }
    void setImg(int IMG)
    {
        img=IMG;
    }   
    int getImg()
    {
        cout<<"img: "<<img<<endl;
        return img;
    }
    void print(int x)
    {
        cout<<"img: "<<img<<endl;
    }
    void print(string x)
    {
        cout<<"real: "<<real<<endl;
    }
    void print()
    {
        cout<<real<<" + i"<<img<<endl;
    }
};

complex_no add(complex_no &c1,complex_no &c2)
{
    complex_no ans;
    ans.setImg(c1.getImg() + c2.getImg());
    ans.setReal(c1.getReal() + c2.getReal());
    return ans;
}

complex_no operator+(complex_no &c1,complex_no &c2)
{
    complex_no ans;
    ans.setImg(c1.getImg() + c2.getImg());
    ans.setReal(c1.getReal() + c2.getReal());
    return ans;
}

ostream& operator<<(ostream &o,complex_no& c1)
{
    cout<<"printing complex number"<<endl;
    c1.getReal();
    c1.getImg();
}

int main()
{
    complex_no c1(3,4);

    c1.print();
    c1.print("abc");
    c1.print(3);

    complex_no c2(4,5);


    complex_no c3=add(c1,c2);
    c3.print();

    complex_no c4= c1 + c2;
    cout<<"printing c4: "<<endl;
    c4.print();

    cout<<"printing c4 using operator: "<<endl;
    cout<<c4;

    // cout<<"printing c4 and c1"<<endl;
    // cout<<c4;
    // cout<<4<<endl;

    cout<<c4<<c3<<endl;



    return 0;
}