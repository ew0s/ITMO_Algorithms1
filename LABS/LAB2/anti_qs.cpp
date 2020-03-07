#include <iostream>
#include <fstream>
using namespace std;


int main() {
    int n;
    ifstream fin ("antiqs.in");
    fin >> n;
    fin.close();

    int a[70000];
    for(int i = 0; i < n; i++){
        a[i] = i + 1;
    }

    for(int i = 2; i < n; i++){
        swap(a[i], a[i / 2]);
    }

    ofstream fout ("antiqs.out");
    for(int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout.close();

    return 0;
}