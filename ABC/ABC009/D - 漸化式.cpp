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
#define int long long
typedef long long ll;
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

int eye = bit(33) - 1;

vector<vector<int>> matmul(vector<vector<int>> A, vector<vector<int>> B) {
  int N = len(A);
  vector<vector<int>> ans(N, vector<int>(N));
  rep(i, N) {
    rep(j, N) {
      int temp = 0;
      rep(k, N) {
        temp ^= A[i][k] & B[k][j];
      }
      ans[i][j] = temp;
    }
  }
  return ans;
}


vector<int> matvec(vector<vector<int>> mat, vector<int> vec, int P) {
  int N = len(mat);
  vector<vector<int>> mat_pow(N, vector<int>(N));
  rep(i, N) {
    mat_pow[i][i] = eye;
  }

  while (P) {
    if (P & 1)
      mat_pow = matmul(mat, mat_pow);
    mat = matmul(mat, mat);
    P /= 2;
  }

  vector<int> ans(N);
  rep(i, N) {
    int temp = 0;
    rep(j, N) {
      temp ^= mat_pow[i][j] & vec[j];
    }
    ans[i] = temp;
  }
  return ans;
}


signed main() {
  int K, M;
  cin >> K >> M;
  vector<int> A(K);
  rep(i, K) {
    cin >> A[i];
  }
  vector<int> C(K);
  rep(i, K) {
    cin >> C[i];
  }

  if (M <= K) {
    cout << A[M - 1] << endl;
    return 0;
  }

  vector<vector<int>> mat(K, vector<int>(K));
  rep(i, K - 1) {
    mat[i][i + 1] = eye;
  }
  rep(j, K) {
    mat[K - 1][j] = C[K - 1 - j];
  }

  vector<int> vec(K);
  rep(j, K) {
    vec[j] = A[j];
  }

  int P = M - K;
  auto vec_pow = matvec(mat, vec, P);

  int ans = vec_pow[K - 1];
  cout << ans << endl;
}