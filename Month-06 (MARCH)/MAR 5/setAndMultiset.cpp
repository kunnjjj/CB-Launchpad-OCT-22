#include <iostream>
#include <set> // header file for set
// #include<multiset> // header file for multiset
#include <iterator>
using namespace std;

int main()
{

    // set<dataType> name;
    set<int> s;       // stores unique items , (SELF BALACING BST)
    multiset<int> ms; // multiple entries can be stored (..."")

    s.insert(15);
    s.insert(2);
    s.insert(3);
    s.insert(10);

    for (int x : s)
        cout << x << " ";
    cout << endl; // inorder traveral

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) // inorder travel
    {
        cout << (*it) << " ";
    }
    cout << endl;

    s.insert(12);
    s.insert(13);
    s.insert(7);
    s.insert(15);

    cout << s.size() << endl;

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) // inorder travel
    {
        cout << (*it) << " ";
    }
    cout << endl;

    auto it = s.begin();
    cout << (*it) << " ";
    it++;
    cout << (*it) << " ";
    cout << endl;

    auto it2 = s.rbegin();
    cout << "s.rbegin(): " << (*it2) << endl;

    it = s.end();
    it--;
    cout << "end-1: " << (*it) << endl;

    auto it3 = s.find(10);

    if (it3 != s.end())
    {
        cout << "target was found" << endl;
    }
    else if (it3 == s.end())
    {
        cout << "target was not found" << endl;
    }

    // s.erase(...)
    s.erase(10);
    cout << "after erasing 10" << endl;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) // inorder travel
    {
        cout << (*it) << " ";
    }
    cout << endl;

    auto it4 = s.find(12);
    s.erase(it4);
    cout << "after erasing it4" << endl;

    for (int x : s)
        cout << x << " ";
    cout << endl; // inorder traveral

    cout << "-------------------------------------------" << endl;

    ms.insert(10);
    ms.insert(12);
    ms.insert(15);
    ms.insert(10);
    ms.insert(8);
    ms.insert(10);
    ms.insert(15);
    ms.insert(15);
    ms.insert(15);
    ms.insert(24);
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    ms.erase(10);
    cout<<"after ms.erase(10):"<<endl;
    for (int x : ms)
        cout << x << " ";
    cout << endl;

    cout<<"after auto it5=ms.find(15); if(it5!=ms.end()){ms.erase(it5)}"<<endl;
    auto it5=ms.find(15);
    if(it5!=ms.end())
    {
        ms.erase(it5);
    }

    for (int x : ms)
        cout << x << " ";
    cout << endl;
    

    return 0;
}