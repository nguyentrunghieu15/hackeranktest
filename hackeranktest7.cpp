#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
     return strcmp(a, b)<=0?1:0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a,b)>=0?1:0;
}
int couting_character(const char *a)
{
    int n=0;
    int c[128];
    for(int i=0;i<128;i++)
    {
        c[i]=0;
    }
    for(int i=0;i<strlen(a);i++)
    {
        if(c[(int)a[i]]==0){
            c[(int)a[i]]++;
            n++;
        }
    }
    return n;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    if(couting_character(a)-couting_character(b)<0)
       return 1;
    else if(couting_character(a)-couting_character(b)>0)
       return 0;
    else
       return lexicographic_sort(a,b);
}

int sort_by_length(const char* a, const char* b) {
     if(strlen(a)==strlen(b))
        return lexicographic_sort(a, b);
     else {
        return strlen(a)>strlen(b)?0:1;
     }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
       for(int i=1;i<len;i++)
       {
           int j=i;
           while(j>0 && (cmp_func(arr[j-1],arr[j])==0))
           {
               char *temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
               j--;
           }
       }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
