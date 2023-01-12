#include<iostream>
using namespace std;
void test_case()
{
	int M,N; cin>>M>>N;
	int turn=1; 
	// if turn=1, it means ayush has to move,
	// if turn=2, it means harshit has to move

	int kitne=1;

	while(1)
	{
		if(turn==1)
		{
			if(kitne<=M)
			{
				M-=kitne;
			}
			else
			{
				cout<<"Harshit"<<endl;
				return ;
			}
		}
		else
		{	
			if(kitne<=N)
			{
				N-=kitne;

			}
			else
			{
				cout<<"Aayush"<<endl;
				return ;
			}
		}
		turn=3-turn;
		kitne++;
	}
}

int main() {

	int t; cin>>t;
	while(t--)
	{
		test_case();
	}

	return 0;
}