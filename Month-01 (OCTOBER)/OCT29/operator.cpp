#include<iostream>
using namespace std;

int main()
{
    cout<<"and is: "<<(7&21)<<endl;

//     00000111
//    &00010101
// -------------
//     00000101 = 5

    cout<<"or is: "<<(7|21)<<endl;
    
//     00000111
//    |00010101
// --------------
//     00010111 = 23


    cout<<"xor is: "<<(7^21)<<endl;
//     00000111
//    |00010101
// --------------
//     00010010 = 18

    cout<<"&& wala: "<< (0 && 21)<<endl;
    // && ke side mein boolen expression hai 0: false, nonZero: true
    cout<<"|| wala: "<<(0 || 21)<<endl;
    // || ke side mein boolen expression hai 0: false, nonZero: true
    return 0;
}