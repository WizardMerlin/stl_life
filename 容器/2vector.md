# vector

概念: 将元素放置于动态数组中加以管理, 支持随机存取([], at()), 尾部添加和移除元素比较快(中部和头部比较慢,因为要移动后面的元素)
vector存储的元素的副本, 所以如果是自定义类型的对象, 要提供合适的 `拷贝构造函数` , 即元素可以拷贝.

```c++
#include<vector>
vector<T> vecT;
vecT.push_back(t);//尾部添加
vecT.front(); //获取头部元素(可以做左值, 被修改)

while(vecT.size() > 0){
    vecT.back();//获取尾部元素(可以做左值, 被修改)
	vecT.pop_back();//弹出元素(从容器中删除)
}
```

初始化:

```c++
vector<int> v1(10); //v1有10个元素, 全部初始化为0, 之后push_back()则是在第11个位置添加元素
v1.push_back(1);
v1.push_back(2);

vector<int> v2 = v1;
vector<int> v3(v1.begin(), v1.end());
```

遍历:
```c++
//通过数组的方式访问vector (遍历)
v1[i] = i+1;  //当你用数组方式赋值时, 一定确保容器中已经有相应的内存vector<int> v1(10);
```
修改他的值, 最好不要用数组的方式, 仅当要获取值得时候, 采用数组的方式.

```c++
//vector的迭代器操作()
vector<int> v1(10);
for(int i =0; i<10; i++){
    v1[i] = i+1;
}
//begin指向第一个元素, end指向末尾元素的后一个位置
for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
    cout << *it < endl;
}
```



删除操作: 
(区间删除, 指定元素删除, 指定迭代器位置删除)

```c++
v1.erase(begin, end); //区间删除
v1.erase(pos); //指定位置删除
iterator = v1.erase(iterator); //删除当前迭代器元素后, 迭代器自动下移.
```

vector插入操作
* insert(); 
* push_back();  



其他补充:
* clear()不会重置capacity(即不会释放空间)
* clear同时释放空间, 可以这么写
 ```c++
 template <typename T> 
 void clearAndRelease(vector<T> &v)
 {
     vector<T> vTmp;
     vTmp.swap(v);
 }
 ```
* reserve() 提前设定大小, 避免频繁分配内存空间
* 重新分配内存是性能下降, 其他时候和普通数组一样 (重新分配之后请手动更新迭代器)
* 自动扩容一般是2倍
* c++11提供了shrink_to_fit(), 但是如果自己修正的话可以借助临时容器(临时容器使用完毕自动销毁了)
 `vector<int>(v).swap(v);`
