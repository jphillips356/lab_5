#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
    int counter = 0; //var to count nodes
    node *current = head; //creat temp node to go though
    while(current->next != NULL){
        counter++;
        current = current->next;
    }
    return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int strLen = length(head);
    char* str = (char*)malloc((strLen) * sizeof(char));
    int i = 0;
    node* current = head;
    while (current != NULL) {
        str[i++] = current->letter;
        current = current->next;
    }
    str[i] = '\0'; // add null terminator
    return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;
    if(*pHead == NULL)
        *pHead = newNode;
    else{
        node *currentNode = *pHead;
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node *current = *pHead; //creat temp node to go though
    while(current->next != NULL){
        node* newNode = current->next;
        free(current);
        current = newNode;
    }
    *pHead = NULL;
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt","r");
    if(inFile == NULL){
        printf("Incorrect file address.");
        return 1;
    }
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile," %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}