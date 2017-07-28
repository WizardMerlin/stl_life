list双向链表
不能随机存取元素, 所以不支持[]和at(), 迭代器可以顺序移动it++或者it--但是不能it+5,it-5
节点序号从0开始

```c++
#include<list>
```

存取:
```c++
push_back();
push_front();
pop_front();
pop_back();

insert(it, value);
```
3号位置插入元素, 实际上是在3号位置的前面(替代了当前的3号位置的值, 原来3号位置的值往后移动了)



删除元素:
```c++`
clear(); //全部数据清除
erase(begin, end); //左闭右开, end位置的元素不会删除
erase(pos); //删除pos位置的数据, 返回下一个数据的位置
remove(elem);//删除容器中所有与elem值匹配的元素
```

注意list里面的remove是真的可以删除元素, 不用结合erase使用.