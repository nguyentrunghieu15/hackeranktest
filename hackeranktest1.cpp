#include<stdio.h>
#include<time.h>
int n;
/* De bai la draw a square
input n
output a square

example:
input n=2
output
222
212
222
input n=4
output
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/
void ve_vong_so(int a[][100],int i); 


int main()
{
	clock_t start,end;
	printf("Nhap n:");
	scanf("%d",&n);  //Nhap n
	int a[2*n-1][2*n-1];
	start=clock();
//	ve_vong_so(a,n);
    for(int i=n;i>=1;i--)
    {
    	if(i==1)
			a[n-1][n-1]=1;
	else
	{
		a[n-i][n-i]=i;
		a[n+i-2][n+i-2]=i;
		for(int j=1;j<=2*(i-1);j++)
		{
			a[n-i][n-i+j]=i;
			a[n-i+j][n-i]=i;
			a[n+i-2-j][n+i-2]=i;
			a[n+i-2][n+i-2-j]=i;
		}
	}
}
	for(int i=0;i<2*n-1;i++)
	   {
	   	printf("\n");
	   	for(int j=0;j<2*n-1;j++)
	   	    printf("%5d",a[i][j]);
	   }
	   end=clock();
	   printf("\n%lf",double(end-start)/CLOCKS_PER_SEC);
	return 0;
}
void ve_vong_so(int a[][100], int i) // ve ra  vong thu i cua so i cho truoc
{
	if(i==1)
	{
		a[n-1][n-1]=1;
		return;
	}
	else
	{
		a[n-i][n-i]=i;
		a[n+i-2][n+i-2]=i;
		for(int j=1;j<=2*(i-1);j++)
		{
			a[n-i][n-i+j]=i;
			a[n-i+j][n-i]=i;
			a[n+i-2-j][n+i-2]=i;
			a[n+i-2][n+i-2-j]=i;
		}
		return  ve_vong_so(a,i-1);
	}
	  
}
