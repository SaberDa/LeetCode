Leetcode刷题记录

最近在找实习刷LeetCode，所以开了这么一个系列。一是巩固自己的记忆；二是发出来我的思路或者我找到的思路，想让大家集思广益，分析是否有更好的解法。这个系列估计会在我找到全职工作后才会停止更新。

我觉得刷LeetCode最大的乐趣并不在于你WA了多次后迎来AC，或者一遍AC，而是AC后去讨论区，看看其他人的代码是怎么写的？看看有没有和你不一样的解题思路？看看其他人是怎样优化他们的代码？看看他们的编码方式有哪些值得学习。这些才是我认为LeetCode上最有用的地方。

或许你可以说这些东西GitHub上都有，甚至会有更好的代码云云，但是举个通俗的例子来讲，这就好比你在高中时刷的题一样，只有自己付出时间努力思考，才能高效理解老师或者同学给出的解题思路。

我是按照题目类型去刷题的，而非题目编号顺序。好比我现在一直在刷数组类的题目，即解题使用的数据结构是基于数组而非链表的。在这个大范围下，又细分了很多小类，比如 K-Sum、双指针之类的问题。这些类型网上都有很棒的开源仓库记录，大家如果也想按照这个方法刷题的话，用搜索引擎搜索“LeetCode 分类 GitHub”即可。

同时，我刷题的主要语言是C++，所以下面给出一些代码示例都是C++的。

数组类Part1

拿C++来说，如果想不费力气的去做这方面的题，这里建议事先复习好关于vector, unordered_map, map, prioity_queue等STL提供的数据结构。用一个适合该题目的数据结构解题会节省你大量的时间。

K-Sum 问题

问题描述：这类题会给你一个数组和一个数字，让你计算出这个数组中的n个值的和或者积等于或者大于给出的数字。LeetCode的第一题就是该类题目。

第一题描述。

解题：解题前要注意下题目给出的要求，观察是否要按照升序或者降序输出，或者是否要求不能有重复的子数组，或者要求是否连续。

一般这种题目我首先会使用双指针来解题。如果使用双指针过于复杂，我会考虑是否使用unordered_map，即hash-map解决。

这里拿259题做个例子。

Given an array of *n* integers *nums* and a *target*, find the number of index triplets `i, j, k` with `0 <= i < j < k < n` that satisfy the condition `nums[i] + nums[j] + nums[k] < target`

**Example:**

```
Input: nums = [-2,0,1,3], and target = 2
Output: 2 
Explanation: Because there are two triplets which sums are less than 2:
             [-2,0,1]
             [-2,0,3]
```

**Follow up:** Could you solve it in *O*(*n*2) runtime?

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0;
        if(nums.size() <= 2) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i) {
            int left = i+1, right = nums.size()-1;
            while(left < right) {
                if(nums[i] + nums[left] + nums[right] < target) {
                    res += right-left;
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return res;
    }
};

这道题是让我们从给出的数组中选出3个值，使这3个值的和小于给出的target，最后输出一共有几组符合上诉条件。像这种题目中已经暗示你需要排序的题目是很简单的，先把给出的数组排序，然后设立两个指针left和right分别指向头和尾。因为STL中的sort排序默认结果是从小到大的，所以排序后的数组越靠后的值越大。所以先固定一个值，然后分别移动left和right指针，如果和小于target，数量就+1同时左指针右移；反之右指针左移。

这道题是一个非常典型的使用双指针法求解K-Sum问题的例题。我们使用双指针时，这两个指针的初始位置一定要灵活，根据题意初始化位置。

区间问题

问题描述：这类问题一般会给你一个包含多个子数组的数组，然后针对这些数组创造的空间是否重合来对问题进行判断。

解题：这种问题我们一般都需要对给出的数组进行排序。简单的情况可以只对原始数组进行排序，一些复杂的题解需要分别对数组的元素进行排序然后单独保存，之后再进行比较。解决这种问题时，用笔在纸上画图是最容易找出解题思路的，一般我们都需要在前一个区间的end和后一个区间的start中找交集。

这里我给出两道这方面的例题进行解释。

56 Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), compare);
    
        int count = 0;
        res.push_back(intervals[count]);
    
        for (int i = 1; i < intervals.size(); i++) {
            if (res[count][1] >= intervals[i][0]) {
                res[count][1] = max(res[count][1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
                count++;
            }
        }
        return res;
    }
};

