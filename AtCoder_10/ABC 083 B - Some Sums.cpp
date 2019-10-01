#include <bits/stdc++.h>
using namespace std;

int wa(int n)
{
  int wa = 0;
  while (n)
  {
    wa += n % 10;
    n /= 10;
  }
  return wa;
}

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  int sum = 0;
  for (int i = 1; i <= N; i++)
  {
    int waa = wa(i);
    if (A <= waa && waa <= B)
      sum += i;
  }
  cout << sum << endl;
}