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
  bundledCode: "#line 2 \"math/power.hpp\"\n#include<functional>\n\ntemplate<class\
    \ S,auto op,auto e>\nS power(S a,long long b){\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n    S mul=a;\n    S ans=e();\n\
    \    while(b){\n        if(b&1){\n        \tans=op(ans,mul);\n        }\n    \
    \    b>>=1;\n        mul=op(mul,mul);\n    }\n    return ans;\n}\n"
  code: "#pragma once\n#include<functional>\n\ntemplate<class S,auto op,auto e>\n\
    S power(S a,long long b){\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n    S mul=a;\n    S ans=e();\n\
    \    while(b){\n        if(b&1){\n        \tans=op(ans,mul);\n        }\n    \
    \    b>>=1;\n        mul=op(mul,mul);\n    }\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/power.hpp
  requiredBy: []
  timestamp: '2024-06-18 19:22:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/power.hpp
layout: document
redirect_from:
- /library/math/power.hpp
- /library/math/power.hpp.html
title: math/power.hpp
---
