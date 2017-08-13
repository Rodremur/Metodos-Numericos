/*-------------------------------------------------------
 * Proyecto Final Matemáticas Computacionales: Laberinto
 * Fecha: 28-11-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */
#include <stdio.h>
#include <iostream>

void printMaze();
void moveForward(char * p);
void checkSides(char * p);

const int mazeheight = 10;
const int mazewidth = 12;
const char wall = '#';
const char free = ' ';
char facing;

class POS
{
public:
	int x;
	int y;
	POS(int n, int m)
	{
		x = n;
		y = m;
	}
	POS(const POS &a)
	{
		x = a.x;
		y = a.y;
	}
};


char maze[mazeheight][mazewidth+1] =
{
	"########## #",
	"#   #      #",
	"# # # ######",
	"# #   #  # #",
	"#  #####   #",
	"##   ### ###",
	"#  #  ##   #",
	"# ######## #",
	"#          #",
	"# ##########",
};

POS startp(1,9);
POS endp(10,0);
POS playerpos(startp);

int main(int argc, char const *argv[])
{
	facing = 'u';
	printMaze();
	while (maze[endp.y][endp.x] == ' ')
	{
		checkSides(&facing);
	}
	return 0;
}

void printMaze()
{
    getchar();
	for (int i = 0; i < mazeheight; i++)
	{
		printf("%s\n", maze[i]);
	}
	printf("\n");
}

void moveForward(char *p)
{
	switch(*p)
	{
		case 'u':
			if (maze[playerpos.y][playerpos.x] != ' ')
				maze[playerpos.y][playerpos.x] += 1;
            else maze[playerpos.y][playerpos.x] = '*';
			playerpos.y -= 1;
		break;
		case 'd':
			if (maze[playerpos.y][playerpos.x] != ' ')
				maze[playerpos.y][playerpos.x] += 1;
            else maze[playerpos.y][playerpos.x] = '*';
			playerpos.y += 1;
		break;
		case 'l':
			if (maze[playerpos.y][playerpos.x] != ' ')
				maze[playerpos.y][playerpos.x] += 1;
            else maze[playerpos.y][playerpos.x] = '*';
			playerpos.x -= 1;
		break;
		case 'r':
			if (maze[playerpos.y][playerpos.x] != ' ')
				maze[playerpos.y][playerpos.x] += 1;
            else maze[playerpos.y][playerpos.x] = '*';
			playerpos.x += 1;
		break;
	}
}

void checkSides(char *p)
{
		switch(*p)
	{
		case 'u':
			if (maze[playerpos.y][playerpos.x+1] == wall)
			{
				if (maze[playerpos.y-1][playerpos.x] == wall)
					*p = 'l';
				else
					moveForward(p);
					printMaze();
			} else {
			    *p = 'r';
			    moveForward(p);
                printMaze();
			}
		break;
		case 'd':
				if (maze[playerpos.y][playerpos.x-1] == wall)
			{
				if (maze[playerpos.y+1][playerpos.x] == wall)
					*p = 'r';
				else
					moveForward(p);
					printMaze();
			} else {
			*p = 'l';
			moveForward(p);
            printMaze();
			}
		break;
		case 'l':
				if (maze[playerpos.y-1][playerpos.x] == wall)
			{
				if (maze[playerpos.y][playerpos.x-1] == wall)
					*p = 'd';
				else
					moveForward(p);
					printMaze();
			} else {
                *p = 'u';
                moveForward(p);
                printMaze();
			}
		break;
		case 'r':
				if (maze[playerpos.y+1][playerpos.x] == wall)
			{
				if (maze[playerpos.y][playerpos.x+1] == wall)
					*p = 'u';
				else
					moveForward(p);
					printMaze();
			} else {
			    *p = 'd';
			    moveForward(p);
                printMaze();
			}
		break;
	}
}
