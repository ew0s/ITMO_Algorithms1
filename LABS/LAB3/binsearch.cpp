#include <stdio.h>

int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    int n, m, key, lR = -1, RR = -1, first, last;
    int arr[100000];
    int mid;
    scanf("%i", &n);

    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }

    scanf("%i", &m);

    for(int i = 0; i < m; i++){
        scanf("%i", &key);
        first = 0;
        last = n-1;
        if (key < arr[first] || key > arr[last])
        {
            printf("-1 -1\n");
        }
        else
        {
            while (first < last)
            {
                mid = (first + last) / 2;
                if (key <= arr[mid]) last = mid;
                else first = mid + 1;
            }
            if (arr[last] == key){

                lR=last;
                while(lR>0 && (arr[lR - 1] == key)){
                    lR--;
                }

                RR = last;

                while(RR < n-1 && arr[RR + 1] == key){
                    RR++;
                }
                printf("%i %i\n", lR + 1,RR + 1);
            }
            else {
                printf("-1 -1\n");
            }
        }
    }
    return 0;
}