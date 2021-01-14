#ifndef FREQUENCY_H
#define FREQUENCY_H

#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;

typedef struct node {
    char letter;
    long unsigned int count;
    boolean isLeaf;
    struct node* children[NUM_LETTERS];
    char* prev;
} Node;
Node* buildTrie();
Node *newNode(Node *root, char c);
int insert(Node *root);
int search(Node *root, const char *key);
int charToIndex(char c);
void printWords(Node *root);
void printWordsRevers(Node *root);
// Node* buildTrie();

#endif