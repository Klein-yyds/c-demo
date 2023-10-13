# 项目名称

交通管理系统

# 描述

这是一个用c++写的，用qt作为界面构建工具制作的一个桌面应用，模拟交通管理系统。系统里面的用户对象有3种，分别是管理员，乘客和司机。系统模拟了他们之间的交互。

## 角色间的交互

管理员能看到所有的乘客和司机，以及他们对应的信息（乘客的账号，密码，姓名以及状态。司机的账号，密码，姓名，车牌号码，收费情况以及状态）。管理员能对司机以及乘客进行增删改查。（除了状态的改变）

乘客能看到地图上的所有地点。在指定出发地和目的地之后乘客能看到从出发地到目的地是否有路线能到达，预计耗时最短路线是耗时多久，预计耗时最短路线距离以及预计耗时最短路线沿途所经过的地点。同时乘客的状态变成需要乘车，意为向司机发起订单。除以上功能之外，乘客还可以单独修改自己的个人信息（除了状态以外）。

司机能看到所有状态为“需要乘车”的乘客，然后自主的选择乘客进行乘客的订单。司机进行订单之后，将会进入进行订单界面，乘客的状态将会改变为“乘车”，司机的状态将会改变为“正在进行某某乘客的订单”。假如司机在进行订单界面中途退出程序，重新登录回来也是进入进行订单界面。只有当司机完成订单之后，点击完成订单按钮才能返回到能看到所有状态为“需要乘车”乘客的界面。

## 特点

采用迪杰特斯拉算法。迪杰特斯拉算法可用于带权或不带权的图，寻找某一地点到另一地点权值最小的路线。其思路为循环遍历所有地点，找到还没有确定最短路径且当前最短路径最短的地点，将其设为最短路径已经确定且就是当前最短路径。然后检查所有邻接自该地点的结点，若有结点还没确定最短路径且从该地点有更短路径到达这结点，则更新到该结点的最短路径。循环遍历直到所有地点的最短路径均被确定。算法的结果是找到了从出发点到其余所有点的最短路线。而我们只要取目标点即可。

# 使用

## 运行项目

在windows系统下运行文件TravelSystem下的.exe即可运行该项目。（确保.exe文件所需要的运行脚本都在）

## 项目使用介绍

运行后进入登录界面：

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image002.gif)

系统有判空警告，往后输入不一一展示警告：

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image004.gif)

管理员登录后进入的界面可以看到所有乘客以及司机的信息

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image006.gif)

管理员点击管理乘客信息后

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image008.gif)

通过下拉框选择要修改的乘客，后续界面的下拉框作用大致相同，就不一一展示

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image010.gif)

管理员点击进入修改司机信息界面后

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image012.gif)

对乘客和司机信息修改后，将返回管理员主界面，看到对应的信息被修改。可对比上面的管理员主界面，就可以看出明显变化。

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image014.gif)

乘客登录后进入乘客主界面，在这里你可以看到地图上所有地点。地图如下

![map of europe with rail links connecting major cities](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image015.jpg)

乘客界面如下

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image017.gif)

乘客选择出发地以及目的地之后，点击确认，系统将自动展示预计最短耗时，最短耗时的路程以及路线。（不是所有两个地点之间都是互通的，小概率会碰到不是互通的出发地和目的地，此时系统会显示“对不起，您所查找的路线不存在”）同时乘客的状态会被改变成“需要乘车”。

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image019.gif)

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image021.gif)

乘客点击修改个人信息后进入的界面

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image023.gif)

司机登录后的进入司机主界面。可以看到所有有乘车需求的乘客，然后通过下拉框选择进行某个乘客的订单

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image025.gif)

司机点击接单后会进入接单界面，此时司机的状态会被改变成“正在进行某某乘客的订单”。此时即使司机中途退出程序，也会直接进入接单界面而不会进入司机主界面。只有当司机点击完成订单后才能返回司机主界面。

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image027.gif)

点击完成订单后返回主界面，可以看到主界面有乘车需求的乘客少了一个，因为该乘客的订单被完成了。

![img](file:///C:/Users/Liang/AppData/Local/Temp/msohtmlclip1/01/clip_image029.gif)

以上就是本项目的基本功能。