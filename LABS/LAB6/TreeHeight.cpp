#include <iostream>
#define mod 200001
using namespace std;


struct wood{
    int left;
    int right;
    wood* left_key;
    wood* right_key;
};
wood arr[mod];

void len_wood(int i, int maxi, int* global_max){

    if (arr[i].left_key){
        maxi++;
        len_wood(arr[i].left, maxi, global_max);
        maxi--;
    }

    if (arr[i].right_key){
        maxi++;
        len_wood(arr[i].right, maxi, global_max);
        maxi--;
    }

    if(!arr[i].left_key && !arr[i].right_key) {
        maxi++;
        if (maxi > *global_max) {
            *global_max = maxi;
        }
    }
}

int main() {
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int n;
    int key;
    int left;
    int right;
    int global_max_numb = 0;
    int* global_max = &global_max_numb;



    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> key >> left >> right;

        arr[i].left = left;
        arr[i].right = right;

        if (left){
            arr[i].left_key = &arr[left];
        }

        if (right){
            arr[i].right_key = &arr[right];
        }
    }
    if (n != 0) {
        len_wood(1, 0, global_max);
    }

    cout << *global_max;
    return 0;
}