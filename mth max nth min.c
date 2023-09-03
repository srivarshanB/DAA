#include <stdio.h>

void findMinMaxSumDiff(int arr[], int size, int M, int N) {
    if (M <= 0 || N <= 0 || M > size || N > size) {
        printf("Illegal input\n");
        return;
    }

    // Sort the array in ascending order
    int i,j;
    for ( i = 0; i < size - 1; i++) {
        for ( j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int MthMax = arr[size - M];
    int NthMin = arr[N - 1];
    int sum = MthMax + NthMin;
    int diff = MthMax - NthMin;

    printf("M-th maximum: %d\n", MthMax);
    printf("N-th minimum: %d\n", NthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
}

int main() {
    int arr[] = {16,16,16,16,16};
    int M = 0;
    int N = 1;

    int size = sizeof(arr) / sizeof(arr[0]);

    findMinMaxSumDiff(arr, size, M, N);

    return 0;
}
