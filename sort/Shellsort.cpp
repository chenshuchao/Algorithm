#include <iostream>

void shellSort(int A[], int n) {
   
    int i, j;
    int temp;
    int k = n / 2;
    while(k > 0) {
        for(i = k; i < n; i++) {
            temp = A[i];
            for(j = i - k; j >= 0 && A[j] > temp; j = j - k) {
                A[j+k] = A[j];
            }
            A[j+k] = temp;
        }
        k = k / 2;
    }
}


void printArr(int A[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {

    int A[] = {3, 2, 4, 14, 7, 6, 9};
    int n = sizeof(A) / sizeof(int);
    printArr(A, n);
    shellSort(A, n);
    printArr(A, n);
    
    return 0;
}

