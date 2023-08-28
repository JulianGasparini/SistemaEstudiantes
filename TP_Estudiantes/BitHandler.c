#include <stdio.h>
#include "stdlib.h"

/**
 * Transforms bit position "subjectId" from a 64bit long number that is initialized
 *  as a 0(every position in binary representation is 0) into a 1
 * @param subjectId -> number between 0-63
 * @return A unsigned long long with binary position subjectId as 1
 */
unsigned long long subjectToBitSecuence(char subjectId){
    unsigned long long bits = 1;

    for (int i = 1; i < subjectId; ++i) {
        bits = bits*2;
    }
    return bits;
}

/**
 * @note Can be used to set correlatives or approved/in course correlatives
 * @pos Turns position indicated by subjectID into a 1 in the 64bit long indicated
 * by the parameter subject
 *
 * @param subject-> 64 bit positive only long
 * @param subjectID-> number between 0-63
 */
unsigned long long turnSubjectIdBitON(unsigned long long subject, char subjectID) {

    unsigned long long subjectBits = subjectToBitSecuence(subjectID);
    return subject | subjectBits;
}

/**
 * @note Can be used to remove correlatives or approved/in course correlatives
 * @pos Turns position indicated by subjectID into a 1 in the 64bit long indicated
 * by the parameter subject
 *
 * @param subject-> 64 bit positive only long
 * @param subjectID-> number between 0-63
 */
unsigned long long turnSubjectIdBitOFF(unsigned long long subject, char subjectID) {

    unsigned long long subjectBits = subjectToBitSecuence(subjectID);
    return subject ^ subjectBits;
}



/**
 * @param number -> 64 bit positive long
 * @return string/char pointer with the binary representation of number
 */
char* longLongToBits(long long number) {
    int bits = sizeof(long long) * 8;  // Cantidad de bits en un long long
    char* bitsStr = malloc(bits + 1);  // +1 para el carácter nulo al final

    // Copiar cada bit del número a la cadena de caracteres
    for (int i = 0; i < bits; i++) {
        bitsStr[bits - 1 - i] = (number & (1LL << i)) ? '1' : '0';
    }

    bitsStr[bits] = '\0';  // Agregar el carácter nulo al final

    return bitsStr;
}

/**
 *
 * @param bits -> 64 char long string with binary representation of 64bit positive long
 * @return array of 64 numbers where each ones contains the position turned on (1) bits from
 * the string "bits"
 */
int * bitsOnToArray(char* bits) {
    int * numbers = malloc(64*sizeof(int));
    for (int i = 0; i < 64; i++) {
        if (bits[i] == '1') {
            numbers[i] = 64-i;
        } else {
            numbers[i] = 0;
        }
    }
    return numbers;
}

/**
 * Converts 64 bit long into a int array of 64 elements in which
 * each position contains either 0 or 1 depending on the 64bit long binary representation
 * @note use for testing
 * @param num -> positive 64 bit number
 */
void _decimalToBinary(unsigned long long num) {
    printf("\n");
    if (num == 0) {
        printf("0");
        return;
    }

    // Stores binary representation of number.
    int binaryNum[64]; // Assuming 32 bit integer.
    int i = 0;

    for (; num > 0;) {
        binaryNum[i++] = num % 2;
        num /= 2;
    }

    // Printing array in reverse order.
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }

    printf("\n");
}