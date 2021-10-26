#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#include <iostream>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
#include <ctype.h>
using namespace std;
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    char ****convert_document;
    int couting_paragraph=0,couting_sentence=0, couting_word=0, couting_char=0;
    int n=strlen(text);
    for(int i=0;i<=n;i++)
		if(text[i]=='\n'||text[i]=='\0')
                couting_paragraph++;  
    convert_document=(char****)malloc(sizeof(char ***)*couting_paragraph);
    couting_paragraph=0,couting_sentence=0, couting_word=0, couting_char=0;
    for(int i=0;i<=n;i++)
    {
       if(text[i]=='.')
           couting_sentence++;
        if(text[i]=='\n'||text[i]=='\0')
            {
                convert_document[couting_paragraph]=(char ***)malloc(sizeof(char **)*couting_sentence);
				couting_sentence=0;
                couting_paragraph++;  
            }
    }
    couting_paragraph=0,couting_sentence=0, couting_word=0, couting_char=0;
    for(int i=0;i<=n;i++)
    {
        if(text[i]==' ')
            couting_word++;
        if(text[i]=='.')
            {
                convert_document[couting_paragraph][couting_sentence]=(char**)malloc(sizeof(char*)*(couting_word+1));
				couting_word=0;
                couting_sentence++;
            }

        if(text[i]=='\n'||text[i]=='\0')
        {
            couting_sentence=0;
            couting_word=0;
            couting_paragraph++;         
        }
    }
    couting_paragraph=0,couting_sentence=0, couting_word=0, couting_char=0;
    for(int i=0;i<=n;i++)
    {
        if(isalpha(text[i]))
            couting_char++;
        if(text[i]==' ')
        {
            convert_document[couting_paragraph][couting_sentence][couting_word]=(char*)malloc(sizeof(char)*(couting_char+1));
            couting_word++;
            couting_char=0;
        }
        if(text[i]=='.')
        {
             convert_document[couting_paragraph][couting_sentence][couting_word]=(char*)malloc(sizeof(char)*(couting_char+1));
             couting_word=0;
             couting_char=0;
             couting_sentence++;
        }
        if(text[i]=='\n'||text[i]=='\0')
        {
            couting_paragraph++;
            couting_sentence=0;
            couting_word=0;
            couting_char=0;
        }
    }

    couting_paragraph=0,couting_sentence=0, couting_word=0, couting_char=0;
    for(int i=0;i<=n;i++)
    {
        
        if(isalpha(text[i]))
            {
                convert_document[couting_paragraph][couting_sentence][couting_word][couting_char]=text[i];
                couting_char++;
            }
        if(text[i]==' ')
            {
                convert_document[couting_paragraph][couting_sentence][couting_word][couting_char]='\0';
                puts(convert_document[couting_paragraph][couting_sentence][couting_word]);
				couting_char=0;
                couting_word++;
            }
        if(text[i]=='.')
        {
            convert_document[couting_paragraph][couting_sentence][couting_word][couting_char]='\0';
             puts(convert_document[couting_paragraph][couting_sentence][couting_word]);
			 couting_char=0;
            couting_word=0;
            couting_sentence++;
        }
        if(text[i]=='\n'||text[i]=='\0')
        {
            couting_sentence=0;
            couting_word=0;
            couting_paragraph++;
            couting_char=0;
        }
            
    }
    return convert_document;
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
	return 0;
}
