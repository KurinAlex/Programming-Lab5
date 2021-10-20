#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void EnterInteger(int* num, const char* num_name)
{
	printf("Enter %s:\n", num_name);
	scanf_s("%d", num);
}

void OutputArray(int* array, int size, const char* array_name)
{
	printf("%s: ", array_name);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Sort(int* array, int size)
{
	for (int i = 1; i < size; i++)
	{
		int value = array[i];
		int j = i;
		while (j > 0 && value < array[j - 1])
		{
			array[j] = array[j - 1];
			j--;
		}
		array[j] = value;
	}
}

void GenerateSortedArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
	}
	Sort(array, size);
}

void MergeInSortedArray(int* A, int size_A, int* B, int size_B, int* C, int size_C)
{
	int it_C = 0;

	for (int it_A = 0; it_A < size_A; it_A++, it_C++)
	{
		C[it_C] = A[it_A];
	}
	for (int it_B = 0; it_B < size_B; it_B++, it_C++)
	{
		C[it_C] = B[it_B];
	}

	Sort(C, size_C);
}

int main()
{
	srand(time(NULL));

	int size_A;
	EnterInteger(&size_A, "size of A");

	int size_B;
	EnterInteger(&size_B, "size of B");

	int size_C = size_A + size_B;

	int* A = calloc(size_A, sizeof(int));
	GenerateSortedArray(A, size_A);
	OutputArray(A, size_A, "A");

	int* B = calloc(size_B, sizeof(int));
	GenerateSortedArray(B, size_B);
	OutputArray(B, size_B, "B");

	int* C = calloc(size_C, sizeof(int));
	MergeInSortedArray(A, size_A, B, size_B, C, size_C);
	OutputArray(C, size_C, "C");

	free(A);
	free(B);
	free(C);

	getch();
	return 0;
}