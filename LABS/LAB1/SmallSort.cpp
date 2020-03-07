#include <iostream>
#include <fstream>
using namespace std;

int main (){
    int n;
    ifstream fin ("smallsort.in");
    fin >> n;
    int m[10000];

    for(int i = 0; i < n; i++) {
        fin >> m[i];
    }
    fin.close();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if (m[i] > m[j]){

                m[j] += m[i];
                m[i] = m[j] - m[i];
                m[j] -= m[i];
            }
        }
    }

    ofstream fout ("smallsort.out");
    for(int i = 0; i < n; i++){
        fout << m[i] << " ";
    }
    fout.close();
    return 0;
}
