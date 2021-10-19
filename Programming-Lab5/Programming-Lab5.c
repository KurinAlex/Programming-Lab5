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

void GenerateSortedArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand();
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

void CopyTo(int* A, int start_index_A, int end_index_A, int* B, int start_index_B)
{
	for (int it_A = start_index_A, it_B = start_index_B; it_A < end_index_A; it_A++, it_B++)
	{
		B[it_B] = A[it_A];
	}
}

void MergeInSortedArray(int* A, int size_A, int* B, int size_B, int* C, int size_C)
{
	int it_A = 0;
	int it_B = 0;
	int it_C = 0;

	for (; it_A < size_A && it_B < size_B; it_C++) //поки не пройдемо всі елементи одного із масивів
	{
		C[it_C] = (A[it_A] < B[it_B]) ? A[it_A++] : B[it_B++];
	}

	if (it_C != size_C) //у якомусь із масивів ще є непройдені елементи
	{
		if (it_A == size_A) //у масиві В ще є непройдені елементи
		{
			CopyTo(B, it_B, size_B, C, it_C);
		}
		else //у масиві А ще є непройдені елементи
		{
			CopyTo(A, it_A, size_A, C, it_C);
		}
	}
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