#include <iostream>
using namespace std;

void partition(int *array, int begin, int end, int k){
   int left = begin, right = end, piv = array[(begin + end) / 2];

    while(left <= right){
       while(array[left] < piv){
           left++;
       }

       while(array[right] > piv){
           right--;
       }

       if(left <= right){
           swap(array[left], array[right]);
           left++;
           right--;
       }
   }

   if(right > begin && k <= right){
       partition(array, begin, right, k);
   }

   if(left < end && k >= right){
       partition(array, left, end, k);
   }
}


int main(){
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);

    int n, k, a, b, c;
    cin >> n >> k >> a >> b >> c;
    int arr[n + 1];

    if (n == 1){
        cin >> arr[1];
    } else {
        cin >> arr[1] >> arr[2];
    }

    for(int i = 3; i <= n; i++){
        arr[i] = a * arr[i - 2] + b * arr[i - 1] + c;
    }

    partition(arr, 1, n, k);

    cout << arr[k];

    return 0;
}