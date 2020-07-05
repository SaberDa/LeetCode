LeetCode 刷题记录 - Part 3

---

本篇是该系列第三篇，[第一篇]([http://www.saberismywife.com/2020/01/19/LeetCode%E5%88%B7%E9%A2%98%E8%AE%B0%E5%BD%95-Part1/](http://www.saberismywife.com/2020/01/19/LeetCode刷题记录-Part1/))和[第二篇]([http://www.saberismywife.com/2020/03/15/LeetCode%E5%88%B7%E9%A2%98%E8%AE%B0%E5%BD%95-Part2/](http://www.saberismywife.com/2020/03/15/LeetCode刷题记录-Part2/))的链接在此。本篇将介绍Trie Tree 和 Union Find。两者都是很常见的树状数据结构。



这篇应该是LeetCode刷题系列的最后一篇，本来还打算包含 segment tree 和 topological sort 的介绍，但是后来发现这两个部分的题目数量是真的少，没必要写出来。至于之前还计划整理一篇位运算的相关操作，但是想了想这东西在工作中的实际运用，也被删除了。



接下来估计会开 system design 系列。这东西在北美找全职也是要准备的，之前还自以为刷题什么的就可以了。



什么是Trie ？

---

- Trie 是一种树状的数据结构，它的每个结点通常上存储单个的字母

- Trie 是一种有序的树数据结构，每次遍历它的分支用户都会得到一个字符串，是一种哈希树的变种

- 典型应用

既然 Trie 又被称为字典树，它的主要应用在于统计和排序大量的字符串，比如在搜索引擎系统中进行词频统计。



基本结构

---

这里采取最常见的结构，在实际做题的过程中，要根据题意进行细微的变化，比如将 bool 类型的判断符换成 string 类型的标识符，或者改变存储数组的大小。下文中提到的所有 Trie 结构都是基于该最基础的结构。



{% codeblock %}

struct TrieNode {

​	bool isWord;

​	TrieNode *next[26];

​	TrieNode() : isWord(false) {

​		memset(next, NULL, sizeof(next));

​	}

};

{% codeblockend %}



一个典型的 Trie 结构包含一个为空的根结点，和对其他所有结点的引用。

至于引用的具体数量，取决于当前要遍历的值的总数。举个例子，比如当前 Trie 表示仅包含小写字母的字符串。然后从 "a" 到 "z" 有26个不同的字母，那么它的引用个数就是26。如果是专门储存二进制变量的 Bitwise Trie，那么的引用只需要两个，分别为 0 和 1。

---

Trie 的每个结点都包含什么呢？

---

Trie 的每个结点包含两部分：

- 一个存储对其他结点引用的数组
- 一个 bool 值，可以称其为 Leaf。（需要注意的是，这里的 Leaf 是用于检查当前字符串是否在该结点结束，而不是结点本身是否是叶子结点）

---

实例

下面通过一步步构建出一个 Trie 树来帮助大家更好的理解。

List = {"apple", "app", "abide", "ball", "bat"};

Note: All the string in the list contains lowercase letters from 'a' to 'z'.



图片1



第一步：apple 被添加到树中。

上图中的第一个结点是根结点，其本身值为空。

现在根结点已经有了一个引用 'a'，'a' 结点本身只有一个对 'p' 的引用，其他的为空。依次类推余下的结点。



图片2



第二步：将 app 添加到树中。

从根结点开始，判断当前的引用是否存在。如果存在，那么移动到该引用指向的结点那里。否则，需要创建一个新的结点，并将引用指向新的结点。

当前结点的所有子结点都具有与该结点关联的字符串的公共前缀。



图片3



第三步：将 abide 添加到树中。

abide 所代表的分支与 apple 分支共享一个公共前缀 'a'



图片4



第四步：将 ball 添加到树中。

因为当前根结点没有对 'b' 的引用，所以我们创建一个新的分支。



图片5



第五步：将 bat 添加到树中。

上图即为根据当前输入字符串列表所建立的最终的 Trie。



----

具体代码实现：



{% codeblock %}

class TrieTree {

private:

​	struct TrieNode {

​		bool isWord;

​		TrieNode *next[26];

​		TrieNode() : isWord(false) {

​			memset(next, NULL, sizeof(next));

​		}

​	};

​	TrieNode *root;



​	// 插入过程

​	// Insert

​	void buildTree(string s) {

​		TrieNode *node = root;

​		for (auto c : s) {

​			if (!node->next[c - 'a']) node->next[c - 'a'] = new TrieNode();

​			node = node->next[c - 'a'];

​		}

​		node->isWord = true;

​	}



​	// 查找过程

​	// Search

​	bool findWord(string s) {

​		TrieNode *node = root;

​		for (auto c : s) {

​			if (!node->next[c - 'a']) return false;

​			node = node->next[c - 'a'];

​		}

​		return node->isWord;

​	}



public:



​	TrieTree() {

​		root = new TrieNode();

​	}

​	

​	// Do other things



};

{% codeblockend %}

---

例题分析

[Leetcode 676](https://leetcode.com/problems/implement-magic-dictionary/)

这道题是一个典型的使用 Trie Tree 解决的问题。



图片 676



这道题我们首先需要依据输入的字符串数组建树。然后对之后输入的字符串进行处理，当每次仅变换一个字母时，能否在树中查找到对应的单词，如果可以返回 true，否则返回 false。



图片676code



[源码](https://github.com/SaberDa/LeetCode/blob/master/C%2B%2B/676-implenmentMagicDictionart.cpp)。



还有一些使用 Trie 的变种。[LeetCode 421](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/) 是使用了 Bitwise Trie，[LeetCode 1023](https://leetcode.com/problems/camelcase-matching/) 则是在初始化树的结构时需要考虑大写和小写的情况。



---

Trie 的优点

- Trie Tree 类似于 HashMap，但是在时间和空间上有一些变化。

  在 Trie 中搜索一个字符串的时间复杂度为 O(m)，其中 m 表示带搜索字符串长度。

- 相比于哈希表，Trie 避免了碰撞冲突。

- 并且 Trie 本身不需要任何的哈希计算函数
- Trie在自动补全功能上有着显著的作用。

---

时间复杂度分析

- 最坏的情况下，建树为 O(mn)。其中 m 是最长的字符串，n 是字符串的总数。时间复杂度取决于 Trie 所包含的字符串数量以及它们的长度
- Trie 执行插入、搜索、删除需要的时间都是 O(m)，其中 m 是待操作单词的长度

---

空间复杂度分析

- O(kN)，其中 k 是所有索引的数量（包含为空的索引），N 是树中的结点个数



---



Union Find 并查集

---



Union Find 简单来讲就是解决图的连通性问题。并广泛应用于解决集合问题，比如判断某个元素是否属于一个集合，或者两个元素是否属于同一个集合，或者求解集合的个数等等。



主要操作

---

- Find 

  确定元素属于哪一个子集，或判断两个元素是否属于同一子集

- Union

  将两个子集合并成一个集合

简单来讲，find 操作是查找当前两个元素的公共祖先；Union 操作是修改元素的root。



在LeetCode中具体应用挺八股文的，只要你分析出这道题可以使用 Union Find ，那么代码的大致结构都是差不多的。



一个简单的模板

---

该模板为了方便大家理解，就不使用泛型了。采取题目中出现次数比较频繁的int型，并将 Union 操作合并到了主要操作中。



{% codeblock%}

int find(vector<int>& parents, int c) {

​	return (parents[c] == c) ? parents[c] ? find(parents, parents[c]);

}



int doSomething(vector<vector<int>> nums, ...) {

​	int m = nums.size();

​	// The vector size must be the sum + 1

​	vector<int> parents(m + 1);

​	// Assignment value to vector from 0 to m

​	iota(parents.begin(), parents.end(), 0);

​	for (auto it : nums) {

​		// This is the Union() operation

​		int root1 = find(parents, it[0]);				// Find the root1

​		int root2 = find(parents, it[1]);				// Find the root2

​		// If root1 == root2, do operations according to problem

​		// Else if root1 != root2, put the root2 as the value of parents[root1]

​		if (root1 != root2) parents[root1] = root2;

​	}

​	// Do other operations

}

{% codeblockend %}



----

例题分析



以 [LeetCode 323](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) 为例，这道题以图形化的方式帮助大家更好的理解 Union Find 问题。



图片 323



这道题的意思是让我们根据输入的结点，找出一共有几个联通子图。



比如在 Example 1 中，先将 0 和 1 相连，然后讲 2 和 1 相连。这就是合并集合的操作。



图片 323code



[源码](https://github.com/SaberDa/LeetCode/blob/master/C%2B%2B/323-numberOfConnectedComponentsInAnUndirectedGraph.cpp)。



Union Find 另一个比较典型的操作就是判断森林中是否存在环，比如 [LeetCode 261](https://leetcode.com/problems/graph-valid-tree/) 。



这几道题都是比较典型的应用，还有一些变形，需要我们处理 parent 数组的大小，或者对 Union 操作进行一些变形。比如 [LeetCode 990](https://leetcode.com/problems/satisfiability-of-equality-equations/) 就是一道需要我们变换 parent 数组的题目，这道题也可以理解为寻找环形 DFS。



一些比较复杂的 DFS 问题，如果能将其转换换成 Union Find 来处理，则会大大降低难度，比如 [LeetCode 130](https://leetcode.com/problems/surrounded-regions/)，这道题是个典型的 DFS 问题，但是我们可以使用一个 dummy 结点当做所有 O 值的祖先结点，添加动态连通性，这样就可以把二维坐标映射到一维坐标，降低难度。



----



Union Find 操作的具体应用还是挺套路化的，感觉和 topological sort 差不多，两者都是使用起来模板化。但是需要针对具体题目进行变换。



Union Find 还有很多针对它本身的优化，这里就不一一讲解了，毕竟只是针对刷题，大家有兴趣的可以自行去了解。



---

后记



笔者现在刷题数量已经400多了，已经开始有条件的按类型反复刷了。刷题这个过程主要是让你思考相关题目的主要思路，比如看到求和（xSUM）问题，自然而然的就想到双指针；树的同层遍历，那就先上deque。诸如此类。



刷题的目的不是让大家在面试中碰到原题，当然如果碰到原题那自然最好，而是去分析这个题目的目的，去联想这道题的 follow up。当然这都是老生常谈的问题。这里并不是说大量刷题是没用的、或者是浪费时间的，肌肉记忆还是需要的。有些题可能第一次见时一脸懵逼不知从哪里下手，但是见得多了就自然掌握了。



这篇文章总结的两种数据结构应用的大致模板，都是相关类型的题刷够一定数量上自然而然掌握的。类似的还有链表的翻转、二维矩阵的搜索等，都是那个套路，唯一不同的就是需要分析题意来判断边界。



至于遗忘问题，这是必然的。但是当我们见过一道之前做过的题目时，不能只想起来“这道题我做过”，而是要想起来“这道题我记得是用XXX方法来做的”，所以说如果大家每次都是第一种反应的话，建议每做完一道题后，都对类似的相关题目进行 BFS 一遍（LeetCode的每道题下面基本都有 "similar question"），这些题目可以不做，但是一定要分析为什么和之前的题目是相似的，如果我使用之前题目的解法，我能不能解答出这道题。

