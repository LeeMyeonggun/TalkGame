#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


#define SIZE 10


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
	
#pragma region 포인터 배열

	
	
	// int data = 10;
	// 
	// if (data % 2 == 0)
	// {
	// 	printf("%d는 짝수입니다.\n", data);
	// }
	// else
	// {
	// 	printf("%d는 홀수입니다.\n", data);
	// }

	
	 int cnt = 0;
	 
	 const char* dialog[SIZE];
	 
	 dialog[0] = "반갑습니다. 뭐든지 해결해주는 탐GPT 입니다.";
	 dialog[1] = "업무량이 너무 많은데 해결해 주실 수 있나요.";
	 dialog[2] = "물론이죠. 아래 프롬프트 창에 요구사항을 입력해주세요.";
	 dialog[3] = "칼퇴하고싶습니다.";
	 dialog[4] = "칼퇴할 수 있도록 하는 5가지 방법은 다음과 같습니다. 첫째...";
	 dialog[5] = "왜 말을 하다가 마시죠?.";
	 dialog[6] = "프롬프트 길이가 제한되어 있습니다. 계속하시려면 탐GPT plus를 결제해주세요.";
	 dialog[7] = "다른 탐정에게 찾아가겠습니다.";
	 dialog[8] = "네, 이용해주셔서 감사합니다. 다음에도 방문해주세요.";
	 dialog[9] = "다시는 오지 않을 겁니다.";
	 
	 while (1)
	 {
	 	// 0x0000 : 이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
	 	
	 	// 0x0001 : 이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
	 
	 	// 0x8000 : 이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
	 
	 	// 0x8001 : 이전에 누른 적이 있고 호출 시점에도 눌려있는 상태
	 
	 	if (GetAsyncKeyState(VK_SPACE) & 0x0001)
	 	{
	 					
	 		if (cnt % 2 == 0)
	 		{
	 			printf("[탐정] : %s\n", dialog[cnt]);
	 		}
	 		else
	 		{
	 			printf("[의뢰인] : %s\n", dialog[cnt]);
	 		}
	 		
	 		++cnt;
	 	}
	 
	 	if (cnt >= SIZE)
	 	{
	 		break;
	 	}
	 	
	 }
	 
	 Sleep(3000);
	 
	 printf("대화가 종료되었습니다.");

#pragma endregion

	return 0;
}