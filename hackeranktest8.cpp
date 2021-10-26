#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap_string(char *a, char *b)
{
    char c[100];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}
void sort_deincreasing(int n, int point, char **s)
{
    for(int i=point+1;i<n;i++)
    {
        int j=i;
        while(j>point && strcmp(s[j-1], s[j])>0)
        {
            swap_string(s[j-1], s[j]);
            j--;
        }
    }
}
int next_permutation(int n, char **s)
{
        int j=n-1;
        while(strcmp(s[j],s[j-1])<=0)
            {
                j--;
                if(j==0)
                    return 0;
            }
        int i=j-1;
        for(int j=n-1; j>i;j--)
            if(strcmp(s[j],s[i])>0)
               {
                   swap_string(s[i],s[j]);
                   break;
               }
        sort_deincreasing(n,i+1,s);
        return 1;        
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = (char **)calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = (char*)calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
