#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;

  reverse(S.begin(), S.end());
  vector<string> T(4);
  T.at(0) = "maerd";
  T.at(1) = "remaerd";
  T.at(2) = "esare";
  T.at(3) = "resare";

  int i = 0;
  while (i < S.size())
  {
    bool exist = false;
    for (int j = 0; j < 4; j++)
    {
      if (S.substr(i, T.at(j).size()) == T.at(j))
      {
        i += T.at(j).size();
        exist = true;
      }
    }
    if (exist == false)
    {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}