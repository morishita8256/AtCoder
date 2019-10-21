#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int64_t> Lucas(N + 1);
  Lucas.at(0) = 2;
  Lucas.at(1) = 1;

  for (int i = 2; i <= N; i++)
  {
    Lucas.at(i) = Lucas.at(i - 1) + Lucas.at(i - 2);
  }

  cout << Lucas.at(N) << endl;
}