这个就是很明显的区间合并问题，比如在第一个example中，[1,3] 和 [2,6] 中，后一个区间的start在第一个区间内，此时就把两者合并为一个区间[1, 6]。此题的核心思路在于我们只需要比较当前区间的end是否大于等于下一个区间的start，如果是的话，则比较当前区间的end和下一个区间的end，并且取两者中的最大值作为当前区间的end，然后进行下一次循环，直到当前区间end小于下一个区间的start。

253 Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times `[[s1,e1],[s2,e2],...]` (si < ei), find the minimum number of conference rooms required.

**Example 1:**

```
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
```

**Example 2:**

```
Input: [[7,10],[2,4]]
Output: 1
```

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        vector<int> start;
        vector<int> end;
        for (int i = 0; i < intervals.size(); i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int room = 0;
        int count = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if (start[i] < end[count]) {
                room++;
            } else {
                count++;
            }
        }
        return room;


​       
    }

};

这道题也是明显的区间判断问题，但是比上一道给出的例题复杂。这道题就需要我们分别对各个区间的start和end进行排序，然后通过计算比end大的start的数量给出最终答案。![1](C:\Users\Saberda\Desktop\1.png)

正如图解所示，第一行为start的排序结果，第二行为end的排序结果。如果下个会以的start大于当前的end，则表示需要第二间会议室来承办下个会以。

组合类

问题描述：给出一个数组，要求解出所有满足条件的子数组。最典型的例子就是求子集。

解法：这类题目利用回溯法递归来生成符合条件的子集。根据题目要求判断递归条件即可。

90 Subset II

Given a collection of integers that might contain duplicates, ***nums\***, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

```
Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
```

class Solution {
public:
    
    void backtrack(vector<int>& nums, int k, vector<int> subset, vector<vector<int>>& res) {
        if (k == nums.size()) {
            res.push_back(subset);
            return;
        }
        backtrack(nums, k+1, subset, res);
        subset.push_back(nums[k]);
        backtrack(nums, k+1, subset, res);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        backtrack(nums, 0, vector<int> (), res);
        
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            sort(res[i].begin(), res[i].end());
        }
        
        sort(res.begin(), res.end());
        vector<vector<int>>::iterator iter;
        iter = unique(res.begin(), res.end());
        res.erase(iter, res.end());
        
        return res;
        
    }
};

注意，这道题目要求结果中不能包含重复的子集，所以主函数在递归的后面加了筛选条件剔除重复的子集。

连续子数组问题

问题描述：给出一个数组，求符合条件的最长或者最短连续子数组。

解法：这类问题使用滑窗法即可。至于什么是滑窗法，见下面这道例题。

239 Sliding Window Maximum

Given an array *nums*, there is a sliding window of size *k* which is moving from the very left of the array to the very right. You can only see the *k* numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

**Example:**

