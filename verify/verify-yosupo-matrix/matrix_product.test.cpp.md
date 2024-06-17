---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: matrix/matrix.hpp
    title: matrix/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"verify/verify-yosupo-matrix/matrix_product.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#line 1 \"\
    matrix/matrix.hpp\"\n#include<vector>\n#include<cassert>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct matrix{\n\tint H,W;\n\tvector<vector<T>> table;\n\
    \tmatrix(int h,int w) : H(h),W(w){\n\t\ttable.resize(h,vector<T>(w));\n\t}\n\t\
    int size(){\n\t\treturn H;\n\t}\n\tmatrix pow(long long N){\n\t\tassert(H==W);\n\
    \t\tassert(0<=N);\n\t\tmatrix x=*this;\n\t\tmatrix r(H,H);\n\t\tfor(int i=0;i<H;i++){\n\
    \t\t\tr[i][i]=1;\n\t\t}\n\t\twhile(N){\n\t\t\tif(N&1)r*=x;\n\t\t\tx*=x;\n\t\t\t\
    N>>=1;\n\t\t}\n\t\treturn r;\n\t}\n\tvector<T>& operator[](int index){\n\t\tassert(index<H);\n\
    \t\treturn table[index];\n\t}\n\tmatrix& operator+=(const matrix &other){\n\t\t\
    for(int i=0;i<H;i++){\n\t\t\tfor(int j=0;j<W;j++){\n\t\t\t\tif((int)(other.table.size())<=i){\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tif((int)(other.table[i].size())<=j){\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\t(*this)[i][j]+=other.table[i][j];\n\t\t\
    \t}\n\t\t}\n\t\treturn *this;\n\t}\n\tmatrix operator*=(const matrix &other){\n\
    \t\tint h=other.H;\n\t\tint w=other.W;\n\t\tassert(h==W);\n\t\t//\u7D50\u679C\u306F\
    H*w\u884C\u5217\u306B\u306A\u308B\n\t\tmatrix result(H,w);\n\t\tfor(int i=0;i<H;i++){\n\
    \t\t\tfor(int k=0;k<W;k++){\n\t\t\t\tfor(int j=0;j<w;j++){\n\t\t\t\t\tresult.table[i][j]+=table[i][k]*other.table[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t*this=result;\n\t\treturn *this;\n\t}\n};\n#line\
    \ 3 \"verify/verify-yosupo-matrix/matrix_product.test.cpp\"\n#include<iostream>\n\
    #include<atcoder/modint>\nusing namespace atcoder;\nusing mint=modint998244353;\n\
    \nint main(){\n\tint N,M,K;\n\tscanf(\"%d%d%d\",&N,&M,&K);\n\tmatrix<mint> A(N,M);\n\
    \tmatrix<mint> B(M,K);\n\tfor(int i=0;i<N;i++){\n\t\tfor(int j=0;j<M;j++){\n\t\
    \t\tint a;\n\t\t\tscanf(\"%d\",&a);\n\t\t\tA[i][j]=a;\n\t\t}\n\t}\n\tfor(int i=0;i<M;i++){\n\
    \t\tfor(int j=0;j<K;j++){\n\t\t\tint b;\n\t\t\tscanf(\"%d\",&b);\n\t\t\tB[i][j]=b;\n\
    \t\t}\n\t}\n\tA*=B;\n\tfor(int i=0;i<A.H;i++){\n\t\tfor(int j=0;j<A.W;j++){\n\t\
    \t\tprintf(\"%d \",A[i][j].val());\n\t\t}\n\t\tprintf(\"\\n\");\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"../../matrix/matrix.hpp\"\n#include<iostream>\n#include<atcoder/modint>\n\
    using namespace atcoder;\nusing mint=modint998244353;\n\nint main(){\n\tint N,M,K;\n\
    \tscanf(\"%d%d%d\",&N,&M,&K);\n\tmatrix<mint> A(N,M);\n\tmatrix<mint> B(M,K);\n\
    \tfor(int i=0;i<N;i++){\n\t\tfor(int j=0;j<M;j++){\n\t\t\tint a;\n\t\t\tscanf(\"\
    %d\",&a);\n\t\t\tA[i][j]=a;\n\t\t}\n\t}\n\tfor(int i=0;i<M;i++){\n\t\tfor(int\
    \ j=0;j<K;j++){\n\t\t\tint b;\n\t\t\tscanf(\"%d\",&b);\n\t\t\tB[i][j]=b;\n\t\t\
    }\n\t}\n\tA*=B;\n\tfor(int i=0;i<A.H;i++){\n\t\tfor(int j=0;j<A.W;j++){\n\t\t\t\
    printf(\"%d \",A[i][j].val());\n\t\t}\n\t\tprintf(\"\\n\");\n\t}\n}\n"
  dependsOn:
  - matrix/matrix.hpp
  isVerificationFile: true
  path: verify/verify-yosupo-matrix/matrix_product.test.cpp
  requiredBy: []
  timestamp: '2024-06-17 09:42:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/verify-yosupo-matrix/matrix_product.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-yosupo-matrix/matrix_product.test.cpp
- /verify/verify/verify-yosupo-matrix/matrix_product.test.cpp.html
title: verify/verify-yosupo-matrix/matrix_product.test.cpp
---
