<div align =center><img src="https://github.com/kangzhiheng/GuideOfProgram/blob/master/src/adoredee.png"/></div>

# 剑指offer刷题指南

 Author | adoredee
 :-: | :-:
 E-mail | kangzhiheng@sjtu.edu.cn

## :computer: :bookmark_tabs:算法目录

本repo记录本人学习《剑指offer》的经历。

主要有两个文件夹：

- [剑指offer](https://github.com/kangzhiheng/GuideOfProgram/tree/master/%E5%89%91%E6%8C%87offer/%E5%89%91%E6%8C%87offer)—— 依据书上的思路，结合自己的思考，用C++ STL进行改写，并提供完整的示例，包括详细的**思路**和**注释**以及完整多样的**输入**和**输出**
- [剑指offer源代码](https://github.com/kangzhiheng/GuideOfProgram/tree/master/%E5%89%91%E6%8C%87offer/%E5%89%91%E6%8C%87offer%E6%BA%90%E4%BB%A3%E7%A0%81)—— 《剑指offer》完整的源代码

根据书上的题目类型和顺序，我把这些题目大致分为以下两个目录，以方便查阅：

* [相关性分类](#相关性分类)

* [剑指offer目录](#剑指offer目录)    

### 相​关性分类

#### 数据结构

* 数组与矩阵
  - 面试题3 —— 数组中重复的数字
    - [找出数组中重复的数字](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/03_01_%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E4%B8%AD%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97.cpp)
    - [不修改数组找出重复的数字](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/03_02_%E4%B8%8D%E4%BF%AE%E6%94%B9%E6%95%B0%E7%BB%84%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97.cpp)
  - [面试题4 —— 二维数组的查找](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/04_%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.cpp)
  - [面试题11 —— 转数组中的最小数字](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/11_%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97.cpp)
  - [面试题16 —— 数值的整数次方](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/16_数值的整数次方.cpp)
  - [面试题17 —— 打印从1到最大的n位数](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/17_打印1到最大的n位数.cpp)
  - [面试题21 —— 调整数组顺序使奇数位于偶数前面](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/21_调整数组顺序使奇数位于偶数前面.cpp)
  - [面试题29 —— 顺时针旋转矩阵](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/29_顺时针旋转矩阵.cpp)
* 字符串
  - [面试题5 —— 替换空格](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/06_%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.cpp)
  - [面试题20 —— 表示数值的字符串](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/20_表示数值的字符串.cpp)
* 链表
  - [面试题6 —— 从头到尾打印链表](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/06_%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.cpp)
  - 面试题18 —— 删除链表的节点
    - [在O(1)时间内删除链表节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/18_01_在O(1)时间内删除链表节点.cpp)
    - [删除链表中重复的节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/18_02_删除链表中重复的节点.cpp)
  - [面试题22 —— 链表中倒数第k个节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/22_链表中倒数第k个节点.cpp)
  - [面试题24 —— 反转链表](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/24_%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.cpp)
* 树
  - [面试题7 —— 重建二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/07_%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.cpp)
  - [面试题8 —— 二叉树的下一个节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/08_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%8B%E4%B8%80%E4%B8%AA%E8%8A%82%E7%82%B9.cpp)
  - [面试题26 —— 树的子结构](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/26_树的子结构.cpp)
  - [面试题27 —— 二叉树的镜像](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/27_二叉树的镜像.cpp)
  - [面试题28 —— 对称的二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/28_对称的二叉树.cpp)
  - 面试题32 —— 从上到下打印二叉树
    - [不分行从上往下打印二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/32_01_从上到下打印二叉树.cpp)
    - [分行从上到下打印二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/32_02_分行从上到下打印二叉树.cpp)
* 栈和队列
  - 面试题9 —— 栈和队列的转换
    - [用两个栈实现队列](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/09_01_%E7%94%A8%E4%B8%A4%E4%B8%AA%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.cpp)
    - [用两个队列实现栈](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/09_02_%E7%94%A8%E4%B8%A4%E4%B8%AA%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.cpp)
  - [面试题30 —— 包含min函数的栈](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/30_包含min函数的栈.cpp)
* 图
* 位运算
  - [面试题15 —— 二进制中的1的个数](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/15_二进制中的1的个数.cpp)

#### 算法思想

* 递归和循环
  - 面试题10 —— 斐波那契系列问题
    - [求斐波那契数列的第n项](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/10_01_%E6%B1%82%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97%E7%9A%84%E7%AC%ACn%E9%A1%B9.cpp)
    - [青蛙普通跳台阶(最多跳2级)](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/10_02_%E9%9D%92%E8%9B%99%E6%99%AE%E9%80%9A%E8%B7%B3%E5%8F%B0%E9%98%B6(%E6%9C%80%E5%A4%9A%E8%B7%B32%E7%BA%A7).cpp)
    - [青蛙变态跳台阶(最多跳n级)](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/10_03_%E9%9D%92%E8%9B%99%E5%8F%98%E6%80%81%E8%B7%B3%E5%8F%B0%E9%98%B6(%E6%9C%80%E5%A4%9A%E8%B7%B3n%E7%BA%A7).cpp)
* 排序
* 动态规划
  - [面试题14 —— 剪绳子](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/14_%E5%89%AA%E7%BB%B3%E5%AD%90.cpp)
* 分治
* 二分法

### 剑指offer目录

* 面试题3 —— 数组中重复的数字

  - [找出数组中重复的数字](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/03_01_%E6%89%BE%E5%87%BA%E6%95%B0%E7%BB%84%E4%B8%AD%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97.cpp)

  - [不修改数组找出重复的数字](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/03_02_%E4%B8%8D%E4%BF%AE%E6%94%B9%E6%95%B0%E7%BB%84%E6%89%BE%E5%87%BA%E9%87%8D%E5%A4%8D%E7%9A%84%E6%95%B0%E5%AD%97.cpp)

- [面试题4 —— 二维数组的查找](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/04_%E4%BA%8C%E7%BB%B4%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9F%A5%E6%89%BE.cpp)
- [面试题5 —— 替换空格](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/06_%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.cpp)
- [面试题6 —— 从头到尾打印链表](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/06_%E4%BB%8E%E5%B0%BE%E5%88%B0%E5%A4%B4%E6%89%93%E5%8D%B0%E9%93%BE%E8%A1%A8.cpp)
- [面试题7 —— 重建二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/07_%E9%87%8D%E5%BB%BA%E4%BA%8C%E5%8F%89%E6%A0%91.cpp)
- [面试题8 —— 二叉树的下一个节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/08_%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E4%B8%8B%E4%B8%80%E4%B8%AA%E8%8A%82%E7%82%B9.cpp)
- 面试题9 —— 栈和队列的转换
  - [用两个栈实现队列](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/09_01_%E7%94%A8%E4%B8%A4%E4%B8%AA%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.cpp)
  - [用两个队列实现栈](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/09_02_%E7%94%A8%E4%B8%A4%E4%B8%AA%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.cpp)
- 面试题10 —— 斐波那契系列问题
  - [求斐波那契数列的第n项](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/10_01_%E6%B1%82%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97%E7%9A%84%E7%AC%ACn%E9%A1%B9.cpp)
  - [青蛙普通跳台阶(最多跳2级)](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/10_02_%E9%9D%92%E8%9B%99%E6%99%AE%E9%80%9A%E8%B7%B3%E5%8F%B0%E9%98%B6(%E6%9C%80%E5%A4%9A%E8%B7%B32%E7%BA%A7).cpp)
  - [青蛙变态跳台阶(最多跳n级)](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/10_03_%E9%9D%92%E8%9B%99%E5%8F%98%E6%80%81%E8%B7%B3%E5%8F%B0%E9%98%B6(%E6%9C%80%E5%A4%9A%E8%B7%B3n%E7%BA%A7).cpp)
- [面试题11 —— 旋转数组中的最小数字](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/11_%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84%E4%B8%AD%E7%9A%84%E6%9C%80%E5%B0%8F%E6%95%B0%E5%AD%97.cpp)
- [面试题12 —— 矩阵中的路径](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/12_矩阵中路径.cpp)
- [面试题13 —— 机器人的运动范围](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/13_机器人的运动范围.cpp)
- [面试题14 —— 剪绳子](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/14_%E5%89%AA%E7%BB%B3%E5%AD%90.cpp)
- [面试题15 —— 二进制中的1的个数](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/15_二进制中的1的个数.cpp)
- [面试题16 —— 数值的整数次方](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/16_数值的整数次方.cpp)
- [面试题17 —— 打印从1到最大的n位数](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/17_打印1到最大的n位数.cpp)
- 面试题18 —— 删除链表的节点
  - [在O(1)时间内删除链表节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/18_01_在O(1)时间内删除链表节点.cpp)
  - [删除链表中重复的节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/18_02_删除链表中重复的节点.cpp)
- [面试题20 —— 表示数值的字符串](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/20_表示数值的字符串.cpp)
- [面试题21 —— 调整数组顺序使奇数位于偶数前面](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/21_调整数组顺序使奇数位于偶数前面.cpp)
- [面试题22 —— 链表中倒数第k个节点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/22_链表中倒数第k个节点.cpp)
- [面试题23 —— 链表中环的入口结点](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/23_链表中环的入口结点.cpp)
- [面试题24 —— 反转链表](https://github.com/kangzhiheng/GuideOfProgram/blob/master/%E5%89%91%E6%8C%87offer/剑指offer/24_%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.cpp)
- [面试题25 —— 合并两个排序的链表](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/25_合并两个排序的链表.cpp)
- [面试题26 —— 树的子结构](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/26_树的子结构.cpp)
- [面试题27 —— 二叉树的镜象](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/27_二叉树的镜像.cpp)
- [面试题28 —— 对称的二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/28_对称的二叉树.cpp)
- [面试题29 —— 顺时针旋转矩阵](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/29_顺时针旋转矩阵.cpp)
- [面试题30 —— 包含min函数的栈](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/30_包含min函数的栈.cpp)
- 面试题32 —— 从上到下打印二叉树
  - [不分行从上往下打印二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/32_01_从上到下打印二叉树.cpp)
  - [分行从上到下打印二叉树](https://github.com/kangzhiheng/GuideOfProgram/blob/master/剑指offer/剑指offer/32_02_分行从上到下打印二叉树.cpp)
