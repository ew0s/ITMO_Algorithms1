#include <iostream>
#define mod 1000000

using namespace std;

struct hash_table {
    hash_table* prev = nullptr;
    hash_table* prev_key = nullptr;
    string key;
    string value;
    hash_table* next = nullptr;
    hash_table* next_key = nullptr;
};
hash_table* arr[mod];

hash_table* make_hash(string& key, string& value) {
    auto* hash = new hash_table();
    hash->prev = nullptr;
    hash->prev_key = nullptr;
    hash->key = key;
    hash->value = value;
    hash->next_key = nullptr;
    hash->next = nullptr;

    return hash;
}

hash_table* add_hash(hash_table*& last, string& key, string& value) {
    hash_table* hash = make_hash(key, value);
    hash->prev = last;
    last->next = hash;

    return hash;
}

int get_hash(string& key) {
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
        return (mod - abs(hash) % mod);
    }
}

hash_table* hash_put(string& key, string& value, hash_table*& last) {
    int hash = get_hash(key);
    hash_table* head = arr[hash];

    if (head) {
        hash_table* qur = head;
        while (qur->next) {
            if (qur->key == key) {
                qur->value = value;
                return nullptr;
            }
            qur = qur->next;
        }

        if (qur->key != key) {
            hash_table* new_hash = add_hash(qur, key, value);
            new_hash->prev_key = last;

            if (last) last->next_key = new_hash;

            return new_hash;
        }

        else {
            qur->value = value;
            return nullptr;
        }
    }

    else {
        arr[hash] = make_hash(key, value);
        arr[hash]->prev_key = last;

        if (last) last->next_key = arr[hash];

        return arr[hash];
    }
}

void hash_delete(string& key, hash_table*& last) {
    int hash = get_hash(key);
    hash_table* qur = arr[hash];

    while (qur) {
        if (qur->key == key) {
            if (last == qur){
                last = qur->prev_key;
            }

            if (qur->prev_key){
                qur->prev_key->next_key = qur->next_key;
            }

            if (qur->next_key){
                qur->next_key->prev_key = qur->prev_key;
            }

            if (qur->prev){
                qur->prev->next = qur->next;
            }

            if (qur->next){
                qur->next->prev = qur->prev;
            }

            if (qur == arr[hash]){
                arr[hash] = nullptr;
            }

            free(qur);
            return;
        }

        qur = qur->next;
    }
}

void hash_get(string& key) {
    hash_table* qur = arr[get_hash(key)];
    while (qur) {
        if (qur->key == key) {
            cout << qur->value << "\n";
            return;
        }
        qur = qur->next;
    }
    cout << "none" << '\n';
}

hash_table* hash_find(string& key) {
    hash_table* cur = arr[get_hash(key)];
    while (cur) {
        if (cur->key == key)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}

void hash_prev(string& key) {
    hash_table* element = hash_find(key);

    if (element && element->prev_key) cout << element->prev_key->value << "\n";
    else cout << "none" << '\n';
}

void hash_next(string& key) {
    hash_table* element = hash_find(key);

    if (element && element->next_key) cout << element->next_key->value << "\n";
    else cout << "none" << '\n';
}

int main() {
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    hash_table* last = nullptr;
    string command;
    string key;
    string value;

    while (cin >> command) {
        cin >> key;

        if (command == "put") {
            cin >> value;
            hash_table* pointer = hash_put(key, value, last);
            if (pointer) last = pointer;
        }

        else if (command == "delete") {
            hash_delete(key, last);
        }

        else if (command == "get") {
            hash_get(key);
        }

        else if (command == "prev") {
            hash_prev(key);
        }

        else if (command == "next") {
            hash_next(key);
        }
    }

    return 0;
}