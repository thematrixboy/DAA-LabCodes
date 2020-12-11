#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>i,pair<int,int>j){
    return i.second<j.second;
}

int main()
{
      vector<pair<int,int>>vec {{0,6},{1,4},{2,14},{3,5},{3,9},{5,7},{5,9},{6,10},{8,11},{8,12},{12,16}};
      //vector<pair<int,int>>vec (11);
      //cout<<"Starting time of activities: "<<endl;
      // for(int i=0;i<11;i++){
      //     cin>>vec[i].first;
      // }
      // cout<<"Finishing time of activities: "<<endl;
      // for(int i=0;i<11;i++){
      //     cin>>vec[i].second;
      // }
      // for(int i=0;i<n;i++){
      //     m[vec[i]]=i;
      // }
      sort(vec.begin(),vec.end(),comp);
      vector<pair<int,int>>v;
      v.push_back(vec[0]);
      pair<int,int>current=vec[0];
      for(int j=1;j<11;j++){
          if(vec[j].first > current.second){
              v.push_back(vec[j]);
              current=vec[j];
          }
      }
      vector<pair<int,int>>::iterator i;
      cout<<"Following activities are selected- "<<endl;
      for(i=v.begin();i!=v.end();i++){
          cout<<"("<<(*i).first<<","<<(*i).second<<"), ";
      }
      cout<<endl;
  return 0;
}