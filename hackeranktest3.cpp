#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* tr, int n) {
	double array_area[n],t1;
    triangle t;
          for(int i=0;i<n;i++)
          {
              double p=tr[i].a+tr[i].b+tr[i].c;
              p=p/2;
              array_area[i]=sqrt(p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
        }
        for(int i=0;i<n;i++)
        {
    		printf("%lf\n",array_area[i]);
		}
        for(int i=1;i<n;i++)
        {
            int j=i;
            while(array_area[j]<array_area[j-1]&&j>0)
            {
                t1=array_area[j];
                array_area[j]=array_area[j-1];
                array_area[j-1]=t1;
                t=tr[j];
                tr[j]=tr[j-1];
                tr[j-1]=t;
                j--;
            }
        }
               for(int i=0;i<n;i++)
        {
    		printf("%lf\n",array_area[i]);
		}
              
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = (triangle*)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
