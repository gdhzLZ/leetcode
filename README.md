刷题记录
============

2020.1.27 4:28   Leetcode315
------------------
这个题乍一看用二叉搜索树做不难。但自己折在了“Count += root -> count + 1;“
我写成了"cout = root-》count+1；insert_node = count" 这其实是难点所在。
每个节点的count都记录了左子树所有的节点的个数。这也是二叉搜索树的精华所在。可以
直接跳到下一个大于当前节点的位置。那这样看来count的值一定是+=计算下来的.
二叉搜索树示意：
 （8 9 10 （5 6 7））可以看到，每个节点左子树都记到了碰到比自己大的地方就停止了。
 所以不会出现我想的重复加的情况。count(7) = 2; count(10) = 2;所以如果下一个是11
 的话，计算过程是2+1+2+1 = 5;
 
2020.1.27 23:31   leetcode542
--------------------
首先说一句自己太菜了，这么简单地题做了很长时间
这道题跟迷宫题很像，只不过这道题相当于是多个出口。
先把所有的0全都压入队列，然后逆向bfs
判断是否入队列的条件就看这个点之前有没有入队列过
如果没有如果队列，就一定是1，此时也一定是到达这个位置的最短位置。
这个题学习两点：1.记住方向遍历的简单写法2.二维vector确定大小和初始化的写法

2020.1.28 22:21 leetcode456
-------------------
还是太菜了，试了很多想法要么是超时，要么是错误。想的麻烦了。
最朴素的dp就完事了。n2复杂度。对于每一次内循环，起点是不变的，
只需要更改区间[first,second]的j就可以，改变之前先检查一下，当前的数在
不在区间里。如果在返回true，不再就看是否会让这个上升区间拉长，
可以的话就把second改成当前的nums[j]。初始的first,second可以设置成nums[i]
显然这个做法不是最好的。但思路很清晰。
