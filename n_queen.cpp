#include<bits/stdc++.h>
using namespace std;
bool is_safe(int **arr,int x,int y,int N)
{
	//column wise
	for(int r=0;r<x;r++)
	{
		if(arr[r][y]==1)
		{
			return false;
		}
	}
	//diagonal wise
	int row=x;
	int col=y;
	while(row>=0 && col>=0)
	{
		if(arr[row][col]==1)
		{
			return false;
		}
		row--;
		col--;
	}
	
	int row1=x;
	int col1=y;
	while(row1>=0 && col1<N)
	{
		if(arr[row1][col1]==1)
		{
			return false;
		}
		row1--;
		col1++;
	}
	return true;
}
bool n_queen(int **arr,int row,int N)
{
	if(row>=N)
	{
		return true;
	}
	for(int col=0;col<N;col++)
	{
		if(is_safe(arr,row,col,N)){
			
			arr[row][col]=1;
			if(n_queen(arr,row+1,N)){
				return true;
			}
			arr[row][col]=0;
		}
	}
	return false;
}
int main()
{
	int N;
	cout<<"Enter chess board size : ";
	cin>>N;
	int **arr=new int*[N]; //for rows
	for(int i=0;i<N;i++)
	{
		arr[i]= new int[N]; //for colms
		for(int j=0;j<N;j++)
		{
			arr[i][j]=0;
		}
	}
	if(n_queen(arr,0,N))
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<arr[i][j]<<" ";
			}
		cout<<endl;	
		}
	}
	else
	{
		cout<<"solution not found ";
	}
}
