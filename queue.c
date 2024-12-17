#include <stdio.h>
#define SIZE 3

// Function to enqueue an element into the queue
void enqueue(int queue[], int *front, int *rear, int value) {
    if (*rear == SIZE - 1) {
        printf("Queue Overflow!\n");
    } else {
        if (*front == -1) {
            *front = 0;
        }
        queue[++(*rear)] = value;
        printf("%d enqueued into the queue.\n", value);
    }
}

// Function to dequeue an element from the queue
void dequeue(int queue[], int *front, int *rear) {
    if (*front == -1 || *front > *rear) {
        printf("Queue Underflow!\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[(*front)++]);
        if (*front > *rear) {
            *front = *rear = -1; // Reset the queue if it becomes empty
        }
    }
}

// Function to display elements of the queue
void display(int queue[], int front, int rear) {
    if (front == -1 || front > rear) {
        printf("The queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[SIZE], front = -1, rear = -1;
    int choice, value;

    while (1) {
       
        printf("1) Enqueue ");
        printf("2) Dequeue ");
        printf("3) Display ");
        printf("4) Exit ");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, &front, &rear, value);
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
