# 引子

以前的库, 重新整理下上传, 记录了我以前学习STL的过程.

(不要学的很痛苦, 不要文章太长)

除了教程类, 您还可以关注我的github账号和github博客, 这里也许有你想要的:

1. github: https://github.com/WizardMerlin
   (分享easy的教程, 分享成熟的库, 自己的轮子)
2. 私人博客: https://wizardmerlin.github.io/
   (主要是概括性的文章, 思考, 书评, 翻译, 深入剖析)
3. 社区博客:(讨论开源, 提问 & 回答别人的问题)
   * https://my.oschina.net/wizardmerlin/blog  (讨论 & 简单的教程)
   * https://segmentfault.com/u/wizardmerlin  (问答 & 简单的教程)

   当然也欢迎你加入我们的日常组, 高级Linux开发群: `59151639`


其他技术问题, 只要我知道或者感兴趣,一定会个给您满意的回复.
  
期待更多的交流: `wizardmerlin945@gmail.com`



# 正文

## 常规学习方法

说实话, 标准模板库, 还是挺大的; 在经历了30分钟入门之后, 就已经算是入门了.

按照孟岩先生所说:
"我主张, 在具备基础之后, 学习新任何东西, 都要抓住主线, 突出重点. 对于关键理论的学习, 要集中精力, 速战速决. 而旁枝末节和非本质的东西完全可以留给实践去零敲碎打". 

(当然侯捷也说过三层境界, 但是那要花费很长的时间, 不做过多言语;)

STL如下核心内容:

	0. 容器: 序列容器() + 关联容器() + 特殊容器(容器适配器&操作受限容器)
	1. 迭代器: 5种迭代器() + 迭代器适配器()
	2. 函数对象: 函数对象概念(包括谓词函数等) + 预定义函数对象 + 自定义函数对象
	3. 算法:  变动算法 + 非变动算法 + 移除算法 + 变序性算法 + 排序算法 + 已序区间算法 + 数值算法
	   (算法比较多, 常用的就有70多个, 但至少一个个玩一把)-----把所有算法玩一遍很花时间.
	4. 分配器(我想的话, 除非你涉及内存数据库redis, memcache等或者过于担心内存碎片化, 否则你不需要自己实现分配器)

		
其中上述内容中容器是重点, 其他地位相当. 学习的时候按比例分配时间.

容器的常规学习方法:

	0. 容器有哪些共通的方法
	1. 容器实现采用的哪种数据结构
	2. 初始化 & 遍历
	3. 增删查改
	4. 该容器特殊的地方
		比如使用vector如何高效的进行resize, 比如如何通过临时容器"交换"来调整过多的剩余空间
	5. 其他注意事项


算法的常规学习方法:
	0. 常用的算法晚熟




## 详细记录
参考一下本库里面各个目录和文件吧:


标准库概述     ----   ./标准库概述.md
容器          ----   ./容器, 其中code尝试重写了一下动态数组 vector
算法          ----   ./算法, 算法基础 and STL算法小结
函数对象      ----   ./函数对象, 函数对象小结


## 进阶推荐

0. C++ 11 推出的 `array` , `forward_list` ,  `unordered_set` , `unordered_map`
1. 《effective stl》 中那50条 (本库其实已经涵盖了很多)




## 参考书籍
	1. <C++标准模板库编程实战> (这本红皮书, 涉及到了c++11, 用的时候注意一下)
	2. <大道至简 C++STL标准模板库 精解> (有大量的案例, 大而全; 但不如上一本告诉你所以然, 适合查漏补缺;)
	3. <STL标准库自学手册(上,下)> (这本书我买的英文版, 作者说的清晰易懂; 但是有了上两本的基础,    这本书很快翻了一下: 主要看C++11改写的部分)
	4. <C++STL源码分析> (从这本书可以看出来你的数据结构底子够不够, 也可以看出侯捷大师作为一个技术人, 真的是有脾气有性格的) 
	5. <effective stl> (集中的把开发中遇到的一些问题抽取出来了, 还不错)



# 尾巴


学习过程比较杂乱, 但是应该涉及到了, 都说到了.
(读书笔记, 分享的话, 在博客里面单独写)





