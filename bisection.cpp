// bisection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cmath>

using namespace std;

double f(double x) {
	double ans = (4 * x - 7) / (x - 2);
	return ans;
}

int main()
{
	cout.precision(4);
	double x1, x2, xr, acc, fx1, fx2, fxr, ea, xrold;
	xr = 0;
	int iter = 0;
	cout << "Enter the initial guesses:\nx1=";
	cin >> x1;
	cout << "\nx2=";
	cin >> x2;
	acc = 0.000001;
		do {
			xrold = xr;
			xr = (x1 + x2) / 2.0;
			fx1 = f(x1);
			fx2 = f(x2);
			fxr = f(xr);
			iter++;
			ea = fabs(((xr - xrold) / (xr)) * 100);
			cout << "x1=" << x1 << "     x2=" << x2 << "     xr=" << xr << "     fxr=" << fxr << "     ea= " << ea << endl;
			if (fx1*fxr>0)
			{
				x1 = xr;
			}
			else
			{
				x2 = xr;
			}

		} while (fabs(fxr*fx1)>acc);

	cout << "The root of the equation is " << xr << endl;
	cout << "The approximate error is " << ea << endl;
	cout << "Iterations: " << iter << endl;
	return 0;
}