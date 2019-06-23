/*
Uddesh Shankar Sonawane
HPC Practicle 1 : perform matrix multiplication using parallel computing
date: 22nd June, 2019
OS : Linux Ubuntu
*/

#include <stdio.h>
#include<stdlib.h>
#include<omp.h>                //OpenMP (Open Multi-Processing) is an application programming interface (API) that supports multi-platform shared memory multiprocessing programming in C, C++, and Fortran. It consists of a set of compiler directives, library routines, and environment variables that influence run-time behavior.

int main()
{
	/*int a[3][3] = {  {0, 1, 2} ,   
 			 {4, 5, 6} ,   
  		         {8, 9, 10}};
	int b[3][3] = {  {0, 1, 2} ,   
                         {4, 5, 6} ,   
                         {8, 9, 10}};*/
	int n;
	printf("enter index of square matrix: ");
	scanf("%d",&n);
	
	int a[n][n];
	int b[n][n];
	int c[n][n];
     // int c[3][3];
	//int i,j,k;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=rand() % 50;    // rand() is used to generate random numbers  ||  %50 is used to restrict the selection of those random numbers form 0-50	
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i][j]=rand() % 50;
		}
	}

	#pragma omp parallel for      //The pragma omp parallel is used to fork additional threads to carry out the work enclosed in the construct in parallel. 
	for(int i=0;i<n;i++)
	{
		#pragma omp parallel for
		for(int j=0;j<n;j++)
		{
			c[i][j]=0;
			for(int k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
      
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",c[i][j]);
		}
	printf("\n");
	}
}


/*

execution command for parallel programming : gcc -fopenmp <filename.c>
                                             ./a.out
execution command for simple programming : gcc <filename.c>
                                             ./a.out

to know time of execution : time ls -r
*/
