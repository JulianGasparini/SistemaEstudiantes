#include "LinkedList.c"
#include <string.h>
#include "Student.c"

/**
 * @pos performs a linear search on the student list and print the student with the
 * same dni as indicated in params when found.
 * If not found prints "not found"
 *
 * @param list->    LinkedList containing students
 */
void print_student_by_DNI(LinkedList* list, int dni){
    Node *pointer = list->head;
    for (int i = 0; i < size_of_list(list); ++i) {

        if (st_get_dni(pointer->data) == dni){
            st_print_student(pointer->data);
            break;
        }
        pointer = pointer->next;
    }
    printf("Student with DNI: %d is not in database", dni);
}

/**
 * @pos performs a linear search on the student list and print the student with the
 * same name as indicated in params when found.
 * If not found prints "not found"
 *
 * @param list->    LinkedList containing students
 * @param name->    Student name, can be full name
 */
void print_student_by_name(LinkedList* list, char* name){
    Node *pointer = list->head;
    for (int i = 0; i < size_of_list(list); ++i) {
        if (strcmp(st_get_name(pointer->data), name) == 0){
            st_print_student(pointer->data);
            break;
        }
        pointer = pointer->next;
    }
    printf("Student with name: %s is not in database", name);
}

/**
 * @pos performs a linear search on the student list and print the students between
 * the age range specified in the params
 *
 * @param list->    LinkedList containing students
 */
void print_student_by_age_range(LinkedList* list, int minAge, int maxAge){
    Node *pointer = list->head;
    for (int i = 0; i < size_of_list(list); ++i) {
        int age = st_get_age(pointer->data);
        if (age >= minAge && age <= maxAge){
            st_print_student(pointer->data);
        }
        pointer = pointer->next;
    }
}

/**
 * @param list->    LinkedList containing students
 * @param dni->     DNI number of student
 * @return pointer to Student if found, pointer to NULL if not
 */
Student* get_student_by_DNI(LinkedList* list, int dni){
    Node *pointer = list->head;
    for (int i = 0; i < size_of_list(list); ++i) {
        if (st_get_dni(pointer->data) == dni){
            break;
        }
        pointer = pointer->next;
    }
    return pointer->data;
}

/**
 * @param list->    LinkedList containing students
 * @param name->    string with name of student
 * @return pointer to Student if found, pointer to NULL if not
 */
Student* get_student_by_name(LinkedList* list, char* name){
    Node *pointer = list->head;
    for (int i = 0; i < size_of_list(list); ++i) {
        if (strcmp(st_get_name(pointer->data), name) == 0){
            break;
        }
        pointer = pointer->next;
    }
    return pointer->data;
}

/**
 * @pos prints personal info of all students in list
 * @param list->    LinkedList containing students
 */
void print_students(LinkedList* list){
    Node *pointer = list->head;
    for (int i = 0; i < size_of_list(list); ++i) {
        st_print_student(pointer->data);
        pointer = pointer->next;
    }
}

/**
 * @param list ->  LinkedList containing students
 * @param c -> pointer to Career Struct
 * @return list containing all student that signed up for the subject
 */
LinkedList* filter_students_signed_up_to_subject (LinkedList* list, Career* c, char* subjectName){
    Node* pointer = list->head;
    LinkedList * students = create_list();
    for (int i = 0; i < size_of_list(list); ++i) {
        if (st_is_signed_up(c, pointer->data,subjectName)) {
            list_add_node(students, pointer->data);

        }
        pointer= pointer->next;
    }
    return students;
}

/**
 * @param list ->  LinkedList containing students
 * @param c -> pointer to Career Struct
 * @return list containing all student that are able to sign up for the subject
 */
LinkedList *filter_students_able_to_signup_to_subject (LinkedList* list, Career* c, char* subjectName){
    Node* pointer = list->head;
    LinkedList* students = create_list();
    for (int i = 0; i < size_of_list(list); ++i) {
        if (st_can_signup_to_subject(c, pointer->data,subjectName)) {
            list_add_node(students, pointer->data);
        }
        pointer = pointer->next;
    }
    return students;
}

/**
 * @param list ->  LinkedList containing students
 * @param c -> pointer to Career Struct
 * @return list containing all student that approved the subject
 */
LinkedList *filter_students_with_approved_subject (LinkedList* list, Career* c, char* subjectName){
    Node* pointer = list->head;
    LinkedList* students = create_list();
    for (int i = 0; i < size_of_list(list); ++i) {
        if (st_has_approved_subject(c, pointer->data,subjectName)) {
            list_add_node(students, pointer->data);
        }
        pointer=pointer->next;
    }
    return students;
}

/**
 * @param list -> LinkedList containing students
 * @return average grade of students in the list
 */
double get_average_of_student_list(LinkedList* list) {
    Node* pointer = list->head;
    double avg = 0;

    for (int i = 0; i < size_of_list(list); ++i) {
        avg += st_get_averageGrade((Student*)pointer->data);
        pointer=pointer->next;
    }
    printf("%d",avg);
    return avg/ size_of_list(list);
}





