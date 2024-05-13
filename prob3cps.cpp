#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const double G = 1.0;
const double pi = acos(-1.0);
const double dt = 0.01;
const int Ns = 40;
const int Nt = 20000;

double m[2], px[2], py[2], vpx[2], vpy[2], apx[2], apy[2];
double sx[2][Ns], sy[2][Ns], vxs[2][Ns], vys[2][Ns], asx[2][Ns], asy[2][Ns];
double u, rs, rp, ms;

void interacoes(int i);
void orbita(int i);

int main()
{
    srand(time(0));

    // Posição inicial dos planetas
    px[0] = -5.0;
    py[0] = 0.0;
    px[1] = 5.0;
    py[1] = 0.0;
    vpx[0] = 0.0;
    vpx[1] = 0.0;
    vpy[0] = 0.0;
    vpy[1] = 0.0;
    m[0] = 2.0;
    m[1] = 1.0;
    ms = 0.001;

    for (int j = 0; j < 2; ++j)
        cout << px[j] << " " << py[j] << endl;

    // Posição inicial dos satélites
    for (int j = 0; j < 2; ++j)
    {
        for (int i = 0; i < Ns; ++i)
        {
            u = (double)rand() / RAND_MAX * (2 * pi);
            rs = (double)rand() / RAND_MAX * 20 + 5;
            sx[j][i] = px[j] + rs * cos(u);
            sy[j][i] = py[j] + rs * sin(u);
            vxs[j][i] = -(py[j] - sy[j][i]) * (sqrt(G * m[j]) / pow(rs, 3));
            vys[j][i] = (px[j] - sx[j][i]) * (sqrt(G * m[j]) / pow(rs, 3));
            cout << sx[j][i] << " " << sy[j][i] << endl;
        }
    }

    // Início do estudo da dinâmica dos corpos
    for (int k = 0; k < Nt; ++k)
    {
        for (int i = 0; i < Ns; ++i)
        {
            apx[0] = 0.0;
            apy[0] = 0.0;
            apx[1] = 0.0;
            apy[1] = 0.0;
            asx[0][i] = 0.0;
            asy[0][i] = 0.0;
            asx[1][i] = 0.0;
            asy[1][i] = 0.0;
            interacoes(i);
            orbita(i);
        }

        for (int i = 0; i < Ns; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                sx[j][i] += vxs[j][i] * dt;
                sy[j][i] += vys[j][i] * dt;
                vxs[j][i] += asx[j][i] * dt;
                vys[j][i] += asy[j][i] * dt;
            }
        }

        for (int j = 0; j < 2; ++j)
        {
            px[j] += vpx[j] * dt;
            py[j] += vpy[j] * dt;
            vpx[j] += apx[j] * dt;
            vpy[j] += apy[j] * dt;

            if (k % 40 == 0)
            {
                cout << sx[0][i] << endl;
                cout << sx[0][i] << " " << sy[0][i] << endl;
                cout << sx[1][i] << " " << sy[1][i] << endl;
            }
        }

        cout << px[0] << " " << py[0] << endl;
        cout << px[1] << " " << py[1] << endl;
    }

    return 0;
}

void interacoes(int i)
{
    for (int p = 0; p < 2; ++p)
    {
        rs = sqrt(pow(sx[1][i] - px[p], 2) + pow(sy[1][i] - py[p], 2));
        apx[p] += (G * ms * (sx[1][i] - px[p])) / pow(rs, 3);
        apy[p] += (G * ms * (sy[1][i] - py[p])) / pow(rs, 3);
        rs = sqrt(pow(sx[0][i] - px[p], 2) + pow(sy[0][i] - py[p], 2));
        apx[p] += (G * ms * (sx[0][i] - px[p])) / pow(rs, 3);
        apy[p] += (G * ms * (sy[0][i] - py[0])) / pow(rs, 3);
    }

    for (int p = 0; p < Ns; ++p)
    {
        for (int l = 0; l < 2; ++l)
        {
            if (i != p)
            {
                rs = sqrt(pow(sx[0][p] - sx[l][i], 2) + pow(sy[0][p] - sy[l][i], 2));
                asx[l][i] += (G * ms * (sx[0][p] - sx[l][i])) / pow(rs, 3);
                asy[l][i] += (G * ms * (sy[0][p] - sy[l][i])) / pow(rs, 3);
                rs = sqrt(pow(sx[1][p] - sx[l][i], 2) + pow(sy[1][p] - sy[l][i], 2));
                asx[p][i] += (G * ms * (sx[1][p] - sx[l][i])) / pow(rs, 3);
                asy[p][i] += (G * ms * (sy[1][p] - sy[l][i])) / pow(rs, 3);
            }
        }
    }
}

void orbita(int i)
{
    void orbita(int i)
    {
        for (int j = 0; j < 2; ++j)
        {
            rs = sqrt(pow(px[0] - sx[j][i], 2) + pow(py[0] - sy[j][i], 2));
            asx[j][i] += (G * m[0] * (px[0] - sx[j][i])) / pow(rs, 3);
            asy[j][i] += (G * m[0] * (py[0] - sy[j][i])) / pow(rs, 3);
            rs = sqrt(pow(px[1] - sx[j][i], 2) + pow(py[1] - sy[j][i], 2));
            asx[j][i] += (G * m[1] * (px[1] - sx[j][i])) / pow(rs, 3);
            asy[j][i] += (G * m[1] * (py[1] - sy[j][i])) / pow(rs, 3);
        }
    }
}