#include <iostream>
#include <cmath>
#include <cstdlib>

int main() {
    int nr = 10;

    for (int nt = 100; nt <= 152222; nt += 33) {
        double pibar = 0;
        double sumxi2 = 0;
        
        for (int i = 0; i < nr; ++i) {
            double xo = 2.0, yo = 3.0, l = 5.0, r = 1.0;
            int ncir = 0;
            
            for (int n = 1; n <= nt; ++n) {
                double u1 = (double) rand() / RAND_MAX;
                double u2 = (double) rand() / RAND_MAX;
                double x = l * u1;
                double y = l * u2;
                
                double a1 = pow(x - xo, 2) + pow(y - yo, 2);
                double a2 = pow(r, 2);
                
                if (a1 <= a2) {
                    ncir++;
                }
            }
            
            double ac = pow(l, 2) * ncir / nt;
            double xi2 = pow(ac, 2);
            sumxi2 += xi2;
            pibar += ac;
        }

        std::cout << nt << " " << pibar / nr << std::endl;
        double erro = sqrt(sumxi2 / nr - pow(pibar / nr, 2));
        std::cout << nt << " " << erro << std::endl;
        std::cout << erro << std::endl;
    }

    return 0;
}
