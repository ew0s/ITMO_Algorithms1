#include <iostream>
#include <string>
#define mod 100000
using namespace std;

struct hash_table{
    string key;
    string value;
    hash_table* next;
};
hash_table* arr[mod];


int get_hash(const string& key) {
    const int p = 31;
    int hash = 0, p_pow = 1;
    for (char i : key)
    {
        hash += (i - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    if (hash >= 0) {
        return hash % mod;
    }
    else {
        return (mod - abs(hash) % mod) % mod;
    }
}


void put(const string& x, const string& y, int hash){
    auto* el = new hash_table();
    el->key = x;
    el->value = y;

    if (!arr[hash]){
        arr[hash] = el;
    }
    else{
        hash_table** q = &arr[hash];

        while((*q)->next != nullptr && (*q)->key != x){
            q = &(*q)->next;
        }

        if((*q)->key == x){
            (*q)->value = y;
        }

        else if((*q)->next == nullptr){
            (*q)->next = el;
        }
    }
}


void del(const string &x, int hash){
    if (arr[hash]){
        if (arr[hash]->key == x){
            arr[hash] = arr[hash]->next;
        }

        else if (arr[hash]->next){
            hash_table** prev = &arr[hash];
            hash_table** q = &(*prev)->next;

            while ((*q)->next != nullptr && (*q)->key != x){
                prev = q;
                q = &(*q)->next;
            }

            if ((*q)->key == x){
                (*prev)->next = (*q)->next;
            }
        }
    }
}


void get(const string &x, int hash){
    if(arr[hash]){
        hash_table* q = arr[hash];

        while(q->next != nullptr && q->key != x){
            q = q->next;
        }

        if(q->key == x){
            cout << q->value << "\n";
            return;
        }

        else{
            cout << "none\n";
            return;
        }
    }
    else{
        cout << "none\n";
        return;
    }
}


int main() {
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    string operators;
    string key;
    string str;
    int hash;

    while(cin >> operators){
        cin >> key;

        hash = get_hash(key);

        if (operators == "put"){
            cin >> str;
            put(key, str, hash);
        }

        else if(operators == "delete"){
            del(key, hash);
        }

        else if(operators == "get"){
            get(key, hash);
        }
    }
    return 0;
}