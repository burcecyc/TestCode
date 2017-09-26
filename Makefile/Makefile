######### 标准Makefile Lv1.2 / 使用动态库 ########
EXE       = main
SUBDIR    = . 

#CXXFLAGS:编译选项, LDFLAGS:链接选项
CXXFLAGS += -MMD
LDFLAGS  += 

#所有的SUBDIR中的.c源文件
CXX_SOURCES = $(foreach   dir, $(SUBDIR), $(wildcard $(dir)/*.c))

#所有的SUBDIR中的由.c编译生成的.o文件
CXX_OBJECTS = $(patsubst  %.c, %.o      , $(CXX_SOURCES))

#所有的SUBDIR中的替换.c文件为.d文件
DEP_FILES   = $(patsubst  %.o, %.d      , $(CXX_OBJECTS))

$(EXE): $(CXX_OBJECTS)
	gcc  $(CXX_OBJECTS) -o $(EXE) $(LDFLAGS)
	
%.o: %.c
	gcc  -c  $(CXXFLAGS) $< -o $@

-include $(DEP_FILES)

clean: 
	rm  -rf  $(CXX_OBJECTS)  $(DEP_FILES)  $(EXE)

test:
	echo $(CXX_OBJECTS)

	
