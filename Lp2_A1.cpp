#include<bits/stdc++.h>
using namespace std;
class Node{
	int data;
	Node* left;
	Node* right;
	friend class Btree;
	
	Node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};

class Btree{
	public:
	Node* head;
	Btree()
	{
		head=NULL;
	}
	void set_root(Node* parent);
	Node* create_btree();
	void inorder(Node* root);
	int get_height(Node* root);
	void bfs_recursive(Node* root,int level);
};


void Btree::set_root(Node* parent)
{
	head=parent;
}
Node* Btree::create_btree()
{
		int d;
		cout<<"Enter the value of node or -1 for NULL : ";
		cin>>d;
		if(d==-1)
		{
			return NULL;
		}
		Node* parent = new Node(d);
		parent->left= create_btree();
		parent->right=create_btree();
		return parent;
}

//DFS traversal
void Btree::inorder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
		
}
int Btree::get_height(Node* root)
{
	queue<Node*> q1;
	int current_nodes;
	int height=-1;
	q1.push(root);
	while(!q1.empty())
	{
		current_nodes=q1.size();
		height++;
		while(current_nodes>0)
		{
			Node* temp = q1.front();
			q1.pop();
			//pushing the child nodes to the queue for each node at a particular level
			if(temp->left!=NULL)
			{
				q1.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				q1.push(temp->right);
			}
			current_nodes--;
		}
	}
	return height;
	
}
void Btree::bfs_recursive(Node* root,int level)
{
	if(root==NULL)
	{
		return;
	}
	if(level==0)
	{
		cout<<root->data<<" ";
	}
	else if(level>0)
	{
		bfs_recursive(root->left,level-1);
		bfs_recursive(root->right,level-1);
	}
}
int main()
{
	Btree b1;
	Node* temp= b1.create_btree();
	b1.set_root(temp);
	cout<<"Inorder traversal is : \n";
	b1.inorder(b1.head);
	
	cout<<endl;
	int h=b1.get_height(b1.head);
	cout<<"Height of tree is : "<<h<<endl;
	cout<<"BFS recursive is : \n";
	for(int level=0;level<=h;level++)
	{
		b1.bfs_recursive(b1.head,level);
	}
	return 0;
}
