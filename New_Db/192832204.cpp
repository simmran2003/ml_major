#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

bool cmp(string a, string b){
    string first = a + b, second = b + a;

    return first < second;

    // if(first == second) return true;

    // int i = 0;
    // while(first[i] == second[i]) i++;

    // return first[i] < second[i];
}

int main(){
    // freopen("file.txt", "r", stdin);
    // fstream cout("output.txt");

    int n;
    cin >> n;
    string arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n, cmp);

    for(const auto &now : arr) cout << now;

    return 0;
}