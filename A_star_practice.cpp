#include<bits/stdc++.h>
#define N 3
using namespace std;
class Node{
	public:
		Node* parent;
		int grid[N][N];
		int x;
		int y;
		//These are the x and y coordinates of 0 
		// here instead of _ we are using 0 to indicate empty slide in the 3*3 puzzle
		int h_value=0;      //it is the count of missPlaced tiles
		int level=0;
		//huristic function is f(n)=h_value+level(g);
};



Node* set_grid(int current[N][N],int x,int y,int NewX,int NewY,int current_level,Node* parent) //Here x and y are old coordinates of empty slide and NewX and NewY are new coordinates of empty slide after moving it     
{
	Node* temp = new Node();
	temp->parent=parent;
	memcpy(temp->grid,current,sizeof temp->grid);  //copies the whole current matrix into grid
	swap(temp->grid[x][y],temp->grid[NewX][NewY]);  //see the figure ttt
	//changing the old coordinates of empty slide with its new coordinates
	temp->x=NewX;
	temp->y=NewY;
	temp->level=current_level;
	temp->h_value=INT_MAX;         //lower h_value is given high priority
	
	
}
int count_of_missPlaced_tiles(int current[N][N],int goal[N][N])
{
	int count=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(current[i][j] && current[i][j]!=goal[i][j])
			{
				count++;
			}
		}
	}
	return count;
}
struct check_priority{
	bool operator()(const Node* n1,const Node* n2) const
	{
		return (n1->h_value+n1->level) > (n2->h_value+n2->level) ;     //using operator overloading the arrange the nodes based of lower f value
		                                                               //where f= h_value+level
	}                                                                  // i.e highest priority is given to a node which has lowest f value
};

//for moving the empty slide in 4 directions
//{1,0}-for down     {-1,0}-for up  {0,-1}-for left  {0,1}-for right
//arrange in down left up right
int row[]={1,0,-1,0};
int col[]={0,-1,0,1};
bool valid_move(int move_x,int move_y)
{
	return ((move_x>=0 && move_x<N) && (move_y>=0 && move_y<N));     //if the x and y coordinates are inside the grid then the move is valid
}
void print_matrix(int mat[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
void solve(int current[N][N],int x,int y,int goal[N][N])
{
	Node* root= set_grid(current,x,y,x,y,0,NULL);  //it will copy the content of current matrix into grid(matrix) of a new object and return that new object (see class Node for understanding)
	root->h_value=count_of_missPlaced_tiles(current,goal);
	priority_queue<Node*,vector<Node*>,check_priority> pq;  //This is the syntax for storing Node pointers in priority queue
	 //Here we are storing the Nodes in the priority queue based on increasing value of f.       where f=h+level
	 // i.e highest priority is given to a node which has lowest f value
	//check_priority is a function in the form of struct to check the "f" value of node where f= h+level
	pq.push(root);
	while(!pq.empty())
	{
		Node* min=pq.top(); //it will give the matrix with least f value
		pq.pop();
		print_matrix(min->grid);
		cout<<endl;
		if(min->h_value==0)
		{
			return;      //if h_value of the matrix is 0 then it means all tiles are similar to goal matrix and hence its our soltion and we will stop
		}
		for(int i=0;i<4;i++)   //i goes from 0 to 3 because we have 4 valid moves down left up right
		{
			if(valid_move(min->x+row[i],min->y+col[i]))
			{
				Node* child= set_grid(min->grid,min->x,min->y,min->x+row[i],min->y+col[i],min->level+1,min);
				//we will copy the same parent matrix(temp->grid) into the child->grid just the change that
				// new x and y coordinates of empty slide(0) will be temp->x+row[i] and temp->y+col[i] respectively
				child->h_value= count_of_missPlaced_tiles(child->grid,goal);
				pq.push(child);
			}
		}
	}	
}
int main()
{
	int x,y;
	int start[N][N];
	int goal[N][N];
	cout<<"Enter the initial matrix : \n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>start[i][j];
			if(start[i][j]==0)
			{
				x=i;
				y=j;
				// x and y are the coordinates of empty slide 
				//as we have to start solving puzzle by moving the empty slide therefore we are taking its coordinates
			}
		}
	}
	cout<<"Enter the final matrix : \n";
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>goal[i][j];
		}
	}
	cout<<endl;
	solve(start,x,y,goal);
	return 0;
	
}
