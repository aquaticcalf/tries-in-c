#include <stdio.h>
#include <stdbool.h> // for boolean
#include <stdlib.h> // for malloc

struct node {
    bool flag;
    struct node* child[26];
};

struct node* create() { // create trie
    struct node* newnode = (struct node*)malloc(struct node);
    node -> flag = false;
    for (int i = 0; i < 26; i++) {
        newnode -> child[i] = NULL;
    }
    return newnode;
}

void insert(struct node* root, const char* key) { // inserting key to trie
    struct node* current = root;
    while(*key) {
        int index = *key - 'a';
        if (!current -> child[index]) {
            current -> child[index] = create();
        }
        current = current -> child[index];
        key++;
    }
    current -> flag = true;    
}

int main() {
    return 0;
}
