#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string S;
  cin >> S;

  bool good = true;
  for (int i = 0; i < 3; i++)
  {
    if (S[i] == S[i + 1])
    {
      good = false;
      break;
    }
  }

  cout << (good ? "Good" : "Bad") << endl;
}