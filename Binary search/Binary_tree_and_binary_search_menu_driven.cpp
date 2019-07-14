/*
Date : 13th July,2019
By Uddesh Shankar Sonawane

Problem statement: Parallel Search Algorithm-
				Design and implement parallel algorithm utilizing all resources available. for
				* Binary Search for Sorted Array
				* Depth-First Search ( tree or an undirected graph ) OR
				* Breadth-First Search ( tree or an undirected graph) OR
				* Best-First Search that ( traversal of graph to reach a target in the shortest possible path)

			Depth First Search can be implemented in 3 ways.  1] Inorder    (PERFORMED IN THIS CODE)
													2] Preorder
													3] Postorder
*/


#include<iostream>
using namespace std;

//------------------------  BINARY SEARCH -------------------------
int checkbinary_search(int arr[], int start, int end, int search)    
{
	if(end>=start)
	{
		int mid = start + (end - start) / 2;
		if (arr[mid] == search)     // element found at mid position
            		return mid;	
            	if (arr[mid] > search)     // search element on 
            		return checkbinary_search(arr, start, mid - 1, search);	
            	return checkbinary_search(arr, mid + 1, end, search); 
            	cout<<"\n**";
	}
	return -1;  // terminating condition. If element is not present in array then only we reach here
}
//-----------------------------------------------------------BINARY SEARCH END


//---------------------  STRUCTURE DEFINATION ---------------------
struct node
{
	int data;
	struct node *left=NULL, *right=NULL;
}; 
//------------------------------------------------------------STRUCTURE DEFINATION END


//--------------------  INORDER TRAVERSAL OF BINARY TREE -------------
void inorderTraversal(node* root) 
{ 
    if (root) 
    {
        inorderTraversal( root->left ); 
        cout << root->data << " "; 
        inorderTraversal( root->right ); 
    } 
}
//-------------------------------------------------------------INORDER TRAVERSAL OF BINARY TREE END


//------------------  BINARY TREE CREATION  ------------------------------
node* create_Binary_Tree()
{
	node *temp, *treeroot=NULL, *root;
	int temp_data;
	while(1)
	{
		cout<<"\nEnter data : ";
		cin>>temp_data;
		if(temp_data==-1)
		{
			break;
		}
		else
		{
			temp=new node;            // creation of new node dynamically
			temp->data=temp_data;
			temp->left=temp->right=NULL;
			
			if(treeroot==NULL)    
			{
				treeroot=temp;
				cout<<"\nroot updated";     //executed only once
			}
			else
			{
				root=treeroot;
				while(1)               // infinite loop terminates only when we insert a node in tree at appropriate position
				{
					if(temp_data<root->data)   // left subtree traversal
					{
						if(root->left==NULL)
						{
							root->left=temp;
							cout<<"\nnode added to left";
							break;
						}
						else
							root=root->left;
					}
				
					if(temp_data>root->data)    // right subtree traversal
					{
						if(root->right==NULL)
						{
							root->right=temp;
							cout<<"\nnode added to right";
							break;
						}
						else
							root=root->right;
					}	
				}// end of nested while
			}
		}
	}
	return treeroot;
}
//-----------------------------------------------------------------BINARY TREE CREATION END


//-----------------------  FUNCTOIN TO SEARCH ELEMENT  ---------------
void search_element(int element_to_search, node* treeroot)
{
	node *temp, *root;
	root=treeroot;
	int i=0;
	while(1)
	{
		if(root->data==element_to_search)
		{
			cout<<"\nelement '"<<element_to_search<<"' found after "<<i+1<<" searches";
			break;
		}	
		else if(element_to_search<root->data)
			root=root->left;
		else
			root=root->right;		

		i++;
	}
}
//---------------------------------------------------------------SEARCH FUNCTOIN END


	
int main()
{
	cout<<"\nSelect appropriate option :\n\t1] Binary search on sorted array\n\t2] Create and perform search on binary tree\n\t -> press any key to exit\n";
	int choice;
	cin>>choice;
	if(choice==1)
	{
		int n;
		cout<<"\nEnter total number of elements : ";
		cin>>n;
		int arr[n];
		cout<<"\nEnter sorted elements ";
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<i+1<<": ";
			cin>>arr[i];
		}
	
		cout<<"\n*** The elements in array ***";
		for(int i=0;i<n;i++)
		{
			cout<<"\n"<<i+1<<" : "<<arr[i];
		}
	
		int tosearch;   
		cout<<"\nEnter element to be searched : ";
		cin>>tosearch;
		int check;
	
		check=checkbinary_search(arr,0,n, tosearch);     // Check will store the returned value by function 
		if(check==-1)
			cout<<"\nSorry, the element is not present in the array";
		else
			cout<<"\nElement found at position "<<check+1;
	}
	else if(choice==2)
	{
		cout<<"\nEnter the data to store in the binary tree ";
		cout<<"\nEnter '-1' to rpresent the end of insertion ";

		node *root=create_Binary_Tree();

		cout<<"\n|| Sorted list : ";
		inorderTraversal(root);         //to display the numbers in sorted order ascending	
		cout<<" ||";       

		int element_to_search;
		cout<<"\nEnter number to search : ";
		cin>>element_to_search;
		search_element(element_to_search,root);
	}
	
	cout<<"\n\nHave a nice day :)\n\n";
return 0;
}

/*

sample output

Select appropriate option :
	1] Binary search on sorted array
	2] Create and perform search on binary tree
	 -> press any key to exit
2

Enter the data to store in the binary tree 
Enter '-1' to rpresent the end of insertion 
Enter data : 5

root updated
Enter data : 6

node added to right
Enter data : 4

node added to left
Enter data : 8

node added to right
Enter data : 9

node added to right
Enter data : 2

node added to left
Enter data : -1

|| Sorted list : 2 4 5 6 8 9  ||
Enter number to search : 6

element '6' found after 2 searches

Have a nice day :)

-------------------------------------------------------


Select appropriate option :
	1] Binary search on sorted array
	2] Create and perform search on binary tree
	 -> press any key to exit
1

Enter total number of elements : 6

Enter sorted elements 
1: 1

2: 2

3: 3

4: 4

5: 5

6: 6

*** The elements in array ***
1 : 1
2 : 2
3 : 3
4 : 4
5 : 5
6 : 6
Enter element to be searched : 4

Element found at position 4

Have a nice day :)


*/
