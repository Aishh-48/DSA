#include <stdio.h>
#include <stdlib. h>
#include <string.h>
struct Node {
char name [50];
struct Node* prev;
struct Node* next;
};
int main() {
struct Node *head = NULL, *tail = NULL, *temp, *newNode;
int choice, pos, size = 0, i;
char name [50], delchoice;

do{
printf(""\n1. Create the list of contacts\n");
printf("2. Insert a new contact \n");
printf("3. Delete a contact \n");
printf("4. Display contact list\n") ;
printf("5. Search for a contact\n");
printf ("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice) ;
Switch (choice) {
case 1:
printf("Enter the number of contacts : ");
scanf( "%d", &size) ;
getchar ();
for (i = 0; i < size; i++) {
printf("Enter contact name %d: ", i + 1);
fgets (name, 50, stdin) ;
name [strcspn (name, "\n")] = 0;
newNode = (struct Node*) malloc (sizeof (struct Node) );
strcpy (newNode->name, name) ;
newNode->prev = NULL;
newNode->next = NULL;
if (head == NULL) {
head = newNode;
tail = newNode;
} else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}
break;
case 2:
printf("Enter the contact's name to insert: ");
getchar ();
fgets (name, 50, stdin) ;
name [strcspn (name, "\n)] = 0;
printf(" Enter the position (0-based index) to insert the contact: ");
scanf ( "%d", &pos);
if (pos < o || pos > size) {
printf(" Invalid position. \n") ;
break;
}
newNode = (struct Node*) malloc (sizeof (struct Node) ) ;
strcpy (newNode->name, name) ;
newNode->prev = NULL;
newNode->next = NULL;
if (pos == 0) {
newNode->next = head;
if (head != NULL) {
head->prev = newNode; }
head = newNode;
} else{
temp = head;
for (i = 0; i < pos - 1; i++) {
temp = temp->next;
}
newNode->next = temp->next;
if (temp->next I= NULL) {
temp->next- >prev = newNode;
}
temp->next = newNode;
newNode->prev = temp;
}
size++;
break;

case 3:
printf("Delete by name or position? (n/p) : ");
getchar ();
Scanf ("%c", &delChoice) ;

if (del Choice = 'n')
printf("Enter the contact 's name to delete: ");
getchar ();
fgets (name, 50, stdin);
name[strcspn (name, "\n")] = 0;

temp = head;
while (temp != NULL &8 strcmp(temp->name, name) != e) {
temp = temp->next;
}
if (temp == NULL) {
printf(" Contact not found. \n");
break;
}
} else if (delchoice == 'p') {
printf("Enter the position (0-based index) to delete the contact: ");
scanf("%d", &pos) ;
if (pos <0 || pos >= size) {
printf("Invalid position.\n");
break;
}
temp = head;
for (i = 0; i < pos; i++) {
temp = temp->next;
}
) else {
printf(" Invalid choice. \n") ;
break;
}
case 4:
temp = head;
printf("Contact list (forward) : ");
while (temp = NULL) (
printf("%s <->", temp- >name) ;
tail = temp;
temp = temp->next;
}
printf("NULL\n");
temp = tail;
printf("" Contact list (backward) : ");
while (temp != NULL)
printf("%s <-> ", temp- >name);
temp = temp->prev;
}
printf("NULL \n") ;
break;

case 5:
printf("Enter the contact 's name to search: ");
getchar ();
fgets (name, 50, stdin) ;
name[strcspn (name, "\n")] = 0;
temp = head;
i = 0;
while (temp I= NULL) {
if (strcmp (temp->name, name) == 0) {
printf("%s found at position %d\n", name, i);
break;
}
temp = temp->next;
i++;
}
if (temp == NULL) {
printf("%s not found in the list.\n", name);
}
break;

case6:
printf("Exiting the program. . . \n") ;
break;
default:
printf("Invalid choice. Please try again. \n");
}
} while (choice I= 6);
return 0;
}
