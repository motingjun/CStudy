## 析构函数

创建对象时，系统会为对象分配所需要的内存空间等资源，当程序结束或对象被释放时，系统为对象分配的资源也需要回收，以便可以重新分配给其他对象使用。
在C++中，对象资源的释放通过析构函数完成。析构函数的作用是在对象被释放之前完成一些清理工作。析构函数调用完成之后，对象占用的资源也被释放。
```c++
class 类名 
{ 
  ~析构函数名称(); 
  ...   //其他成员 
} 

```

关于析构函数的定义，有以下注意事项。
- 析构函数的名称与类名相同，在析构函数名称前添加“～”符号。
- 析构函数没有参数。因为没有参数，所以析构函数不能重载，一个类中只有一个析构函数。
- 析构函数没有返回值，不能在析构函数名称前添加任何返回值类型。在析构函数内部，也不能通过return返回任何值。
- 当程序结束时，编译器会自动调用析构函数完成对象的清理工作，如果类中没有定义析构函数，编译器会提供一个默认的析构函数，但默认的析构函数只能完成栈内存对象的资源清理，无法完成堆内存对象的资源清理。因此，在程序中往往需要自定义析构函数。

析构函数的调用情况主要有以下几种。
- 在一个函数中定义了一个对象，当函数调用结束时，对象应当被释放，对象释放之前编译器会调用析构函数释放资源。
- 对于static修饰的对象和全局对象，只有在程序结束时编译器才会调用析构函数。
- 对于new运算符创建的对象，在调用delete释放时，编译器会调用析构函数释放资源。

注意:
```
析构函数的调用顺序与构造函数的调用顺序是相反的。在构造对象和析构对象时，C++遵循的原则是：先构造的后析构，后构造的先析构。
例如，连续创建了两个对象A1和A2，在创建时，先调用构造函数构造对象A1，再调用构造函数构造对象A2；在析构时，先调用析构函数析构对象A2，再调用析构函数析构对象A1。
```

程序运行结束后，编译器会调用析构函数释放对象资源，在释放时，先释放_food指向的内存空间，再释放对象所占用的内存空间。