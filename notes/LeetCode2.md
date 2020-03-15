LeetCode刷题记录-Part2

本篇是该系列第二篇，第一篇地址见此。本篇还是数组篇，主要介绍各种常见算法的灵活使用，具体为桶排序、环检测算法、单调栈和BFS，并主要针对排序和查找类题目。

这个系列的上一篇是近两个月前写的，这篇的构思在上个月就已经想好了，但是一直拖到现在才开始动笔，实在不该。但是在我重新梳理本篇的结构时，重新审视了之前刷题的代码，发现人终归是会遗忘的，有些题的思路已经忘记了。所以这里笔者提醒正在刷题的各位，一定要养成定期温习之前刷的题目，这里并不是指重新敲一遍，而是在脑海中过一遍题目的解题思路和实现逻辑。

至于怎么温习，我给出两个建议。

第一是要养成记录的习惯。

将每天刷的题按照类型分类，比如所使用的数据结构，是数组、链表还是其他的什么，这里建议在数据结构的大类之下，再对题目细分，比如这道题主要使用最大堆，那就要明确标明出来；或者可以按照解题的类型分类，是使用了DP，还是使用了二分查找，或者采取了自底向上等思想，都可以在记录中明确标明出来。

除了将题目分类之外，还要保持良好的编码习惯。这里的编码习惯主要是强调使用注释。此注释并不是简单的标出每个循环每个函数的意义，而是要在解题函数的声明上面简要的写明思路，特别是当你使用了特殊的算法或者使用了特殊的内置函数。这里只是给出笔者的习惯，至于是否可以借鉴还是取决你们自己的习惯。虽然LeetCode是网页编程，但是笔者还是习惯使用IDE或者编辑器在本地实现代码，然后复制到网页上进行提交。一是IDE的自动补全比LeetCode自带的好用，二是可以使用一些插件来提高效率。笔者的本地环境是VSCode，这里就使用了一些Comment高亮插件，使上文提到的这些特殊注释高亮显示，方便日后查找温习。

第二是要养成建立代码仓库的习惯。

这个习惯在这个系列的上一篇文章中已经提到。众所周知，LeetCode是网页编程，而且将来面试中也会出现白板编程或者文档编程等无法使用自动补全等功能的情况，但是还是推荐使用本地的IDE或者编辑器进行编码实现。除了上一部分提到的可以使用插件提高效率外，IDE的文件管理是另一个提高效率的利器。比如当前的这道题之前做过类似的，可以直接查找查看那道题的解题方法。

当然本地的代码仓库要做，但是同时还要做到远程托管，比如使用GitHub等托管平台。使用远程平台托管这个习惯不止可用于你的代码，你的所有重要文件都建议托管。大家除了可以使用现在免费的GitHub私有仓库外，各种云盘也要习惯使用，特别是Google Drive。

因为笔者本科的电脑硬盘容量只有128G，这迷你的容量迫使笔者养成了这个习惯，而且现在换了1T的硬盘笔者还是保留着这个习惯。就在上周电脑注册表被笔者魔改后系统服务开始大量消耗内存，在一切方法试尽后迫于无奈重装了系统。这里提一下笔者电脑背景，1T的SSD我没有分区，所以重做后基本没有任何保留文件。而我在重做之后除了配置环境费些麻烦，之前的文件基本都是从托管下载回来的。可见使用远程托管十分便利。

量变引起质变

到目前为止笔者刷的题目已经上了三位数，将近150余道，相比于其他人和总题库可能这个数量微不足道，但是笔者已经体会到了量变引起质变的这个过程。

笔者在本科时是基本没有碰过算法相关的比赛的，大部分的编码都是偏向应用类的实现。相比于解算法题要求的巧妙性，偏向应用的代码没有那么多的要求，只要可以跑起来并且没有bug，就是可以用的。但是刷题不是，刷题相比于简简单单的写写界面传传值，涉及到的实现逻辑更加复杂。

这就导致了笔者在刚刚起步的阶段，做一道easy题都要花费很长的时间，甚至到最后都要依靠解答。当时更不要提hard了，有些hard看完之后一丁点的想法都没有。

