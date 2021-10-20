#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
int main()
{
     char* n_endptr;
     char* n_str = readline();
     int n = strtol(n_str, &n_endptr, 10);
     if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
    
    int a;
    scanf("%d", &a);
    if(a==1)
       printf("one");
    else if(a==2)
       printf("two");
    else if(a==3)
       printf("three");
    else if(a==4)
       printf("four");
    else if(a==5)
       printf("five");
    else if(a==6)
       printf("six");
    else if(a==7)
       printf("seven");
    else if(a==8)
       printf("eight");
    else if(a==9)
       printf("nine");
    else 
       printf("Greater than 9");
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = (char*)malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = (char*)realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = (char*)realloc(data, data_length);

    return data;
}

