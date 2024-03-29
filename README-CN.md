# struct
## 什么是struct？

`struct` 是一个升级版的页面切换系统，它专门为使用面向过程的嵌入式编程设计，它脱胎于[Controller](https://github.com/wangtingzheng/controller)，由于时间紧迫和需求不那么强烈等问题，我在设计[Controller](https://github.com/wangtingzheng/controller)中的页面切换系统时，采用了最简单的机制，带来了一些问题，在本项目中，我将尝试改进整个机制，试图克服原有机制的缺点，此项目仍处于开发和测试阶段。

## 页面切换系统
如何在一个面向过程的编程环境下设计一个多叉的页面切换机制？这个问题在嵌入式GUI开发中十分重要。完美的目标是让单个页面按照一定的逻辑连接起来，这个逻辑通常是某一个按键按下的状态被激活，这样你就能按下返回键来返回上一页。

在我的另外一个项目[Controller](https://github.com/wangtingzheng/controller)中，设计了一种十分简陋的页面切换逻辑，它由**页面实现**、**页面管理**、**跳转判断**、**页面跳转**四部分组成。

在**页面实现**里，开发者需要利用GUI库，开发出每一个单个页面的显示效果，这个时候，开发者不需要考虑页面跳转的逻辑关系，只需要一个个地实现每一个页面的效果即可

```c
void page_1_2(){
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, line*1, "1.set distance");
  u8g.drawStr(0, line*2, "2.set angle");
}
```

可以看到，上面一串代码，就实现了一个显示页面，这个页面将在两行中显示`1.set distance`和`2.set angle`

在**页面管理**中，开发者需要给每一个页面编号，并且为这个系统的所有页面设立一个以编号为入口的执行函数，能够按照我的指定来执行任意一个页面，注意，此时开发者仍然不需要考虑页面切换的逻辑关系

```c
void runtest(int n){                          
    switch (n){
      case 0:{
        u8g.firstPage();
        do{
          page_1_2();
        }while(u8g.nextPage());
        break;
      }
    }
}
```

在上面的函数中，我把`page_1_2()`这个页面编为0号，并且在一个函数中放入了switch语句，当我执行`runtest(0)`的时候，屏幕会显示`page_1_2()`所实现的内容

**跳转判断**处于一个死循环中，在跳转判断中，开发者开始要考虑页面跳转逻辑，这里可以通过使用if语句对跳转条件进行判断，进而可以进行相应的跳转，我们通过更新一个全局变量的值来切换页面，这个全局变量是用来储存当前页面的id的，在跳转完成之后，这个值也被改变，那么在下一个循环中，当前页面将会在id层面被切换

```C
if(flag==1&&controller==HEXN[9]) flag=0;
else if(flag==1&&controller==HEXN[12]) flag=2;
else if(flag==1&&controller==HEXN[13]) flag=4;
else if(flag==1&&controller==HEXN[14]) flag=7;
```

在上面的if语句中，需要判断两个东西：当前的页面和当前的跳转条件，每个页面都要多个子页面，我们根据每一个子页面的跳转条件是否满足来判断是否跳入这个子页面，flag的赋值语句就是页面id的更新，此时页面并未真正跳转，只是准备好了指令。

**页面跳转**是真正执行跳转动作的过程，在上一个跳转判断中，我们只完成了页面id的切换，我们将新的页面id输入到页面管理所创立的函数的形参中，实现真正的页面切换。

```c
runtest(flag);
```

我们可以看到，这是页面管理中那个函数的具体执行，传入的flag的值就是更新后的页面的id值，当然如果页面id没有被更新，则它就再执行一次当前的页面，实际看来，页面就是没有任何变化。完整代码请看[这里](https://github.com/WangTingZheng/Controller/blob/master/src/main.cpp)。

## 传统方法的缺陷

在页面实现中，并没有明显的缺陷；在页面管理中，我们可以看到，id和页面的添加是手动的，对于我来讲，我可以直接对源代码进行修改当然没问题，但是对其他人来讲，开发之前看懂源代码是非常低效能的，所以必须要把添加页面id和页面函数的操作标准化，封装好函数，封装好函数时，储存这些信息不能用数组，因为数组在定义时就要定义长度，这样页面的数量是受限的，即使用`#define`来定义长度，然后根据需要去改，也是治标不治本，解决方法是利用链表来储存；在跳转判断中，开发者需要很清楚每一个切换逻辑，即使这样，也很容易漏掉，为此，最好的解决方案就是在当个页面设计的时候就把跳转条件设计好，切换的时候在利用标准化的程序来执行切换；在页面跳转这个阶段，还是比较简洁的，但是如果前面的机制变化的话，它也要变化。

## 改进

### 页面实现

这个部分不需要进行大的修改，但是为了保证源代码的可读性，可以专门创立一个源代码文件来储存这些页面函数。

### 页面树





