#include "Date.c"
#include "Career.c"

typedef struct Student {
    char *name;
    char* grade;
    Date *dateBirth;
    int dni;
    unsigned long long subjectsApproved;
    unsigned long long subjectsInCourse;
} Student;
/**
 * @post Sets name of student.
 * @param s-> Pointer to Student struct
 */
void st_set_name(Student *s, const char *name) {
    s->name = malloc(strlen(name) + 1);
    strcpy(s->name, name);
}

/**
 * @post Sets birthdate of student
 * @param s-> Pointer to Student struct
 */
void st_set_birthdate(Student *s, Date *date) {
    s->dateBirth = date;
}

/**
 * @post Sets id of student
 * @param s->  Pointer to Student struct
 */
void st_set_dni(Student *s, int dni) {
    s->dni = dni;
}

/**
 * @return id of student
 * @param s-> Pointer to Student struct
 */
int st_get_dni(Student *s) {
    return s->dni;
}

/**
 * @return age of student.
 * @param s-> Pointer to Student struct
 */
int st_get_age(Student *s) {
    return calculateAge(s->dateBirth);
}

/**
 * @return name of student.
 * @param s->  Pointer to Student struct
 */
char* st_get_name(Student *s) {
    return s->name;
}

/**
 * Checks if student has all correlatives to that subject approved.
 * @returns: TRUE if possible, FALSE if not
 * @param c->  Pointer to Career struct
 * @param s->  Pointer to Student struct
 */
bool st_can_signup_to_subject(Career* c , Student* s, char* subjectName){
    int subjectID = ht_get(c->subjectToID, subjectName);
    return (s->subjectsApproved & c->correlatives[subjectID]) == c->correlatives[subjectID];
}

/**
 * @pos Adds subject "subjectName" to the subjectInCourse correlatives table
 *
 * @param c->  Pointer to Career struct
 * @param s->  Pointer to Student struct
 */
void st_sing_up_student_to_subject(Career* c, Student* s, char* subjectName){
    int subjectID = ht_get(c->subjectToID, subjectName);
    if(subjectID==-1){
        printf("\033[1;31mInvalid subject\033[0m\n");
    }
    if(st_can_signup_to_subject(c, s, subjectName)) {
        s->subjectsInCourse = turnSubjectIdBitON(s->subjectsInCourse, subjectID);
    }else{
        printf("\033[1;31mFATAL ERROR CALL 911!\033[0m\n",subjectName);
    }
}

/**
 * Checks if Subject "subjectName" is in Subjects "InCourse" for Student "s"
 * @returns TRUE if it is, FALSE if not
 *
 * @param c->  Pointer to Career struct
 * @param s->  Pointer to Student struct
 */
bool st_is_signed_up(Career* c, Student* s, char* subjectName) {
    int subjectID = ht_get(c->subjectToID, subjectName);
    return (s->subjectsInCourse & subjectToBitSecuence(subjectID)) == subjectToBitSecuence(subjectID);

}

/**
 *  @pos Adds subject "subjectName" to the subjectsApproved correlatives
 */
void st_add_approved_subject_to_student(Career* c, Student* s, char*    subjectName, char grade) {
    int subjectID = ht_get(c->subjectToID, subjectName);
    if(st_is_signed_up(c, s, subjectName) && grade >= 4) {

        s->subjectsApproved = turnSubjectIdBitON(s->subjectsApproved, subjectID);
        s->subjectsInCourse = turnSubjectIdBitOFF(s->subjectsInCourse, subjectID);
        s->grade[subjectID] = grade;
    }
}

/**
 * Checks if Subject "subjectName" is approved for Student "s"
 * @returns TRUE if it is, FALSE if not
 *
 * @param c->  Pointer to Career struct
 * @param s->  Pointer to Student struct
 */
bool st_has_approved_subject(Career* c, Student* s, char* subjectName) {
    int subjectID = ht_get(c->subjectToID, subjectName);
    return  (s->subjectsApproved & subjectToBitSecuence(subjectID)) == subjectToBitSecuence(subjectID);
}


/**
 * @returns average with decimals from a student
 *
 * @param s-> Pointer to Student struct
 */
double st_get_averageGrade(Student* s){
    double avg =0;
    int aux = 0;
    for(int i=0; i<64;i++){
        if(s->grade[i]>0){
            avg += s->grade[i];
            aux++;
        }
    }
    return avg/aux;
}

/**
 * Converts takes bits converted to subject, then prints according to each
 * career ID/SubjectNames table. Do not call outside this class
 *
 * @param c  Pointer to Career struct
 */
void _st_print_subjects_from_bits(Career* c, int* array_of_approved_subjects) {
    for (int i = 0; i < 64; ++i) {
        if (array_of_approved_subjects[i] != 0) {
            printf("\t%s\n", c->idToSubject[array_of_approved_subjects[i]]);
        }
    }
}

/**
 * @pos prints approved correlatives of student in params
 *
 * @param c->  Pointer to Career struct
 * @param s->  Pointer to Student struct
 */
void st_print_approved_subjects(Career* c, Student* s) {
    char* binary_ids = longLongToBits(s->subjectsApproved);
    int* array_of_approved_subject_ids = bitsOnToArray(binary_ids);

    printf("\nMaterias aprobadas:\n");
    _st_print_subjects_from_bits(c, array_of_approved_subject_ids);

    free(array_of_approved_subject_ids);
    free(binary_ids);
}

/**
 * @pos prints in course correlatives of student in params
 *
 * @param c->  Pointer to Career struct
 * @param s->  Pointer to Student struct
 */
void st_print_in_course_subjects(Career* c, Student* s) {
    char* binary_ids = longLongToBits(s->subjectsInCourse);
    int* array_of_incourse_subject_ids = bitsOnToArray(binary_ids);

    printf("\nMaterias en curso:\n");
    _st_print_subjects_from_bits(c, array_of_incourse_subject_ids);

    free(array_of_incourse_subject_ids);
    free(binary_ids);
}

/**
 * @pos Prints personal info of Student "s"
 *
 * @param-> s  Pointer to Student struct
 */
void st_print_student(Student *p) {
    printf("\033[1;33mNombre: %s\tFecha de Nacimiento: %d/%d/%d\tDocumento: %d\033[0m\n", p->name, p->dateBirth->day, p->dateBirth->month,
           p->dateBirth->year,p->dni);
}


Student *st_create_student(const char *name, Date *date, int dni) {
    Student *std = malloc(sizeof(Student));
    std->grade = malloc(64*sizeof (char));
    st_set_name(std, name);
    st_set_birthdate(std, date);
    st_set_dni(std, dni);
    std->subjectsApproved = 0;
    std->subjectsInCourse = 0;
    for(int i=0; i<64;i++){
        std->grade[i]=0;
    }
    return std;
}


void _printSubjectsBits(Student *p) {
    _decimalToBinary(p->subjectsApproved);
}





