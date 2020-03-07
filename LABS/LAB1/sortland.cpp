#include <iostream>
#include <fstream>
using namespace std;

int main () {


    ifstream fin ("sortland.in");
    int n, m2[10001];
    double m[10000];
    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> m[i];
        m2[i] = i + 1;
    }

    fin.close();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (m[i] > m[j]) {
                m2[j] += m2[i];
                m2[i] = m2[j] - m2[i];
                m2[j] -= m2[i];


                m[j] += m[i];
                m[i] = m[j] - m[i];
                m[j] -= m[i];
            }
        }
    }

    ofstream fout ("sortland.out");
    fout << m2[0] << " " << m2[n / 2] << " " << m2[n - 1];
    fout.close();


    return 0;
}
