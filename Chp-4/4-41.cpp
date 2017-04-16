/************************************************************************
     File Name: 4-41.cpp
     ID: Liusiyu
     BLOG: http://blog.csdn.net/r_o_j 
     LANG: C++ 
     Mail: 779532360@qq.com 
     Created Time: Sun 16 Apr 2017 07:01:28 PM CST
 ************************************************************************/
#include<bits/stdc++.h>
#define MEM(a,x) memset(a,x,sizeof(a));
#define MEMINF(a) memset(a,0x3f,sizeof(a));
#define pb push_back
#define Abs(x) ((x) >= 0 ? (x) : (-(x)))
using namespace std;
typedef long long LL;
const int MAXN=2e5 + 10;
const int INF=0x3f3f3f3f;
const int MOD=1000000007;
int main() {
 int baker, cooper, fletcher, miller, smith;
 for (baker = 1; baker <= 5; ++baker) {
   if (baker != 5)
     for (cooper = 1; cooper <= 5; ++cooper) {
       if (baker != cooper && cooper != 1)
         for (fletcher = 1; fletcher <= 5; ++fletcher) {
           if (baker != fletcher && cooper != fletcher && fletcher != 5 && fletcher != 1)
             for (miller = 1; miller <= 5; ++miller) {
               if (baker != miller && fletcher != miller && cooper != miller)
                 for (smith = 1; smith <= 5; ++smith) {
                   if (smith != baker && fletcher != smith && cooper != smith &&
                       miller != smith)
                     if (abs(smith - fletcher) != 1 && abs(fletcher - cooper) != 1)
                       printf("%d %d %d %d %d\n",baker,cooper,fletcher,miller,smith);
                 }
             }
         }
     }
 }
}
