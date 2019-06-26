/* LP 2 : HPC : multiply vector and matrix in parallel 
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

	int n1,n2,n3,ad;

	cout<<"\nEnter size the vectors";
	cin>>n1;
	
	cout<<"\nEnter number of rows and columns of matrix";
	cin>>n2>>n3;

	if(n1==n2)
	{
		vector<int> a1;        // vector declaration
		int a2[n2][n3];
		int a3[n1][n3];	
		
		int num1;
		cout<<"\nFirst Vector : ";
		for(int i=0;i<n1;i++)
		{
			num1=rand()%10;        // random values will get generated from 0-9
			a1.push_back(num1);    // syntax to store that element in vector
			cout<<num1<<"  ";
		}

		for(int i=0;i<n2;i++)
		{
			for(int j=0;j<n3;j++)
			{
				a2[i][j]=rand()%10;
				cout<<a2[i][j]<<"   ";
			}
			cout<<"\n";
		}

		cout<<"\nMultiplication is : \n";
		#pragma omp parallel for
		for(int i=0;i<1;i++)
		{
			#pragma omp parallel for
			for(int j=0;j<n3;j++)
			{
				a3[i][j]=0;
				for(int k=0;k<n2;k++)
				{
					a3[i][j]=a3[i][j]+(a1[k]*a2[k][j]);
				}
			}
		}

		for(int i=0;i<1;i++)
		{
			for(int j=0;j<n3;j++)
			{
				cout<<a3[i][j]<<"  ";
			}
			cout<<"\n";
		}	
	}
	else
	{
		cout<<"\nMultiplication is not possible";
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

Enter size the vectors2

Enter number of rows and columns of matrix2
3

First Vector : 3  6  7   5   3   
5   6   2   

Multiplication is : 
51  51  21  

Above addition operation took 0.004899 seconds to execute


*/
