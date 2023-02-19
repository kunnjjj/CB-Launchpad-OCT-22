#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(10, vector<char>(10));
vector<vector<bool>> visited(10, vector<bool>(10));

int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

bool is_safe(int newX, int newY, int n, int m)
{
    return newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] != 'X' && visited[newX][newY] == 0;
}
bool ratChasesCheese(int i, int j, int n, int m)
{
    if (i == n - 1 && j == m - 1)
    {
        visited[i][j] = true;
        return true;
    }

    // UGLY METHOD
    // RIGHT
    // if(j+1<m && visited[i][j]==0 && board[i][j+1]!='X')
    // {

    // }
    // if(i-1>=0 &&....)
    // {

    // }
    // if(i+1<n && ...)
    // {

    // }

    // if(j-1>=0)
    // {

    // }

    visited[i][j]=true;

    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];
        if(is_safe(newX,newY,n,m) && ratChasesCheese(newX,newY,n,m))
        {
            return true;
        }
    }

    visited[i][j]=false;
    return false;
}

int main()
{
    int n,m; cin>>n>>m;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>board[i][j];

    if(ratChasesCheese(0,0,n,m))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"NO PATH FOUND"<<endl;
    }


    return 0;
}