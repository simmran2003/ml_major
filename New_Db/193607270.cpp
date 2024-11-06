#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T>
using pq = priority_queue<T>;
template <class T>
using qp = priority_queue<T, vector<T>, greater<T>>;
#define vec(T, A, ...) vector<T> A(__VA_ARGS__);
#define vvec(T, A, h, ...) vector<vector<T>> A(h, vector<T>(__VA_ARGS__));
#define vvvec(T, A, h1, h2, ...) vector<vector<vector<T>>> A(h1, vector<vector<T>>(h2, vector<T>(__VA_ARGS__)));

#ifndef RIN__LOCAL
#define endl "\n"
#endif
#define spa ' '
#define len(A) A.size()
#define all(A) begin(A), end(A)

#define fori1(a) for(ll _ = 0; _ < (a); _++)
#define fori2(i, a) for(ll i = 0; i < (a); i++)
#define fori3(i, a, b) for(ll i = (a); i < (b); i++)
#define fori4(i, a, b, c) for(ll i = (a); ((c) > 0 || i > (b)) && ((c) < 0 || i < (b)); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define fori(...) overload4(__VA_ARGS__, fori4, fori3, fori2, fori1)(__VA_ARGS__)

template <typename T>
vector<tuple<ll, T>> ENUMERATE(vector<T> &A, ll s = 0){
    vector<tuple<ll, T>> ret(A.size());
    for(int i = 0; i < A.size(); i++) ret[i] = {i + s, A[i]};
    return ret;
}

vector<tuple<ll, char>> ENUMERATE(string &A, ll s = 0){
    vector<tuple<ll, char>> ret(A.size());
    for(int i = 0; i < A.size(); i++) ret[i] = {i + s, A[i]};
    return ret;
}

#define enum1(A) fori(A.size())
#define enum2(a, A) for(auto a:A)
#define enum3(i, a, A) for(auto&& [i, a]: ENUMERATE(A))
#define enum4(i, a, A, s) for(auto&& [i, a]: ENUMERATE(A, s))
#define enum(...) overload4(__VA_ARGS__, enum4, enum3, enum2, enum1)(__VA_ARGS__)

template <typename T, typename S>
vector<tuple<T, S>> ZIP(vector<T> &A, vector<S> &B){
    int n = min(A.size(), B.size());
    vector<tuple<T, S>> ret(n);
    for(int i = 0; i < n; i++) ret[i] = {A[i], B[i]};
    return ret;
}

template <typename T, typename S>
vector<tuple<ll, T, S>> ENUMZIP(vector<T> &A, vector<S> &B, ll s = 0){
    int n = min(A.size(), B.size());
    vector<tuple<ll, T, S>> ret(n);
    for(int i = 0; i < n; i++) ret[i] = {i + s, A[i], B[i]};
    return ret;
}

#define zip4(a, b, A, B) for(auto&& [a, b]: ZIP(A, B))
#define enumzip5(i, a, b, A, B) for(auto&& [i, a, b]: ENUMZIP(A, B))
#define enumzip6(i, a, b, A, B, s) for(auto&& [i, a, b]: ENUMZIP(A, B, s))
#define overload6(a, b, c, d, e, f, g, ...) g
#define zip(...) overload6(__VA_ARGS__, enumzip6, enumzip5, zip4, _, _, _)(__VA_ARGS__)

vector<char> stoc(string &S){
    int n = S.size();
    vector<char> ret(n);
    for(int i = 0; i < n; i++) ret[i] = S[i];
    return ret;
}

#define INT(...) int __VA_ARGS__; inp(__VA_ARGS__);
#define LL(...) ll __VA_ARGS__; inp(__VA_ARGS__);
#define STRING(...) string __VA_ARGS__; inp(__VA_ARGS__);
#define CHAR(...) char __VA_ARGS__; inp(__VA_ARGS__);
#define VEC(T, A, n) vector<T> A(n); inp(A);
#define VVEC(T, A, n, m) vector<vector<T>> A(n, vector<T>(m)); inp(A);

const ll MOD1 = 1000000007;
const ll MOD9 = 998244353;

template<class T> auto min(const T& a){
    return *min_element(all(a));
}
template<class T> auto max(const T& a){
    return *max_element(all(a));
}
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

void FLUSH(){cout << flush;}
void print(){cout << endl;}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(Tail)) cout << spa;
    print(forward<Tail>(tail)...);
}
template<typename T>
void print(vector<T> &A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i == n - 1) cout << endl;
        else cout << spa;
    }
}
template<typename T>
void print(vector<vector<T>> &A){
    for(auto &row: A) print(row);
}
template<typename T, typename S>
void print(pair<T, S> &A){
    cout << A.first << spa << A.second << endl;
}
template<typename T, typename S>
void print(vector<pair<T, S>> &A){
    for(auto &row: A) print(row);
}
template<typename T, typename S>
void prisep(vector<T> &A, S sep){
    int n = A.size();
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i == n - 1) cout << endl;
        else cout << sep;
    }
}
template<typename T, typename S>
void priend(T A, S end){
    cout << A << end;
}
template<typename T>
void priend(T A){
    priend(A, spa);
}
template<class... T>
void inp(T&... a){
    (cin >> ... >> a);
}
template<typename T>
void inp(vector<T> &A){
    for(auto &a:A) cin >> a;
}
template<typename T>
void inp(vector<vector<T>> &A){
    for(auto &row:A) inp(row);
}
template<typename T, typename S>
void inp(pair<T, S> &A){
    inp(A.first, A.second);
}
template<typename T, typename S>
void inp(vector<pair<T, S>> &A){
    for(auto &row: A) inp(row.first, row.second);
}

template<typename T>
T sum(vector<T> &A){
    T tot = 0;
    for(auto a:A) tot += a;
    return tot;
}

template<typename T>
pair<vector<T>, map<T, int>> compression(vector<T> X){
    sort(all(X));
    X.erase(unique(all(X)), X.end());
    map<T, int> mp;
    for(int i = 0; i < X.size(); i++) mp[X[i]] = i;
    return {X, mp};
}

void solve(){
    INT(n);
    VEC(ll, P, n);
    STRING(S);
    ll ans = 0;
    fori(i, n){
        if(S[i] == 'B') ans += P[i];
    }
    ll ma = 0;
    ll cum = 0;
    fori(i, n){
        if(S[i] == 'A') cum += P[i];
        else cum -= P[i];
        chmax(ma, cum);
    }
    cum = 0;
    fori(i, n - 1, -1, -1){
        if(S[i] == 'A') cum += P[i];
        else cum -= P[i];
        chmax(ma, cum);
    }

    print(ans + ma);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // cout << fixed << setprecision(12);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
