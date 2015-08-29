#include <iostream>

void insertSort(int A[], int n) {
   
    int i, j;
    int temp;
    for(i = 1; i < n; i++) {
        temp = A[i];
        for(j = i - 1; j >= 0 && A[j] > temp; j--) {
            A[j+1] = A[j];
        }
        A[j+1] = temp;
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
    insertSort(A, n);
    printArr(A, n);
    
    return 0;
}

