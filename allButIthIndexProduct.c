#include <stdio.h>
#include <stdlib.h>

void calculateArrayAbove(int * above, int * input, int arrSize)
{
		above[arrSize-1] = 1; 
		above[arrSize-2] = input[arrSize-1]; 
		
		for(int i = arrSize-3; i >= 0; --i)
		{
			above[i] = input[i+1] * above[i+1]; 
		}
}

void calculateArrayBelow(int * below, int * input, int arrSize)
{
	below[0] = 1; 
	below[1] = input[0]; 
	
	for(int k = 2; k<arrSize; ++k)
	{
		 below[k] = input[k-1] * below[k-1]; 
	}
}

void allButIthIndexProduct(int arrSize, int * input,int * output)
{
	if(arrSize < 3)
	{
		printf("Error: Not a valid array size\n"); 
		exit(1); 
	}
	
	int below[arrSize]; 
	calculateArrayBelow(below, input, arrSize);
	int above[arrSize];
	calculateArrayAbove(above, input, arrSize); 
	

	for(int i = 0; i<arrSize; ++i)
	{
		output[i] = below[i] * above[i]; 
	}
}

int main()
{ 
	int arrSize = 5;
	int arr[] = {10,3,5,6,2};
	int output[arrSize]; 
	allButIthIndexProduct(arrSize, arr, output);

	return 0; 
}


































