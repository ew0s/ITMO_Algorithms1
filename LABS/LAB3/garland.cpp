#include <cstdio>
int main(){
    FILE *fin, *fout;
    fin = fopen("garland.in", "r");
    fout = fopen("garland.out", "w");
    int n;
    double h1;
    double left = 0;
    fscanf(fin, "%d %lf", &n, &h1);
    double right = h1;
    double last = -1;
    fclose(fin);

    while(true){
        double m = (left + right) / 2;
        if(m == left || m == right){
            break;
        }
        double early = h1;
        double now = m;
        bool not_on_the_ground = now > 0;

        for(int i = 3; i <= n; i++){
            double next = 2 * now - early + 2;
            not_on_the_ground &= next > 0;
            early = now;
            now = next;
        }

        if(not_on_the_ground){
            right = m;
            last = now;
        }

        else{
            left = m;
        }
    }

    fprintf(fout, "%.2f", last);
    fclose(fout);
    return 0;
}