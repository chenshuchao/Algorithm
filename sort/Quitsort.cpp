#include <iostream>

void swap(int A[], int index1, int index2){
    int t = A[index1];
    A[index1] = A[index2];
    A[index2] = t;
}
int partition(int A[], int low, int high) {
    int pivot = A[high];
    int i = low;
    int j = low - 1;
    for(; i < high; i++) {
        if(A[i] < pivot) {
            j ++;
            swap(A, i ,j);
        }
    }
    swap(A, j+1, high);
    return j+1;
}
void quickSort(int A[], int low, int high) {
    if(low >= high) return;
    int mid = partition(A, low, high);
    quickSort(A, low, mid-1);
    quickSort(A, mid+1, high);
}


void printArr(int A[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {

    int A[] = {3};
    int n = sizeof(A) / sizeof(int);
    printArr(A, n);
    
    quickSort(A, 0, n-1);
    printArr(A, n);
    
    return 0;
}

