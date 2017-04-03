#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

double *regresion_potencial(int n, string t_file, string c_file) {

    std::ifstream tempFile(t_file);
    std::ifstream consFile(c_file);

    double xsum, ysum, logx2sum, logxsum, logysum, logxlogysum, x, y;
    double *xval = new double[n];
    double *yval = new double[n];
    logxsum = ysum = logx2sum = logysum = logxlogysum = x = y = 0;

    int i = 0;
    while (tempFile >> x && consFile >> y) {
        ysum += y;
        logxsum += log10(x);
        logysum += log(y);
        logxlogysum += log10(x) * log10(y);
        logx2sum += pow(log10(x),2);

        xval[i] = x;
        yval[i] = y;
        i++;
    }

    double a0, a1, sr, error, my, mx, mlogx, mlogy, st, r, stx, sty;
    my = ysum / n;
    mx = xsum / n;
    mlogx = logxsum / n;
    mlogy = logysum / n;
    sr = st = stx = sty = 0;
    a1 = (n*logxlogysum - logxsum*logysum) / (n*logx2sum - (pow(logxsum, 2)));
    a0 = (mlogy) - (a1*(mlogx));

    for (int i = 0; i < n; i++) {
        sr += pow(yval[i] - pow(10, a0) * pow(xval[i], a1), 2);
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
    double *ans = regresion_potencial(8, "x.txt", "y.txt");
}
