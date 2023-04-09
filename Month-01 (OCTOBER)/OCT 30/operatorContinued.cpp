#include <iostream>
using namespace std;

int main()
{

    cout << "negation: " << (~5) << endl;
    cout << "left shift by 1 " << (23 << 1) << endl;
    cout << "left shift by 2: " << (23 << 2) << endl;

    cout << "right shift by 1 " << (23 >> 1) << endl;
    cout << "right shift by 2: " << (23 >> 2) << endl;

    return 0;
}