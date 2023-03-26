#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>


using namespace std;

int main()
{
    unordered_map<int,int> mp;
    mp[100000000]=19;

    // A[3]=35;
    mp[3]=35;

    cout<<mp.size()<<endl;

    mp[2]=10;

    mp[-10]=29;

    cout<<mp.size()<<endl;
    cout<<mp[10]<<endl;

    cout<<mp.size()<<endl;

    cout<<"printing unordered_map: "<<endl;
    for(pair<int,int> p:mp)
    {
        cout<<"key: "<<p.first<<endl;
        cout<<"value: "<<p.second<<endl;
        cout<<endl;
    }

    cout<<"---------------------"<<endl;
    unordered_map<string,int> mp2;

    mp2["rakesh"]=18;


    map<int,int> mp3;

    // A[3]=35;
    mp3[3]=35;

    cout<<mp3.size()<<endl;

    mp3[2]=10;

    mp3[-10]=29;

    cout<<mp3.size()<<endl;
    cout<<mp3[10]<<endl;

    cout<<mp3.size()<<endl;

    unordered_map<int,vector<int>> mp4;

    mp4[3].push_back(10);
    mp4[3].push_back(11);

    // key=3, value={10,11}

    mp4[4].push_back(12);
    mp4[5].push_back(19);
    cout<<"------------------"<<endl;
    cout<<"printing map: "<<endl;
    for(pair<int,int> p:mp3)
    {
        cout<<"key: "<<p.first<<endl;
        cout<<"value: "<<p.second<<endl;
        cout<<endl;
    }


    // if(mp3.count(3))
    // {
    //     cout<<"3 as key is present"<<endl;
    //     cout<<mp3[3]<<endl;
    // }
    // else
    // {
    //     cout<<"doesn't exist"<<endl;
    // }

    map<int,int>:: iterator it;
    for(it=mp3.begin();it!=mp3.end();it++)
    {
        cout<<"key: "<<(*it).first<<endl;
        cout<<"value: "<<(*it).second<<endl;
    }

    int key=98;

    it=mp3.find(key);
    cout<<"find operation: "<<endl;
    if(it!=mp3.end())
    {
        cout<<"key: "<<(*it).first<<endl;
        cout<<"value: "<<(*it).second<<endl;
        cout<<it->first<<endl;
        cout<<it->second<<endl;
    }
    else
    {
        cout<<"not present"<<endl;
    }

    return 0;
}