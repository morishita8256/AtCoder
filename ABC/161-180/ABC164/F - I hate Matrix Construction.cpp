#pragma region head
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int unsigned long long
typedef unsigned long long ll;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}
#pragma endregion

signed main() {
  int N;
  cin >> N;
  vector<int> S(N);
  rep(i, N) {
    cin >> S[i];
  }
  vector<int> T(N);
  rep(i, N) {
    cin >> T[i];
  }
  vector<int> U(N);
  rep(i, N) {
    cin >> U[i];
  }
  vector<int> V(N);
  rep(i, N) {
    cin >> V[i];
  }

  vector<vector<int>> ans(N, vector<int>(N));

  rep(b, 64) {
    int base = bit(b);
    vector<int> u(N), v(N);
    rep(i, N) {
      u[i] = (U[i] >> b) & 1, v[i] = (V[i] >> b) & 1;
    }

    vector<bool> s(N, false), t(N, false);

    // use strong conditions
    vector<vector<int>> temp(N, vector<int>(N, 2));
    rep(i, N) {
      if (S[i] ^ u[i]) {
        s[i] = true;
        rep(j, N) {
          temp[i][j] = u[i];
        }
      }
    }

    rep(j, N) {
      if (T[j] ^ v[j]) {
        t[j] = true;
        rep(i, N) {
          if (temp[i][j] != 2 && temp[i][j] != v[j]) {
            cout << -1 << '\n';
            return 0;
          } else {
            temp[i][j] = v[j];
          }
        }
      }
    }

    // list up undetermined row/col
    vector<int> I, J;
    rep(i, N) {
      if (!s[i])
        I.pb(i);
    }
    rep(j, N) {
      if (!t[j])
        J.pb(j);
    }

    if (len(I) >= 2 && len(J) >= 2) {
      rep(i, len(I)) {
        rep(j, len(J)) {
          temp[I[i]][J[j]] = (i + j) % 2;
        }
      }

    } else if (len(I) == 1) {
      int ii = I[0];
      for (int j : J) {
        bool exist = false;
        rep(i, N) {
          if (v[j] == temp[i][j])
            exist = true;
        }
        if (!exist)
          temp[ii][j] = v[j];
      }

      bool ok = false;
      rep(j, N) {
        if (temp[ii][j] == 2 || temp[ii][j] == v[j])
          ok = true;
      }
      if (!ok) {
        cout << -1 << '\n';
        return 0;
      }
      for (int j : J) {
        if (temp[ii][j] == 2)
          temp[ii][j] = u[ii];
      }

    } else if (len(J) == 1) {
      int jj = J[0];
      for (int i : I) {
        bool exist = false;
        rep(j, N) {
          if (u[i] == temp[i][j])
            exist = true;
        }
        if (!exist)
          temp[i][jj] = u[i];
      }

      bool ok = false;
      rep(i, N) {
        if (temp[i][jj] == 2 || temp[i][jj] == v[jj])
          ok = true;
      }
      if (!ok) {
        cout << -1 << '\n';
        return 0;
      }
      for (int i : I) {
        if (temp[i][jj] == 2)
          temp[i][jj] = v[jj];
      }
    }


    // check weak conditions
    for (int i : I) {
      bool ok = false;
      rep(j, N) {
        if (temp[i][j] == u[i])
          ok = true;
      }

      if (!ok) {
        cout << -1 << '\n';
        return 0;
      }
    }

    for (int j : J) {
      bool ok = false;
      rep(i, N) {
        if (temp[i][j] == v[j])
          ok = true;
      }

      if (!ok) {
        cout << -1 << '\n';
        return 0;
      }
    }

    rep(i, N) {
      rep(j, N) {
        ans[i][j] += temp[i][j] * base;
      }
    }
  }

  cout << ans << endl;
}