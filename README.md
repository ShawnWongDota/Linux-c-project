Linux下的Makefile工程模板
===================

说明
----------
#如果你不知道工程怎么建立或者不知道怎么组织代码，这个分享将建立一个c工程实例
#如果你也不清楚linux动态库和静态库怎么生成，src下的Makefile将代码生成库文件
#如果你还不清楚怎么链接linux下面的库文件，app下的Makefile将分别链接库

目录文件
-----------
#app（应用）
##main.c 			//这个应用链接库使用它们的函数的实例
##Makefile			//链接库的makefile
#lib（库）
##share				//动态库
##*.a				//静态库
#src（源码）
##cJSON.c			//cjson代码
##cJSON.h			
##hello.c			//随便写的一个文件，主要是为了生成库
##hello.h
##Makefle			//生成库
#Makefile			//执行每个文件中的Makefile


使用
----------
#在linux下进入本目录，输入make生成对应的库文件在lib下
#执行./main运行实例


注
----------
#本实例用的cjson是在网上找的开源代码
#本实例是为了给不知道在linux组织工程代码的借鉴，大神请绕道
#如有疑问可以给我发邮件zhigang3846@163.com