但是现在情况有了肉眼可见的改善。首先easy题只要不是考数学的，基本没什么压力；大部分medium题也能完全独立AC；少部分hard题能在不看解答的情况下实现。这个阶段刷题所带来的快感是前所未有的，当你分析完题目后就能联想到可以用来解题的数据结构和算法，甚至可以考虑到一些特殊的边界情况，然后就动手实现，说行云流水有些夸张，但是相比一个半月前的支支吾吾，进步显而易见。这种感觉我第一次感受到是在本科大二时使用FFmpeg实现一个直播应用，这久别重逢的喜悦难以言表。可谓书读百遍其义自见了吧。

数组类

拿C++来说，如果想不费力气的去做这方面的题，这里建议事先复习好关于vector, unordered_map, map, prioity_queue等STL提供的数据结构。用一个适合该题目的数据结构解题会节省你大量的时间。

线性排序算法--桶排序

在我们刷题时，经常会遇见题目对算法的时间或者空间复杂度有要求，比较常见的除了O(nlogn)外还有 **Try to solve it in linear time/space**。当碰到线性时间复杂度要求时，并且题目经过分析后需要进行排序，那么首选就是桶排序。

大家可能要问，线性排序不是有三个吗？分别是基数排序，计数排序和桶排序。其实基数排序和计数排序从某种意义上来说都可以是桶排序，或者是桶排序的变形。当然在实际生产环境中，根据所需要的排序的数据选择不同的线性排序可能会带来不同的效果，但是在刷题时，并不用明确区分这是使用了那种线性排序，我们需要的只是这种思想。

这里并不给出桶排序的具体实现方式，因为网上已经有很多很成熟的实现方法，只给出三种排序的时间空间复杂度并分析为何三种排序实际上为一种排序。

图片

上图中，d表示位数，k在基数排序中表示k进制，在桶排序中表示桶的个数，maxV和minV表示元素最大值和最小值。

- 计数排序本质上是一种特殊的桶排序，当桶的个数取最大 (maxV - minV + 1) 的时候，就变成了计数排序。
- 基数排序也是一种桶排序。桶排序是按照排序值的区间划分桶，基数排序是按照位数来划分；基数排序可以看做是多轮桶排序，每个数位上都进行一轮桶排序。
- 当用最大值作为基数时，基数排序就变成了计数排序
- 当使用二进制时，k = 2 最小，位数d最大，时间复杂度 O(nd) 就会变大，空间复杂度 O(n + k) 就会变小。当使用最大值作为基数时，k = maxV 最大，d = 1 最小，此时时间复杂度 O(nd) 变小，但是空间复杂度 O(n + k)会急剧增大，此时基数排序退化成计数排序。

下面开始进行一些桶排序及其思想的应用。

> 164. **Maximum Gap**
>
>      Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
>
>      Return 0 if the array contains less than 2 elements.
>
>      **Example 1:**
>
>      ​	Input: [3, 6, 9, 1]
>
>      ​	Output: 3
>
>      ​	Explanation:  The sorted from of the array is [1, 3, 6, 9], either (3, 6) or (6, 9) has the maximum difference 3.
>
>      **Example 2:**
>
>      ​	Input: [10]
>
>      ​	Output: 0
>
>      ​	Explanation: The array contains less than 2 elements, therefore return 0.
>
>      **Note**:
>
>      	- You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range
>      	- Try to solve it in linear time/space

这道题是一道经典的桶排序应用题，同时也可以简答理解为鸽子洞理论。

这里简单解释下什么是鸽子洞理论：若有N个笼子和N+1只鸽子，所有的鸽子都被关在鸽笼里，那么至少有一个笼子有至少2只鸽子。

仔细想想是不是和桶排序的思想很接近，这道题的最佳解题思路就是使用两者思想的结合。

这道题的最简单的思路就是暴力排序，但是代价十分昂贵，而且还需要对每个元素与其他元素进行比较。但是从侧面想，我们不一定必须要对所有的元素进行比较，我们可以只对一些元素进行比较。比如如果事先以某种方式将元素分成组，或者说桶，然后我们只需要对这些桶的边界进行比较即可。

