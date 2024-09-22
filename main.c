/*This code implements some basic operation of singly linked list like inserting in
the beginning and end, delete operation, and display operation*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "main.h"

int main()
{
node *root=NULL; //very important line. Otherwise all function will fail
int ch,ele, place;
while(1)
{
printf("\nMenu: 1. insert at front, 2. reverse list 3. Insert to place 0. exit: ");
scanf("%d",&ch);
if(ch==0)
{
printf("\nGOOD BYE>>>>\n");
freeList(root);
break;
}
if(ch==1)
{
printf("\nEnter data(an integer): ");
scanf("%d",&ele);
root = insert_front(root, ele);
display (root);
}
if(ch==2)
{
  root = reverse(root);  // Update root with reversed list
  printf("List reversed.");
  display(root);
}
if(ch==3)
  {
      printf("\nEnter data (an integer) and place (>1) separated by space: ");
      scanf("%d %d", &ele, &place);
      insertToPlace(root, ele, place);
      display(root);  // Display the modified list
  }
}
return 0;
}