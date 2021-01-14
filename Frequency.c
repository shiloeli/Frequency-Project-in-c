#define NULL 0
#include "Frequency.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



Node *init(){
 Node *n =(Node*)malloc(sizeof(Node));
 if(n == NULL){
     exit(1);
 }
        n->count = 0;
        n->letter = 0;
        n->isLeaf = FALSE;
        n->prev = (char*)malloc(0);
          for(int i=0 ; i < NUM_LETTERS ; i++){
            n -> children[i] = NULL;
        }
    return n;
}

Node *newNode(Node *root, char c){
    Node *n =(Node*)malloc(sizeof(Node));
    if(n != NULL){
        n->count = 0;
        n->letter = c;
        n->isLeaf = FALSE;
        if(root != NULL){
        n -> prev = (char*)malloc(sizeof(strlen(root->prev)+2));
        if(!(n->prev)) exit(1);
        for(int i = 0; i<strlen(root->prev); i++){
          n->prev[i] =root->prev[i]; 
        }
         n->prev[strlen(root->prev)]=c;
         n->prev[strlen(root->prev)+1]='\0';
        for(int i=0 ; i < NUM_LETTERS ; i++){
            n -> children[i] = NULL;
        }
    }
    return n;
}
exit(1);
}
int charToIndex(char c){
    return ((int)c - (int)'a'); 
}


int insert(Node *root){
    Node* current = root;
    char tav;
    scanf("%c", &tav);
    while(tav != ' ' && tav != '\r' && tav != '\n'){
          if(tav == EOF || tav == '\0'){
            current->isLeaf=TRUE;
            current->count++;
            return 1;
          }
          if((tav>='a'&&tav<='z')||(tav>='A'&&tav<='Z')){
         if(tav>='A'&&tav<='Z')
            tav=tav+32;
        int index = charToIndex(tav);
        if(current->children[index] == NULL){
            current->children[index] = newNode(current, tav);

        }
        current = current->children[index];
    }
        if(scanf("%c", &tav)==EOF){
        current->isLeaf=TRUE;
        current->count++;
        return 1;
        }
    }
         current->isLeaf = TRUE;
         current->count += 1;
            return 0;
        }       

void printWords(Node *root){
    if(root == NULL){
       
       return;
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        printWords(root->children[i]);
    }
    if (root->isLeaf)
    {
    printf("%s %ld\n",root->prev,root->count);
    }
     free(root->prev);
    free(root);
}

void printWordsRevers(Node *root){
    if(root == NULL){
       return;
    }
    for (int i = 25; i >= 0; i--)
        printWordsRevers(root->children[i]);
    if (root->isLeaf)
    {
    printf("%s %ld\n",root->prev,root->count);
    
    }
    free(root->prev);
    free(root);
}

Node* buildTrie(){
    Node *root = init();
    int flag  = 0;
    while (!flag){
        flag = insert(root);
        if(flag ==1)break;
    }
    return root;
}