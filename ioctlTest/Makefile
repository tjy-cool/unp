# 使用方式
# make src=udp-sever
# make src=test lib=-lpthread inc=-I. 

# 编译链
CC = gcc

# lib 可以外部传入，也可以不指定
lib =
LIBS = -L../libunp/lib/$(shell uname) -lunp $(lib)

# inc 可以外部传入，也可以不指定
inc = 
INCLUDES = -I../libunp/include/$(shell uname) $(inc)

# 默认使用名为test.c
src = test
# 如果使用 make src=hello,  则会编译hello.c
TARGET = $(src)

# 编译
DEMO:
	$(CC) -o $(TARGET) $(TARGET).c $(INCLUDES) $(LIBS) 

# 清理
.PHONY: clean
	-rm -rf $（TARGET）
