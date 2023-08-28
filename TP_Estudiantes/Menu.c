#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <stdbool.h>
#include "ComputerEngineering.c"
#define ELEMENTOS_POR_PAGINA 5



void mostrarPagina(int pagina, LinkedList* list) {
    int elementoInicial = (pagina - 1) * ELEMENTOS_POR_PAGINA;
    int elementoFinal = elementoInicial + ELEMENTOS_POR_PAGINA - 1;

    printf("--- Página %d ---\n", pagina);

    Node* current = list->head;
    int i = 0;

    while (current != NULL && i < elementoFinal) {
        if (i >= elementoInicial) {
            st_print_student(current->data);
        }
        current = current->next;
        i++;
    }

    printf("----------------\n");
}



void paginado(LinkedList* list){
    int totalElementos = size_of_list(list);
    int totalPaginas = (totalElementos + ELEMENTOS_POR_PAGINA - 1) / ELEMENTOS_POR_PAGINA;
    int paginaActual = 1;

    char opcion;

    do {
        mostrarPagina(paginaActual, list);

        printf("Navegacion: [P]agina anterior  [S]iguiente pagina  [Q]Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &opcion);

        if (opcion == 'P' || opcion == 'p') {
            if (paginaActual > 1) {
                paginaActual--;
            } else {
                printf("Ya estas en la primera pagina.\n");
            }
        } else if (opcion == 'S' || opcion == 's') {
            if (paginaActual < totalPaginas) {
                paginaActual++;
            } else {
                printf("Ya estas en la ultima pagina.\n");
            }
        }
    } while (opcion != 'Q' && opcion != 'q');

}

void sistemaEstudiantes(Career* career){
    LinkedList* lista = create_sts();
    int opcion, ageMin=0, ageMax=0;
    char continuar;
    bool bandera = false;
    int dia=0, mes=0, anio=0, dni=0;
    char carrera[100];
    Career* ing = career;
    Student* studentSearch=NULL;
    char nombre[100];
    char nombre_materia[100];

    do{
        system("cls");
        usleep(10000);
        printf("\033[1;32m******************************************************\033[0m\n");
        printf("\033[1;32m*****************\033[0m \033[1;36mPROGRAMA ESTUDIANTES\033[0m \033[1;32m***************\033[0m\n");
        usleep(3000);
        printf("\033[1;32m*************\033[0m \033[1;36m");
        printf("%s", get_career(career));
        printf("\033[0m \033[1;32m*************\033[0m\n");
        printf("\033[1;32m******************************************************\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m1. Anotar Estudiante\033[0m                            \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m2. Inscribirse en Materia\033[0m                       \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m3. Rendir Materia\033[0m                               \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m4. Buscar estudiante por nombre\033[0m                 \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m5. Buscar estudiante por edad\033[0m                   \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m6. Listar estudiantes\033[0m                           \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m7. Filtrar estudiantes por materia\033[0m              \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m8. Estudiantes inscribibles en la materia.\033[0m      \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m    \033[0;35m9. Filtrar estudiantes por materia aprobada\033[0m     \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m10. Promedio de estudiante por materia\033[0m           \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m11. Salir\033[0m                                        \033[1;32m*\033[0m\n");
        printf("\033[1;32m******************************************************\033[0m\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                system("cls");

                do{
                    printf("Ingrese una fecha (dd/mm/yyyy): \n");
                    scanf("%d/%d/%d", &dia, &mes, &anio);
                    system("cls");
                    printf("dia: %d mes: %d anio: %d\n", dia, mes, anio);

                    if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && anio >= 1000 && anio <= 9999) {
                        printf("Fecha valida: %d/%d/%d\n", dia, mes, anio);
                        break;
                    } else {
                        printf("Fecha invalida. Ingrese una fecha en formato dd/mm/yyyy.\n");
                    }
                }while(bandera == false);

                printf("Ingrese nombre y apellido: \n");

                getchar();
                fgets(nombre, sizeof(nombre), stdin);

                size_t length = strlen(nombre);
                if (nombre[length - 1] == '\n') {
                    nombre[length - 1] = '\0';
                }

                printf("\nIngrese dni: \n");
                scanf("%d", &dni);

                Date* date = construct_date(dia,mes,anio);

                Student* student = st_create_student(nombre, date, dni);

                st_print_student(student);
                list_add_node(lista, student);
                Node *pointer = lista->head;

                printf("Presione una tecla para continuar...");

                getch();
                break;

            case 2:
                system("cls");
                printf("Ingrese dni del estudiante a inscribir: ");
                scanf("%d", &dni);

                studentSearch = get_student_by_DNI(lista, dni);
                if (studentSearch != NULL){
                    st_print_student(studentSearch);
                    printf("Ingrese nombre de la materia a inscribir: \n");
                    usleep(50000);
                    print_subjects(ing);
                    getchar();
                    fgets(carrera, sizeof(carrera), stdin);

                    size_t length = strlen(carrera);
                    if (carrera[length - 1] == '\n') {
                        carrera[length - 1] = '\0';
                    }
                   //printf("\n%d", ht_get(ing->subjectToID, carrera));
                    st_sing_up_student_to_subject(ing, studentSearch, carrera);
                } else {
                    printf("El estudiante con dni %d no se encontro.\n", dni);
                }

                printf("Presione una tecla para continuar...");
                fflush(stdin);
                getch();

                break;
            case 3:
                system("cls");
                int grade=0;
                printf("Ingrese dni del estudiante a inscribir: ");
                scanf("%d", &dni);

                studentSearch = get_student_by_DNI(lista, dni);
                if (studentSearch != NULL){
                    st_print_student(studentSearch);

                    printf("Ingrese nombre de la materia a rendir: ");
                    print_subjects(ing);
                    scanf("%s", carrera);

                    printf("Ingrese nota: ");
                    scanf("%d", &grade);

                    st_add_approved_subject_to_student(ing, studentSearch, carrera, grade);
                } else {
                    printf("El estudiante con dni %d no se encontro.\n", dni);
                }

                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 4:
                system("cls");
                printf("\nIngrese nombre del estudiante a buscar: \n");

                getchar();
                fgets(nombre, sizeof(nombre), stdin);

                // Remove newline character if present
                size_t len = strlen(nombre);
                if (nombre[length - 1] == '\n') {
                    nombre[length - 1] = '\0';
                }
                print_student_by_name(lista, nombre);
                //st_print_in_course_subjects(ing, studentSearch);

                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;

            case 5:
                system("cls");
                printf("Ingrese edad minima del estudiante a buscar: \n");
                scanf("%d", &ageMin);

                printf("Ingrese edad maxima del estudiante a buscar: \n");
                scanf("%d", &ageMax);

                print_student_by_age_range(lista, ageMin, ageMax);
                //st_print_in_course_subjects(ing, studentSearch);
                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 6:
                system("cls");
                paginado(lista);
                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 7:
                system("cls");

                printf("Ingrese el nombre de la materia para filtrar: ");
                print_subjects(ing);
                getchar();
                fgets(carrera, sizeof(carrera), stdin);

                size_t length2xd = strlen(carrera);
                if (carrera[length2xd - 1] == '\n') {
                    carrera[length2xd - 1] = '\0';
                }
                print_students(filter_students_signed_up_to_subject(lista, career, carrera));
                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 8:
                system("cls");

                printf("Ingrese el nombre de la materia para filtrar: ");
                getchar();
                fgets(carrera, sizeof(carrera), stdin);

                size_t length3xd = strlen(carrera);
                if (carrera[length3xd - 1] == '\n') {
                    carrera[length3xd - 1] = '\0';
                }
                print_students(filter_students_able_to_signup_to_subject(lista, career, carrera));

                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 9:
                system("cls");

                printf("Ingrese el nombre de la materia para filtrar: ");
                print_subjects(ing);
                getchar();
                fgets(nombre_materia, sizeof(nombre_materia), stdin);

                size_t size_tres = strlen(nombre_materia);
                if (nombre_materia[size_tres - 1] == '\n') {
                    nombre_materia[size_tres - 1] = '\0';
                }
                print_students(filter_students_with_approved_subject(lista, career, nombre_materia));

                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 10:
                system("cls");

                printf("El promedio es: %.2f", get_average_of_student_list(lista));

                fflush(stdin);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 11:
                destroy_career(carrera);
                delete_list(lista);
                break;
            default:
                system("cls");
                printf("Opcion fuera de rango, elija opciones entre 1 y 4.\nPresione una tecla para regresar al menu.");
                printf("Presione una tecla para continuar...");
                getch();
                break;
        }
    }while(opcion != 11);
    delete_list(lista);
}

