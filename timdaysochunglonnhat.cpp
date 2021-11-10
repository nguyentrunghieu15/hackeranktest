#include <bits/stdc++.h>
char a[201];
char b[201];
int **L;
char dynamic[201];
char max_number[201];
int couting[201];
int cout=0;
typedef struct extryme_point{
	int value;
	int x;
	int y;
}point;
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int swap(point &a,point &b)
{
	point c=a;
	a=b;
	b=c;
}
void gen_L(int m, int n)
{
	for(int i=0;i<=n;i++)
		L[0][i]=0;
	for(int i=0;i<=m;i++)
		L[i][0]=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1])
					L[i][j]=L[i-1][j-1]+1;
				else
					L[i][j]=max(L[i-1][j],L[i][j-1]);
			}
}
int check(int i,int j,int m,int n) // 0 la dung, 1 la lay, 2 la len , 3 la ngang,4 la lay dung
{
	if(j==n)
	{
		if(L[i][j]!=L[i-1][j]&&L[i][j]!=L[i][j-1])
			return 4;
		if(L[i][j]==L[i-1][j]&&L[i][j]!=L[i][j-1])
			return 2;
		if(L[i][j]==L[i-1][j]&&L[i][j]==L[i][j-1])
			return 2;
		return 0;
	}
	else{
		if(L[i][j]==L[i-1][j]&&L[i][j]!=L[i][j-1])
			return 2;
		if(L[i][j]!=L[i-1][j]&&L[i][j]!=L[i][j-1])
			return 1;
		if(L[i][j]!=L[i-1][j]&&L[i][j]==L[i][j-1])
			return 3;
		if(L[i][j]==L[i-1][j]&&L[i][j]==L[i][j-1])
			return 2;
	}
}
void get(point dinh[],int i,int j)
{
	dinh[cout].value=L[i][j];
	dinh[cout].x=i;
	dinh[cout].y=j;
	cout++;
}
void gen_Dinh(point dinh[],int m,int n)
{
	for(int c=n;c>=1;c--)
		{
			if(L[m][c]!=L[m][c-1])
			{
				int j=c;
				int i=m;
				int k=-1;
				while(k!=0)
				{
					k=check(i,j,m,n);
					switch(k)
					{
						case 1:{
							get(dinh,i,j);
							j++;
							break;
						}
						case 2:{
							i--;
							break;
						}
						case 3:{
							j++;
							break;
						}
						case 4:{
							get(dinh,i,j);
							k=0;
							break;
						}
					}
				}
			}
				
		}
}
void sort(point dinh[],int n)
{
	for(int i=1;i<n;i++)
		{
			int j=i;
			while(j>0&& dinh[j-1].value<dinh[j].value)
			{
				swap(dinh[j-1],dinh[j]);
				j--;
			}
		}
}
void dem(point dinh[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(dinh[i].value!=dinh[i+1].value)
			couting[dinh[i].value]=i;
	}
	couting[1]=n-1;
}
bool check_point(int i,int j,int c,int d)
{
	if(i<=c&&j<=d)
		return true;
	else return false;
}
void update_num()
{
	if(strcmp(dynamic,max_number)>0)
		strcpy(max_number,dynamic);
}
void Try(int k,point dinh[],int m,int n)
{
	for(int i=couting[k+1]+1;i<=couting[k];i++)
		{
			if(check_point(dinh[i].x,dinh[i].y,m,n))
			{
				dynamic[k-1]=a[dinh[i].x-1];
				if(k==1)
						update_num();
				else	Try(k-1,dinh,dinh[i].x-1,dinh[i].y-1);
			}
		}
}
void out_put()
{
	int n=strlen(max_number);
	char a[n+1];
	for(int i=0;i<n;i++)
		{
			if(max_number[i]!='0')
				{
					for(int j=i;j<n;j++)
							printf("%c",max_number[j]);
					return;
				}
		}
}
int main(){
	scanf("%s%s",&a,&b);
	clock_t start,end;
	start= clock();
	int m=strlen(a);
	int n=strlen(b);
	L=(int**)malloc(sizeof(int *)*(m+1));
	for(int i=0;i<=m;i++)
		L[i]=(int*)malloc(sizeof(int)*(n+1));
	gen_L(m,n);
	int max_len=L[m][n];
	printf("%d\n",max_len);
	couting[max_len+1]=-1;
	point dinh[m*n/10];
	gen_Dinh(dinh,m,n);
	sort(dinh,cout);
	dem(dinh,cout);
	Try(max_len,dinh,m,n);
	if(max_len==0)
		printf("NaN");
	else
	out_put();
	end=clock();
	printf("\n%lf",(double)(end-start)/CLOCKS_PER_SEC);
	for(int i=0;i<=m;i++)
		delete(L[i]);
	delete(L);
	return 0;
}
