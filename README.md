# **数据结构实验**

## 并查集接口实现

### 并查集合并方式选择

使用者可自行进行下列宏定义，以选择不同的并查集合并方式

*ps:需要在 `DSU.h`文件中定义*

* `USE_WUR_UNION`	采用加权合并原则
* `USE_PC_UNION`	采用压缩路径原则

若不进行宏定义，则不采用任何原则

### API声明

见`DSU.h`文件

### API实现

见`DSU.c`文件

## 无向图接口实现

### 无向图存储结构选择

使用者可根据需要自行进行下列宏定义，以启用不同的图的存储结构

*ps:需要在 `UDGraph.h`文件中定义*

* `ADJMATRIX`	采用邻接矩阵存储结构
* `ADJLIST`	采用邻接表存储结构

### API声明	

见`UDGraph.h`文件

### API实现

见`UDGraph.c`文件
