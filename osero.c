/*�I�Z��PRO partII*/
#include<stdio.h>

#define WHITE 1
#define BLACK 2
#define BLANK 0
#define MASME 8
#define SUC 1
#define DEF 0
#define BLANK 0

int vertical[]={-1,-1,-1,0,1,1,1,0};
int cross[]={-1,0,1,1,1,0,-1,-1};
int colt[MASME][MASME];


//������
void init(int colt[][MASME])
{
	int i,j;
	
	//�Ֆʂ̏������Ɣz�u
	for(i=1;i<=MASME;i++)
	{
		for(j=1;j<=MASME;j++)
		{
			if(MASME/2==i&&MASME/2==j||MASME/2+1==i&&MASME/2+1==j)
			{
				//��
				colt[i][j]=WHITE;
			}
			else if(MASME/2+1==i&&MASME/2==j||MASME/2==i&&MASME/2+1==j)
			{
				//��
				colt[i][j]=BLACK;
			}
			else
			{
				//��
				colt[i][j]=BLANK;
			}
		}
	}
	show(colt);
}
//���Ԃ�����
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
				printf("��");	//WHITE
			}
			else if(colt[i][j]==BLACK)
			{
				printf("�Z");	//BLACK
			}
			else
			{
				printf("��");	//BLANK
			}
		}
		printf("\n");
	}
	
}
//���蔒
void checkwhite(int colt[][MASME],int x,int y)
{
	int i,j,k,num=0,a,b;
	
	while(1)
	{
		for(i=0;i<8;i++)
		{
			if(colt[x+vertical[i]][y+cross[i]]==BLACK)
			{
				for(j=1;j<8;j++)
				{
					a=vertical[i]*j;
					b=cross[i]*j;
					if(colt[x+a][y+b]==WHITE)
					{
						for(k=0;colt[x][y]!=colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)];k++)
						{
							colt[x+vertical[i]*(j-k)][y+cross[i]*(j-k)]=WHITE;
						}
						num+=1;
					}
				}
			}
		}
		if(num==1)
		{
			colt[x][y]=WHITE;
			break;
		}
		else
		{
			printf("�����ɂ͂����܂���\n");
		}
	}
}
//���荕
void checkblack(int colt[][MASME],int x,int y)
{
	int i,j,k,num=0,a,b;
	
	while(1)
	{
		for(i=0;i<8;i++)
		{
			if(colt[x+vertical[i]][y+cross[i]]==WHITE)
			{
				for(j=1;j<8;j++)
				{
					a=vertical[i]*j;
					b=cross[i]*j;
					if(colt[x+a][y+b]==BLACK)
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
			break;
		}
		else
		{
			printf("�����ɂ͂����܂���\n");
		}
	}
}
int main(void)
{
	int i,x,y;
	int flg=0;
	
	init(colt);
	
	for(i=1;i<=MASME*MASME/2;i++)
	{
		scanf("%d%d",&x,&y);
		
		flg^=1;
		//���荕�E��
		if(flg==0 ? checkwhite(colt,x,y):checkblack(colt,x,y))
		
		//���Ԃ�����
		show(colt);
	}
	
	return 0;
}
