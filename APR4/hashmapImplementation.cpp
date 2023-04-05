#include<iostream>
using namespace std;

class node
{
    public:
    string key; // restaurant items
    int val; // price
    node* next;
    node(string key,int val)
    {
        this->key=key;
        this->val=val;
        next=NULL;
    }
    ~node()
    {
            cout<<"deleted"<<endl;
            // cout<<"val: "<<val<<endl;
            cout<<"key: "<<key<<endl;
        if(this->next!=NULL) // this will recursively delete the entire LL
        {
            // recursion on class destructor
            delete(this->next);
        }
    }
};

class hashTable
{
    // IMPLEMENT UPDATE, DELETE FUNCTIONS YOURSELF
    node** table;
    int tableSize;
    int prime=37;
    int cnt;
    double loadFactor;
    
    int hashFunction(string key)
    {
        int hash=0;
        int p=37;
        for(int i=0;i<(int)key.size();i++)
        {
            hash=(hash%tableSize + (key[i] * p)%tableSize)%tableSize;
        }
        return hash;
    }
    
    public:
    hashTable(int intitalSize)
    {
        loadFactor=0.5;
        cnt=0;
        tableSize=intitalSize;
        table=new node* [intitalSize];
        for(int i=0;i<tableSize;i++)
        {
            table[i]=NULL;
        }
    }
    
    void insertAtEnd(node* &head,string &key,int val)
    {
        if(head==NULL) 
        {
            head=new node(key,val);
            return ;
        }
        insertAtEnd(head->next,key,val);
    }

    void insert(string key,int val)
    {
        int idx=hashFunction(key);
        insertAtEnd(table[idx],key,val);
        cnt++;
        // cout<<(cnt*1.0)/ tableSize<<endl;
        // cout<<loadFactor<<endl;
        if( (cnt*1.0)/ tableSize > loadFactor) rehash();
    }


    void print()
    {
        for(int i=0;i<tableSize;i++)
        {
            cout<<i<<"-> ";
            node* temp=table[i];
            while(temp!=NULL)
            {
                cout<<"{ "<<temp->key<<" , "<<temp->val<<"}, ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void rehash()
    {
        cout<<"rehashing"<<endl;
        // jaise hee load factor hit hoga, it will double the table size and compute all hash values again
        int oldTableSize=tableSize;
        tableSize*=2;

        node** oldTable=table;

        // cout<<"tableSize: "<<tableSize<<endl;
        // return ;
        // cout<<"new tableSize: "<<tableSize<<endl;

        table=new node* [tableSize]; // 2*oldTableSize

        for(int i=0;i<tableSize;i++) table[i]=NULL;

        cnt=0;
        for(int i=0;i<oldTableSize;i++)
        {
            // cout<<"i: "<<i<<endl;
            node* temp=oldTable[i];
            while(temp!=NULL)
            {
                string key=temp->key;
                // cout<<"key: "<<key<<endl;
                int val=temp->val;
                insert(key,val);
                temp=temp->next;
            }
            // temp=oldTable[i];
            // for( ; temp!=NULL;temp=temp->next)
            // {
            //     cout<<temp->key<<" ";
            // }
            // cout<<endl;
            temp=oldTable[i];
            delete(temp);
        }
        // cout<<"in rehash"<<endl;
        // print();
        delete[] oldTable;
    }

    pair<string,int> find(string key)
    {
        int idx=hashFunction(key);
        node* temp=table[idx];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return {key,temp->val};
            }
        }
        return {"junk",-1};
    }

};

int main()
{
    hashTable H(7);

    H.insert("burger",150);
    H.print();
    // return 0;
    cout<<"--------------------"<<endl;

    H.insert("pizza",350);
    H.print();
    cout<<"--------------------"<<endl;
    
    H.insert("cholebathure",200);
    H.print();
    cout<<"--------------------"<<endl;

    H.insert("abcd",393);
    H.print();
    
    cout<<"--------------------"<<endl;

    H.insert("abbc",3993);
    H.print();
    
    cout<<"--------------------"<<endl;

    H.insert("abric",23);
    H.print();
    
    cout<<"--------------------"<<endl;

    H.insert("kartik",200);
    H.print();


    cout<<"--------------------"<<endl;
    H.insert("kunj",150);
    H.print();
    
    cout<<"--------------------"<<endl;

    H.insert("abcjsjs",303);
    H.print();


    cout<<"--------------------"<<endl;

    cout<<H.find("pizza").second<<endl;
    cout<<H.find("lasagna").second<<endl;


    return 0;
}