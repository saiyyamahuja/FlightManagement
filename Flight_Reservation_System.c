
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Flight {
    int serial;
    int code;
    char destination[20];
    int price;
    struct Flight* next;
};


struct Flight* createFlight(int serial, int code, const char* destination, int price) {
    struct Flight* newFlight = (struct Flight*)malloc(sizeof(struct Flight));
    newFlight->serial = serial;
    newFlight->code = code;
    strcpy(newFlight->destination, destination);
    newFlight->price = price;
    newFlight->next = NULL;
    return newFlight;
}

struct Flight* addFlight(struct Flight* head, int serial, int code, const char* destination, int price) {
    struct Flight* newFlight = createFlight(serial, code, destination, price);
    if (head == NULL) {
        return newFlight;
    } else {
        struct Flight* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newFlight;
        return head;
    }
}

int findFlightCode(struct Flight* head, int serial) {
    struct Flight* current = head;
    while (current != NULL) {
        if (current->serial == serial) {
            return current->code;
        }
        current = current->next;
    }
    return -1; 
}

int main() {
    struct Flight* head = NULL;

    head = addFlight(head, 101, 74575, "Mumbai", 12000);
    head = addFlight(head, 102, 74589, "Mumbai", 10000);
    head = addFlight(head, 103, 74596, "Mumbai", 15000);
    head = addFlight(head, 122, 84886, "Chennai", 11000);
    head = addFlight(head, 123, 84887, "Chennai", 10000);
    head = addFlight(head, 124, 84890, "Chennai", 15000);

    int choice;
    int p, co, age, payment;
    char name[20];
    char date[10];
    char from[20];
    char gender;
    char destination[20];
    int seriol;

    do {
        printf("\n----------------------------\n");
        printf("  Airline Ticket booking\n");
        printf("----------------------------\n");

        printf(" 1 Booking\n");
        printf(" 2 Price\n");
        printf(" 3 View Ticket details\n");
        printf(" 4 Payment confirmation\n");
        printf(" 5 Cancel your booking\n");
        printf(" 0 Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter passenger name: ");
                fflush(stdin);
                scanf("%19s", name);

                printf("Enter your age: ");
                scanf("%d", &age);

                printf("Enter gender (M/F): ");
                scanf(" %c", &gender);
                if (gender != 'M' && gender != 'F') {
                    printf("Re-enter your gender.");
                    scanf(" %c", &gender);
                }

                printf("Enter date: ");
                fflush(stdin);
                scanf("%9s", date);

                printf("Enter your current location: ");
                fflush(stdin);
                scanf("%19s", from);

                printf("Enter the destination (Mumbai/Chennai/Delhi/Lucknow/Chandigarh): ");
                fflush(stdin);
                scanf("%19s", destination);

                if (strcmp(destination, "Mumbai") == 0) {
                    seriol = 101;
                } else if (strcmp(destination, "Chennai") == 0) {
                    seriol = 122;
                }

                int flightCode = findFlightCode(head, seriol);
                if (flightCode != -1) {
                    printf("Your booking is successful, and your code is '%d'\n", flightCode);
                    printf("Please Remember This Code!\n");
                } else {
                    printf("Wrong destination!\n");
                }
                break;
            }
            case 2: {
                printf("Enter your ticket code:");

                scanf("%d", &co);
                struct Flight* current = head;
                while (current != NULL) {
                    if (current->code == co) {
                        printf("\nTicket price is %d\n", current->price);
                        int x = current->price + current->price * 0.13;
                        printf("Total amount with 13 percent tax is %d\n", x);
                        p = x;
                        break;
                    }
                    current = current->next;
                }
                if (current == NULL) {
                    printf("Wrong code!\n");
                }
                break;
            }
            case 3: {
                printf("Your booking details are as follows:\n");
                printf("From: %s\n", from);
                printf("To: %s\n", destination);
                printf("Name: %s\n", name);
                printf("Age: %d\n", age);
                printf("Gender: %c\n", gender);
                printf("Date: %s\n", date);
                printf("Code: %d\n", co);
                printf("Price: %d\n", p);
                break;
            }
            case 4: {
                printf("Your amount is %d.\n", p);
                for (int j = 1; j < 5;) {
                    for (int confirm = 1; confirm < 2; confirm++) {
                        printf("\nPay this amount to confirm: ");
                        scanf("%d", &payment);
                        if (payment < p) {
                            printf("Your amount is less than %d, kindly pay the actual amount.\n", p);
                            j++;
                        } else if (payment > p) {
                            printf("Your amount is greater than %d, kindly pay the actual amount.\n", p);
                            j++;
                        } else {
                            printf("Your booking is confirmed. Enjoy Your Trip :-D\n");
                            j = 5;
                        }
                    }
                }
                if (payment != p) {
                    printf("Your Booking Is Cancelled\n");
                }
                break;
            }
            case 5: {
                int code_to_cancel;
                if (payment == p) {
                    printf("Enter your ticket code to proceed: ");
                    scanf("%d", &code_to_cancel);
                    if (code_to_cancel == co) {
                        p = 0;
                        printf("Price: %d\n", p);
                        co = 0;
                        printf("Your ticket code is expired now, and your booking is Cancelled.\n");
                    }
                }
                break;
            }
            case 0: {
                printf("You have exited from the booking.\n");
                break;
            }
            default:
                printf("Wrong choice!\n");
        }
    } while (choice != 0);

    return 0;
}