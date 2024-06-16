---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B
  bundledCode: "#line 1 \"Fenwick_Tree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<class S,auto op,auto\
    \ op_inv,auto e>\nstruct Fenwick_Tree{\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(op_inv),\
    \ std::function<S(S, S)>>,\"op_inv must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n\tint siz=1;\n\tvector<S> dat;\n\
    \tFenwick_Tree(int N) : dat(N,e()){\n\t\tsiz=N;\n\t}\n\tFenwick_Tree(vector<S>\
    \ A) : dat(A.size(),e()){\n\t\tsiz=(int)(A.size());\n\t\tvector<S> sum(siz+1,e());\n\
    \t\tfor(int i=1;i<=siz;i++){\n\t\t\tsum[i]=op(sum[i-1],A[i-1]);\n\t\t}\n\t\tfor(int\
    \ i=0;i<siz;i++){\n\t\t\tint len=(i+1)&(-i-1);\n\t\t\tdat[i]=op_inv(sum[i+1],sum[i+1-len]);\n\
    \t\t}\n\t}\n\tvoid add(int k,S x){\n\t\tfor(int i=k;i<siz;i+=((i+1)&(-i-1))){\n\
    \t\t\tdat[i]=op(dat[i],x);\n\t\t}\n\t}\n\tS prod(int k){\n\t\tif(k<=0){\n\t\t\t\
    return e();\n\t\t}\n\t\tif(k>siz){\n\t\t\treturn prod(siz);\n\t\t}\n\t\tS ans=e();\n\
    \t\tfor(int i=k-1;i>=0;i-=((i+1)&(-i-1))){\n\t\t\tans=op(ans,dat[i]);\n\t\t}\n\
    \t\treturn ans;\n\t}\n\tS prod(int l,int r){\n\t\treturn op_inv(prod(r),prod(l));\n\
    \t}\n\tS get(int p){\n\t\treturn prod(p,p+1);\n\t}\n\tvoid update(int k,S x){\n\
    \t\tS y=prod(k,k+1);\n\t\tadd(k,op_sub(x,y));\n\t}\n\tint lower_bound(S x,bool\
    \ (*comp)(S,S)){\n\t\tint k=1;\n\t\twhile(k*2<=siz){\n\t\t\tk*=2;\n\t\t}\n\t\t\
    int ans=0;\n\t\tfor(;k>0;k/=2){\n\t\t\tif(ans+k<=siz && comp(dat[ans+k-1],x)){\n\
    \t\t\t\tx=op_inv(x,dat[ans+k-1]);\n\t\t\t\tans+=k;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ ans;\n\t}\n};\n#line 3 \"verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp\"\
    \n\nlong long op(long long a,long long b){\n\treturn a+b;\n}\n\nlong long op_inv(long\
    \ long a,long long b){\n\treturn a-b;\n}\n\nlong long e(){\n\treturn 0LL;\n}\n\
    \nbool comp(long long a,long long b){\n\treturn a<b;\n}\n\nint main(){\n\tint\
    \ N,Q;\n\tscanf(\"%d%d\",&N,&Q);\n\tFenwick_Tree<long long,op,op_inv,e> fw(N);\n\
    \tfor(;Q--;){\n\t\tint c;\n\t\tscanf(\"%d\",&c);\n\t\tif(c==0){\n\t\t\tint p;\n\
    \t\t\tlong long x;\n\t\t\tscanf(\"%d%lld\",&p,&x);\n\t\t\tp--;\n\t\t\tfw.add(p,x);\n\
    \t\t\tcontinue;\n\t\t}\n\t\tint l,r;\n\t\tscanf(\"%d%d\",&l,&r);\n\t\tprintf(\"\
    %lld\\n\",fw.prod(l-1,r));\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n\ntemplate<class S,auto op,auto\
    \ op_inv,auto e>\nstruct Fenwick_Tree{\n\tstatic_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\"op must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(op_inv),\
    \ std::function<S(S, S)>>,\"op_inv must work as S(S, S)\");\n\tstatic_assert(std::is_convertible_v<decltype(e),\
    \ std::function<S()>>,\"e must work as S()\");\n\tint siz=1;\n\tvector<S> dat;\n\
    \tFenwick_Tree(int N) : dat(N,e()){\n\t\tsiz=N;\n\t}\n\tFenwick_Tree(vector<S>\
    \ A) : dat(A.size(),e()){\n\t\tsiz=(int)(A.size());\n\t\tvector<S> sum(siz+1,e());\n\
    \t\tfor(int i=1;i<=siz;i++){\n\t\t\tsum[i]=op(sum[i-1],A[i-1]);\n\t\t}\n\t\tfor(int\
    \ i=0;i<siz;i++){\n\t\t\tint len=(i+1)&(-i-1);\n\t\t\tdat[i]=op_inv(sum[i+1],sum[i+1-len]);\n\
    \t\t}\n\t}\n\tvoid add(int k,S x){\n\t\tfor(int i=k;i<siz;i+=((i+1)&(-i-1))){\n\
    \t\t\tdat[i]=op(dat[i],x);\n\t\t}\n\t}\n\tS prod(int k){\n\t\tif(k<=0){\n\t\t\t\
    return e();\n\t\t}\n\t\tif(k>siz){\n\t\t\treturn prod(siz);\n\t\t}\n\t\tS ans=e();\n\
    \t\tfor(int i=k-1;i>=0;i-=((i+1)&(-i-1))){\n\t\t\tans=op(ans,dat[i]);\n\t\t}\n\
    \t\treturn ans;\n\t}\n\tS prod(int l,int r){\n\t\treturn op_inv(prod(r),prod(l));\n\
    \t}\n\tS get(int p){\n\t\treturn prod(p,p+1);\n\t}\n\tvoid update(int k,S x){\n\
    \t\tS y=prod(k,k+1);\n\t\tadd(k,op_sub(x,y));\n\t}\n\tint lower_bound(S x,bool\
    \ (*comp)(S,S)){\n\t\tint k=1;\n\t\twhile(k*2<=siz){\n\t\t\tk*=2;\n\t\t}\n\t\t\
    int ans=0;\n\t\tfor(;k>0;k/=2){\n\t\t\tif(ans+k<=siz && comp(dat[ans+k-1],x)){\n\
    \t\t\t\tx=op_inv(x,dat[ans+k-1]);\n\t\t\t\tans+=k;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ ans;\n\t}\n};\n#line 3 \"verify/verify-yosupo-datastructure/point_add_range_sum.test.cpp\"\
    \n\nlong long op(long long a,long long b){\n\treturn a+b;\n}\n\nlong long op_inv(long\
    \ long a,long long b){\n\treturn a-b;\n}\n\nlong long e(){\n\treturn 0LL;\n}\n\
    \nbool comp(long long a,long long b){\n\treturn a<b;\n}\n\nint main(){\n\tint\
    \ N,Q;\n\tscanf(\"%d%d\",&N,&Q);\n\tFenwick_Tree<long long,op,op_inv,e> fw(N);\n\
    \tfor(;Q--;){\n\t\tint c;\n\t\tscanf(\"%d\",&c);\n\t\tif(c==0){\n\t\t\tint p;\n\
    \t\t\tlong long x;\n\t\t\tscanf(\"%d%lld\",&p,&x);\n\t\t\tp--;\n\t\t\tfw.add(p,x);\n\
    \t\t\tcontinue;\n\t\t}\n\t\tint l,r;\n\t\tscanf(\"%d%d\",&l,&r);\n\t\tprintf(\"\
    %lld\\n\",fw.prod(l-1,r));\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: Fenwick_Tree.test.cpp
  requiredBy: []
  timestamp: '2024-06-16 23:44:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Fenwick_Tree.test.cpp
layout: document
redirect_from:
- /verify/Fenwick_Tree.test.cpp
- /verify/Fenwick_Tree.test.cpp.html
title: Fenwick_Tree.test.cpp
---
