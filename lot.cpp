#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define double long double

const double EPS = 1.0e-14;
const double a = -0.00051339;
const double b = 0.04107143;
const double c = -0.00055804;

double X_to_A(double X) {
  double Y = X / 100.0;
  return a * Y * Y + b * Y + c;
}

double A_to_X(double A) {
  double Y = (-b + sqrt(b * b - 4 * a * (c - A))) / (2 * a);
  return Y * 100.0;
}

int main() {
  double X;
  cin >> X;
  if (X > 1500 + EPS)
    X = 1500;
  cout << "Balance = " << X << endl;

  ///////////////////////////////////////////
  // coeff:  0.0  <------------------>  1.0
  //  risk:  Low  <------------------>  High
  double coeff = 0.3;
  ///////////////////////////////////////////

  if (coeff < 0.0 - EPS)
    coeff = 0.0;
  else if (coeff > 1.0 + EPS)
    coeff = 1.0;
  printf("Coefficient = %.2Lf\n\n", coeff);

  double A = X_to_A(X);
  cout << "A = " << A << " --> ";
  A *= coeff;
  cout << A << " --> ";
  A = ((int)(A / 0.01)) * 0.01;
  if (A > 0.5 + EPS)
    A = 0.5;
  printf("%.2Lf\n\n", A);

  cout
      << "Lot *****************************************************************"
      << endl;
  const vector<double> base = {1, 1, 1, 1, 2, 3, 6, 9, 16, 22, 32, 46, 62, 98};
  vector<double> lot(14);
  rep(i, 14) {
    lot[i] = A * base[i];
    printf("%.2Lf", lot[i]);
    cout << (i == 13 ? '\n' : ',');
  }
  cout
      << "*********************************************************************"
      << endl;

  if (A > 0.50 - EPS)
    return 0;

  double next_A = A + 0.01;
  printf("\nNext A = %.2Lf\n", next_A);
  next_A /= coeff;

  double next_X = A_to_X(next_A);
  printf("Next X = %.2Lf\n", next_X);
}