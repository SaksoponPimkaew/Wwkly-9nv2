#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <math.h.>
struct number
{
	int x=0;
	int y=0;
	int pic=0;

}XO[27];
char ch[26];
char* cc=ch;
int k=0;
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void block() {
	for (int i = 1; i <= 11; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (i % 2 == 0 && i > 0 && i<12)
			{
				if (j%6==0)
				{
					gotoxy(j, i);
					printf("|");
				}
				
			}
			else {
				gotoxy(j, i);
				printf("-");
			}
		}		
	}
	gotoxy (0, 15);
}
void xo() {
	int r = 1,v=2;
	for (int i = 0; i < 26; i++)
	{
		XO[i].x = 3+6*(r-1);
		r++;
		XO[i].y = v;
		if (r==6)
		{
		r = 1;
		v += 2;
		}
		char a = 65 + i ;
		ch[i] = a;
		XO[i].pic = 0;
	}
}
void printxo() {
	for (int i = 0; i < 25; i++)
	{
		gotoxy(XO[i].x, XO[i].y);
		printf("%c", ch[i]);
	}
	gotoxy(0, 13);
}
void winner() {
	gotoxy(0, 20);
	if (XO[0].pic* XO[6].pic* XO[12].pic* XO[18].pic* XO[24].pic==-1)
	{
		printf("Player O Won !!!");
		xo();
		system("pause");
	}
	else if (XO[4].pic * XO[8].pic * XO[12].pic * XO[16].pic * XO[20].pic == -1)
	{
		printf("Player O Won !!!");
		xo();
		system("pause");
	}
	else if (XO[0].pic * XO[6].pic * XO[12].pic * XO[18].pic * XO[24].pic == 32)
	{
		printf("Player X Won X!!!");
		xo();
		system("pause");
	}
	else if (XO[4].pic * XO[8].pic * XO[12].pic * XO[16].pic * XO[20].pic == 32)
	{
		printf("Player X Won! X!!");
		xo();
		system("pause");
	}
	for (int i = 0; i < 25; i++)
	{
		if (XO[i].pic* XO[i+1].pic* XO[i+2].pic* XO[i+3].pic* XO[i+4].pic==-1 && i%5==0)
		{
			printf("Player O Won!!!");
			xo();
			system("pause");
		}
		else if (XO[i].pic * XO[i + 1].pic * XO[i + 2].pic * XO[i + 3].pic * XO[i + 4].pic == 32 && i % 5 == 0)
		{
			printf("Player X Won!!!");
			xo();
			system("pause");
		}
		else if (XO[i].pic * XO[i + 5].pic * XO[i + 10].pic * XO[i + 15].pic * XO[i + 20].pic == -1 && i % 5 == 0)
		{
			printf("Player O Won!!!");
			xo();
			system("pause");
		}
		else if (XO[i].pic * XO[i + 5].pic * XO[i + 10].pic * XO[i + 15].pic * XO[i + 20].pic == 32 && i % 5 == 0)
		{
			printf("Player X Won!!!");
			xo();
			system("pause");
		}
	}
	gotoxy(0, 13);
}
int main()
{
	int times = 1,cache;
	int player= -1;

	xo();
	while (ch[25] != 'z') {
		char g;
		times++;
		block();
		printxo();
		
		printf("Player %d Turn\n", abs(player));
		printf("Enter ASCII of A-Y Which You Want If not you lost:");
		scanf("%d", &cache);
		g = cache;



		


		if (XO[g - 65].pic == 0)
		{
			XO[g - 65].pic = player;

			if (player == -1)
			{

				player = 2;
				char a = 79;
				*(cc + g - 65) = a;
			}
			else {
				player = -1;
				char a = 88;
				*(cc + g - 65) = a;
			}
		}
		else{
			while (XO[g - 65].pic != 0) {
				printf("Enter ASCII of A-Y Which You Want Only Again!! :");


				scanf("%d", &cache);
				g = cache;

				if (XO[g-65].pic == 0) {
					XO[g - 65].pic = player;
					g = cache;
					if (player == -1)
					{

						player = 2;
						char a = 79;
						*(cc + g - 65) = a;
						break;
					}
					else {
						player = -1;
						char a = 88;
						*(cc + g - 65) = a;
						break;
					}
				}
			}
	}
		printxo();
		winner();
		system("cls");
	}
	
	return 0;
}

