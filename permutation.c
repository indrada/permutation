#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include<unistd.h>
char* removeChar(char* s,int index){
    char* tmp=malloc(strlen(s)-1);
    for(int i=0;i<strlen(s);i++){
        if(i<index){
            tmp[i]=s[i];
        }
        if(i>index){
            tmp[i-1]=s[i];
        }
    }
    tmp[strlen(s)-1]='\0';
    return tmp;
}
void permute(char * current, char * elements){
    char * tmp=malloc(strlen(current)+2);
    char element;
    char * newElements;
    if(strlen(elements)>0){
        for(int i =0; i<strlen(elements);i++){     
            element=elements[i];
            strncpy(tmp,current,strlen(current));
            tmp[strlen(current)]=element;
            tmp[strlen(current)+1]='\0';
            newElements=removeChar(elements,i);
            permute(tmp,newElements);
        }
    }
    else{
        printf(current);
        printf("\n");
    }
}
int main(){
    char * val;
    printf("Input a word to permute: ");
    scanf(" %[^\n]",val);
    permute("",val);
    }






