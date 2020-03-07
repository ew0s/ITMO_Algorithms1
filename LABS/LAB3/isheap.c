#include<stdio.h>
#include <stdbool.h>

int main(){
    FILE *fin, *fout;
    fin  = fopen("isheap.in", "r");
    fout = fopen("isheap.out", "w");


    int n;
    fscanf(fin, "%d", &n);
    int arr[100001];
    bool check = true;

    for(int i = 1; i <= n; i++){
        fscanf(fin, "%d", &arr[i]);
    }
    fclose(fin);

    for(int i = 1; i <= n; i++){

        if(i * 2 <= n && arr[i] > arr[i * 2]){

                fprintf(fout, "NO");
                check = false;
                break;
        }

        if(i * 2 + 1 <= n && arr[i] > arr[i * 2 + 1]){

                fprintf(fout, "NO");
                check = false;
                break;
        }
    }

    if(check == true){
        fprintf(fout, "YES");
    }
    fclose(fout);

    return 0;
}