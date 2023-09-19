#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*

Context II

Strong passwords are key to secure systems, we can not rely on employees to set strong passwords.
 You are required to generate a strong password to the user.

Tasks to complete
1. You request the user to enter two different words of your choice.
2. You take the first letter of the first word and capitalize
3. Take a random special character and append it to the letter returned in 2 above.
4. Take the second word and reverse it (ensure the second word is in lower case letters).
5. Take the reversed lower cased second word appended to the upper-cased later appended with the character returned.
6. Take another special character and append at the end of what you appended previously.
7. Take a random number (between 0 and 9) and append it to the end.

N.B: If the auto-generated password does not make the length of 8, you will add any random characters or numbers to make sure that the length is at least 8.
 */

/* Constant for the word length */
#define MAX_WORD_LEN 100

/**
 * Generates a special character.
 */
char random_special_char() {
    char special_chars[] = "!@#$%^&*()-_=+{}[]|;:'<>,.?/~";
    return special_chars[rand() % (sizeof(special_chars) - 1)];
}

/**
 * Generates a random number between 0 and 9.
 */
int random_number() {
    return rand() % 10;
}

/**
 * Main - Entry point
 * @return (0) - Success
 */
int main() {
    char password[9] = "";
    char word1[MAX_WORD_LEN], word2[MAX_WORD_LEN];
    printf("Welcome!Strong passwords are key to secure systems. This program will generate a password of 8 characters\n");
    printf("Enter the 1st word of your choice\n");

    scanf("%99s", word1);

    /*take the first letter of the first word and capitalize*/
    password[0] = (char) toupper(word1[0]);

    /*take a random special character and append it to the letter returned in 2 above*/
    password[1] = random_special_char();

    printf("Enter the second word\n");
    scanf("%99s", word2);

    /*ensure the second word is in lower case letters*/
    int i;
    for (i = 0; i < strlen(word2); ++i) {
        word2[i] = (char) tolower(word2[i]);
    }

    /*Reverse the second word*/

    int j = (int) strlen(word2) - 1;

    char reversed_word2[strlen(word2)];
    for (i = 0; i < strlen(word2); i++, j--) {
        reversed_word2[i] = word2[j];
    }
    /*append end of string char*/
    reversed_word2[j] = '\0';

    /*Take the reversed lower cased second word appended to the upper-cased later appended with the character returned*/
    strcpy(password + 2, reversed_word2);

    while (strlen(password) < 8)
        password[strlen(password)] = random_number();


    printf("Your password is %8s\n", password);

    return (0);
}
