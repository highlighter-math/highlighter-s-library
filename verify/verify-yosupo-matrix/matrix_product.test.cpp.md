---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"../../matrix/matrix.hpp\"\n#include<iostream>\n#include \"atcoder/modint\"\
    \nusing namespace atcoder;\nusing mint=modint998244353;\n\nint main(){\n\tint\
    \ N,M,K;\n\tscanf(\"%d%d%d\",&N,&M,&K);\n\tmatrix<mint> A(N,M);\n\tmatrix<mint>\
    \ B(M,K);\n\tfor(int i=0;i<N;i++){\n\t\tfor(int j=0;j<M;j++){\n\t\t\tint a;\n\t\
    \t\tscanf(\"%d\",&a);\n\t\t\tA[i][j]=a;\n\t\t}\n\t}\n\tfor(int i=0;i<M;i++){\n\
    \t\tfor(int j=0;j<K;j++){\n\t\t\tint b;\n\t\t\tscanf(\"%d\",&b);\n\t\t\tB[i][j]=b;\n\
    \t\t}\n\t}\n\tA*=B;\n\tfor(int i=0;i<A.H;i++){\n\t\tfor(int j=0;j<A.W;j++){\n\t\
    \t\tprintf(\"%d \",A[i][j].val());\n\t\t}\n\t\tprintf(\"\\n\");\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/verify-yosupo-matrix/matrix_product.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-matrix/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-matrix/matrix_product.test.cpp
- /verify/verify/verify-yosupo-matrix/matrix_product.test.cpp.html
title: verify/verify-yosupo-matrix/matrix_product.test.cpp
---
