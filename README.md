# Step2SimplifiedMesh
## 使用前步骤
* 将Project1中的includes添加到包含目录中
* 将Project1文件夹中**.h文件添加到项目头文件中
* 将Project1文件夹中engine3D，step2mesh，steo2Obj相关dll添加到项目资源中
## 使用方法
* 演示过程在main.cpp中，直接调用函数即可
 ```python
 step2simplifiedmesh("../file/231.step", 1, 0.999, "../res/tmp.obj", "../res/outer.stl");
 ```
* 已将接口改为函数，可以直接提供给python及C++调用
* 第一个参数，../file/231.step为读取的step格式文件的相对路径，也可替换为绝对路径
* 第二个参数，1表示进行模型简化，0表示不进行简化
* 第三个参数，0.999表示最终生成模型的点个数占原模型的比例，应填写[0,1]的浮点数
* 第四个参数，../res/tmp.obj为生成的obj格式缓存文件的相对路径，也可替换为绝对路径
* 第五个参数，../res/outer.stl为生成的stl格式简化模型文件的相对路径，也可替换为绝对路径

## 版权声明
本库基于Meirshomron/MeshSimplification和foxtrot改写完成，如有版权问题欢迎联系bqw20@mails.tsinghua.edu.cn。侵删。
