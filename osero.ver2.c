/*オセロPRO partIII*/
#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define BLANK 0
#define MASME 8

int vertical[]={-1,-1,-1,0,1,1,1,0};
int cross[]={-1,0,1,1,1,0,-1,-1};

int vertical_leftUP[]={1,1,0};	//端に置いた場合のエラー防止
int cross_leftUP[]={0,1,1};
int vertical_rightUP[]={0,1,1};
int cross_rightUP[]={-1,-1,0};
int vertical_leftDOWN[]={-1,-1,1};
int cross_leftDOWN[]={0,1,1};
int vertical_rightDOWN[]={0,-1,-1};
int cross_rightDOWN[]={-1,-1,0};

int vertical_endX_1[]={0,1,1,1,0};
int cross_endX_1[]={-1,-1,0,1,1};
int vertical_endX_MASME[]={0,-1,-1,-1,0};
int cross_endX_MASME[]={-1,-1,0,1,1};
int vertical_endY_1[]={-1,-1,0,1,1};
int cross_endY_1[]={0,1,1,1,0};
int vertical_endY_MASME[]={-1,-1,0,1,1};
int cross_endY_MASME[]={0,-1,-1,-1,0};

int colt[MASME][MASME];
int flg=2;
int blackscore=0,whitescore=0;


