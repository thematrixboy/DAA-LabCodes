// #include<bits/stdc++.h>
// using namespace std;
 
// int knapsack_dp(int n, int M, int w[], int p[])
// {
//     int i,j;
//     int knapsack[n+1][M+1];

//     for(j=0;j<=M;j++)
//         knapsack[0][j]=0;
 
//     for(i=0;i<=n;i++)
//         knapsack[i][0]=0;
 
//     for(i=1;i<=n;i++)
//     {
//         for(j=1;j<=M;j++)
//         {
            
//             if(w[i-1]<=j)
//             {
//                 knapsack[i][j]=max(knapsack[i-1][j],p[i-1]+knapsack[i-1][j-w[i-1]]);
//             }
//             else
//             {
//                 knapsack[i][j]=knapsack[i-1][j];
//             }
//         }
//     }
//     return knapsack[n][M];
// }
 
// int main()
// {
//     int n=21,M=400;

//     int w[22]={9,13,153,50,15,68,27,39,23,52,11,32,24,48,73,42,43,22,7,18,4,30};  
//     int p[22]={150,35,200,160,60,45,60,40,30,10,70,30,15,10,40,70,75,80,20,12,50,10};  
 
//     int result=knapsack_dp(n,M,w,p);
 
//     cout<<"The maximum value of items that can be put into knapsack is "<<result<<endl;
 
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    if(a>b)
     return a;
   else
return b;
}
 
int knapsack(int W, int weight[], int value[], int n, string names[])
{
    int i, w,x,y;
    int K[n + 1][W + 1];
    string object[n];
int p=0;

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
          K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]],
                    K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
 
   int result = K[n][W];    
   w = W;
    for (i = n; i > 0 && result > 0; i--)
         {
         
         if (result== K[i - 1][w])
           {
       
            continue;
           }        
        else
           {
 
           object[p]=names[i - 1];
            p++;
            result = result - value[i - 1];
            w = w - weight[i - 1];
        }
    }
cout<<"Knapsack: ";
for(i=p;i>=0;i--)
{
 
  cout<<object[i]<<" ";
}
cout<<endl;
return K[n][W];
}

int main()
{
 string names[]={"map","compass","water","sandwich","glucose","tin","banana","apple","cheese","beer","suntan-cream","camera","t-shirts","trousers","umbrella","waterproof-trousers","waterproof-overclothes","note-case","sunglasses","towels","socks","books"};
    int wt[] = { 9,13,153,50,15,68,27,39,23,52,11,32,24,48,73,42,43,22,7,18,4,30};
    int val[] = { 150,35,200,160,60,45,60,40,30,10,70,30,15,10,40,70,75,80,20,12,50,10 };
    int W = 400;
    int n = sizeof(val) / sizeof(val[0]);
   int result= knapsack(W, wt, val, n,names);
cout<<"value:"<<result<<endl;
    return 0;
}
