#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  string S;
  cin >> S;
  int A = 0;
  int C = 0;
  int small = 0;

  int N = S.size();
  rep(i, N) {
    if (S[i] == 'A' && i == 0)
      A++;
    else if (S[i] == 'C' && 2 <= i && i <= N - 2)
      C++;
    else if ('a' <= S[i] && S[i] <= 'z')
      small++;
  }
  if (A == 1 && C == 1 && small == N - 2) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
}