void sistemaCarrera(Career* career){
    int opcion1;
    char corr;
    char* subname;
    do{

        usleep(3000);
        system("cls");
        usleep(3000);
        printf("\033[1;32m**********************************\033[0m\n");
        printf("\033[1;32m******\033[0m \033[1;36m");
        printf("%s", get_career(career));
        printf("\033[0m \033[1;32m******\033[0m\n");
        printf("\033[1;32m**********************************\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m1. Anadir Materia        \033[0m  \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m2. Anadir Correlativas   \033[0m  \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m3. Lista de Materias     \033[0m  \033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m5. Salir                 \033[0m  \033[1;32m*\033[0m\n");
        printf("\033[1;32m**********************************\033[0m\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion1);

        switch (opcion1) {

            case 1:
                system("cls");
                printf("Ingrese el nombre de la materia nueva: ");
                scanf("%s", &subname);
                add_subject(career,&subname);
                printf("%s anadida con exito!\n",&subname);
                printf("Presione una tecla para continuar...");
                fflush(stdin);
                getch();
                break;

            case 2:
                system("cls");
                printf("Ingrese el nombre de la materia que desea anadirle una correlativa: \n");
                print_subjects(career);
                scanf("%s", &subname);
                printf("Ingrese el numero correspondiente a la correlativa que desea anadir: \n");
                print_subjects(career);
                scanf("%d", &corr);
                usleep(15000);
                printf("\tCareer: %s\n\tSubject: %s\n\tCorrelative: %d\n", get_career(career),&subname,corr);
                usleep(15000);
                add_correlative_to_subject(career,&subname,corr);
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 3:
                system("cls");
                usleep(10000);
                print_subjects(career);
                printf("Presione una tecla para continuar...");
                getch();
                break;
        }
    }while(opcion1!=5);
}
void seleccionCarreras(LinkedList* carreras){
    char name[100];
    int opCarreras;
    int opcion2;
    do{
        usleep(4000);
        system("cls");
        printf("\033[1;32m**********************************\033[0m\n");
        printf("\033[1;32m******\033[0m \033[1;36mCARRERAS\033[0m \033[1;32m******\033[0m\n");
        printf("\033[1;32m**********************************\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m1. Crear Carrera         \033[0m\033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m2. Seleccionar Carrera   \033[0m\033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m5. Salir                 \033[0m\033[1;32m*\033[0m\n");
        printf("\033[1;32m**********************************\033[0m\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion2);
        switch (opcion2) {
            case 1:
                system("cls");
                printf("Ingrese el nombre de la carrera nueva: ");
                getchar();
                fgets(name, sizeof(name), stdin);

                size_t length = strlen(name);
                if (name[length - 1] == '\n') {
                    name[length - 1] = '\0';
                }
                Career* c = create_career(name);
                list_add_node(carreras, c);
                sistemaCarrera(c);

            case 2:
                system("cls");
                printf("Seleccione la carrera que desea acceder: \n");
                usleep(10000);
                for (int i = 0; i < size_of_list(carreras); i++) {
                    usleep(10000);
                    printf("%d. ", i + 1);
                    printf("\033[1;33m%s\033[0m\n", get_career(list_get(carreras, i)));
                };
                scanf("%d", &opCarreras);

                Career* c2 = (Career *)list_get(carreras,opCarreras-1);

                sistemaCarrera(c2);
        }
    }while(opcion2!=5);
}
void menu(LinkedList* carreras){
    int opcion;
    int opCarreras;

    do {
        system("cls");
        usleep(6000);
        printf("\033[1;32m**********************************\033[0m\n");
        printf("\033[1;32m*************\033[0m \033[1;36mUNTREF\033[0m \033[1;32m*************\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m1. Sistema Estudiante    \033[0m\033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m2. Sistema de Carreras   \033[0m\033[1;32m*\033[0m\n");
        printf("\033[1;32m*\033[0m   \033[0;35m5. Salir                 \033[0m\033[1;32m*\033[0m\n");
        printf("\033[1;32m**********************************\033[0m\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Seleccione la carrera que desea acceder: \n");
                for(int i = 0; i< size_of_list(carreras);i++){
                    printf("%d. ",i+1);

                    printf("\033[1;33m%s\033[0m\n", get_career(list_get(carreras,i)));
                };
                scanf("%d", &opCarreras);


                sistemaEstudiantes((Career *)list_get(carreras,opCarreras-1));

            case 2:
                system("cls");
                seleccionCarreras(carreras);
        }


    }while(opcion != 5);


}
int main(){
    LinkedList* carreras = create_list();

    list_add_node(carreras, initialize_lollxd());
    list_add_node(carreras,initialize_computer_data());
    list_add_node(carreras,initialize_computer_engineering());

    menu(carreras);
    for(int i = 0; i<3;i++){
        destroy_career(list_get(carreras,i));
    }
    delete_list(carreras);
}