//初期化
void init()
{
	int i,j;
	
	printf("\n打てる場所がないときは0 0と打ち込んでください。\n");
	//盤面の初期化と配置
	for(i=1;i<=MASME;i++)
	{
		for(j=1;j<=MASME;j++)
		{
			if((MASME/2==i&&MASME/2==j)||(MASME/2+1==i&&MASME/2+1==j))
			{
				//白
				colt[i][j]=WHITE;
			}
			else if((MASME/2+1==i&&MASME/2==j)||(MASME/2==i&&MASME/2+1==j))
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
int show()
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
void check()
{
	int i,j,k,num=0,a,b,x,y;
	int s,t;
	char black[]="BLACK";
	char white[]="WHITE";
	char *color[] = {"WHITE","BLACK"};
	
	t = flg;
	flg = (flg==WHITE) ? BLACK:WHITE;
	
	while(1)
	{
		printf("%sの番：",color[flg-1]);
		scanf("%d%d",&x,&y);
		
		if(x==0&&y==0)
		{
			break;
			printf("パスされました\n");
		}
		else if(colt[x][y]==0)		//すでに駒が打ってあった場合
		{
			if(x==1&&y==1)num=check_corner_leftUP(x,y,flg,t);
			else if(x==1&&y==MASME)num=check_corner_rightUP(x,y,flg,t);
			else if(x==MASME&&y==1)num=check_corner_leftDOWN(x,y,flg,t);
			else if(x==MASME&&y==MASME)num=check_corner_rightDOWN(x,y,flg,t);
			/*角以外の端のエラー防ぎ*/
			else if(x==1)num=check_cornerX_1(x,y,flg,t);
			else if(x==MASME)num=check_cornerX_MASME(x,y,flg,t);
			else if(y==1)num=check_cornerY_1(x,y,flg,t);
			else if(y==MASME)num=check_cornerY_MASME(x,y,flg,t);
			
			else
			{
				for(i=0;i<MASME;i++)
				{
					if(colt[x+vertical[i]][y+cross[i]]==t)
					{
						for(j=1;j<MASME;j++)
						{
							a=vertical[i]*j;
							b=cross[i]*j;
							if(colt[x+a][y+b]==flg)
							{
								for(k=0;colt[x][y]!=colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)];k++)
								{
									colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)]=flg;
									num=1;
								}
							}
						}
					}
				}
			}
		}
		
		if(num==1)
		{
			colt[x][y]=flg;
			show(colt);
			break;
		}
		else
		{
			printf("ここにはおけません\n");
		}
	}
}
/*角で起こるエラー対策*/
int check_corner_leftUP(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<3;i++)
	{
		if(colt[x+vertical_leftUP[i]][y+cross_leftUP[i]]==t)
		{
			for(j=1;j<8;j++)
			{
				a=vertical_leftUP[i]*j;
				b=cross_leftUP[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_leftUP[i]*(j-k)][y+cross_leftUP[i]*(j-k)];k++)
					{
						colt[x+vertical_leftUP[i]*(j-k)][y+cross_leftUP[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
int check_corner_rightUP(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<3;i++)
	{
		if(colt[x+vertical_rightUP[i]][y+cross_rightUP[i]]==t)
		{
			for(j=1;j<8;j++)
			{
				a=vertical_rightUP[i]*j;
				b=cross_rightUP[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_rightUP[i]*(j-k)][y+cross_rightUP[i]*(j-k)];k++)
					{
						colt[x+vertical_rightUP[i]*(j-k)][y+cross_rightUP[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
int check_corner_leftDOWN(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<3;i++)
	{
		if(colt[x+vertical_leftDOWN[i]][y+cross_leftDOWN[i]]==t)
		{
			for(j=1;j<8;j++)
			{
				a=vertical_leftDOWN[i]*j;
				b=cross_leftDOWN[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_leftDOWN[i]*(j-k)][y+cross_leftDOWN[i]*(j-k)];k++)
					{
						colt[x+vertical_leftDOWN[i]*(j-k)][y+cross_leftDOWN[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
int check_corner_rightDOWN(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<3;i++)
	{
		if(colt[x+vertical_rightDOWN[i]][y+cross_rightDOWN[i]]==t)
		{
			for(j=1;j<8;j++)
			{
				a=vertical_rightDOWN[i]*j;
				b=cross_rightDOWN[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_rightDOWN[i]*(j-k)][y+cross_rightDOWN[i]*(j-k)];k++)
					{
						colt[x+vertical_rightDOWN[i]*(j-k)][y+cross_rightDOWN[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
/*角以外の端処理*/
int check_cornerX_1(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<5;i++)
	{
		if(y+cross_endX_1[i]==1);
		else if(colt[x+vertical_endX_1[i]][y+cross_endX_1[i]]==t)
		{
			for(j=1;j<MASME;j++)
			{
				a=vertical_endX_1[i]*j;
				b=cross_endX_1[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_endX_1[i]*(j-k)][y+cross_endX_1[i]*(j-k)];k++)
					{
						colt[x+vertical_endX_1[i]*(j-k)][y+cross_endX_1[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
int check_cornerX_MASME(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<5;i++)
	{
		if(colt[x+vertical_endX_MASME[i]][y+cross_endX_MASME[i]]==t)
		{
			for(j=1;j<MASME;j++)
			{
				a=vertical_endX_MASME[i]*j;
				b=cross_endX_MASME[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_endX_MASME[i]*(j-k)][y+cross_endX_MASME[i]*(j-k)];k++)
					{
						colt[x+vertical_endX_MASME[i]*(j-k)][y+cross_endX_MASME[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
int check_cornerY_1(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<5;i++)
	{
		if(colt[x+vertical_endY_1[i]][y+cross_endY_1[i]]==t)
		{
			for(j=1;j<MASME;j++)
			{
				a=vertical_endY_1[i]*j;
				b=cross_endY_1[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_endY_1[i]*(j-k)][y+cross_endY_1[i]*(j-k)];k++)
					{
						colt[x+vertical_endY_1[i]*(j-k)][y+cross_endY_1[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
}
int check_cornerY_MASME(int x,int y,int flg,int t)
{
	int num=0,i,j,a,b,k;
	
	for(i=0;i<5;i++)
	{
		if(colt[x+vertical_endY_MASME[i]][y+cross_endY_MASME[i]]==t)
		{
			for(j=1;j<MASME;j++)
			{
				a=vertical_endY_MASME[i]*j;
				b=cross_endY_MASME[i]*j;
				if(colt[x+a][y+b]==flg)
				{
					for(k=0;colt[x][y]!=colt[x+vertical_endY_MASME[i]*(j-k)][y+cross_endY_MASME[i]*(j-k)];k++)
					{
						colt[x+vertical_endY_MASME[i]*(j-k)][y+cross_endY_MASME[i]*(j-k)]=flg;
						num=1;
					}
				}
			}
		}
	}
	return num;
} 
int finish()
{
	int i,j,num=0;
	
	for(i=1;i<=MASME;i++)
	{
		for(j=1;j<=MASME;j++)
		{
			if(colt[i][j]==BLANK)
			{
				num++;
			}
			else if(colt[i][j]==WHITE)
			{
				whitescore+=1;
			}
			else if(colt[i][j]==BLACK)
			{
				blackscore+=1;
			}
		}
	}
	return num;
}
void score()
{
	if(whitescore<blackscore)printf("黒の勝ちです！\n");
	else if(blackscore<whitescore)printf("白の勝ちです！\n");
	else printf("引き分けです\n");
}
int main(void)
{
	init(colt);
	
	while(1)
	{
		check();
		
		if(finish()==0)
		{
			score();
			break;
		}
	}
	
	return 0;
}
