#include <stdbool.h>
#include "Student.c"
#include "LinkedList.c"

typedef struct Subject {
    char *name;
    LinkedList *studentsInCourse;
    LinkedList *studentsAproved;
} Subject;

Subject *constructSubject(char *name) {
    Subject *sub = malloc(sizeof(Subject));
    sub->name = name;
    return sub;
}
void singUpStudent(Subject* subject, Student* student){
    list_add_node(subject->studentsInCourse,student);
}
void aproveStudent(Subject* subject, Student* student){
    list_add_node(subject->studentsAproved,student);
    //delete(subject->studentsInCourse, student); AGREGAR METODO DELETE QUE ELIMINE DIRECTAMENTE EL NODO == DATA
}
bool isAproved(Subject *subject, Student *student) {
    return list_contains(subject->studentsAproved, student);
}

void pass(Subject *subject, Student *student) {
    list_add_node(subject->studentsAproved, student);
}