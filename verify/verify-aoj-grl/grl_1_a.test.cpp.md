---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: dijkstra
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A
  bundledCode: "#line 1 \"verify/verify-aoj-grl/grl_1_a.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n#line 2 \"graph/dijkstra.hpp\"\
    \n#include<queue>\n#include<utility>\n#include<vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<T> dijkstra(vector<vector<pair<int,T>>> G,int v){\n\
    \tvector<bool> kakutei((int)(G.size()),false);\n\tvector<T> cur((int)(G.size()),2000000000000LL);\n\
    \tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;\n\t\
    cur[v]=0;\n\tque.push(make_pair(cur[v],v));\n\twhile(!que.empty()){\n\t\tint pos=que.top().second;\n\
    \t\tque.pop();\n\t\tif(kakutei[pos]==true){\n\t\t\tcontinue;\n\t\t}\n\t\tkakutei[pos]=true;\n\
    \t\tfor(pair<int,T> i : G[pos]){\n\t\t\tint nex=i.first;\n\t\t\tT cost=i.second;\n\
    \t\t\tif(cur[nex]>cur[pos]+cost){\n\t\t\t\tcur[nex]=cur[pos]+cost;\n\t\t\t\tque.push(make_pair(cur[nex],nex));\n\
    \t\t\t}\n\t\t}\n\t}\n\tfor(int i=0;i<(int)(cur.size());i++){\n\t\tif(cur[i]==2000000000000LL){\n\
    \t\t\tcur[i]=-1;\n\t\t}\n\t}\n\treturn cur;\n}\n#line 3 \"verify/verify-aoj-grl/grl_1_a.test.cpp\"\
    \n#include<stdio.h>\n\nint main(){\n\tint N,M,r;\n\tscanf(\"%d%d%d\",&N,&M,&r);\n\
    \tvector<vector<pair<int,long long>>> G(N);\n\tfor(int i=0;i<M;i++){\n\t\tint\
    \ s,t;\n\t\tlong long d;\n\t\tscanf(\"%d%d%lld\",&s,&t,&d);\n\t\tG[s].push_back(make_pair(t,d));\n\
    \t}\n\tvector<long long> dist=dijkstra(G,r);\n\tfor(int i=0;i<N;i++){\n\t\tif(dist[i]==-1){\n\
    \t\t\tprintf(\"INF\\n\");\n\t\t}\n\t\telse{\n\t\t\tprintf(\"%lld\\n\",dist[i]);\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_A\"\n#include\
    \ \"../../graph/dijkstra.hpp\"\n#include<stdio.h>\n\nint main(){\n\tint N,M,r;\n\
    \tscanf(\"%d%d%d\",&N,&M,&r);\n\tvector<vector<pair<int,long long>>> G(N);\n\t\
    for(int i=0;i<M;i++){\n\t\tint s,t;\n\t\tlong long d;\n\t\tscanf(\"%d%d%lld\"\
    ,&s,&t,&d);\n\t\tG[s].push_back(make_pair(t,d));\n\t}\n\tvector<long long> dist=dijkstra(G,r);\n\
    \tfor(int i=0;i<N;i++){\n\t\tif(dist[i]==-1){\n\t\t\tprintf(\"INF\\n\");\n\t\t\
    }\n\t\telse{\n\t\t\tprintf(\"%lld\\n\",dist[i]);\n\t\t}\n\t}\n}\n"
  dependsOn:
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: verify/verify-aoj-grl/grl_1_a.test.cpp
  requiredBy: []
  timestamp: '2024-07-11 12:11:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-aoj-grl/grl_1_a.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-aoj-grl/grl_1_a.test.cpp
- /verify/verify/verify-aoj-grl/grl_1_a.test.cpp.html
title: verify/verify-aoj-grl/grl_1_a.test.cpp
---
