#include <stdio.h>
#include <stdlib.h>
#include "operations.c"
int main()
{
    srand(time(0)); // Seed the random number generator

    int current_day = 13, current_month = 10, current_year = 2024; // Simulate the current date
    char current_date[DATE_SIZE]; // Store current date in DD-MM-YYYY format

    // Event Date: Set to 15-10-2024
    const char event_date[DATE_SIZE] = "15-10-2024";

    // Initialize current date
    sprintf(current_date, "%02d-%02d-%04d", current_day, current_month, current_year);

    List *student_list = initialize();

    int choice;
    do {
        printf("\n1. Register for the event\n");
        printf("2. Deregister from the event\n");
        printf("3. Display Dashboard\n");
        printf("4. Display Registered Students Details\n");
        printf("5. Advance Day\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Register student
                int id;
                char name[MAX_SIZE];
                char gender;

                printf("Enter Student ID: ");
                scanf("%d", &id);
                if (is_student_registered(student_list, id)) {
                    printf("Student is already registered!\n");
                    break;
                }
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Gender (M/F): ");
                scanf(" %c", &gender);

                // Create and insert student
                Student new_student = create_student(id, name, gender, current_date);
                insert_at_end(student_list, new_student);

                printf("Student registered successfully. OTP: %d\n", new_student.otp);
                break;
            }
            case 2: {
                // Deregister student
                int id;

                printf("Enter Student ID to deregister: ");
                scanf("%d", &id);

                // Check if the current date is at least 48 hours (2 days) before the event date
                if (can_deregister_before_event(current_date, event_date)) {
                    // Create dummy student for ID matching
                    Student student;
                    student.id = id;

                    // Delete the student
                    delete_student(student_list, student);

                } else {
                    printf("Deregistration not allowed (less than 48 hours before the event).\n");
                }


                break;
            }
            case 3:
                display_dashboard(student_list);
                break;
            case 4:
                display_list(student_list);
                break;
            case 5:
                // Simulate advancing the date by 1 day
                advance_day(&current_day, &current_month, &current_year);
                sprintf(current_date, "%02d-%02d-%04d", current_day, current_month, current_year);
                printf("Date advanced to: %s\n", current_date);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}
