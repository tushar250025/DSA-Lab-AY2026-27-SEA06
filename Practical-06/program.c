//practical 6
//  Name: Tushar Khandade 
// Roll no: SEA06
// Train Ticket Booking System Using Queue 
 
#include <stdio.h>
#define SIZE 5
int q[SIZE];
int wait[SIZE];
int front = -1, rear = -1;
int wcount = 0;
void book( ) {
int t;
printf("Enter ticket number: ");
scanf("%d", &t);
if ((rear + 1) % SIZE == front) {
if (wcount == SIZE)
printf("Waiting list full\n");
else {
wait[wcount] = t;
wcount++;
printf("Added to waiting list\n");
}
}
else {
if (front == -1)
front = 0;
rear = (rear + 1) % SIZE;
q[rear] = t;
printf("Ticket booked\n");
}
}
void cancel( ) {
int t, i, j, found = 0;
printf("Enter ticket number to cancel: ");
scanf("%d", &t);
if (front == -1) {
printf("No tickets\n");
return;
}
i = front;
while (1) {
if (q[i] == t) {
found = 1;
break;
}
if (i == rear)
break;
i = (i + 1) % SIZE;
}
if (!found) {
printf("Ticket not found\n");
return;
}
if (wcount > 0) {
q[i] = wait[0];
printf("Ticket %d cancelled\n", t);
printf("Waiting ticket %d confirmed\n", wait[0]);
for (j = 0; j < wcount - 1; j++)
wait[j] = wait[j + 1];
wcount--;
}
else {
while (i != rear) {
q[i] = q[(i + 1) % SIZE];
i = (i + 1) % SIZE;
}
if (front == rear)
front = rear = -1;
else
rear = (rear - 1 + SIZE) % SIZE;
printf("Ticket cancelled\n");
}
}
void display( ) {
int i;
printf("\nConfirmed Tickets: ");
if (front != -1) {
i = front;
while (1) {
printf("%d ", q[i]);
if (i == rear)
break;
i = (i + 1) % SIZE;
}
}
printf("\nWaiting List: ");
for (i = 0; i < wcount; i++)
printf("%d ", wait[i]);
printf("\n");
}
int main( ) {
int ch;
do {
printf("\n1. Book Ticket");
printf("\n2. Cancel Ticket");
printf("\n3. Display");
printf("\n4. Exit");
printf("\nEnter choice: “);
scanf("%d", &ch);
switch (ch) {
case 1:
book();
break;
case 2:
cancel();
break;
case 3:
display();
break;
case 4:
printf("Exit\n");
break;
default:
printf("Invalid choice\n");
}
} while (ch != 4);
return 0;
}
