---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-grl/grl_1_a.test.cpp
    title: verify/verify-aoj-grl/grl_1_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dijkstra.hpp\"\n#include<queue>\n#include<utility>\n\
    #include<vector>\nusing namespace std;\n\ntemplate<typename T>\nvector<T> dijkstra(vector<vector<pair<int,T>>>\
    \ G,int v){\n\tvector<bool> kakutei((int)(G.size()),false);\n\tvector<T> cur((int)(G.size()),2000000000000LL);\n\
    \tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;\n\t\
    cur[v]=0;\n\tque.push(make_pair(cur[v],v));\n\twhile(!que.empty()){\n\t\tint pos=que.top().second;\n\
    \t\tque.pop();\n\t\tif(kakutei[pos]==true){\n\t\t\tcontinue;\n\t\t}\n\t\tkakutei[pos]=true;\n\
    \t\tfor(pair<int,T> i : G[pos]){\n\t\t\tint nex=i.first;\n\t\t\tT cost=i.second;\n\
    \t\t\tif(cur[nex]>cur[pos]+cost){\n\t\t\t\tcur[nex]=cur[pos]+cost;\n\t\t\t\tque.push(make_pair(cur[nex],nex));\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor(int i=0;i<(int)(cur.size());i++){\n\t\tif(cur[i]==2000000000000LL){\n\
    \t\t\tcur[i]=-1;\n\t\t}\n\t}\n\treturn cur;\n}\n"
  code: "#pragma once\n#include<queue>\n#include<utility>\n#include<vector>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nvector<T> dijkstra(vector<vector<pair<int,T>>>\
    \ G,int v){\n\tvector<bool> kakutei((int)(G.size()),false);\n\tvector<T> cur((int)(G.size()),2000000000000LL);\n\
    \tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;\n\t\
    cur[v]=0;\n\tque.push(make_pair(cur[v],v));\n\twhile(!que.empty()){\n\t\tint pos=que.top().second;\n\
    \t\tque.pop();\n\t\tif(kakutei[pos]==true){\n\t\t\tcontinue;\n\t\t}\n\t\tkakutei[pos]=true;\n\
    \t\tfor(pair<int,T> i : G[pos]){\n\t\t\tint nex=i.first;\n\t\t\tT cost=i.second;\n\
    \t\t\tif(cur[nex]>cur[pos]+cost){\n\t\t\t\tcur[nex]=cur[pos]+cost;\n\t\t\t\tque.push(make_pair(cur[nex],nex));\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor(int i=0;i<(int)(cur.size());i++){\n\t\tif(cur[i]==2000000000000LL){\n\
    \t\t\tcur[i]=-1;\n\t\t}\n\t}\n\treturn cur;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-07-11 12:11:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-grl/grl_1_a.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: dijkstra
---

## 使い方
- `vector<T> dijkstra<T>(vector<vector<pair<int,T>>> G,int v)`

グラフ $G$ の $v$ 始点最短距離を書いたvectorを返す．

## 計算量
$O((V+E) \log V)$