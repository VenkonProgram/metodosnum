#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

double *regresion_exponencial(int n, string t_file, string c_file) {

    std::ifstream tempFile(t_file);
    std::ifstream consFile(c_file);

    double xsum, ysum, x2sum, logysum, xlogysum, x, y;
    double *xval = new double[n];
    double *yval = new double[n];
    xsum = ysum = x2sum = logysum = xlogysum = x = y = 0;

    int i = 0;
    while (tempFile >> x && consFile >> y) {
        xsum += x;
        ysum += y;
        x2sum += x*x;
        logysum += log(y);
        xlogysum += x*log(y);

        xval[i] = x;
        yval[i] = y;
        i++;
    }

    double a0, a1, sr, error, my, mx, mlogy, st, r, stx, sty;
    my = ysum / n;
    mx = xsum / n;
    mlogy = logysum / n;
    sr = st = stx = sty = 0;
    a1 = (n*xlogysum - xsum*ysum) / (n*x2sum - (pow(xsum, 2)));
    a0 = (mlogy) - (a1*(mx));

    for (int i = 0; i < n; i++) {
        sr += pow(yval[i] - exp(a0) * exp(a1*xval[i]), 2);
        st += (yval[i] - my)*(xval[i] - mx);
        stx += pow((xval[i] - mx),2);
        sty += pow((yval[i] - my),2);
    }

    error = sqrt(sr / (n - 2));
    r = st/(sqrt(stx)*sqrt(sty));

    cout << "y = " << a0 << " +"  << a1 << "x" << endl;
    cout << "Error estandar= " << error << endl;
    cout << "Coeficiente de correlacion= " << r << endl;

    //return new double[2]{ a0,a1 };
}

int main()
{
    double *ans = regresion_exponencial(8, "x.txt", "y.txt");
}
