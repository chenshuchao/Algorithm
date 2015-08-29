#include <iostream>
using namespace std;

/* 递归实现
 *
// 将 r[s,m] r[m+1,t] 二路归并
void merge(int r[], int s, int m , int t, int temp[]) {
    int i = s;
    int j = m + 1;
    int k = 0;
    while(i <= m && j <= t) {
        if (r[i] < r[j])
            temp[k++] = r[i++];
        else 
            temp[k++] = r[j++];
    }
    while(i <= m) temp[k++] = r[i++];
    while(j <= t) temp[k++] = r[j++];

    for(int i = 0; i < k; i++) {
        r[s+i] = temp[i];
    }
}

// 将 r[s,t] 归并排序
void mergeSort(int r[], int s, int t, int temp[]) {
    if(s < t) {
        int m = (s + t) / 2;
        mergeSort(r, s, m, temp);
        mergeSort(r, m+1, t, temp);
        merge(r, s, m, t, temp);
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
    int *temp = new int[n];
    printArr(A, n);
    mergeSort(A, 0, n-1, temp);
    printArr(A, n);
    
    return 0;
}
*/


/* 非递归实现
*/

void merge(int r[], int s, int m , int t, int temp[]) {
    int i = s;
    int j = m + 1;
    int k = s;
    while(i <= m && j <= t) {
        if (r[i] < r[j])
            temp[k++] = r[i++];
        else 
            temp[k++] = r[j++];
    }
    while(i <= m) temp[k++] = r[i++];
    while(j <= t) temp[k++] = r[j++];
}
void mergePass(int r[], int n, int h, int temp[]) {
    int i = 0;
    while(i < (n - 2*h + 1)) {
        merge(r, i, i+h-1, i+2*h-1, temp);
        i += 2*h;
    }
    if(i < n - h) {
        merge(r, i, i+h-1, n-1, temp);
    } else {
        for(; i < n; i++) {
            temp[i] = r[i]; 
        }
    }
}
void mergeSort(int r[], int n) {
    int *temp = new int[n];
    int h = 1;
    while(h < n) {
        mergePass(r, n, h, temp);
        for(int i = 0; i < n; i++) {
            r[i] = temp[i];
        }
        h = h * 2;
    }
    delete[] temp;
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
    mergeSort(A, n);
    printArr(A, n);
    
    return 0;
}

