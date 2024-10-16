#include "header.h"

List * initialize()
{
    List *my_list ;
    my_list = (List*)malloc(sizeof(List));

    if(my_list == NULL)
        return MEM_ALLOC_FAILED;

    my_list->head = my_list->tail = NULL;
    my_list->count = 0;
    my_list->female_count = 0;
    my_list->male_count = 0;

    return my_list;
}

Node* get_node(Student new_student)
{
    Node *new_node;
    new_node = (Node*)malloc(sizeof(Node));

    if(NULL == new_node)
        return MEM_ALLOC_FAILED;

    new_node->data = new_student;
    new_node->ptr = NULL;

    return new_node;
}
int insert_at_end(List* my_list, Student new_student)
{
    Node *new_node;
    new_node = get_node(new_student);

    if(NULL == new_node)
        return FAILED;

    if (my_list->tail == NULL) {
        my_list->head = my_list->tail = new_node;
    } else {
        my_list->tail->ptr = new_node;
        my_list->tail = new_node;
    }
    my_list->count++;
    if (new_node->data.gender == 'M') my_list->male_count++;
        else if (new_node->data.gender == 'F') my_list->female_count++;
    return SUCCESS;

}

int delete_student(List* list, Student s)
{
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL && current->data.id != s.id) {
        previous = current;
        current = current->ptr;
    }

    if (current == NULL) {
        printf("Student with ID %d not found.\n", s.id);
        return FAILED;
    }

    // If the student is found
    if (previous == NULL) {
        // Student is the head
        list->head = current->ptr;
    } else {
        previous->ptr = current->ptr;
    }

    if (current == list->tail) {
        // Student is the tail
        list->tail = previous;
    }

    if(current->data.gender == 'M') list->male_count--;
        else if (current->data.gender == 'F') list->female_count--;
    free(current);
    list->count--;
    printf("Student with ID %d deregistered successfully.\n", s.id);
    return SUCCESS;
}

void display_list(List *list) {
    Node *current = list->head;
    if (current == NULL) {
        printf("No students registered.\n");
        return;
    }

    while (current != NULL) {
        Student s = current->data;
        printf("ID: %d, Name: %s, Gender: %c, OTP: %d\n", s.id, s.name, s.gender, s.otp);
        current = current->ptr;
    }
}

int generate_otp() {
    return rand() % 9000 + 1000; // 4-digit number between 1000 and 9999
}

Student create_student(int id, const char* name, char gender, const char* reg_date) {
    Student s;
    s.id = id;
    strncpy(s.name, name, MAX_SIZE - 1);
    s.gender = gender;
    s.otp = generate_otp();
    strncpy(s.registration_date, reg_date, DATE_SIZE); // Store the registration date
    return s;
}

int is_student_registered(List* list, int id) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data.id == id) {
            return REGISTERED; // Student already registered
        }
        current = current->ptr;
    }
    return NOT_REGISTERED; // Student not registered
}

int can_deregister_before_event(const char *current_date, const char *event_date) {
    int cur_day, cur_month, cur_year;
    int event_day, event_month, event_year;

    // Parse the current date and event dates
    sscanf(current_date, "%02d-%02d-%04d", &cur_day, &cur_month, &cur_year);
    sscanf(event_date, "%02d-%02d-%04d", &event_day, &event_month, &event_year);

    // Calculate if the deregistration is at least 2 days before the event date
    if (event_year > cur_year ||
        (event_year == cur_year && event_month > cur_month) ||
        (event_year == cur_year && event_month == cur_month && event_day - cur_day >= 2)) {
        return ALLOWED; // Deregistration allowed (more than 48 hours before event)
    }
    return NOT_ALLOWED; // Deregistration not allowed (less than 48 hours before the event)
}

// Function to simulate advancing the date by 1 day
void advance_day(int *day, int *month, int *year) {
    (*day)++;
    if (*day > 30) {
        *day = 1;
        (*month)++;
        if (*month > 12) {
            *month = 1;
            (*year)++;
        }
    }
}

void display_dashboard(List * my_list) {
    printf("\n--- Dashboard ---\n");
    printf("Total Students Registered: %d\n", my_list->count);
    printf("Male Students: %d\n", my_list->male_count);
    printf("Female Students: %d\n", my_list->female_count);
    printf("-----------------\n");
}
