#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}

int main()
{
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }

  int max = 0;
  for (int i = 0; i < N; i++)
  {
    chmax(max, A[i]);
  }
  int max_cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if (max == A[i])
      max_cnt++;
  }

  if (max_cnt >= 2)
  {
    for (int i = 0; i < N; i++)
    {
      cout << max << endl;
    }
  }
  else
  {
    int second_max = 0;
    for (int i = 0; i < N; i++)
    {
      if (A[i] != max)
        chmax(second_max, A[i]);
    }

    for (int i = 0; i < N; i++)
    {
      if (A[i] == max)
        cout << second_max << endl;
      else
        cout << max << endl;
    }
  }
}