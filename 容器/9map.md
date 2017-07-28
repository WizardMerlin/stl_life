# map, multimap
关联式容器, (key, value); 提供key的快速检索能力; (key唯一, 元素按照一定的顺序排列)
map的实现也是平衡二叉树(红黑树), 所以插入删除比vector快.

支持[]操作, 例如map[key]
(multimap允许重复key)

```c++
#include <map>
map<T1, T2> map1;
```
增:
```
insert(pair<T1, T2>(t1, t2))  //key-value
insert(make_pair(t1, t2)) 
insert(map<T1, T2>::value_type(t1, t2))
map[7] = "value" //直接赋值, 进行插入(注意第二次插入同一位置, 会覆盖; 而insert插入第二次则不成功)
```

(insert同样返回pair, 一般都要判断一下是否插入成功)


遍历:
```c++
map<int, string>::iterator it = map1.begin();
it.first;
it.second;
```

删除:
```c++
if(map.empty()){
    it = map.begin();
	map.erase(it);
}
```
也可以按照key删除



查找:
find()查找, 返回迭代器, 找不到用it.end()做判断.

equal_range查找, 返回一个pair(包含俩迭代器)
```c++
pair<map<int, string>::iterator, map<int, string>::iterator> pair
  = m1.equal_range(5);
map<int, string>::iterator itBeg = pair.first; //指向5的迭代器
map<int, string>::iterator itEnd = pair.second; //指向7的迭代器
```


multimap
同一个key, 可以对应多个value, 主要应用场景就是数据分组.

例如:
```c++
m1.insert(make_pair("sale_department", person1);
m1.insert(make_pair("sale_department", person2);
```

查询:
```c++
int num = count("sale_department"); //2

multimap<string, Person>::iterator it = map.find("sale_department");
int i = 0;
while(it != map.end() && i<num){
    cout << it.first << it->second << endl;
	it++;
}
```