我们一步步来分析。首先假设我们把每个元素都放在单独的桶中。此时如果我们减少桶的数量，一些桶就会装载多个元素。其次来讨论下元素之间距离的实际意义。先从最优解入手，数组中的所有元素都拥有均匀的间隔，这意味着每一对相邻的元素间的距离是一个常数。因此，对一个存在n个元素的数组，存在 n-1 个间隔，设每个间隔为t。那么我们就会有 t = (max - min) / (n - 1) （其中max和min分别为数组中元素的最大值最小值）。在最简单的情况下，此时的t就是我们的结果。由此，我们可以判断出，间隔t对于任意的数组都有如下性质：对于元素数量相同、并且极差相同的数组，他们的t是相同的。

现在再来分析普遍情况。上诉分析可以得出，如果我们将桶作为单位进行比较，会比在比较单个元素的基础上减少比较所需要的次数。所以我们进一步分析如何以某种方式，使得我们只需要比较桶与桶的边界元素，而不需要对每个桶内的元素进行比较。答案显而易见：我们只需要将元素分配到它正确的桶中即可。

但是与此同时，我们还需要保证桶与桶之间的间隔可以代表输入数组中的最大间隔。我们可以通过设置桶的存储范围b小于t。（ t = (max - min) / (n - 1) ）。这样我们保证了桶中元素的距离肯定小于t，这样就可以推断出最大间隔必定只会出现在两个相邻的桶之间。

综上，我们只需要将桶的大小b设置为 1 < b <= (max-min) / (n-1) 即可。这样，我们可以确保至少存在一个间隔为所解答的最大间隔。

现在再重新梳理一遍：

- 每个桶的大小都被设为b。
- 每个桶存储的元素不应该存在覆盖问题。比如桶的大小为3，那么相邻的两个桶之间只会分别存储3~6和7~9。
- 每个桶的大小实际上指的是该桶能存储的元素范围，并且这个范围取决于输入数组元素的个数和它的最大最小值。
- 如何计算相邻桶之间的距离：将当前桶储存的最大值于下一个桶的最小值进行计算，结果就是桶之间的间隔。
- 怎么减少的比较次数：这个算法实际的比较次数只是桶的数量的两倍。

算法逻辑：

- 计算桶的存储范围 b = ⌊ (max−min) / (n−1) ⌋。（注意此处为向下取整）
- 将元素分配到桶中，计算出桶的整体数量 k = ⌈ (max−min) / b ⌉。（注意此处向上取整）
- 这样，i<sup>th</sup> 的桶说存储的元素范围为：[ min + (i - 1) * b, min + i * b)。
- 计算每个元素所属的桶：(curNum - min ) / b。
- 当所有的元素都在桶中时，计算 k - 1 个桶间间距，从中寻找出最大值即为解。

代码实现：

图片 164

算法时间复杂度分析：

时间复杂度：O(n + b) ≈ O(n)

空间复杂度：O(2 * b) ≈ O(b)

这道题是一道很经典的桶排序应用题，但是更多的题目需要的是桶排序这个思想。比如下一道题。

> 75. **Sort Colors**
>
>     Given an array with *n* objects colored red, white or blue, sort them **in place** so that objects of the same color are adjacent, with the colors in the order red, white and blue.
>
>     Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
>
>     **Note:** You are not suppose to use the library's sort function for this problem.
>
>     **Example:**
>
>     ​	Input: [2, 0, 2, 1, 1, 0]
>
>     ​	Output: [0, 0, 1, 1, 2, 2]
>
>     **Follow up:**
>
>     - A rather straight forward solution is a two-pass algorithm using counting sort.
>       First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
>     - Could you come up with a one-pass algorithm using only constant space?

这道题要求我们把所有的0放在前面，所有的2放在后面，中间放1。其实很简单，我们要做的只是把0放到前面，2放到后面，中间的自然是1。所以这里采取桶排序的计数思想。

代码实现：

图片

总之，桶排序重要的并不是提供一种线性时间的排序算法，而是提出了计数这个思想。我们在做题中要活用这个思想。

环检测算法

