#include<stdio.h>

void swap(int* a, int a1, int a2){
    int temp = a[a1];
    a[a1] = a[a2];
    a[a2] = temp;
}



void heapify(int* a, int n, int i){
    int largest = i;
    int left = i*2 + 1;
    int right = i*2 + 2;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }

    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest != i){
        swap(a, i, largest);

        heapify(a, n, largest);
    }

}


void heap_sort(int* a, int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }

    for(int i = n - 1; i >= 0; i--){
        swap(a, 0, i);

        heapify(a, i, 0);
    }
}




int main() {
    FILE *fin, *fout;
    fin  = fopen("sort.in", "r");
    fout = fopen("sort.out", "w");

    int n;
    fscanf(fin, "%d", &n);
    int arr[100000];

    for(int i = 0; i < n; i++){
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);
    heap_sort(arr, n);

    for(int i = 0; i < n; i++){
        fprintf(fout, "%d ", arr[i]);
    }
    fclose(fout);

    return 0;
}