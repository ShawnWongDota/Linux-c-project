APP = main
CC = $(CROSSCOMPILE)gcc
#CC =arm-hisiv100-linux-
INCLUDE = -I ../src/
CCFLAGS = -Wall -Werror $(INCLUDE) 

#静态库
LDFLAGS = -L../lib -ltest -lm -lpthread

#动态库
#增加/etc/profile下LD_LIBRARY_PATH的动态库的路径（条件变量）
#export LD_LIBRARY_PATH=/home/apple/workspace/test/lib/share:$LD_LIBRARY_PATH
#LDFLAGS = -L../lib/share -ltest


all: $(APP)

%.o: %.c
	$(CC) $(CCFLAGS) $< -c

main: main.o 
	-$(CC) $^ -o $@ $(LDFLAGS)
	-mv main ../
	
clean:
	-rm -f *.o
	-rm -f ../main