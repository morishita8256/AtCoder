#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double err = 1e-9;

int main()
{
  ll W, H, x, y;
  cin >> W >> H >> x >> y;

  int multi = 1;
  if (W % 2)
    multi = 0;
  if (H % 2)
    multi = 0;
  if (W / 2 != x || H / 2 != y)
    multi = 0;
  cout << W * H / 2.0 << ' ' << multi << endl;
}