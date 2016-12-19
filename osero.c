/*オセロPRO partIII*/
#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define BLANK 0
#define MASME 8

int vertical[]={-1,-1,-1,0,1,1,1,0};
int cross[]={-1,0,1,1,1,0,-1,-1};
int colt[MASME][MASME];
int flg=0;


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
//裏返し処理
int show(int colt[][MASME])
{
	int i,j;
	
	for(i=0;i<MASME;i++)
	{
		printf(" %d",i+1);
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
//判定
void check(int colt[][MASME])
{
	int i,j,k,num=0,a,b,x,y;
	int s,t;
	char black[]="BLACK";
	char white[]="WHITE";
	
	flg ^= 1;
	
	s = (flg==0) ? BLACK:WHITE;
	t = (flg==0) ? WHITE:BLACK;
	
	while(1)
	{
		printf("%d",s);
		printf("%d\n",t);
		printf("%sの番：",flg==0?black:white);
		scanf("%d%d",&x,&y);
		
		for(i=0;i<8;i++)
		{
			if(colt[x+vertical[i]][y+cross[i]]==t)
			{
				for(j=1;j<8;j++)
				{
					a=vertical[i]*j;
					b=cross[i]*j;
					if(colt[x+a][y+b]==s)
					{
						for(k=0;colt[x][y]!=colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)];k++)
						{
							colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)]=s;
						}
						num+=1;
					}
				}
			}
		}
		if(num==1)
		{
			colt[x][y]=s;
			break;
		}
		else
		{
			printf("ここにはおけません\n");
		}
	}
}
int finish(int colt[][MASME])
{
	int i,j,num=0;
	
	for(i=0;i<MASME;i++)
	{
		for(j=0;j<MASME;j++)
		{
			if(colt[i][j]==BLANK)
			{
				num++;
			}
		}
	}
	return num;
}
int main(void)
{
	init(colt);
	
	while(1)
	{
		check(colt);
		show(colt);
		
		if(finish(colt)==0)
		{
			break;
		}
	}
	
	return 0;
}
