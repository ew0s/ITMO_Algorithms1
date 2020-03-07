#include <iostream>
#include <string>
#define mod 100000
using namespace std;


struct hash_table{
    int value;
    hash_table* next;
};
hash_table* arr[mod];


void hash_in(int x, int hash){
    auto* el = new hash_table();
    el->value = x;

    if (!arr[hash]){
        arr[hash] = el;

    } else{
        hash_table** q = &arr[hash];

        while ((*q)->next != nullptr && (*q)->value != x){
            q = &(*q)->next;
        }

        if ((*q)->next == nullptr && (*q)->value != x){
            (*q)->next = el;
        }
    }
}


void hash_delete(int x, int hash){
    if (arr[hash]){
        if (arr[hash]->value == x){
            arr[hash] = arr[hash]->next;
        }

        else if (arr[hash]->next){
            hash_table** prev = &arr[hash];
            hash_table** q = &(*prev)->next;

            while ((*q)->next != nullptr && (*q)->value != x){
                prev = q;
                q = &(*q)->next;
            }

            if ((*q)->value == x){
                (*prev)->next = (*q)->next;
            }
        }
    }
}


void hash_exists(int x, int hash){
    if(arr[hash]){
        hash_table* q = (arr[hash]);

        while (q->next != nullptr && q->value != x){
            q = q->next;
        }

        if(q->value == x){
            cout << "true" << "\n";
            return;
        }

        else{
            cout << "false" << "\n";
            return;
        }
    }

    else{
        cout << "false" << "\n";
        return;
    }
}


int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int numb;
    int hash;
    string operators;

    while (cin >> operators) {
        cin >> numb;
        hash = abs(numb) % mod;

        if (operators == "insert") {
            hash_in(numb, hash);
        }

        else if (operators== "delete"){
            hash_delete(numb, hash);
        }

        else if (operators == "exists") {
            hash_exists(numb, hash);
        }
    }
    return 0;
}