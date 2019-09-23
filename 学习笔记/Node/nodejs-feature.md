# nodejs重要特性

## 回调函数

如果看见某个函数定义长下面这样👇那它就应该是个带回调的函数。这类的函数一般为js内置，在调用的时候都是作为一个新线程运行的。

```javascript
function some_function(param1,param2,callback){}
```

callback里面写上一个自己定义的函数函数，例如

```javascript
function another_function(err,data){}
```

然后调用

```javascript
statement1

some_function(param1,param2,another_function)

statement2
```

那么`some_function`会和`statement2`并行执行，`some_function`执行完后就会调用`another_function`然后给`another_function`传两个个参数`err`和`data`。nodejs中带回调的函数都把错误信息作为回调的第一个参数，返回的数据作为第二个参数。回调函数`another_function`也将是并行执行的。

## 事件循环

引入模块👇创建对象👇

```javascript
var events = require('events');
var eventEmitter = new events.EventEmitter();
```

把某个事件`'eventName'`绑定到某个函数`eventHandler`上

```javascript
eventEmitter.on('eventName', eventHandler);
```

然后就可以触发事件了👇

```javascript
eventEmitter.emit('eventName');
```

### 触发事件的内部机制是？

![事件循环](i/nodejs_1.jpg)

事件循环👆每次`eventEmitter.emit`都会有一个事件名称（'eventName'）入队列，在队列的另一端是一群处理函数（eventHandler）在不断从队列中取事件进行处理。

### eventEmitter还有这些功能👇

```javascript
addListener(event, listener)
#为指定事件添加一个监听器到监听器数组的尾部。

on(event, listener)
#为指定事件注册一个监听器，接受一个字符串 event 和一个回调函数。 

once(event, listener)
#为指定事件注册一个单次监听器，即 监听器最多只会触发一次，触发后立刻解除该监听器。

removeListener(event, listener)
#移除指定事件的某个监听器，监听器必须是该事件已经注册过的监听器。
它接受两个参数，第一个是事件名称，第二个是回调函数名称。

removeAllListeners([event])
#移除所有事件的所有监听器， 如果指定事件，则移除指定事件的所有监听器。

setMaxListeners(n)
#默认情况下， EventEmitters 如果你添加的监听器超过 10 个就会输出警告信息。 setMaxListeners 函数用于提高监听器的默认限制的数量。

emit(event, [arg1], [arg2], [...])
#按监听器的顺序执行执行每个监听器，如果事件有注册监听返回 true，否则返回 false。

listenerCount(emitter, event)
#返回指定事件的监听器数量。
```

### 继承 EventEmitter

大多数时候我们不会直接使用 EventEmitter，而是在对象中继承它。

包括 fs、net、 http 在内的，只要是支持事件响应的核心模块都是 EventEmitter 的子类。

为什么要这样做呢？原因有两点：

* 具有某个实体功能的对象实现事件符合语义， 事件的监听和发生应该是一个对象的方法。

* JavaScript 的对象机制是基于原型的，支持部分多重继承，继承EventEmitter 不会打乱对象原有的继承关系。