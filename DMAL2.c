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
