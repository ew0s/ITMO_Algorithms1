#include <iostream>
#define mod 200001
using namespace std;


struct wood{
    int key;
    int left;
    int right;
    wood* left_key;
    wood* right_key;
};
wood arr[mod];



bool is_correct(wood* node, int min, int max) {

    if (node == nullptr){
        return true;
    }

    if(node->key <= min || node->key >= max){
        return false;
    }

    return is_correct(node->left_key, min, node->key) && is_correct(node->right_key, node->key, max);
}


int main() {
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    int n;
    int key;
    int left;
    int right;
    int max = 1000000001;
    int min = -1000000001;


    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> key >> left >> right;

        arr[i].key = key;
        arr[i].left = left;
        arr[i].right = right;

        if (left){
            arr[i].left_key = &arr[left];
        }

        if (right){
            arr[i].right_key = &arr[right];
        }
    }

    if (is_correct(&arr[1], min, max)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}