```
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

class Solution {
public:
    
    int compare(vector<int>& nums, int i, int j) {
        int max = i;
        while (i < j) {
            if (nums[max] < nums[i+1]) {
                max = i+1;
            }
            i++;
        }
        return max;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) {
            return res;
        }
        int first = 0;
        int last = k-1;
        while (last < nums.size()) {
            int max = compare(nums, first, last);
            res.push_back(nums[max]);
            first++;
            last++;
        }
        return res;
    }
};

239中的example很好的解释了什么是滑窗，只不过这道题固定了滑窗的长度。具体解法还是双指针，左指针确定滑窗左值，右指针确定滑窗右值。注意，一般这种要求给出连续数组的题目最好不要使用排序来打乱原始顺序。

其他一些分享

这个模块是分享一些个人觉得很巧妙的解题思路。当然来自LeetCode的Discuss模块。抄代码不可耻，可耻的是不会抄袭好的代码。

这道题是求解中位数的一道题，并不怎么难，但是这个人的思路非常巧妙，他使用两个堆，一个大顶堆一个小顶堆，来表示排序后数组。中位数要么是大顶堆的顶值，要么是两个堆顶值的和的一半。

295 Find Median from Data stream

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,

```
[2,3,4]`, the median is `3
[2,3]`, the median is `(2 + 3) / 2 = 2.5
```

Design a data structure that supports the following two operations:

- void addNum(int num) - Add a integer number from the data stream to the data structure.
- double findMedian() - Return the median of all elements so far.

**Example:**

```
addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
```

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }
        if (left.size() > right.size()+1) {
            int temp = left.top();
            left.pop();
            right.push(temp);
        }
        if (left.size() < right.size()) {
            int temp = right.top();
            right.pop();
            left.push(temp);
        }
    }
    
    double findMedian() {
        
        double res;
        if (left.size() == right.size()) {
            res = (left.top() + right.top()) / 2.0;
        } else {
            res = left.top();
        }
        return res;
        
    }
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
};

代码由两部分组成，第一部分是将数组中的元素分别入堆，第二部分是计算中位数的值。



分享的第二道题是昨晚新发现的一种map处理方式。一般我们使用map时，都习惯将key作为序号，value作为保存的值。但是这道题反其道而行之，用key来保存值，value表示序号，即长度。

325 Maximum Size Subarray Sum Equals k

Given an array *nums* and a target value *k*, find the maximum length of a subarray that sums to *k*. If there isn't one, return 0 instead.

**Note:**
The sum of the entire *nums* array is guaranteed to fit within the 32-bit signed integer range.

**Example 1:**

```
Input: nums = [1, -1, 5, -2, 3], k = 3
Output: 4 
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
```

**Example 2:**

```
Input: nums = [-2, -1, 2, 1], k = 1
Output: 2 
Explanation: The subarray [-1, 2] sums to 1 and is the longest.
```

**Follow Up:**
Can you do it in O(*n*) time?

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, int> m;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (!m.count(sum)) {
                m[sum] = i;
            }
            if (sum == k) {
                ans = max(ans, i+1);
            }
            if (m.count(sum-k)) {
                ans = max(ans, i-m[sum-k]);
            }
        }
        return ans;
    }
};

这道题是让我们求出最长的连续自序列，使该子序列的值等于k。这里我使用哈希表来满足最后的O(n)。key里存储的是当前子序列的和，value储存的是当前连续子序列的长度。该子序列是从数组初始元素开始，每次递加一个长度。然后我们只需要判断当前的和减去给出的k，然后判断这个差是否存在于表里即可。如果存在的话，用当前长度减去差所储存的value值就是当前符合条件的连续子序列长度。

建立个人的代码仓库

这里的代码仓库指的并不是记录你解题的仓库，而是在你刷题过程中，经常使用的或者一些巧妙的算法实现。比如我就把用大顶堆和小顶堆来计算中位数的代码存进了这个仓库。还存储了一些经常使用的操作符重载和一些题目都会用到的模板。这里分享两个。

第一个是对二维vector进行排序的函数。

  static bool compare(vector<int>& a, vector<int>& b) {

​    if (a[0] == b[0]) {

​      return a[1] < b[1];

​    }

​    return a[0] < b[0];

  }

vector<vector<int>> res;

sort(intervals.begin(), intervals.end(), compare);

第二个是我在做组合问题时总结出来的一个递归模板。等我再遇到组合问题时，直接上代码库中找到这段代码粘贴过去在更改递归判断条件即可。

```
vector<vector<int>> main(...){
    vector<vector<int>>res;  // Store the result, could be other container
    backtrack(res, ...);  // Recursion function to fill the res
    return res;
}

void backtrack(vector<vector<int>>& res, int cur, ..., vector<int>vec){
    if(meet the end critria, i.e. cur reach the end of array){  
        //vec could be a certain path/combination/subset
        res.push_back(vec);
        return;
    }
    // Current element is not selected
    backtrack(res, cur+1, ..., vec);
    // Current element is selected
    vec.push_back(cur); // or could be vec.push_back(nums[cur]), vec.push_back(graph[cur]);
    backtrack(res,cur+1, ..., vec);
}
```

灵活运用你的代码库，并且不断的为其添加复用性高、灵活性高的代码模板，会极大提高刷题效率。