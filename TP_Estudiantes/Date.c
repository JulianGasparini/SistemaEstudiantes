#include <stdlib.h>
#include <time.h>

typedef struct Date {
    int day, month, year;
} Date;

Date* construct_date(int day, int month, int year) {
    Date* d = malloc(sizeof(Date));
    d->month=month;
    d->day=day;
    d->year=year;

    return d;
}
/**
 * @returns current age using local time of the device running the program
 */
int calculateAge(Date* birth_date) {
    time_t actualTime = time(NULL);
    struct tm* actualTimeStruct = localtime(&actualTime);

    int actualYear = actualTimeStruct->tm_year + 1900;
    int actualMonth = actualTimeStruct->tm_mon + 1;
    int actualDay = actualTimeStruct->tm_mday;

    int age = actualYear - birth_date->year;

    if (actualMonth < birth_date->month || (actualMonth == birth_date->month && actualDay < birth_date->day)) {
        age--;
    }

    return age;
}
