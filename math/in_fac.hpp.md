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
  bundledCode: "#line 2 \"math/in_fac.hpp\"\n#include<vector>\n\ntemplate<class S>\n\
    void in_fac(auto *factorial){\n\tfactorial[0]=1;\n\tfor(int i=1;i<10;i++){\n\t\
    \tfactorial[i]=factorial[i-1]*i;\n\t}\n}\n\ntemplate<class S>\nvoid in_fac(std::vector<S>\
    \ &factorial){\n\tfactorial[0]=1;\n\tfor(int i=1;i<10;i++){\n\t\tfactorial[i]=factorial[i-1]*i;\n\
    \t}\n}\n"
  code: "#pragma once\n#include<vector>\n\ntemplate<class S>\nvoid in_fac(auto *factorial){\n\
    \tfactorial[0]=1;\n\tfor(int i=1;i<10;i++){\n\t\tfactorial[i]=factorial[i-1]*i;\n\
    \t}\n}\n\ntemplate<class S>\nvoid in_fac(std::vector<S> &factorial){\n\tfactorial[0]=1;\n\
    \tfor(int i=1;i<10;i++){\n\t\tfactorial[i]=factorial[i-1]*i;\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/in_fac.hpp
  requiredBy: []
  timestamp: '2024-06-20 00:23:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/in_fac.hpp
layout: document
redirect_from:
- /library/math/in_fac.hpp
- /library/math/in_fac.hpp.html
title: math/in_fac.hpp
---
