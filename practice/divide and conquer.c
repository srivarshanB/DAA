#include <stdio.h>
int max(int arr[], int start, int end) {
    int i, max_val = arr[start];
    for (i = start + 1; i <= end; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}
int min(int arr[], int start, int end) {
    int i, min_val = arr[start];
    for (i = start + 1; i <= end; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }      
    }
    return min_val;
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_val = max(arr, 0, n - 1);
    int min_val = min(arr, 0, n - 1);
    printf("Maximum value in the list is %d\n", max_val);
    printf("Minimum value in the list is %d\n", min_val);
    return 0;
}