大名鼎鼎的Floyd's Tortoise and Hare算法，通过一快一慢两个指针来判断链表中是否存在环。既然是链表的算法，那笔者为什么要放在数组类中进行介绍？同理于桶排序，重要的不是检测环，而是检测环的这个思路。下面笔者将例举两道题来分析该算法的实际应用。一道是传统的链表环检测问题，另一道就是该算法的灵活使用。

> 142. Linked List Cycle II
>
>      Given a linked list, return the node where the cycle begins. If there is no cycle, return NULL.
>
>      To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
>
>      **Note:** Do not modify the linked list.
>
>      Example:
>
>      ​	Input: head = [3, 2, 0, -4], pos = 1
>
>      ​	Output: tail connects to node index 1
>
>      ​	Explanation: There is a cycle in the linked list, where tail connects to the second node.

图片 环

环检测算法的原理就是通过一个快指针，一个慢指针，同时对该链表遍历。如果存在环路，则快慢两个指针必定会相遇；若没有相遇，这表明该链表不存在环。

这道题在判断环的基础上更进一步，要求我们求出环路开始的节点。那么我们在快慢指针相遇后，将其中一个指针移动到头结点，然后使两者匀速遍历，当两者再次相遇时就是环路开始的节点。

代码实现：

图片142

上题就是经典的环检测算法的应用。下一题我们采用这个思想，来判断数组中是否存在相同的元素。

