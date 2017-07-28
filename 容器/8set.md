# set/multiset容器

这里的set是采用红黑树变体(平衡二叉树)实现的数据结构.
按照排序规则插入, 所以不能在指定位置插入元素, 但增删比vector块( `O(lgn) < O(n)` )
(`2^t=n` --> t = `O(lgn)`)

set的元素不重复, multiset元素可以重复.

修改: 不能修改元素(存储的时候按照默认的规则存储的, 默认是从小到大), 只能先删除, 后新增元素. 元素唯一, 自动排序.

插入元素: insert(); //返回时`pair<iterator, bool>`
删除元素: erase();


insert()的返回值:
pair1.first  //具体类型的iterator
pair2.second //bool 是否插入成功

然后进行比较就可以了


排序规则(比较大小的函数):
`set<int> set1;`
相当于 `set<int, less<int>> set1; //less是升序`
如果要从大到小:(记得头文件 <functional>)
`set<int, greater<int>> set2;`


如果是非基本类型: 借助仿函数, 函数对象(重载函数调用操作符)

stuct StuFunction
{

    bool operator() (const Student& stu1, const Student& stu2){
        return (stu1.age < stu2.age);  //小于是升序
    }

}; 

set<Student, StuFunction> s1;



查找:
find(elem); //返回元素迭代器的位置
count(elem);  //返回个数, 要么是0, 要么是1; multiset则可能大于1

lower_bound(elem); //返回第一个>=elem的迭代器
upper_bound(elem); //返回第一个>elem的迭代器

例如: lower_bound(5); 找到的可能是5或者6, 但是upper_bound(elem);找到的一定大于5, 可能是7

equal_range(elem); //返回一个pair,
例如: pair<set<int>::iterator, set<int>::iterator> pairInt = 
                         s1.equal_range(5);


一个简单的使用:

```c++
#include <funcitonal>
#include <algorithm>
#include <iterator>

int array[] = {1, 2, 3, 4};
set<int, greater<int>> s(array, array+5, greater<int>()); //<functional>

copy(s.begin(), s.end(), ostream_iterator<int>(cout, ", ")); //输出

```



multiset略: (在set的基础上, 可以重复而已)