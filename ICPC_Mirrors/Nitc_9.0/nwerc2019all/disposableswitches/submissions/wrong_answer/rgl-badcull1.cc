#include <bits/stdc++.h>
using namespace std;

vector<pair<int,uint64_t>> edge[2000];
uint64_t dist[2001][2000];
bool visited[2001][2000];
bool answer[2000];

struct Line{int64_t m=0,c=0;};

int main(){
  int n,m; cin>>n>>m;
  for (int i=0; i<m; i++){
    int a,b; uint64_t c; cin>>a>>b>>c; --a,--b;
    edge[a].emplace_back(b,c);
    edge[b].emplace_back(a,c);
  }

  // Compute shortest path to each node for each path size.
  memset(dist,-1,sizeof dist);
  dist[0][0]=0;
  for (int d=0; d<n; d++)
    for (int i=0; i<n; i++)
      if (~dist[d][i])
        for (auto e: edge[i])
          dist[d+1][e.first]=min(dist[d+1][e.first],dist[d][i]+e.second);

  // Find which shortest paths aren't dominated by others.
  vector<Line> best;
  for (int d=n; d>=1; --d) if (~dist[d][n-1]) {
    Line const me={d,(int)dist[d][n-1]};
    while (best.size()>=1 and me.c<=best.back().c) best.pop_back();
    while (best.size()>=2){
      Line const a=best[best.size()-2], b=best[best.size()-1];
      if ((me.c-a.c)*(a.m-b.m) >= (b.c-a.c)*(a.m-me.m)) break;
      best.pop_back();
    }
    best.push_back(me);
  }

  // Walk back and save anything that's on at least one of the paths.
  queue<pair<int,int>> todo;
  for (Line p: best){
    visited[p.m][n-1]=true; todo.emplace(p.m,n-1);
  }
  while (not todo.empty()){
    int d=todo.front().first,x=todo.front().second; todo.pop();
    answer[x]=true;
    for (auto e: edge[x])
      if (d and not visited[d-1][e.first] and dist[d-1][e.first]+e.second==dist[d][x])
        visited[d-1][e.first]=true, todo.emplace(d-1,e.first);
  }

  int score=n-accumulate(answer,answer+n,0);
  cout<<score<<endl;
  for (int i=0; i<n; i++) if (not answer[i]) cout<<i+1<<(--score?' ':'\n');
}
