/* LP 2 : HPC : Vector adddition in parallel 
Uddesh Shankar Sonawane
Date: 26th June,2019
*/

#include<iostream>
#include<omp.h>            //openmp library
#include<vector>           // to use functionality of vectors
#include<cstdlib>          // for rand() function
#include<ctime>            // to use system clock
using namespace std;

int main()
{
	clock_t start, end;
	double cpu_time_used; 
	start = clock();          // stores the no of clock pulses at this point of time

	vector<int> a1;        // vector declaration
	vector<int> a2;
	vector<int> a3;
	int n1,n2,ad;

	cout<<"\nEnter sizes of both the vectors";
	cin>>n1>>n2;
	
	int num1, num2;
	cout<<"\nFirst Vector : ";
	for(int i=0;i<n1;i++)
	{
		num1=rand()%10;        // random values will get generated from 0-9
		a1.push_back(num1);    // syntax to store that element in vector
		cout<<num1<<"  ";
	}

	cout<<"\nSecond Vector : ";
	for(int i=0;i<n2;i++)
	{
		num2=rand()%10;
		a2.push_back(num2);
		cout<<num2<<"  ";
	}
	
	int n3;
	if(n1>n2)         // check whether which vector has more number of elements
	{
		for(int i=n2;i<n1;i++)
		{
			a1.push_back('0');   // store 0 in that extended array
		}
		n3=n1;
	}
	else
	{
		for(int i=n1;i<n2;i++)
		{
			a2.push_back('0');
		}
		n3=n2;
	}

	cout<<"\nAddition of vectors: ";
	#pragma omp parallel for            // call to parallel processing
	for(int i=0;i<n3;i++)
	{
		ad=a1[i]+a2[i];
		a3.push_back(ad);
		cout<<a3[i]<<"  ";	
	}
	
	end = clock();               // note clock pulses occured till this point
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;      //total clock pulses occured divided by clock pulses in one second
	cout<<"\nAbove addition operation took "<<cpu_time_used<<" seconds to execute"; 
	cout<<"\n";
return 0;
}

/*
output: g++ -o gfg -fopenmp vect_add.cpp    ( object file creation is optional. you can do directly as : g++ -fopenmp <file_name>)
	./a.out
to know time of execution : time ls -r

sample output

Enter sizes of both the vectors10
12

First Vector : 3  6  7  5  3  5  6  2  9  1  
Second Vector : 2  7  0  9  3  6  0  6  2  6  1  8  
Addition of vectors: 5  13  7  14  6  11  6  8  11  7  1  8  
Above addition operation took 0.000215 seconds to execute


*/
