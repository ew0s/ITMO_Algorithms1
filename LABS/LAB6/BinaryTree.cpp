#include <iostream>
#include <string>
using namespace std;


struct wood{
    int key;
    wood* left;
    wood* right;
    wood* parent;
};


wood* maximum(wood* node){
    while(node->right != nullptr){
        node = node->right;
    }
    return node;
}


wood* minimum(wood* node){
    while(node->left != nullptr){
        node = node->left;
    }
    return node;
}


wood* search_in_wood(wood* node, int numb){
    while (node != nullptr && node->key != numb){
        if(numb < node->key){
            node = node->left;
        }

        else{
            node = node->right;
        }
    }

    return node;
}


void insert(wood* node, int numb){
    auto* q = new wood();
    q->key = numb;


    while (node != nullptr) {

        if (q->key > node->key) {

            if (node->right != nullptr) {
                node = node->right;
            }

            else{
                q->parent = node;
                node->right = q;
                return;
            }

        } else if (q->key < node->key) {

            if (node->left != nullptr) {
                node = node->left;
            }

            else{
                q->parent = node;
                node->left = q;
                return;
            }
        }

        else {
            node->key = q->key;
            return;
        }
    }
}


wood* next(wood* cur, int numb){
    wood* q = search_in_wood(cur, numb);

    if (q != nullptr) {

        if (q->right != nullptr) {
            return minimum(q->right);
        }
        wood *p = q->parent;
        while (p != nullptr && q == p->right) {
            q = p;
            p = p->parent;
        }

        return p;
    }

    else {
        wood* elem = new wood();
        elem->key = 1000000001;
        while (cur != nullptr){
            if (numb > cur->key){
                cur = cur->right;
            }
            else{
                elem->key = cur->key;
                cur = cur->left;
            }
        }

        if (elem->key == 1000000001){
            return nullptr;
        }
        else {
            return elem;
        }
    }
}


wood* prev(wood* cur, int numb){
    wood* q = search_in_wood(cur, numb);

    if (q != nullptr) {

        if (q->left != nullptr) {
            return maximum(q->left);
        }

        wood *p = q->parent;

        while (p != nullptr && q == p->left) {
            q = p;
            p = p->parent;
        }

        return p;
    }

    else {
        wood* elem = new wood();
        elem->key = -1000000001;

        while (cur != nullptr){
            if (numb > cur->key){
                elem->key = cur->key;
                cur = cur->right;
            }

            else{
                cur = cur->left;
            }
        }

        if (elem->key == -1000000001){
            return nullptr;
        }
        else {
            return elem;
        }
    }
}


void del(wood* node, int numb){
    wood* q = search_in_wood(node, numb);

    if(q) {
        wood* p = q->parent;

        if(q->left == nullptr && q->right == nullptr){
            if (p == nullptr){
                q->key = 1000000001;
                return;
            }
            else {
                if (p->left == q) {
                    p->left = nullptr;
                    return;
                } else if (p->right == q) {
                    p->right = nullptr;
                    return;
                }
            }

        }

        else if (q->left == nullptr || q->right == nullptr){
            if (q->left == nullptr){
                if(p != nullptr) {
                    if (p->left == q) {
                        p->left = q->right;
                    } else {
                        p->right = q->right;
                    }
                    q->right->parent = p;
                    return;
                }

                else {
                    q = q->right;
                    q->parent = nullptr;
                    return;
                }
            }

            else{
                if (p != nullptr) {
                    if (p->left == q) {
                        p->left = q->left;
                    } else {
                        p->right = q->left;
                    }
                    q->left->parent = p;
                    return;
                }

                else {
                    q = q->left;
                    q->parent = nullptr;
                    return;
                }
            }
        }

        else{
            wood* successor = next(node, numb);
            q->key = successor->key;

            if(successor->parent->left == successor){
                successor->parent->left = successor->right;

                if(successor->right != nullptr){
                    successor->right->parent = successor->parent;
                }
            }

            else{
                successor->parent->right = successor->left;

                if(successor->left != nullptr){
                    successor->right->parent = successor->parent;
                }
            }
            return;
        }
    }
}


void exists(wood* node, int numb){
    (search_in_wood(node, numb) == nullptr) ? cout << "false\n" : cout << "true\n";
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    string operators;
    int numb;
    struct wood wood = {1000000001, nullptr, nullptr, nullptr};

    while (cin >> operators){
        cin >> numb;

        if (operators == "insert"){
            if (wood.key == 1000000001){
                wood.key = numb;
            }
            else {
                insert(&wood, numb);
            }
        }

        else if (operators == "delete"){
            del(&wood, numb);
        }

        else if (operators == "exists"){
            exists(&wood, numb);
        }

        else if (operators == "next"){
            struct wood* check = next(&wood, numb);
            (check == nullptr) ? cout << "none\n" : cout << check->key << "\n";
        }

        else if (operators == "prev"){
            struct wood* check = prev(&wood, numb);
            (check == nullptr) ? cout << "none\n" : cout << check->key << "\n";

        }
    }
    return 0;
}