> 287. **Find the Duplicate Number**
>
>      Given an array *nums* containing *n* + 1 integers where each integer is between 1 and *n* (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
>
>      **Example 1:**
>
>      ​	Input: [1, 3, 4, 2, 2]
>
>      ​	Output: 2
>
>      **Example 2:**
>
>      ​	Input: [3, 1, 3, 4, 2]
>
>      ​	Output: 3
>
>      **Note:**
>
>      - You **must not** modify the array (assume the array is read only).
>      - You must use only constant, *O*(1) extra space.
>      - Your runtime complexity should be less than O(n<sup>2</sup>).
>      - There is only one duplicate number in the array, but it could be repeated more than once.

这道题我们的解决思路与上面的第142题有着异曲同工之处，同样使用两个快慢指针，当两个指针相遇后，让其中的一个从头开始，两者按照一样的速度遍历，直到再次相遇，相遇的值就是重复的值。

代码实现：

图片 287

仔细观察不难看出，这道题的实现就是把142的数据结构换成数组，其余的基本一模一样。这也是我所说的灵活运用环检测算法的意义。

单调栈

单调栈这种数据结构看上去简单，然而在实际应用中却不是很简单。首先什么是单调栈？单调栈就是要求我们维护一个栈，使其里面的元素单调递增或者递减。下面通过第84题来具体分析单调栈的使用。

> 84. Largest Rectangle in Histogram
>
>     Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
>
>     Example:
>
>     ​	Input: [2, 1, 5, 6, 2, 3]
>
>     ​	Output: 10

图片 单调栈

这道题的具体思路就是将元素入栈，如果当前元素大于栈顶元素，入栈；否则栈顶元素出栈。用数学表达式来直观表达即为：(curNum - stcak[top - 1] - 1) * nums[stack[top]]。

实现代码：

图片84

通过代码来讲解这道题，首先每个元素都要入栈一次，出栈一次。入栈的时候是遍历到该元素时，我们只需要判断出元素出栈的条件即可。当元素出栈时，意味着我们已经可以计算以它为边界的右边框的最大矩形。首先，我们可以使用反证法来证明该算法的正确性。最后的结果中的最大矩形的右边界，一定与某一个元素代表的矩形重合，否则我们一定可以通过增加右边界来增加这个矩形的面积。

之后，当元素出栈时，此时我们可以计算的矩形的左右边界已经是极限值。结合单调栈的性质，我们可以知道左边框是栈顶元素+1，栈顶元素所对应的矩形已经比出栈元素对应的矩形小，所以出栈元素对应的矩形的高无法继续向左延伸。结合代码，我们知道右边界对应的值是当前的元素的值，因为我们已经判断过这个元素对应的矩形一定比出栈元素的矩形小，所以矩形此时也无法向右延伸。

若这个元素和左右边界之间还有空隙，那么这些空隙里所存在的矩形一定是当我们维护单调栈时被弹出了。换言之，如果存在一个矩形的高可以扩展当前围成的矩形，那么当前左右边界围成的不是一个矩形，而是一个凹形。

因此我们证明了当前元素出栈时，我们可以计算以当前元素为高的最大矩形面积。

最后关于单调栈的时间复杂度：

因为每个元素都入栈、出栈一次，所以是线性时间复杂度。

84题是典型的单调栈应用题，若各位想提高的话，可以试试第407题，该题在三维上使用单调栈，因为此题比较复杂，除了单调栈外，还需要用到大顶堆等组合成复杂的数据结构，笔者怕无法用笔者的语言准确的描述以及证明算法，所以不在此做过多描述。

简单来讲，使用单调栈的难点在于如何判断元素出栈，以及元素出栈所代表的意义。经过笔者的实践，可以推断出，当你有高效率的获取某个位置左右两侧大于或小于的数的位置的需求时，可以试试使用单调栈。

BFS的变种

BFS可谓是老生常谈的考题了，但是有些BFS的变种，比如two-end BFS在解题时更有效率性。

Two-End BFS: Bidirectional Search

Bidirectional Search是一种图搜索算法，可找到目标顶点对的最短路径。它同时运行两个BFS：

- 从源节点向目标节点的向前搜索
- 从目标节点向源节点的向后搜索

Bidirectional Search使用两个较小的子图替换了整个搜索图，一个子图从源节点开始，另一个从目标节点开始。当两个图相交时，搜索结束，源节点、目标节点与交点相连接的路径即为所求结果。

下图给出了一个简单的例子：

图片 Bidirectional Search

假设我们要查找是否存在从节点0到节点14的最短路径。这里，我们开始两个BFS，一个从0开始，一个从14开始。当向前和向后搜索在节点7相遇时，停止搜索。可见，我们并不需要对其他节点，比如2,3,11,12等，即避免了不必要的搜索。

为什么要使用Bidirectional Search而不是普通的BFS

能用Bidirectional Search解决的问题自然能用BFS解决，但是在许多情况下，使用Bidirectional Search会更快，会大大减少需要的勘探量。这里假设一棵树的分支节点为b，目标节点到源节点的距离为d，若使用传统的BFS搜索的复杂度为O(b ^ d)。另一方面，如果我们执行Bidirectional Search，这每次搜索的复杂度将为 O(b ^ (d / 2))，总复杂度为 O(b ^ (d / 2) + b ^ (d / 2))，远远小于O(b ^ d)。

何时适合使用Bidirectional Search

- 初始状态和目标状态都是唯一的，并且定义完全
- 两个方向的分支节点权重相同

Bidirectional Search性能

- Completeness: 如果两个搜索都使用BFS，则Bidirectional Search是完全的。
- Optimality: 如果使用BFS进行Bidirectional Search，并且图上节点权重相同，则Bidirectional Search是最优的
- Time and Space Complexity: 时空复杂度为O(b ^ (d / 2))

算法伪代码：

图片Bidirectional Search（2）

在具体应用中，我们需要维护两个BFS队列。每次更新较小的那个队列，直到两个队列中有元素重合，说明路径找到。

> 126. **Word Ladder II**
>
>      Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
>
>      	1. Only one letter can be changed at a time
>       	2. Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
>
>      **Note:**
>
>      - Return an empty list if there is no such transformation sequence.
>      - All words have the same length
>      - All words contains only lowercase alphabetic characters
>      - You may assume beginWord and endWord are non-empty and are not the same
>      - You may assume no duplicates in the word list
>
>      **Example:**
>
>      ​	Input: 
>
>      ​		beginWord = "hit"
>
>      ​		endWord = "cog"
>
>      ​		wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
>
>      ​	Output:
>
>      ​		[
>
>      ​			["hit","hot","dot","dog","cog"],
>
>      ​			["hit","hot","lot","log","cog"]
>
>      ​		]

这道题表面上给的是一个字符串数组，但是实际上是隐式地给出了一个迷宫，其中两个词可以通过规则相互转换，从而将他们连接起来。因此，问题实际上是找到从开始到结束的所有最短路径。

使用Bidirectional Search可以根据方向较少的选项从任意一个方向搜索下一个转换后的单词，以转换为ladder中的下一个单词。这样避免了从一段到另一端有太多路径，最后一刻才能到达另一端的情况。

此问题可以细化为两个子问题：

- 构建mapNextWord来查找每个单词的所有下一个转换后的词典单词。因为边上没有权重，可以简单的使用BFS执行
- 使用mapNextWord建立所有最短的ladders，这可以简单的通过回溯完成。

代码实现：



\#include <iostream>

\#include <vector>

\#include <string>

\#include <unordered_set>

\#include <unordered_map>



using namespace std;



// Key Observations:

// 1. The dictionary actually implicitly gives a maze where two words are connected if they can transform to each other by the rules. 

//  So the problem is actually to find all shortest path from begin to end

// 2. Use two-end BFS to search next transformed words from either direction based on whichever direction has fewer options to transform to next word in ladder.

//  This avoid the scenario where the arr way too mant path from one end, but only a few paths could reach the other end at the last moment.

// 3. This problem can be decoupled into two sub-questions:

//   a) build mapNextWords to find all next transformed dictionary words for each word

//     (we only need to build the map enough to only cover all shortest paths. This can be guaranteed by BFS on graph with no weight on edges)

//   b) build all shortest ladders using the map mapNextWords. This can be done by standard back tracking



// word dictionary

unordered_set<string> dict;



// mapNextWord[w]: set of all w's possible next words in dictionary

// The "next" is always in start -> end direction

unordered_map<string, unordered_set<string>> mapNextWords;



// all shortest ladders

vector<vector<string>> ladders;



/**

 \* Build mapNextWords recursively using two-end BFS

 \* Note: each recursion dose exactly 1 transform distance from either start or end direction

 \* @param {unordered_set<string>} layer1 : 

 \* @param {unordered_set<string>} layer2 : 

 \* @param {bool} isForward        : 

 */

void buildMapNextWords(unordered_set<string>& layer1, unordered_set<string>& layer2, bool isForward) {

  if (layer1.empty()) {

​    return;

  }

  

  // always BFS from the smaller layer side

  if (layer1.size() > layer2.size()) {

​    swap(layer1, layer2);

​    isForward = !isForward;

  }



  // remove used words from dict

  for (auto& w : layer1) {

​    dict.erase(w);

  }

  for (auto& w : layer2) {

​    dict.erase(w);

  }



  // next layer of layer1 by word transform

  unordered_set<string> nextLayer;



  bool shortest_ladder_found = false;



  // transform each word in layer1

  for (auto w : layer1) {

​    string origW = w;

​    for (int i = 0; i < w.size(); i++) {

​      char origCh = w[i];

​      for (char c = 'a'; c <= 'z'; c++) {

​        // transform word w

​        w[i] = c;    



​        // keep current->next always on start->end direction

​        string curWord = origW;

​        string nxtWord = w;

​        if (!isForward) {

​          swap(curWord, nxtWord);

​        }

​        

​        // next layer of layer1 meets layer2: shortest path found

​        if (layer2.count(w)) {

​          shortest_ladder_found = true;

​          mapNextWords[curWord].insert(nxtWord);

​        }



​        // next layer of layer1 didn't meet layer2, but still in dict, so keep going

​        else if (dict.count(w)) {

​          nextLayer.insert(w);

​          mapNextWords[curWord].insert(nxtWord);

​        }

​      }

​      w[i] = origCh;

​    }

  }



  //recursively build map if not done

  if (!shortest_ladder_found) {

​    buildMapNextWords(nextLayer, layer2, isForward);

  }

}



/**

 \* Build add shortest ladders using back tracking

 \* 

 \* @param {string} curWord    : current word in ladder

 \* @param {string} endWord    : end word in ladder

 \* @param {vector<string>} ladder : current ladder in building process

 */

void buildLadders(string curWord, string endWord, vector<string>& ladder) {

  // if current word reaches end, current ladder is done

  if (curWord == endWord) {

​    ladders.push_back(ladder);

​    return;

  }  



  // try all next word options and append to current ladder

  for (auto& w : mapNextWords[curWord]) {

​    ladder.push_back(w);

​    buildLadders(w, endWord, ladder);

​    ladder.pop_back();

  }

}



int main() {



  vector<string> wordList = { "hot","dot","dog","lot","log","cog" };

  string beginWord = "hit";

  string endWord = "cog";



  dict = unordered_set<string>(wordList.begin(), wordList.end());



  if (!dict.count(endWord)) {

​    return 0;

  }



  // initialize two layers for two-end BFS

  unordered_set<string> forwardLayer({beginWord});

  unordered_set<string> backwardLayer({endWord});



  // sub-problem 1: build next word map

  buildMapNextWords(forwardLayer, backwardLayer, true);



  // sub-problem 2: build ladders

  vector<string> ladder({beginWord});

  buildLadders(beginWord, endWord, ladder);



  for (int i = 0; i < ladders.size(); i++) {

​    for (int j = 0; j < ladders[0].size(); j++) {

​      cout << ladders[i][j] << " ";

​    }

​    cout << " " << endl;

  }

  return 0;

}

当然，既然存在双源BFS，那肯定存在多源BFS。实现多源BFS的核心在于将多个源节点同时push到队列中，然后开始BFS。

大家可以尝试去做第296题来实现多源BFS。

> 296. Best Meeting Point
>
>      A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using [Manhattan Distance](http://en.wikipedia.org/wiki/Taxicab_geometry), where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
>
>      Example:
>
>      ​	Input:	
>
>      ```
>      1 - 0 - 0 - 0 - 1
>      |   |   |   |   |
>      0 - 0 - 0 - 0 - 0
>      |   |   |   |   |
>      0 - 0 - 1 - 0 - 0
>      ```
>
>      Output: 6
>
>      Explanation: Given three point living at (0,0), (0,4) and (2,2): The point (0,2) is an ideal meeting point, so the total travel distance of 2+2+2=6 is minimal. So return 6.

然而可惜的是笔者在使用多源BFS解决这道题时，LeetCode提示超时。然后去看了看Discuss，发现所有使用BFS的都是超时，官方解法是使用中位数，其中涉及到数学证明，笔者不做过多陈诉。这里笔者吐槽一下，这种难度的题竟然考你数学，属实不应该。

其他一些碎碎念

现在全球基本都在流行COVID-19，目前国内是控制住了，但是国内的小伙伴们也不能放松警惕，每日出行口罩一定要戴。和我一样在国外的小伙伴，口罩该戴还是要戴的，相比于歧视，小命更重要。

今晚吃饭时和室友讨论如果川普检测阳性怎么办的时候，从石油降价到经济危机，再到死亡率，室友当时崩出的话挺让我震惊的，“死的人跟我又有什么关系呢”，这时候我深刻认识到彼此的三观竟然有如此巨大的差别，我也不能反驳他什么，毕竟他的话也不无道理，做好自己足矣。

各个阶层之间没有沟通渠道，我看不到你在干什么，你也看不到我在干什么。其他人过着怎样的生活与自己关系确实不大，但是还是人们都更加善良些。

《人世间》总导演周全曾经说过一段很有温度的话，我感觉很适合当前的环境。“生命力很奇怪，它熊熊燃烧的时候，你不敢去直视它，你会绕着走。恰恰是那火烧成灰，灰里吐出火星的时候，你反而注意到它。也许生长在人心最底层的善良与怜悯，才是真正的生命力。”

尽管目前全球各个国家都有自己各自应对疫情的方法，有些甚至令人觉得可笑，但是我并不希望人们带着偏见的眼光去审视任何一个国家的政策，因为那些国家也有因此离世的人，也有因此家庭遭遇了事故，那些国家更多的，是那些依然在努力活着的人。

我希望在今后的某个岁月，大家回想起这段疫情的时候，更多的不是吹嘘在家隔离了多长时间、不是回想不能出门的日子，而是回忆起这个特殊时期，做出了巨大贡献的那批人。**人，还是要善良的。**

写于2020年3月15日的深夜，阿灵顿，窗外下着雨。

