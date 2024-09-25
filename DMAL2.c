#include <stdio . h>
#include <string. h>
#define MAX 100
#define NAME_LEN 50

void displayList (char students [MAX] [NAME_LEN], int count) {
if (count == 0) {
printf("The student list is empty. \n");
} else {
printf("Student list: ["):
for (int i = 0; i< count; it+) {
printf( "%s", students [i] );
if (i < count - 1) {
print f(", ");
}
}
printf("]\n");
}
}
void createlist (char students [MAX] [NAME_LEN], int *count) {
printf("Enter the number of students : ");
Scanf("%d", count);
getchar();
for (int i = 0; i< *count; it+) {
print f("Enter student name %d: ", i + 1);
fgets (students [i], NAME_LEN, stdin);
students [i] [strcspn(students [i], "\n")] = 0;
}
displayList (students, *count ) ;
}
void insertStudent (char students [MAX] [NAME_LEN], int *count) {
if (*count == MAX) {
printf("Student list is full, cannot insert more students . \n");
return;
}
char name [NAME_ LEN];
int p0S;

printf("Enter the student's name to insert: ");
getchar ();
fgets (name, NAME_ LEN, stdin);
name [strcspn (name, "\n")] = 0;

printf("Enter the position (0-based index ) to insert the student: ");
scanf("%d", &pos);

if (pos <0 || pos > *count) {
printf("Invalid position . \n");
return;
}
for (int i = *count; i > pos; i--) {
strcpy(students [ij. students [i - 1]);
}
strcpy(student s [pos], name);
(*count) ++;
displayList (students, *count );
}
void deleteStudent (char students [MAX] [NAME_LEN], int *count) {
if (*count == 0) {
printf("The student list is empty. \n");
return;
}
char choice;
printf("Delete by name or position? (n/p): ");
getchar();
scanf("%c", &choice);

if (choice == 'n') {
char name [NAME_ LEN];
int found = 0;
printf("Enter the student's name to delete : ");
getchar();
fgets (name, NAME_LEN, stdin);
name [strcspn (name, "\n") ] = 0;
for (int i = 0; i < *count;i++) {
if (strcmp (students [i], name) == 0) {
for (int j = i;j< *count - 1; j++) {
strcpy (students [j). students [j + 1]);
}
(*count) --;
found = 1;
break;
}
}
if (!found) {
print f("Student not found. \n");
}
} else if (choice == "p') {
int pos;
print f("Enter the position to delete the student: ");
Scanf("%d", &pos) ;

if (pos <0 || pos >= *count) {
printf("Invalid position. \n");
return;
}
for (int i = pos; i < *Count - 1; itt) {
strcpy(students [i], students [i + 1);
}
(*count )-- ;
} else {
printf(" Invalid choice. \n ");
}
displayList (students, * count) ;
}
void searchStudent (char students [MAX] [NAME_LEN], int count) {
char name [NAME_ LEN];
int found = 0;
if (count == 0) {
printf("The student list is empty. \n");
return;
}
printf("Enter the student 's name to search: ");
get char ();
fgets (name, NAME_ LEN, stdin);
name [strcspn (name, "\n'")] = 0;
for (int i = 0; i< count; i++) {
if (strcmp (students [i] , name) == 0) {
printf("%s found at position %d\n", name, i);
found=1;
break;
}
if (! found) {
printf("%S not found in the list. \n", name);
}
}
int main() {
char students [MAX] [NAME_LEN];
int count = 0;
int choice;

do {
printf("\n1 . Create the list of students\n ");
printf("2. Insert a new student \n");
printf("3. Delete a student \n");
printf("4. Display student list\n");
printf("5. Search for a student \n");
printf("6. Exit\n");
printf("Enter your choice:");
scanf ("%d", &choice) ;
switch (choice) {
case 1:
createList (students, &count) ;
break;
case 2:
insertStudent (students , &count);
break;
Case 3:
deleteStudent (students, &count);
break;
case 4:
displayList (students, count );
break;
case 5:
searchStudent (students, count);
break;
case6:
printf("Exiting the program. . .\n") ;
break;
default:
printf("Invalid choice. Please try again. \n");
}
} while (choice != 6);
return 0;
}
