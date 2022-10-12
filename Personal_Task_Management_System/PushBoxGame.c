#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> 
#include <ctype.h>

int main(){
	char stage[50][50]={"        ######## ",
					    "        #     S# ",
					    "        # O#O ## ",
					    "        # O  O#  ",
					    "        ##O O #  ",
					    "######### O # ###",
					    "#****  ## O  O  #",
					    "##***    O  O   #",
					    "#****  ##########",
					    "########         "
	};
	for(int i=0;i<=9;i++){
		puts(stage[i]);
	} 		
	int y=1;
	int x=14;
	char ch;
	while(stage[6][1]=='*'||stage[6][2]=='*'||stage[6][3]=='*'||stage[6][4]=='*'||
		  stage[7][2]=='*'||stage[7][3]=='*'||stage[7][4]=='*'||
		  stage[8][1]=='*'||stage[8][2]=='*'||stage[8][3]=='*'||stage[8][4]=='*'||
		  stage[6][1]=='s'||stage[6][2]=='s'||stage[6][3]=='s'||stage[6][4]=='s'||
		  stage[7][2]=='s'||stage[7][3]=='s'||stage[7][4]=='s'||
		  stage[8][1]=='s'||stage[8][2]=='s'||stage[8][3]=='s'||stage[8][4]=='s'){
		ch = tolower(getch());
		if(ch == 'w'){
			if(stage[y-1][x]==' '&&stage[y][x]=='S'){//moving to a blank space
				stage[y][x]=' ';
				y--;
				stage[y][x]='S';
			}
			else if(stage[y-1][x]=='O'&&stage[y-2][x]==' '){//pushing O into blank
				if (stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				y--;
				stage[y][x]='S';
				stage[y-1][x]='O';
			}
			else if(stage[y-1][x]=='O'&&stage[y-2][x]=='*'){//pushing O into *
				if(stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				y--;
				stage[y][x]='S';
				stage[y-1][x]=' ';                
			}
			else if(stage[y-1][x]=='*'&&stage[y][x]=='S'){//entering * area
				stage[y][x]=' ';
				y--;
				stage[y][x]='s';
			}
			else if(stage[y-1][x]=='*'&&stage[y][x]=='s'){//moving in * area
				stage[y][x]='*';
				y--;
				stage[y][x]='s';
			}
			else if(stage[y-1][x]==' '&&stage[y][x]=='s'){//exiting * area
				stage[y][x]='*';
				y--;
				stage[y][x]='S';
			}
		}
		if(ch == 'a'){
			if(stage[y][x-1]==' '&&stage[y][x]=='S'){
				stage[y][x]=' ';
				x--;
				stage[y][x]='S';
			}
			else if(stage[y][x-1]=='O'&&stage[y][x-2]==' '){
				if (stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				x--;
				stage[y][x]='S';
				stage[y][x-1]='O';
			}
			else if(stage[y][x-1]=='O'&&stage[y][x-2]=='*'){
				if(stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				x--;
				stage[y][x]='S';
				stage[y][x-1]=' ';
			}
			else if(stage[y][x-1]=='*'&&stage[y][x]=='S'){
				stage[y][x]=' ';
				x--;
				stage[y][x]='s';
			}
			else if(stage[y][x-1]=='*'&&stage[y][x]=='s'){
				stage[y][x]='*';
				x--;
				stage[y][x]='s';
			}
			else if(stage[y][x-1]==' '&&stage[y][x]=='s'){
				stage[y][x]='*';
				x--;
				stage[y][x]='S';
			}
		}
		if(ch == 's'){
			if(stage[y+1][x]==' '&&stage[y][x]=='S'){
				stage[y][x]=' ';
				y++;
				stage[y][x]='S';
			}
			else if(stage[y+1][x]=='O'&&stage[y+2][x]==' '){
				if (stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				y++;
				stage[y][x]='S';
				stage[y+1][x]='O';
			}
			else if(stage[y+1][x]=='O'&&stage[y+2][x]=='*'){
				if(stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				y++;
				stage[y][x]='S';
				stage[y+1][x]=' ';
			}
			else if(stage[y+1][x]=='*'&&stage[y][x]=='S'){
				stage[y][x]=' ';
				y++;
				stage[y][x]='s';
			}
			else if(stage[y+1][x]=='*'&&stage[y][x]=='s'){
				stage[y][x]='*';
				y++;
				stage[y][x]='s';
			}
			else if(stage[y+1][x]==' '&&stage[y][x]=='s'){
				stage[y][x]='*';
				y++;
				stage[y][x]='S';
			}
		}
		if(ch == 'd'){
			if(stage[y][x+1]==' '&&stage[y][x]=='S'){
				stage[y][x]=' ';
				x++;
				stage[y][x]='S';
			}
			else if(stage[y][x+1]=='O'&&stage[y][x+2]==' '){
				if (stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				x++;
				stage[y][x]='S';
				stage[y][x+1]='O';
			}
			else if(stage[y][x+1]=='O'&&stage[y][x+2]=='*'){
				if(stage[y][x]=='s')stage[y][x]='*';
				else stage[y][x]=' ';
				x++;
				stage[y][x]='S';
				stage[y][x+1]=' ';
			}
			else if(stage[y][x+1]=='*'&&stage[y][x]=='S'){
				stage[y][x]=' ';
				x++;
				stage[y][x]='s';
			}
			else if(stage[y][x+1]=='*'&&stage[y][x]=='s'){
				stage[y][x]='*';
				x++;
				stage[y][x]='s';
			}
			else if(stage[y][x+1]==' '&&stage[y][x]=='s'){
				stage[y][x]='*';
				x++;
				stage[y][x]='S';
			}
		}
	system("cls");
	for(int i=0;i<=9;i++){
		puts(stage[i]);
	}
	}
	printf("you win!");
	for(int i=1;i<=3;i++){
		system("color 10");
		Sleep(250);
		system("color 20");
		Sleep(250);
		system("color 30");
		Sleep(250);
		system("color 40");
		Sleep(250);
		system("color 50");
		Sleep(250);
		system("color 60");
		Sleep(250);
	}
	system("color 07");
	return 0;	
}