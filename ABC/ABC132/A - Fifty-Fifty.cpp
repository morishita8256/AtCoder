#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;

  int cnt[26];
  for (int i = 0; i < 26; i++)
  {
    cnt[i] = 0;
  }

  for (int i = 0; i < 4; i++)
  {
    cnt[S[i] - 'A']++;
  }

  int flag = 0;
  for (int i = 0; i < 26; i++)
  {
    if (cnt[i] == 2)
      flag++;
  }

  if (flag == 2)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}