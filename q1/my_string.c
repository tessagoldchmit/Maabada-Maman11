#include <stdio.h>

/* function declarations */
int my_strcmp(char cs[], char ct[]);

int my_strncmp(char cs[], char ct[], int n);

int my_strchr(char cs[], char c);

int main() {
    char cs[80];
    char ct[80];
    int n;
    char c;

    int my_strcmp_result;
    int my_strncmp_result;
    int my_strchr_result;

    /* get input from user */
    printf("In the following code we will run 3 functions that implement the functions strcmp, strncmp, strchr.\n"
           "For the my_strcmp function we will receive 2 strings.\n"
           "For the my_strncmp function we will also receive a number n.\n"
           "For the my_strchr function we will receive a character c and check if it appears in the first string that was entered.\n");

    printf("\nEnter string 1:\n");
    scanf("%s", cs);

    printf("Enter string 2:\n");
    scanf(" %s", ct);

    printf("Enter n (used for my_strncmp):\n");
    scanf(" %d", &n);

    printf("Enter c (used for my_strchr):\n");
    scanf(" %c", &c);

    printf("\nThe strings that were entered are %s, %s.\n", cs, ct);
    printf("The param n equals to %d.\n", n);
    printf("The param c equals to %d.\n", c);

    /* get results for all functions */
    my_strcmp_result = my_strcmp(cs, ct);
    my_strncmp_result = my_strncmp(cs, ct, n);
    my_strchr_result = my_strchr(cs, c);

    /* my_strcmp results */
    printf("\n/*** my_strcmp results ***/\n");
    if (my_strcmp_result < 0) {
        printf("%s is less than %s\n", cs, ct);
    } else if (my_strcmp_result > 0) {
        printf("%s is greater than %s\n", cs, ct);
    } else {
        printf("%s is equal to %s\n", cs, ct);
    }

    /* my_strncmp results */
    printf("\n/*** my_strncmp results ***/\n");
    if (my_strncmp_result < 0) {
        printf("%s is less than %s for the first %d characters\n", cs, ct, n);
    } else if (my_strncmp_result > 0) {
        printf("%s is greater than %s for the first %d characters\n", cs, ct, n);
    } else {
        printf("%s is equal to %s for the first %d characters\n", cs, ct, n);
    }

    /* my_strchr results */
    printf("\n/*** my_strchr results ***/\n");
    printf("The index of %c in %s is %d\n", c, cs, my_strchr_result);


    return 0;
}

int my_strcmp(char cs[], char ct[]) {
    int i = 0;
    while (cs[i] != '\0' && ct[i] != '\0') {
        if (cs[i] != ct[i]) {
            return cs[i] - ct[i];
        }
        i++;
    }
    return cs[i] - ct[i];  /* return the difference between the two terminating characters */
}

int my_strncmp(char cs[], char ct[], int n) {
    int i = 0;
    while (i < n && cs[i] != '\0' && ct[i] != '\0') {
        if (cs[i] != ct[i]) {
            return cs[i] - ct[i];
        }
        i++;
    }
    if (i == n || cs[i] == ct[i]) { /* if n characters have been compared or the two terminating characters are equal */
        return 0;
    }
    return cs[i] - ct[i]; /* return the difference between the two non-matching characters */
}

int my_strchr(char cs[], char c) {
    int i = 0;
    while (cs[i] != '\0') {
        if (cs[i] == c) {
            return i;  /* return the index where the character is found */
        }
        i++;
    }
    return -1;
}