#########################################################################
# File Name: test01.sh
# Author: chenyingchun
# mail: yingchun.chen1@pactera.com
# Created Time: 2017年10月10日 星期二 13时46分33秒
#########################################################################
#如下:<< !和!之间的注释为多行注释
: << !
csc@csc-OptiPlex-790:~/git/myGithub/TestCode/linuxShellProgram$ ./test01.sh 11 12
$#: means shell script parameter numbers: 2
$0: means shell script name: ./test01.sh

$0: ./test01.sh
$1: 11
$2: 12

$@: all the shell script argumes: 11 12

$@ 输出
11
12
-----------------
"$@" 输出
11
12
-----------------------------
$* 输出
11
12
-----------------
"$*" 输出
11 12

$$: show process id:13284
$?: show previous command return state: 0
!

#!/bin/sh
num=$# # $#表示的是执行shell命令之后的参数个数，比如 ./test01.sh 01 02，那么$# = 2
name=$0 #　$0表示的是shell命令的某一个参数，比如 ./test01.sh 01 02, 那么$0为./test01.sh, $1为01, $2为02
echo "\$#: means shell script parameter numbers: $num"
echo "\$0: means shell script name: $name"
echo
echo \$0: $0
echo \$1: $1
echo \$2: $2 #如果没有$2,则打印的结果为空
echo

#for ((i=0; i<$num; i++))
#do
#    echo \$$i: "$$i"
#done
#echo

echo "\$@: all the shell script argumes: $@"  #$@表示所有的参数
echo 

echo "\$@ 输出"
for key in $@
do
    echo $key
done

echo "-----------------"

echo "\"\$@\" 输出"
for key in "$@"
do
    echo $key
done

echo "-----------------------------"

echo "\$* 输出"
for key2 in $*
do 
    echo $key2
done

echo "-----------------"

echo "\"\$*\" 输出"
for key2 in "$*"
do 
    echo $key2
done

echo

echo "\$\$: show process id:$$"
echo "\$?: show previous command return state: $?"
echo
