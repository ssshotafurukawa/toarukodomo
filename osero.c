/*オセロPRO partII*/
#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define MASME 8
#define SUC 1
#define DEF 0

//初期化
void syokika(int bord[][MASME])
{
	int i,j;
	
	for(i=1;i<=MASME;i++)
	{
		for(j=1;j<=MASME;j++)
		{
			if(MASME/2==i&&MASME/2==j||MASME/2+1==i&&MASME/2+1==j)
			{
				//白
				bord[i][j]=1;
			}
			else if(MASME/2+1==i&&MASME/2==j||MASME/2==i||MASME/2+1==j)
			{
				//黒
				bord[i][j]=2;
			}
			else
			{
				//空白
				bord[i][j]=0;
			}
		}
	}
}
//判定
int hantei(int x,int y,bord[][MASME])
{
	while(1)
	{
		
}
//裏返し処理
int hyozi(int x,int y,bord[][MASME])
{
	int i;
	
	for(i=1;i<=MASME*MASME;i++)
	{
		

int main(void)
{
	
	int i,num;
	int bord[MASME][MASME];
	
	syokika(bord);
	
	for(i=1;i<=MASME*MASME;i++)
	{
		while(1)
		{
			scanf("%d%d",&x,&y)
			//判定
			num=hantei(x,y,bord);
			
			if(num==SUC)break;
		}
		//裏返し処理
		hyozi(x,y);
	}


