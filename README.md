CodeForces代码（持续更新）

---

337D

本来没想出来，看的题解，类似于求直径的方法，3次dfs，第一次求距离1最远的出现妖怪的点x，第二次求距离x最远的出现妖怪的点，也就是求了最远的妖怪点对，然后所有点里面距离这两个点的距离都小于d的就可能是魔法书所在的点。

---

274B

这道题有点奇怪，或者说我太菜了。。。这种方法是真想不到。

题解看luogu吧，dfs和addn，ren数组的故事。

https://www.luogu.org/problemnew/solution/CF274B

---

1156C

开始想的是二分法，先排个序，每次找一个最小的大于$x+m$的数，但是发现这样会有问题。。。

所以用贪心，尺取法，具体看代码吧。。。

---

461B

树形DP，$d[x][0]$表示节点x的子树没有黑色节点的方案数，$dp[x][1]$表示x节点的子树只有一个黑色节点的方案数。

所以：

$dp[x][1] = dp[x][1] \times (dp[y][0] + dp[y][1]) + dp[x][0] \times dp[y][1]$

$dp[x][0] = dp[x][0] \times (dp[y][0] + dp[y][1])$

---

739B

这题让我很开心，完全没看题解一遍A。嘿嘿嘿。

我的想法是，因为他说a,b两点之间距离小于这个点的点权，并且a是b子树里的点，那么称b控制了a，所以树上两点间距离用一次dfs就能求，还有因为如果b控制a，那么a和b路径上所有的点都控制a，所以想到树上差分。然后再一次dfs的时候，对于每一个点，找一个可以控制他的最高的点的父亲ans-1（为什么是父亲），并且他自己的父亲ans+1，这个往上找的过程需要用到lca的倍增思想。然后再来一次dfs，把ans维护一下，就可以输出答案了。

然后剩下的看程序吧。嗨森！！

---

52C

就是个环形数组求最小值，直接维护线段树，如果一个询问$l < r$那么直接更新r~n, 1~x。

如果$r\leq l$ 那么正常更新即可。

---

519E

求两个点之间，如果长度为奇数，说明点数为偶数，直接输出0，反之，分为三种情况讨论：

先求出a，b两点的lca，记为lcaab，如果lcaab和a，b分别的距离相等，那么答案就是树的大小减去这个lcaab的两个通向a，b方向的儿子的大小。

如果距离不同，那么先找到这个中点，中点与它不包含所询问点的子树上的点都是满足条件的点。

看代码吧。

---

617E

因为异或的性质，可以转化为异或前缀和。

https://www.luogu.org/blog/SSL-ZYC/solution-cf617e