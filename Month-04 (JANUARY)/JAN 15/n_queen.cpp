#include<iostream>
using namespace std;
int N=4;
int BOARD[10][10]={0};

bool is_safe(int row,int col)
{
    // VERTICAL
    for(int i=row;i>=0;i--)
    {
        if(BOARD[i][col]==1) return false;
    }

    // LEFT DIAGONAL
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(BOARD[i][j]==1) return false;
    }

    // RIGHT DIAGONAL
    for(int i=row,j=col;i>=0 && j<N;i--,j++)
    {
        if(BOARD[i][j]==1) return false;
    }
    return true;
}

bool nQueen(int row) // if I have placed some queens in 0...row-1, 
{                    //can i place queen this row onwards


    if(row==N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(BOARD[i][j]==1)
                {
                    cout<<"Q ";
                }
                else
                {
                    cout<<"- ";
                }
            }
            cout<<endl;
        }
        return true;
    }

    for(int col=0;col<N;col++)
    {
        if(is_safe(row,col))
        {
            BOARD[row][col]=1;
            bool res=nQueen(row+1);
            if(res==true) return true;
            BOARD[row][col]=0; // BACKTRACKING
        }
    }
    return false;
}

int main()
{
    nQueen(0);
    return 0;
}