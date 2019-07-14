/*

Uddesh Shankar Sonawane
Date: 29th June, 2019
HPC: Practicle 2 : Parallel Sorting Algorithms-
			For Bubble Sort and Merger Sort, based on existing sequential algorithms, design and
			implement parallel algorithm utilizing all resources available.

*/

#include<iostream>
#include<omp.h>
#include<cstdlib>
#include<ctime>
using namespace std;

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	int L[n1], R[n2];       //create temp arrays 

	for (i = 0; i < n1; i++)         // Copy data to temp arrays L[] and R[] 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	// Merge the temp arrays back into arr[l..r]
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	// Copy the remaining elements of L[], if there are any 
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	//Copy the remaining elements of R[], if there are any 
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = l+(r-l)/2;     // Same as (l+r)/2, but avoids overflow for large l and h 

		#pragma omp parallel     // Sort first and second halves in parallel
		{
			mergeSort(arr, l, m); 
			mergeSort(arr, m+1, r);
		}
		merge(arr, l, m, r); 
	} 
} 

void bubble_sort(int a[], int n)
{
	int stp=0, temp;
	do
	{
		#pragma omp parallel for
		for(int i=0;i<n-1;i=i+2)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}

		#pragma omp parallel for
		for(int i=1;i<n-1;i=i+2)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
			}
		}
		stp++;
	}while(stp!=n);
}

int main()
{
	clock_t start, end;
	double cpu_time_used;
	start = clock(); // stores the no of clock pulses at this point of time

	int n;
	cout<<"\nEnter number of elements to be sorted";
	cin>>n;

	cout<<"\nEnter the elements";
	int a[n];
	/*for(int i=0;i<n;i++)
	{
		cout<<"\nNumber "<<i+1<<" : ";
		cin>>a[i];
	}*/

	for(int i=0;i<n;i++)
	{
		a[i]=rand()%10;
	}

	cout<<"\nGiven Numbers are: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"] : "<<a[i]<<"\n";
	}

	int choice;
	do
	{
		cout<<"\nEnter your choice :\n\t1] Bubble Sort\n\t2] Merge Sort\n\t0] Exit";
		cin>>choice;

		if(choice== 1)
		{
			bubble_sort(a,n);	
		}
		else if(choice==2)
		{
			mergeSort(a, 0, n- 1);           //n array size
		}
		else
		{
			cout<<"\nEnter valid option \n";
		}
	}while(choice!=0);
	
	cout<<"\nSorted Numbers are: \n";
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"] : "<<a[i]<<"\n";
	}
	end = clock(); // note clock pulses occured till this point
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; //total clock pulses occured divided by clock pulses in one second
	cout<<"\nAbove sorting operation took "<<cpu_time_used<<" seconds to execute along with delays";
	cout<<"\n";
	
return 0;
}

/*
Sample output

captain@sunny-System-Product-Name:~/Downloads$ g++ -fopenmp bubble.cpp
captain@sunny-System-Product-Name:~/Downloads$ ./a.out

Enter number of elements to be sorted10

Enter the elements
Given Numbers are: 
a[0] : 3
a[1] : 6
a[2] : 7
a[3] : 5
a[4] : 3
a[5] : 5
a[6] : 6
a[7] : 2
a[8] : 9
a[9] : 1

Enter your choice :
	1] Bubble Sort
	2] Merge Sort
	0]Exit2

Enter your choice :
	1] Bubble Sort
	2] Merge Sort
	0]Exit0

Enter valid option 

Sorted Numbers are: 
a[0] : 1
a[1] : 2
a[2] : 3
a[3] : 3
a[4] : 5
a[5] : 5
a[6] : 6
a[7] : 6
a[8] : 7
a[9] : 9

Above addition operation took 0.004696 seconds to execute


*/
