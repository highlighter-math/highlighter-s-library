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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data-structure/Fenwick_Tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../../data-structure/Fenwick_Tree.hpp\"\nusing namespace std;\n\nlong\
    \ long op(long long a,long long b){\n\treturn a+b;\n}\n\nlong long op_inv(long\
    \ long a,long long b){\n\treturn a-b;\n}\n\nlong long e(){\n\treturn 0LL;\n}\n\
    \nbool comp(long long a,long long b){\n\treturn a<b;\n}\n\nint main(){\n\tint\
    \ N,Q;\n\tscanf(\"%d%d\",&N,&Q);\n\tvector<long long> A(N);\n\tfor(int i=0;i<N;i++){\n\
    \t\tscanf(\"%lld\",&A[i]);\n\t}\n\tFenwick_Tree<long long,op,op_inv,e> fw(A);\n\
    \tfor(;Q--;){\n\t\tint c;\n\t\tscanf(\"%d\",&c);\n\t\tif(c==0){\n\t\t\tint p;\n\
    \t\t\tlong long x;\n\t\t\tscanf(\"%d%lld\",&p,&x);\n\t\t\tfw.add(p,x);\n\t\t\t\
    continue;\n\t\t}\n\t\tint l,r;\n\t\tscanf(\"%d%d\",&l,&r);\n\t\tprintf(\"%lld\\\
    n\",fw.prod(l,r));\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Fenwick_Tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: Fenwick_Tree.test.cpp
layout: document
redirect_from:
- /verify/Fenwick_Tree.test.cpp
- /verify/Fenwick_Tree.test.cpp.html
title: Fenwick_Tree.test.cpp
---
