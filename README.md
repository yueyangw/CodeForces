CodeForces代码（持续更新）

---

337D

本来没想出来，看的题解，类似于求直径的方法，3次dfs，第一次求距离1最远的出现妖怪的点x，第二次求距离x最远的出现妖怪的点，也就是求了最远的妖怪点对，然后所有点里面距离这两个点的距离都小于d的就可能是魔法书所在的点。