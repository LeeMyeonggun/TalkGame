#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>


#define SIZE 10000

void Call(const char * fileName)
{

	char key = 0;

	if (_kbhit)
	{
		key = _getch();

		if (key == -32)
		{
			key = _getch();

		}

		if (key == 32)
		{

			FILE* file = fopen(fileName, "r");

			char buffer[SIZE] = { 0, };

			fread(buffer, 1, SIZE, file);

			printf("%s", buffer);

			fclose(file);

		}

	}
}



int main()
{

#pragma region ���� �����

#pragma region ���� ����
	
	// ù ��° �Ű����� (������ �̸�)
	// �� ��° �Ű����� (������ ����� ���)
	// FILE * file = fopen("data.txt", "w");
	// 
	// fputs("Character Information\n", file);
	// fputs("Health : \n", file);
	// fputs("Attack : \n", file);
	// fputs("Defense : \n", file);
	// 
	// fclose(file);


#pragma endregion

#pragma region ���� �б�
	
	

	// ù ��° �Ű����� : ���� �����͸� ������ �޸� ������ ������ ����
	// �� ��° �Ű����� : �� ������ �׸��� ũ��
	// �� ��° �Űܺ��� : �����͸� �о�� ������ �׸��� ��
	// �� ��° �Ű����� : �����͸� �о�� ������ ������ ����

	// Call("Pipebo2.txt");




		
#pragma endregion


#pragma endregion


	

	return 0;
}