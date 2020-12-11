#include <bits/stdc++.h>
using namespace std;
long long int counter=0;
void lcsAlgo(char *S1, char *S2, int m, int n) {
  int LCS[m + 1][n + 1];

  for (int i = 0; i <= m; i++) {
	for (int j = 0; j <= n; j++) {
	    ++counter;                              //incrementing steps
      	if (i == 0 || j == 0)
            	LCS[i][j] = 0;
      	else
            	if (S1[i - 1] == S2[j - 1])
                  	LCS[i][j] = LCS[i - 1][j - 1] + 1;
            	else
                  	LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
	}
  }

  int index = LCS[m][n];                    //this portion is for printing LCS
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
  cout <<"LCS: "<< lcsAlgo << "\n";
}

int main()
{
    string str1 ("");                       //string str1 declaration
    int i,j=0;
    for(i=0; i < 1000; i++){                  // i < 10, i < 100, i < 1000
        j = rand()%10;                      //generating number from rand()
        str1+=to_string(j);                 //converting int to string and concating it in str1
    }
    char S1[str1.size() + 1];               //character array declaration
    strcpy(S1, str1.c_str());               //copying elements to array (converting string to char array)
    int m = strlen(S1);
    
    srand((unsigned int)time(NULL));        //setting seed for the random number generator

    string str2 ("");                       //string str2 declaration       
    for(i=0; i < 1000; i++){                  // i < 10, i < 100, i < 1000
        j = rand()%10;                      //generating number from rand()
        str2+=to_string(j);                 //converting int to string and concating it in str2
    }
    char S2[str2.size() + 1];               //character array declaration
    strcpy(S2, str2.c_str());               //copying elements to array (converting string to char array)
    int n = strlen(S2);
    
    lcsAlgo(S1, S2, m, n);
    cout<<"Number of Steps "<<counter<<endl;                    //number of steps 
}

// << "[ " << S1 << " ]\n[ " << S2 << " ]\nLCS: " 