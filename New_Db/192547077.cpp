#include "cstdio"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include "string"
#include <map>
#include <stack>
#include <iomanip>
#include <cstring>


#pragma GCC optimize "trapv"
#define ll long long
const int oo = 1e9;
const int oM = -2e9;
const int N = 1e6 + 5;
const ll mod = 1073741824;
#define  nl  cout<<"\n";
#define mySort  sort(v.begin(),v.end());
#define mySortG  sort(v.begin(),v.end(),greater<>());
#define vi vector<int>
#define myFor  for (int i = 0; i < n; ++i) {cin>>v[i];}
#define myPrint for (int i = 0; i < n; ++i) {cout<<v[i]<<" ";}
#define FIO ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll n, k;
int ing[N][2], stook[N];
vector<string> ss(3);
bool iP[N + 1];
int nums[2000];
vi ans;
vector<ll> primeNums;
int obj_num;


void split(string str, char seperator) {
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= str.length()) {
        if (str[i] == seperator || i == str.length()) {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            ss[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
    }
}

int ok(int x) {
    ll sum = x + x * 2;
    if (sum == n) {
        cout << x << " " << x;
        return 1;
    }
    sum = (x - 1) + x * 2;
    if (sum == n) {
        cout << x - 1 << " " << x;
        return 1;
    }
    sum = x + (x - 1) * 2;
    if (sum == n) {
        cout << x << " " << x - 1;
        return 1;
    }
    if (sum > n)
        return -1;
    else
        return -2;

}

int vaild(vector<ll> arr, ll m, ll c) {
    ll count = 0;
    for (int i = n / 2; i < n; ++i) {
        count += max(0ll, m - arr[i]);
    }
    return count <= c;
}

int doNothing() {
    return 1;
}

bool isPrime(int num) {
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}


void getPrime(int num) {
    memset(iP, true, sizeof(iP));
    iP[0] = iP[1] = false;
    for (int i = 2; i * i <= num; ++i) {
        if (iP[i]) {
            for (int j = i * i; j <= num; j += i) {
                iP[j] = false;
            }
        }
    }
    for (int i = 2; i < num; ++i) {
        if (iP[i])
            primeNums.push_back(i);
    }
}

void getDiv() {
    for (int i = 1; i <= 7; ++i) {
        for (int j = i; j <= 7; j += i) {
            nums[j]++;
        }
    }
}

vector<int> findDivisors(int num) {
    vi tmp;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            tmp.push_back(i);
        }
    }
    return tmp;

}

void init() {
    for (int i = 1; i <= 2000; ++i) {
        if (i % 3 != 0) {
            string s = to_string(i);
            if (s[s.size() - 1] != '3')
                ans.push_back(i);
        }
    }
}

void test() {
//   vi v =  findDivisors(7);
    cin >> n;
    vector<vector<int>> dev(8);
    vi vec(n);
    for (int i = 1; i < 8; ++i) {
        dev[i] = findDivisors(i);
    }
    int arr[99999];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vec[i] = x;
        arr[x]++;

    }
    sort(vec.begin(), vec.end());
    int end = n - 1;
    vector<vector<int>> v(n / 3);
    for (int i = 0; i < n / 3 && end != 0; ++i) {

        vi tmp = dev[vec[end]];
        int size = tmp.size() - 2;
        v[i].push_back(vec[end]);
        bool f = true;
        for (int l = size; l >= 0; --l) {
            if (arr[tmp[l]] > 0) {
                v[i].push_back(tmp[l]);
                arr[tmp[l]]--;
                end--;
                f = false;
                tmp = findDivisors(tmp[l]);
                size = tmp.size() - 2;
                bool f2 = true;
                for (int j = size; j >= 0; --j) {
                    if (arr[tmp[j]] > 0) {
                        v[i].push_back(tmp[j]);
                        arr[tmp[j]]--;
                        f2 = false;
                        break;
                    }
                }
                if(f2){
                    cout << -1;
                    return;
                }
                break;

            }
        }
        if (f) {
            cout << -1;
            return;

        }
    }
    for (int i = 0; i < n / 3; ++i) {
        for (int j = 2; j >= 0; --j) {
            cout << v[i][j] << " ";
        }
        nl
    }
}

double arr[10][10];

int main() {
    FIO


    int t = 1;
//    cin >> t;
    while (t--) {
        test();
    }
}