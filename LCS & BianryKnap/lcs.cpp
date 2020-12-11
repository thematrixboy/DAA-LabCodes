#include<bits/stdc++.h>
using namespace std;

void lcsAlgo(char *S1, char *S2, int m, int n) {
  int LCS[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        LCS[i][j] = 0;
      else 
        if (S1[i - 1] == S2[j - 1])
          LCS[i][j] = LCS[i - 1][j - 1] + 1;
        else
          LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
    }
  }

  int index = LCS[m][n];
  char lcsAlgo[index + 1];
  lcsAlgo[index] = '\0';

  int i = m, j = n;
  while (i > 0 && j > 0) {
    if (S1[i - 1] == S2[j - 1]) {
      lcsAlgo[index - 1] = S1[i - 1];
      i--;
      j--;
      index--;
    }
    else 
      if (LCS[i - 1][j] > LCS[i][j - 1])
        i--;
      else
        j--;
  }
  
  cout << "[ " << S1 << " ]\n[ " << S2 << " ]\nLCS: " << lcsAlgo << "\n";
}

int main() 
{
  char S1[] = "0010210122";
  char S2[] = "2202020120";
  int m = strlen(S1);
  int n = strlen(S2);

  lcsAlgo(S1, S2, m, n);
}