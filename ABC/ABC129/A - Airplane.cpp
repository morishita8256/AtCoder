#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> PQR(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> PQR.at(i);
  }

  sort(PQR.begin(), PQR.end());
  cout << PQR.at(0) + PQR.at(1) << endl;
}