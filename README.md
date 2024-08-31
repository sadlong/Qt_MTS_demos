##  3种技术模块---Qt_MTS_demos

- 菜单栏
- 工具栏
- 状态栏



**导入图片到项目中**

首先要准备好图片，从网上随便下载文件就行，放在你预先准备好的文件夹中，然后复制到项目主文件夹(Qt_MTS_demos)内

![1725095491830](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1725095491830.png)

在当前的主项目文件加Qt_MTS_demos右键选中add new...然后选择Qt->Qt Resource File，起个名称(只要不是中文就行)，版本控制选none

![1725095696436](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1725095696436.png)

先添加前缀然后再添加文件，再选中你全部准备好的图片添加进去即可，保存这以上步骤也很重要，在下图展示的位置点×会弹出窗口然后点击save all

![1725095907106](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1725095907106.png)



**this概念的解析**

在这个项目的实例中，遇到了一个this，这个this也是我一直学Qt困扰着我的地方，以下面为例

```cpp
//菜单栏设计与实现
QMenuBar* pMenuBar = new QMenuBar(this);
setMenuBar(pMenuBar);   //用于将 QMenuBar 设置为 QMainWindow 的菜单栏。这个函数的作用是将指定的 QMenuBar 对象作为主窗口的菜单栏，使其显示在窗口的顶部。
```

首先这个语句出现在mainwindow.cpp中，那么这里的this指的就是主窗口mainwindow实例。那么这一条语句执行后就包含了两种含义：1、创建pMenueBar对象。2、传递this作为父对象也就是mainwindow。那么这样做有什么好处呢？

- 内存管理： 通过将 `this` 传递给 `QMenuBar` 的构造函数，你指定了 `MainWindow` 作为 `QMenuBar` 的父对象。当 `MainWindow` 被销毁时，Qt 会自动销毁其子对象（包括 `QMenuBar`），这简化了内存管理。 
- 对象层级结构：Qt 的对象系统使用层级结构来组织和管理对象。通过设置父对象，你将 `QMenuBar` 作为 `MainWindow` 的子对象。这种结构有助于组织界面元素，使它们在视觉和功能上都与父窗口关联。
- 事件处理： 子对象可以继承父对象的事件处理。虽然 `QMenuBar` 不直接从 `MainWindow` 继承事件处理，但将其作为子对象可以使得 `MainWindow` 更好地管理和协调子对象的行为。 





**ui修改图标和窗口名称**

![1725102376596](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1725102376596.png)

在QWidget选项中找到windowTitle和windowIcon进行修改后效果如图

![1725102509560](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1725102509560.png)



**成果效果图**

![1725108899814](C:\Users\123\AppData\Roaming\Typora\typora-user-images\1725108899814.png)

