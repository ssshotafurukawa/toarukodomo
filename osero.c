/*オセロPRO partII*/
#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define BLANK 0
#define MASME 8
#define SUC 1
#define DEF 0
#define BLANK 0

int vertical[]={-1,0,1,-1,1,-1,0};
int cross[]={-1,-1,-1,0,0,1,1};

//初期化
void init(int colt[][MASME])
{
	int i,j;
	
	//盤面の初期化と配置
	for(i=1;i<=MASME;i++)
	{
		for(j=1;j<=MASME;j++)
		{
			if(MASME/2==i&&MASME/2==j||MASME/2+1==i&&MASME/2+1==j)
			{
				//白
				colt[i][j]=WHITE;
			}
			else if(MASME/2+1==i&&MASME/2==j||MASME/2==i&&MASME/2+1==j)
			{
				//黒
				colt[i][j]=BLACK;
			}
			else
			{
				//空白
				colt[i][j]=BLANK;
			}
		}
	}
	show(colt);
}
//判定白
int checoowhite(int colt[][MASME],int x,int y)
{
	int i,j,k,num=0;
	
	for(i=0;i<=6;i++)
	{
		if(colt[x+vertical[i]][y+cross[i]]==BLACK)
		{
			//printf("%d  %d\n",x+vertical[i],y+cross[i]);
			for(j=1;j<=6;j++)
			{
				if(colt[x+vertical[i]*j][y+cross[i]*j]==WHITE)
				{
					//printf("%d   %d\n",x+vertical[i]*j,y+cross[i]*j);
					for(k=0;colt[x][y]!=colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)];k++)
					{
						colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)]=WHITE;
						//printf("%d  %d %d\n",j-k,vertical[i]*j-k,y+cross[i]*j-k);
					}
					num+=1;
				}
			}
		}
	}
	if(num==1)
	{
		colt[x][y]=WHITE;
		return SUC;
	}
	else
	{
		return DEF;
		printf("ここにはおけません\n");
	}
}
//判定黒
int checooblack(int colt[][MASME],int x,int y)
{
	int i,j,k,num=0;
	
	for(i=0;i<=6;i++)
	{
		if(colt[x+vertical[i]][y+cross[i]]==WHITE)
		{
			for(j=1;j<=6;j++)
			{
				if(colt[x+vertical[i]*j][y+cross[i]*j]==BLACK)
				{
					for(k=0;colt[x][y]!=colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)];k++)
					{
						colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)]=BLACK;
					}
					num+=1;
				}
			}
		}
	}
	if(num==1)
	{
		colt[x][y]=BLACK;
		return SUC;
	}
	else
	{
		return DEF;
		printf("ここにはおけません\n");
	}
}
//裏返し処理
int show(int colt[][MASME])
{
	int i,j;
	
	for(i=1;i<=MASME;i++)
	{
		printf(" %d",i);
	}
	printf("\n");
	for(i=1;i<=MASME;i++)
	{
		printf("%d",i);
		for(j=1;j<=MASME;j++)
		{
			if(colt[i][j]==WHITE)
			{
				printf("●");	//WHITE
			}
			else if(colt[i][j]==BLACK)
			{
				printf("〇");	//BLACK
			}
			else
			{
				printf("□");	//BLANK
			}
		}
		printf("\n");
	}
	
}
	
int main(void)
{
	
	int i;
	int numblack=0,numwhite=0;
	int colt[MASME][MASME];
	int x,y;
	
	init(colt);
	
	for(i=1;i<=MASME*MASME/2;i++)
	{
		while(1)
		{
			scanf("%d%d",&x,&y);
			//判定
			numwhite=checoowhite(colt,x,y);
			
			if(numwhite==SUC)
			{
				break;
			}
		}
		numwhite=0;
		//裏返し処理
		show(colt);
		while(1)
		{
			scanf("%d%d",&x,&y);
			//判定
			numblack=checooblack(colt,x,y);
			
			if(numblack==SUC)
			{
				break;
			}
		}
		numblack=0;
		show(colt);
	}
	
	return 0;
}
