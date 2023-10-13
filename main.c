#include <stdio.h>
#include <string.h>

#define M_LINE_LEN 200
#define M_NUM_REPLACEMENTS 30
#define M_ORG_LEN 20
#define M_REPL_LEN 20


typedef struct {
    char orig[M_ORG_LEN];
    char repl[M_REPL_LEN];
} Replacement;


int main() {
    char Line[M_LINE_LEN];
    Replacement replacements[M_NUM_REPLACEMENTS];
    FILE *source,*dic,*new;
    source = fopen("C:\\Users\\mobin\\Desktop\\source.txt","r");
    dic = fopen("C:\\Users\\mobin\\Desktop\\dictionary.txt","r");
    new = fopen("new_file.txt","w");
    int num;
    if(source == NULL || dic == NULL){
        printf("Error while reading file");
        return 1;
    }
    fscanf(dic,"%d",&num);

    for (int i = 0; i < num; ++i) {
        fscanf(dic,"%s %s",replacements[i].repl,replacements[i].orig);
    }
    while(!feof(source)){
        fgets(Line,M_LINE_LEN,source);
        int line_length = strlen(Line);
        if (Line[line_length - 1] == '\n') {
            Line[line_length - 1] = '\0';  // Remove newline character
        }

        char *word_by_word = strtok(Line," ");
        char word[20];
        while (word_by_word){
            int T = 1;
            for (int j = 0; j < num; ++j) {
                char *ptr = strstr(word_by_word,replacements[j].orig);
                while (ptr != NULL){
                    strcpy(word,word_by_word);
                    word[strlen(word_by_word)- strlen(replacements[j].orig)]='\0';
                    strncat(word,replacements[j].repl, strlen(replacements[j].repl));
                    printf("%s\n",word);
                    fprintf(new,"%s ",word);
                    T = 0;
                    j = num;
                    break;
                }
            }if(T == 1){
                fprintf(new,"%s ",word_by_word);
            }
            word_by_word= strtok(NULL," ");
        }
        fprintf(new,"\n");
    }
    fclose(source);
    fclose(dic);
    fclose(new);
    return 0;
}
