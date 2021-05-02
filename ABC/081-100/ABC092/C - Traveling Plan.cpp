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
  int N;
  cin >> N;
  vector<int> A(N + 2);

  A[0] = 0;
  repp(i, 1, N) cin >> A[i];
  A[N + 1] = 0;

  ll all = 0;
  repp(i, 0, N) { all += abs(A[i] - A[i + 1]); }

  vector<int> save(N + 1, 0);
  repp(i, 1, N) {
    bool can_save = (A[i + 1] < A[i] && A[i - 1] < A[i]) ||
                    (A[i + 1] > A[i] && A[i - 1] > A[i]);
    if (can_save) {
      save[i] = 2 * min(abs(A[i + 1] - A[i]), abs(A[i - 1] - A[i]));
    }
  }
  repp(i, 1, N) { cout << all - save[i] << endl; }
}