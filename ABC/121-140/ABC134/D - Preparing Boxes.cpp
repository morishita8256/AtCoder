#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N;
  cin >> N;

  int a[N + 1];
  for (int i = 1; i <= N; i++)
  {
    cin >> a[i];
  }

  int box[N + 1];
  for (int i = 1; i <= N; i++)
  {
    box[i] = 0;
  }

  int box_cnt = 0;
  for (int i = N; i >= 1; i--)
  {
    int sum = 0;
    for (int j = 2 * i; j <= N; j += i)
    {
      sum += box[j];
    }
    if (sum % 2 == a[i])
      box[i] = 0;
    else
    {
      box[i] = 1;
      box_cnt++;
    }
  }
  cout << box_cnt << endl;

  if (box_cnt == 0)
    return 0;

  for (int i = 1; i <= N; i++)
  {
    if (box[i] == 1)
    {
      cout << i;
      if (--box_cnt > 0)
        cout << ' ';
    }
  }
  cout << endl;
}