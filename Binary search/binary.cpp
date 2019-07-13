/*
Date : 13th July, 2019

Uddesh

Practical no 3: LP1 : Binary search on sorted array : this program will return the index at which the element is stored provided no duplicate elements

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
//----------------------   BINARY SEARCH END -----------------------


int main()
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
		
	return 0;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
Sample output:

Enter total number of elements : 8

Enter sorted elements 
1: 2

2: 6

3: 7

4: 8

5: 9

6: 10

7: 15

8: 80

*** The elements in array ***
1 : 2
2 : 6
3 : 7
4 : 8
5 : 9
6 : 10
7 : 15
8 : 80
Enter element to be searched : 8

Element found at position 4


*/
