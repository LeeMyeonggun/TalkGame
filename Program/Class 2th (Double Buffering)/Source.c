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


char maze[HEIGHT][WIDTH] = { {'0', '0', '1', '1', '1', '1' ,'1', '1', '1', '1', '1' },
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

void Render()
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

}



typedef struct
{
	int x;
	int y;
	const char* shape;

} Character;

int main()
{
		
	char key = 0;

	Character character = {0, 0, "★"};
	
	Render();
	
	while (1)
	{

		if (_kbhit)
		{
			key = _getch();

			if (key == -32)
			{
				key = _getch();
			}
						
			switch (key)
			{
			case UP:
				if (maze[character.y - 1][character.x/2] != '1')
				{
					character.y--;
				}
				
				break;

			case LEFT:
				if (maze[character.y][character.x/2 - 1] != '1')
				{
					character.x -= 2;
				}
				
				break;

			case RIGHT:
				if (maze[character.y][character.x/2 + 1] != '1')
				{
					character.x += 2;
				}
				
				break;

			case DOWN:
				if (maze[character.y + 1][character.x/2] != '1')
				{
					character.y++;
				}
				
				break;

			}

			system("cls");

			Render();
		}

		if (maze[character.y][character.x / 2] == '2')
		{
			printf("Finish");
			break;
		}

		Position(character.x, character.y);
		printf("%s", character.shape);


				
	}

	

	return 0;
}