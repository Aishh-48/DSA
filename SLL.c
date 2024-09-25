#include <stdio.h>
#include <stdlib h>
#include <string.h>
struct Node {
char name [50];
struct Node* next;
};
struct Node* createNode (char* name) {
struct Node* newNode = (struct Node*) malloc (sizeof (struct Node));
strcpy (newNode- >name, name);
newNode-> next = NULL;
return newNode;
}
void displayList (struct Node* head) {
struct Node* temp = head;
if (temp == NULL) {
printf("Contact list is empty.\n");
return;
}
printf("Contact list: ");
while (temp ! NULL) {
printf( "%s -> ", temp->name) ;
temp = temp->next;
}
printf("NULL\n") ;
}
struct Node* createList() {
int n;
char name [50];
struct Node* head = NULL;
struct Node* temp = NULL;
printf("Enter the number of contacts: ") ;
scanf ("%d", &n);
getchar ();
for (int i = 0; i<n; i++) {
printf("Enter contact name %d: ", i + 1);
fgets (name, 50, stdin);
name[strcspn (name, "\n")] = 0;
struct Node* newNode = createNode (name);

if (head = NULL) {
head = newNode;
} else {
temp->next = newNode;
}
temp = newNode; 
}
displayList(head) ;
return head;
}
struct Node* insertContact (struct Node* head) {
char name [50];
int pos, i = 0;
printf("Enter the contact's name to insert: ");
getchar();
fgets (name, 50, stdin) ;
name [strcspn (name, "\n")] = 0;
printf("Enter the position (0-based index) to insert the contact: ");
scanf ("%d", &pos);
struct Node* newNode = createNode (name);
if (pos == 0) {
newNode->next = head;
head = newNode;
} else {
struct Node* temp = head;
while (i < pos - 1 && temp != NULL) {
temp = temp->next;
i++;
}
if (temp == NULL) {
printf("Invalid position . \n");
free (newNode) ;
return head;
}
newNode->next = temp-> next;
temp->next = newNode;
}
displayList (head) ;
return head;
}
struct Node* deleteContact (struct Node* head) {
if (head == NULL) {
printf("The contact list is empty. \n");
return head;
}
char choice, name [50];
int pos;
printf("Delete by name or position? (n/p) : ");
getchar( );
scanf("%c", &choice);
if (choice == "n') {
printf("Enter the contact 's name to delete: ");
getchar( );
fgets (name, 50, stdin);
name [strcspn (name, "\n")] = 0;
struct Node* temp = head;
struct Node* prev = NULL;
while (temp != NULL && strcmp (temp- >name, name) != 0) {
prev = temp;
temp = temp->next;
}
if (temp == NULL) {
printf("Contact not found. \n");
return head;
}
if (prev == NULL) {
head = temp->next;
} else {
prev->next = temp->next;
}
free (temp);
} else if (choice == 'p') {
printf("Enter the position to delete the contact: ");
scanf("%d", &pos);

if (pos == 0) {
struct Node* temp = head;
head = head->next; 
free (temp);
} else{
struct Node* temp = head;
struct Node* prev = NULL;
int i = 0;
while (i < pos && temp != NULL) {
prev = temp;
temp = temp->next;
i++;
}
if (temp == NULL) {
printf("Invalid position . \n");
return head;
}
prev->next = temp->next;
free (temp);
}
} else {
printf("Invalid choice. \n");
}
displayList (head);
return head;
}
void searchContact (struct Node* head) {
char name [50];
int pos = 0;
struct Node* temp = head;
printf("Enter the contact's name to search: ");
getchar();
fgets (name, 50, stdin) ;
name [strcspn (name, "\n") ] = 0;
while (temp != NULL) {
if (strcmp (temp->name, name) == 0) {
printf("%s found at position %d\n", name, pos);
return;
}
temp = temp->next;
pos++;
}
printf("%s not found in the list. \n", name);
}
int main() {
struct Node* head = NULL;
int choice;
do {
printf("\n. Create the list of contacts\n");
printf("2. Insert a new contact\n");
printf("3. Delete a contact\n" );
printf("4. Display contact list\n");
printf("5. Search for a contact\n") ;
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice){
case 1:
head = createList ();
break;
case 2:
head = insertContact (head) ;
break;
case 3:
head = deleteContact (head);
break;
case 4:
displayList (head);
break;
case 5:
searchContact (head);
break;
case 6:
printf("Exiting the program. . . \n");
break;
default:
printf(" Invalid choice. Please try again.\n");
}
} while (choice != 6);
return 0;
}
