#include<iostream>
using namespace std;

int main() {
int n;
cin >> n;

int i = n + 1;
while( i >= 2){

	int j = 1;
	while( j <= n + 1 - i){

    cout << "  ";
     j++;

	}

    j =	i - 1;
//cout<< " ";
while( j  >= 0){

	cout << j << " ";
	j= j - 1;
	//cout<<" ";
}
j = 1;
while( j <= i - 1){

	cout << j << " ";
	j++;

}
cout  << endl;
i = i - 1;
//cout<<" ";

}
i = 1;
 while( i <= n + 1){
	 int j = 1;

	 while( j <= n + 1 - i){
		 cout << "  ";
		 j++;
	 }
	 j = i - 1;
	 //cout<< " ";


	 while( j >= 0){

		 cout << j << " ";
		 j = j - 1;
	 }
	 j = 1;
	 while( j <= i - 1){

		 cout << j << " ";
		 j++;
	 }
		 cout  <<endl;
		 i++;
 }


	return 0;
}