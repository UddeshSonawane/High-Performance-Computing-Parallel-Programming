/*
Uddesh Shankar Sonawane
Date: 17th July, 2019

Problem Statement : K Nearest Neighbours (KNN)

*/


#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

int main()
{
	cout<<"\nEnter the coordinate points of a node along with Y/N";
	int n;
	cout<<"\n\nEnter total number of points :";
	cin>>n;
	int points[n][2];
	char array[n];
	int sorted[n];    // this array will be needed while sorting
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nX-Coordinate : ";
		cin>>points[i][0];
		cout<<"\nY-Coordinate : ";
		cin>>points[i][1];
		cout<<"\nHaving any criminal record? ";
		cin>>array[i];
		sorted[i]=i+1;
	}
	
	cout<<"\n******  The data available  ******";
	
	cout<<"\n\nID\tX-Co.\tY-Co.\tCriminal record";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<i+1<<"]\t"<<points[i][0]<<"\t"<<points[i][1]<<"\t"<<array[i];
	}
	
	//-------------------------------------------------get data for new node which we need to inspect-------------------
	int X,Y;
	cout<<"\n\nEnter inspecting node values";
	cout<<"\nX-Coordinate : ";
	cin>>X;
	cout<<"\nY-Coordinate : ";
	cin>>Y;
	
	
	float distance[n], distance_copy[n];     //------------------declare array to store the values after calculating eucladian distance
	
	int temp1,temp2;
	float value;
	for(int i=0;i<n;i++)
	{
		temp1=points[i][0];
		temp2=points[i][1];
		
		temp1=(X-temp1)*(X-temp1);
		temp2=(Y-temp2)*(Y-temp2);
		temp1=temp1+temp2;
		value=sqrt(temp1);
		distance[i]=value;
		distance_copy[n]=value;
	}

	cout<<"\nDistance of the given test point from all other points is given as";
	cout<<"\nDistance \t ID";    //   to print the distance of a point from all other points
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<distance[i]<<"   from point   "<<i+1;
	}
	
	
	//--------------------------------------let's sort those distances in ascending order 
	
                            // bubble sort
	int stp=0, tempdata1, tempdata2;
	do
	{
		#pragma omp parallel for
		for(int i=0;i<n-1;i=i+2)
		{
			if(distance[i]>distance[i+1])
			{
				tempdata1=sorted[i];
				sorted[i]=sorted[i+1];
				sorted[i+1]=tempdata1;
				
				tempdata2=distance[i];
				distance[i]=distance[i+1];
				distance[i+1]=tempdata2;
			}
		}

		#pragma omp parallel for
		for(int i=1;i<n-1;i=i+2)
		{
			if(distance[i]>distance[i+1])
			{
				tempdata1=sorted[i];
				sorted[i]=sorted[i+1];
				sorted[i+1]=tempdata1;
				
				tempdata2=distance[i];
				distance[i]=distance[i+1];
				distance[i+1]=tempdata2;
			}
		}
		stp++;
	}while(stp!=n);  //------------------------end of bubble sort
	
	cout<<"\n\nDistances after sorting";
	cout<<"\nPoint ID\tDistance\tCriminal record";    //   to print the distance of a point from all other points
	for(int i=0,j;i<n;i++)
	{
		j=sorted[i];
		cout<<"\n"<<j<<")\t\t"<<distance[i]<<"\t\t"<<array[j-1];
	}
	
	cout<<"\nEnter the value of K for neighbours : ";
	int k,j;
	cin>>k;

	cout<<"\n\nSorted distances of K neighbours";
	cout<<"\nPoint ID\tDistance\tCriminal record";    //   to print the distance of a point from all other points
	for(int i=0,j;i<k;i++)
	{
		j=sorted[i];
		cout<<"\n"<<j<<")\t\t"<<distance[i]<<"\t\t"<<array[j-1];
	}

	char ch;
	int y_count=0, n_count=0;    //---------here onwards we are counting the Y and M values
	for(int i=0;i<k;i++)
	{
		j=sorted[i];
		ch=array[j-1];
		if(ch=='Y' || ch=='y')
			y_count++;
		else if(ch=='n' || ch=='N')
			n_count++;
	}
	
	
	//-----------here we predict the walue that new node should posses based on data of K Nearest Neighbours
	if(y_count>n_count)
	{
		cout<<"\n\nProof : Y_count="<<y_count<<",  N_count="<<n_count;
		cout<<"\nThe new node matches with the qualities 'Y' \n";
	}
	else
	{
		cout<<"\n\nProof : Y_count="<<y_count<<",  N_count="<<n_count;
		cout<<"\nThe new node matches with the qualities 'N' \n";
	}
	
return 0;
}


/*
Sample output

Enter the coordinate points of a node along with Y/N

Enter total number of points :4

X-Coordinate : 0

Y-Coordinate : 0

Having any criminal record? y

X-Coordinate : 1

Y-Coordinate : 2

Having any criminal record? y

X-Coordinate : 7

Y-Coordinate : 8

Having any criminal record? n

X-Coordinate : 6

Y-Coordinate : 6

Having any criminal record? n

******  The data available  ******

ID	X-Co.	Y-Co.	Criminal record
1]	0	0	y
2]	1	2	y
3]	7	8	n
4]	6	6	n

Enter inspecting node values
X-Coordinate : 5

Y-Coordinate : 4

Distance of the given test point from all other points is given as
Distance 	            ID
6.40312   from point   1
4.47214   from point   2
4.47214   from point   3
2.23607   from point   4

Distances after sorting
Point ID	Distance	Criminal record
4)		2.23607		n
2)		4		y
3)		4		n
1)		6		y
Enter the value of K for neighbours : 3


Sorted distances of K neighbours
Point ID	Distance	Criminal record
4)		2.23607		n
2)		4		y
3)		4		n

Proof : Y_count=1,  N_count=2
The new node matches with the qualities 'N'


*/
