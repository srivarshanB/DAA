#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isPalindromeString(const char *str) {
    int len = strlen(str);
    int i;
    for ( i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}
int isPalindromeNumber(int num) {
    int originalNum = num;
    int reverseNum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        reverseNum = reverseNum * 10 + digit;
        num /= 10;
    }   
    return originalNum == reverseNum;
}
int main() {
    int choice;
    printf("Choose an option:\n");
    printf("1. Check if a string is a palindrome\n");
    printf("2. Check if a number is a palindrome\n");
    scanf("%d", &choice);   
    if (choice == 1) {
        char str[100];
        printf("Enter a string: ");
        scanf("%s", str);
        if (isPalindromeString(str)) {
            printf("Palindrome\n");
        } else {
            printf("Not a Palindrome\n");
        }
    } else if (choice == 2) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        if (isPalindromeNumber(num)) {
            printf("Palindrome\n");
        } else {
            printf("Not a Palindrome\n");
        }
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}
