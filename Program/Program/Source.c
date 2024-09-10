#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Shuffle(int array[], int size)
{	
	
	int* ptr;
	int temp = 0;
	int ind = 0;

	for (int i = 0; i < size; i++)
	{
		
		ind = rand() % size;
		ptr = &array[i];

		temp = array[i];
		
		*ptr = array[ind];

		ptr = &array[ind];

		*ptr = temp;

	}

}

int main()
{

#pragma region 셔플 함수

	// srand(time(NULL));
	// 
	// //  0   1   2   3   4   5   6   7   8   9
	// // [1] [2] [3] [4] [5] [6] [7] [8] [9] [10]
	// int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	// 
	// int size = sizeof(list) / sizeof(int);
	// 
	// Shuffle(list, size);
	// 
	// printf("{ ");
	// for (int i = 0; i < size; i++)
	// {
	// 	printf("%d ", list[i]);
	// 
	// }
	// printf("}");

#pragma endregion

	
	const char* dialog[3];

	dialog[0] = "안녕하세요?";
	dialog[1] = "누구신가요?";
	dialog[2] = "탐정입니다.";

	for (int i = 0; sizeof(dialog) / sizeof(char*); i++)
	{
		printf("%s\n", dialog[i]);
	}

	return 0;
}