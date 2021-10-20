#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
   struct document dcmt_convertion;
   int cout_pragraph=0,cout_sentence=0,cout_word=0,cout_char=0;
   for (int i=0;text[i]!='\0'; i++)
   {
        if(text[i]=='\n')
           cout_pragraph++;       
   }
   dcmt_convertion.data=(struct paragraph*)malloc(sizeof(struct paragraph)*cout_pragraph);
   cout_pragraph=0;cout_sentence=0;cout_word=0;cout_char=0;
   for (int i=0;text[i]!='\0'; i++)
   {
       if(text[i]=='.')
          cout_sentence++;
       if(text[i]=='\n'||text[i+1]=='\0')
           {
               dcmt_convertion.data[cout_pragraph].data=(struct sentence*)malloc(sizeof(struct sentence)*cout_sentence);
               cout_sentence=0;
               cout_pragraph++;
           }
   }
    cout_pragraph=0;cout_sentence=0;cout_word=0;cout_char=0;
   for (int i=0;text[i]!='\0'; i++)
   {
       if(text[i]==' ')
          cout_word++;
        if(text[i]=='.')
         {
             dcmt_convertion.data[cout_pragraph].data[cout_sentence].data=(struct word*)malloc(sizeof(struct word)*(cout_word+1));
             cout_sentence++;
             cout_word=0;
         }
         if(text[i]=='\n')
         {
             cout_pragraph++;
             cout_sentence=0;
         }
   }
    cout_pragraph=0;cout_sentence=0;cout_word=0;cout_char=0;
   for (int i=0;text[i]!='\0'; i++)
   {
       if((text[i]>='a' &&text[i]<='z')||(text[i]>='A' &&text[i]<='Z'))
           cout_char++;
         if(text[i]==' ')
         {
             dcmt_convertion.data[cout_pragraph].data[cout_sentence].data[cout_word].data=(char*)malloc(sizeof(char)*(cout_char+1));
             cout_word++;
             cout_char=0;
         }
         if(text[i]=='.')
         {
              dcmt_convertion.data[cout_pragraph].data[cout_sentence].data[cout_word].data=(char*)malloc(sizeof(char)*(cout_char+1));
             cout_word=0;
             cout_sentence++;
             cout_char=0;
         }
         if(text[i]=='\n')
         {
             cout_pragraph++;
             cout_sentence=0;
             cout_word=0;
             cout_char=0;
         }
         
   }
    cout_pragraph=0;cout_sentence=0;cout_word=0;cout_char=0;
    for (int i=0;text[i]!='\0'; i++) 
    {
        if((text[i]>='a' &&text[i]<='z')||(text[i]>='A' &&text[i]<='Z'))
           {
               dcmt_convertion.data[cout_pragraph].data[cout_sentence].data[cout_word].data[cout_char]=text[i];
               cout_char++;
           }
        if(text[i]==' ')
        {
            dcmt_convertion.data[cout_pragraph].data[cout_sentence].data[cout_word].data[cout_char]='\0';
            cout_char=0;
            cout_word++;
        }
        if(text[i]=='.')
        {
            dcmt_convertion.data[cout_pragraph].data[cout_sentence].data[cout_word].data[cout_char]='\0';
            dcmt_convertion.data[cout_pragraph].data[cout_sentence].word_count=cout_word+1;
            cout_char=0;
            cout_word=0;
            cout_sentence++;
        }
        if(text[i]=='\n')
        {
            dcmt_convertion.data[cout_pragraph].sentence_count=cout_sentence;
            cout_char=0;
            cout_word=0;
            cout_sentence=0;
            cout_pragraph++;
        }
    }
    dcmt_convertion.paragraph_count=cout_pragraph+1;
    return dcmt_convertion;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) 
{
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) 
{ 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k) 
{
    return Doc.data[k-1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);
    print_document(Doc);
    

//    int q;
//    scanf("%d", &q);
//
//    while (q--) {
//        int type;
//        scanf("%d", &type);
//
//        if (type == 3){
//            int k, m, n;
//            scanf("%d %d %d", &k, &m, &n);
//            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
//            print_word(w);
//        }
//
//        else if (type == 2) {
//            int k, m;
//            scanf("%d %d", &k, &m);
//            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
//            print_sentence(sen);
//        }
//
//        else{
//            int k;
//            scanf("%d", &k);
//            struct paragraph para = kth_paragraph(Doc, k);
//            print_paragraph(para);
//        }
//        printf("\n");
//    }     
}
