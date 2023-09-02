#include <stdio.h>
#include <stdbool.h>
void sieveOfEratosthenes(int limit) { 
    bool isPrime[limit + 1];
    int i,num,multiple;
    for (i = 0; i <= limit; i++) {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (num = 2; num * num <= limit; num++) {
        if (isPrime[num] == true) {
            for ( multiple = num * num; multiple <= limit; multiple += num) {
                isPrime[multiple] = false;
            }
        }
    }   
    printf("Prime numbers up to %d are:\n", limit);
	for (i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
int main() {
    int limit;
    printf("Enter the limit to generate prime numbers: ");
    scanf("%d", &limit);
    sieveOfEratosthenes(limit);
    return 0;
}
 
