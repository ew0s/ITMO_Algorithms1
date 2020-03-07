#include <iostream>
#include <string>
using namespace std;

void radix_sort(string* mas, int n, int k, int m){
    string re_array[1000];

    while(m != 0) {

        int count[26] = {0};

        for (int i = 0; i < n; i++) {
            count[(int(mas[i][k]) + 7) % 26]++;
        }

        for (int i = 1; i < 26; i++){
            count[i] += count[i - 1];
        }

        for(int i = n - 1; i >= 0; i--){
            re_array[count[(int(mas[i][k]) + 7) % 26] - 1] = mas[i];
            count[(int(mas[i][k]) + 7) % 26] --;
        }

        for(int i = 0; i < n; i++){
            mas[i] = re_array[i];
        }

        k--;
        m--;
    }

    for(int i = 0; i < n; i++){
        cout << mas[i] << "\n";
    }
}

int main(){
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    int n, m, k;
    cin >> n >> k >> m;
    string arr[1000];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    radix_sort(arr, n, k - 1, m);
    return 0;
}