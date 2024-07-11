---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \t\t\t}\n\t\t}\n\t}\n\treturn cur;\n}\n"
  code: "#pragma once\n#include<queue>\n#include<utility>\n#include<vector>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nvector<T> dijkstra(vector<vector<pair<int,T>>>\
    \ G,int v){\n\tvector<bool> kakutei((int)(G.size()),false);\n\tvector<T> cur((int)(G.size()),2000000000000LL);\n\
    \tpriority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> que;\n\t\
    cur[v]=0;\n\tque.push(make_pair(cur[v],v));\n\twhile(!que.empty()){\n\t\tint pos=que.top().second;\n\
    \t\tque.pop();\n\t\tif(kakutei[pos]==true){\n\t\t\tcontinue;\n\t\t}\n\t\tkakutei[pos]=true;\n\
    \t\tfor(pair<int,T> i : G[pos]){\n\t\t\tint nex=i.first;\n\t\t\tT cost=i.second;\n\
    \t\t\tif(cur[nex]>cur[pos]+cost){\n\t\t\t\tcur[nex]=cur[pos]+cost;\n\t\t\t\tque.push(make_pair(cur[nex],nex));\n\
    \t\t\t}\n\t\t}\n\t}\n\treturn cur;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2024-07-11 12:01:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
