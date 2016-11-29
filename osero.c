/*ƒIƒZƒPRO partII*/
#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define MASME 8
#define SUC 1
#define DEF 0

//‰Šú‰»
void syokika(int bord[][MASME])
{
	int i,j;
	
	for(i=1;i<=MASME;i++)
	{
		for(j=1;j<=MASME;j++)
		{
			if(MASME/2==i&&MASME/2==j||MASME/2+1==i&&MASME/2+1==j)
			{
				//”’
				bord[i][j]=1;
			}
			else if(MASME/2+1==i&&MASME/2==j||MASME/2==i||MASME/2+1==j)
			{
				//•
				bord[i][j]=2;
			}
			else
			{
				//‹ó”’
				bord[i][j]=0;
			}
		}
	}
}
//”»’è
int hantei(int x,int y,bord[][MASME])
{
	while(1)
	{
		
}
//— •Ô‚µˆ—
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
			//”»’è
			num=hantei(x,y,bord);
			
			if(num==SUC)break;
		}
		//— •Ô‚µˆ—
		hyozi(x,y);
	}


