#ifndef FREQUENCY_H
#define FREQUENCY_H

#define NUM_LETTERS ((int)26)


typedef struct node {
    char letter;
    long unsigned int count;
    bool isWord;
    struct node* children[NUM_LETTERS];
    char* word;
} Node;

Node *crateRoot();
Node *newNode(Node *root, char c);
int insert(Node *root);
int charToIndex(char c);
bool charIsCurrct(char c);
void printWords(Node *root);
void printWordsRevers(Node *root);
Node* buildTrie();

#endif