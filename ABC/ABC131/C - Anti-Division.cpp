#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  return a * b / gcd(a, b);
}

int main()
{
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  A--;
  ll CC = B / C - A / C;
  ll DD = B / D - A / D;
  ll CD = lcm(C, D);
  ll CDCD = B / CD - A / CD;

  cout << (B - A) - (CC + DD) + (CDCD) << endl;
}