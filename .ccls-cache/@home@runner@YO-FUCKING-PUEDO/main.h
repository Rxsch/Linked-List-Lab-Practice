#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
}node;


//this function takes an item and insert it in the linked list pointed by root.
node* insert_front(node *root, int item)
{
node *temp;
//create a new node and fill-up the node
temp= (node *) malloc(sizeof(node));
temp->data=item;
temp->next=NULL;
if(root==NULL) //if there is no node in the linked list
root=temp;
else //there is an existing linked list, so put existing root after temp
{
temp->next = root; //put the existing root after temp
root = temp; //make the temp as the root!
}
return root;
}

//Reverse list
node* reverse(node* root) 
{
    node* temp = NULL;   
    node* temp2 = NULL; 

    // Traverse the list
    while (root != NULL) {
        temp2 = root->next;  
        root->next = temp;  
        temp = root;         
        root = temp2;        
    }
    // At the end of the loop, temp points to the new root of the reversed list
    return temp;
}


//Display function
void display(node*root)
{
    printf("\nPrinting your linked list.......");
    while (root!=NULL) 
    {
    printf(" %d", root->data);
    root=root->next;
    }
}
//insert in place function
void insertToPlace(node* root, int val, int place) 
{

    // Create the new node and assign data
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    // Traverse the list to find the insertion position
    node* walker = root;
    int count = 1;

    // Traverse the list until the position before the insertion point
    while (walker != NULL && count < place - 1) {
        walker = walker->next;
        count++;
    }

    // If the walker reaches NULL (place is greater than the length of the list), insert the new node at the end of the list
    if (walker == NULL) {
        // Traverse to the end of the list
        walker = root;
        
        while (walker->next != NULL) {
            walker = walker->next;
        }
        // Insert newNode 
        walker->next = newNode;
    } else {
        // Insert the new node at the desired place
        newNode->next = walker->next;
        walker->next = newNode;
    }
}
//Free function
void freeList(node* root) {
    node* temp;
    while (root != NULL) {
        temp = root;       // Store the current node
        root = root->next; // Move to the next node
        free(temp);        // Free the current node
    }
}
