#include<iostream>
#include <fstream>
using namespace std;


void merge(int *array, int l, int m, int r) {
    int i, j, k, leftIndex, rightIndex;
    leftIndex = m - l + 1; rightIndex = r - m;
    int leftArray[leftIndex], rightArray[rightIndex];

    for(i = 0; i < leftIndex; i++)
        leftArray[i] = array[l + i];

    for(j = 0; j < rightIndex; j++)
        rightArray[j] = array[m + 1 + j];
    i = 0; j = 0; k = l;

    while(i < leftIndex && j < rightIndex) {
        if(leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }else{
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
    
    while(i < leftIndex) {
        array[k] = leftArray[i];
        i++; k++;
    }
    
    while(j < rightIndex) {
        array[k] = rightArray[j];
        j++; k++;
    }
}


void mergeSort(int *array, int l, int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);
        merge(array, l, m, r);
    }
}


int main() {
    int n;
    ifstream fin ("sort.in");
    fin >> n;
    int array[n];
    for(int i = 0; i < n; i++) {
        fin >> array[i];
    }
    fin.close();

    mergeSort(array, 0, n - 1);

    ofstream fout ("sort.out");
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    fout.close();
    return 0;
}