#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void Position(int x, int y)
{
	// X와 y축을 설정하는 구조체입니다.
	COORD position = { x, y };

	// 콘솔 커서의 좌표를 설정하는 함수입니다.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}


#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

#define WIDTH 11
#define HEIGHT 11


int screenIndex;
HANDLE screen[2];

void Initialize()
{
	CONSOLE_CURSOR_INFO cursor;

	// 화면 버퍼를 2개 생성합니다.
	screen[0] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	screen[1] = CreateConsoleScreenBuffer
	(
		GENERIC_READ | GENERIC_WRITE,
		0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL
	);

	cursor.dwSize = 1;
	cursor.bVisible = FALSE;
	SetConsoleCursorInfo(screen[0], &cursor);
	SetConsoleCursorInfo(screen[1], &cursor);
}

void Flip()
{
	SetConsoleActiveScreenBuffer(screen[screenIndex]);

	//   0              1
	screenIndex = !screenIndex;


}

void Clear()
{

	COORD position = { 0, 0 };

	DWORD dword;

	FillConsoleOutputCharacter
	(
		screen[screenIndex], ' ', 50 * 20, position, &dword
	);

}

void Release()
{
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);

}

void Render(int x, int y, const char* string)
{
	DWORD dword;
	COORD position = { x, y };

	SetConsoleCursorPosition(screen[screenIndex], position);
	WriteFile(screen[screenIndex], string, strlen(string), &dword, NULL);

}

char maze[HEIGHT][WIDTH] = { {'2', '0', '1', '1', '1', '1' ,'1', '1', '1', '1', '1' },
							{'1', '0', '1', '0', '1', '1' ,'1', '1', '0', '1', '1' },
							{'1', '0', '1', '0', '0', '0' ,'1', '1', '0', '0', '1' },
							{'1', '0', '0', '0', '1', '0' ,'1', '0', '0', '0', '1' },
							{'1', '1', '1', '1', '1', '0' ,'1', '0', '1', '1', '1' },
							{'1', '0', '0', '0', '0', '0' ,'0', '0', '0', '1', '1' },
							{'1', '1', '1', '0', '1', '1' ,'1', '1', '0', '1', '1' },
							{'1', '0', '1', '0', '1', '1' ,'1', '1', '1', '1', '1' },
							{'1', '0', '0', '0', '0', '0' ,'0', '0', '0', '0', '1' },
							{'1', '1', '1', '0', '1', '1' ,'1', '1', '1', '0', '1' },
							{'1', '1', '1', '1', '1', '1' ,'1', '1', '1', '0', '2' } };

typedef struct
{
	int x;
	int y;
	const char* shape;

} Character;

int main()
{



	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (maze[i][j] == '1')
			{
				printf("■");
			}
			else if (maze[i][j] == '0')
			{
				printf("  ");
			}
			else
			{
				printf("⊙");
			}

		}
		printf("\n");

	}
	char key = 0;

	Character character = { 0,0,"★" };
		
	
	

	//Initialize();


	while (1)
	{
	
		//Flip();
	
		//Clear();
	
		key = _getch();
	
		if (key == -32)
		{
			key = _getch();
		}
	
	
		switch (key)
		{
		case UP:
			character.y--;
			break;
	
		case LEFT:
			character.x -= 2;
			break;
	
		case RIGHT:
			character.x += 2;
			break;
	
		case DOWN:
			character.y++;
			break;
	
		}
	
		Position(character.x, character.y);
		printf("%s",character.shape);
		
		//system("cls");
		
		// Render(x, y, "☆");
	}




	return 0;
}