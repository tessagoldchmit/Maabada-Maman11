#include <stdio.h>

int count_bits(unsigned long num);


int main() {
    int bits_count;  /* number of bits that are turned on in even indexes */
    unsigned long num;  /* input number */

    /* get input from user */
    printf("The function summarizes and returns the number of bits that are turned on in even indexes.\n");
    printf("Enter a number for the test:\n");
    scanf("%lu", &num);
    printf("\nThe number that was entered is %lu.\n", num);

    bits_count = count_bits(num);  /* call the function to count the number of bits */
    printf("Number of even-indexed bits that are on: %d\n", bits_count);
    return 0;
}

/* function to count the number of bits that are turned on in even indices */
int count_bits(unsigned long num) {
    int count = 0;  /* count of bits */
    int i = 0;  /* index for while loop */

    while (i < 8) {
        unsigned long bit = (num >> i) & 00000001;  /* get the last bit only */
        if (bit == 1) {
            count++;  /* increment the counter if the bit is turned on */
        }
        i += 2;  /* move to the next even index */
    }
    return count;   /* return the count of bits that are turned on in even indexes */
}