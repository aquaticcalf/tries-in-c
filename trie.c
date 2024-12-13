#include <stdio.h>
#include <stdbool.h> // for boolean
#include <stdlib.h> // for malloc

struct node {
    bool flag;
    struct node* child[26];
};

int global_count = 0;

struct node* create() { // create trie
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> flag = false;
    for (int i = 0; i < 26; i++) {
        newnode -> child[i] = NULL;
    }
    global_count++;
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
    int number;
    printf("enter the number of strings to be inserted to the trie: ");
    scanf("%d", &number);

    struct node* root = create();

    for (int i = 0; i < number; i++) {
        char key[100]; 
        printf("enter string %d: ", i + 1);
        scanf("%s", key); 
        insert(root, key); 
    }

    printf("total nodes created in the trie: %d\n", global_count);

    return 0;
}
