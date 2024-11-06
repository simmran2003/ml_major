// Problem: D. Xenia and Dominoes
// Contest: Codeforces - Codeforces Round #199 (Div. 2)
// URL: https://codeforces.com/problemset/problem/342/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize(2)

#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>

using G = std::vector<std::vector<int>>;

const int MOD = 1e9 + 7;

int main() {
  std::ios_base::sync_with_stdio(0); 
  std::cin.tie(0);
  
  int n;
  std::cin >> n;
  
  std::vector<std::vector<char>> board(n + 1, std::vector<char>(4));
  
  for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= n; j++) {
          std::cin >> board[j][i];
      }
  }
  
  G f(n + 1, std::vector<int>(100, 0));
  
  f[0][21] = 1;
  
  for (int i = 1; i <= n; i++) {
      std::vector<int> cur1(3, 0);
      for (int u = 1; u <= 3; u++) {
          if (board[i][u] == '.') {
              cur1[u - 1] = 0;
          }
          else if (board[i][u] == 'O') {
              cur1[u - 1] = 3;
          }
          else if (board[i][u] == 'X') {
              cur1[u - 1] = 1;
          }
      }
      
      // if (i == 2) {
          // std::cerr << cur1[0] << " " << cur1[1] << " " << cur1[2] << std::endl;
      // }
      
      for (int j = 0; j < 64; j++) {
          std::vector<int> last(3, 0);
          int temp = j;
          int idx = 2;
          while (temp) {
              last[idx] = temp % 4;
              idx--;
              temp /= 4;
          }
          
          // if (i == 1 && j == 21) {
              // std::cerr << last[0] << " " << last[1] << " " << last[2] << std::endl;
          // }
          
          std::vector<int> cur = cur1;
          bool valid = true;
          for (int u = 0; u < 3; u++) {
              if (last[u] == 0 && cur[u] == 0) {
                  cur[u] = 2;
              }
              else if (last[u] == 0 && cur[u] != 0) {
                  valid = false;
              }
              else if (last[u] == 2 && cur[u] == 3) {
                  cur[u] = 1;
              }
              else if (last[u] == 3 && cur[u] != 0) {
                  valid = false;
              }
          }
          
          if (!valid) continue;
          
          // 00*
          if (cur[0] == 0 && cur[1] == 0 && !(last[0] == 3 || last[1] == 3)) {              
              // 111
              if (cur[2] == 3 || cur[2] == 1) {
                  f[i][21] = (f[i][21] + f[i - 1][j]) % MOD;
                  f[i][21] = (f[i][21] + MOD) % MOD;
              }
              
              // 110
              if (cur[2] == 0) {
                  f[i][20] = (f[i][20] + f[i - 1][j]) % MOD;
                  f[i][20] = (f[i][20] + MOD) % MOD;
              }
              
              // 112
              if (cur[2] == 2) {
                  f[i][22] = (f[i][22] + f[i - 1][j]) % MOD;
                  f[i][22] = (f[i][22] + MOD) % MOD;
              }
              
              // continue;
          }

          // *00
          if (cur[1] == 0 && cur[2] == 0  && !(last[1] == 3 || last[2] == 3)) {
              // 111
              if (cur[0] == 3 || cur[0] == 1) {
                  f[i][21] = (f[i][21] + f[i - 1][j]) % MOD;
                  f[i][21] = (f[i][21] + MOD) % MOD;
              }
              
              // 011
              if (cur[0] == 0) {
                  f[i][5] = (f[i][5] + f[i - 1][j]) % MOD;
                  f[i][5] = (f[i][5] + MOD) % MOD;
              }
              
              // 211
              if (cur[0] == 2) {
                  f[i][37] = (f[i][37] + f[i - 1][j]) % MOD;
                  f[i][37] = (f[i][37] + MOD) % MOD;
              }
              
              // continue;
          }
          
          int next_state = cur[0] * 16 + cur[1] * 4 + cur[2];
          f[i][next_state] = (f[i][next_state] + f[i - 1][j]) % MOD;
          f[i][next_state] = (f[i][next_state] + MOD) % MOD;
          
          // if (i == 1 && j == 21) {
              // std::cerr << next_state << std::endl;
          // }
      }
  }
  
  // std::cerr << f[1][41] << std::endl;
  
  int result = 0;
  for (int i = 0; i < 64; i++) {
      int temp = i;     
      std::vector<int> ss(3, 0);
      int idx = 0;
      while (temp) {
          int remainder = temp % 4;          
          ss[idx] = remainder;
          idx++;
          temp /= 4;
      }
      
      bool valid = true;
      for (int j : ss) {
          if (j == 0 || j == 3) {
              valid = false;
          }
      }
      
      if (valid) {
          // if (f[1][i]) std::cerr << i << std::endl;
          // std::cerr << i << std::endl;
          result = (result + f[n][i]) % MOD;
          result = (result + MOD) % MOD;
      }
  }
  
  std::cout << result;
  
  return 0;
}
