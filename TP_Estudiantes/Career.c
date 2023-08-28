#include "ht.c"
#include "BitHandler.c"
typedef struct Career {
   unsigned long long correlatives[64];
   char* name;
   ht* subjectToID;
   char** idToSubject;
   int count;
} Career;
void cr_set_name(Career *s, char *name) {
    s->name = malloc(strlen(name) + 1);
    strcpy(s->name, name);
}
/**
 * @returns pointer to a Career struct
 */
Career * create_career(char* name) {
    Career* c = malloc(sizeof(Career));
    cr_set_name(c,name);
    c->subjectToID = ht_create();
    c->count = 0;
    for (int i = 0; i < 64; ++i) {
        c->correlatives[i] = 0;
    }
    c->idToSubject = (char**)malloc(64* sizeof(char*));

    for (int i = 0; i < 64; i++) {
        c->idToSubject[i] = (char*)malloc(100 * sizeof(char));
        if (c->idToSubject[i] == NULL) {
            printf("Memory allocation failed for string at index %d\n", i);
        }
    }
    //for (int i = 0; i < 64; ++i) {
    //    c->idToSubject[i] = NULL;
    //}

    return c;
}
void destroy_career(Career* career) {
    if (career) {
        free(career->name);
        ht_destroy(career->subjectToID);
        ht_destroy(career->idToSubject);
        ht_destroy(career->correlatives);
        free(career);
    }
}
/**
 * @pos Adds subject to a career, giving it an ID.
 * @note Subjects shouldn't be modified or added multiple times.
 */
void add_subject(Career* c, char* subjectName) {
    ht_set(c->subjectToID, subjectName, c->count);
    c->idToSubject[c->count] = subjectName;
    c->count++;
}



/**
 * Each subject is composed by an 64bit long long
 * @pos turns correlative ID (transformed to bit) from a 0 to a 1.
 */
void add_correlative_to_subject(Career* c, char* subjectName, char correlative) {
    int subjectID = ht_get(c->subjectToID, subjectName);
    if(subjectID==-1){
        printf("\033[1;31mInvalid subject\033[0m\n");
    }
    c->correlatives[subjectID] = turnSubjectIdBitON(c->correlatives[subjectID], correlative);

}

/**
 * @pos Adds multiple correlatives to the subject. Must specify the amount in amountOfSubjects
 */
void add_correlative_array_to_subject(Career* c, char* subjectName, char correlatives[], char amountOfSubjects) {
    for (int i = 0; i < amountOfSubjects; ++i) {
        add_correlative_to_subject(c, subjectName, correlatives[i]);
    }
}

void print_subjects(Career* c){

    for (int j = 0; j < 64; ++j) {
        if (c->idToSubject[j] != ""){
            if(strlen(c->idToSubject[j]) == 0){break;}
            printf("%d. ",j+1);
            printf("\033[1;33m%s\033[0m\n", c->idToSubject[j]);
        }
    }
}

char* get_career(Career* c){
    return c->name;
}

/**
 * used for testing
 */
void print_subject_correlatives_bits(Career* c, int subjectID){
    _decimalToBinary(c->correlatives[subjectID - 1]);
}



