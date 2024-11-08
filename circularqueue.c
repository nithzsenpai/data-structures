#include <stdio.h>
#include <stdlib.h>
#define MAX 5 

void enqueue(int queue[], int *front, int *rear, int value) {
if (front == (rear + 1) % MAX) {
printf("Queue is full!\n");
} else {
if (*front == -1) 
*front = 0;
*rear = (*rear + 1) % MAX;
queue[*rear] = value;
printf("Inserted %d\n", value);
}
}

void dequeue(int queue[], int *front, int *rear) {
if ( *front == -1) {
printf("Queue is empty!\n");
} else {
printf("Deleted %d\n", queue[*front]);
if (*front == *rear) { 

*front = -1;
*rear = -1;
} else {
*front = (*front + 1) % MAX;
}
}
}
// Function to display the queue
void display(int queue[], int front, int rear) {
if ( front == -1) {
printf("Queue is empty!\n");
} else {
printf("Queue elements are: ");
int i = front;
while (i != rear) {
printf("%d ", queue[i]);
i = (i + 1) % MAX;
}
printf("%d\n", queue[i]);
}
}

int main() {
int queue[MAX];
int front = -1, rear = -1;
int choice, value;

while (1) {
printf("\nCircular Queue Menu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");

printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1: // Enqueue
printf("Enter value to insert: ");
scanf("%d", &value);
enqueue(queue, &front, &rear, value);
break;

case 2: // Dequeue
dequeue(queue, &front, &rear);
break;

case 3: // Display
display(queue, front, rear);
break;

case 4: // Exit
printf("Exiting...\n");
exit(0);
break;

default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
