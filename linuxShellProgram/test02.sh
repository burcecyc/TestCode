#########################################################################
# File Name: test02.sh
# Author: chenyingchun
# mail: yingchun.chen1@pactera.com
# Created Time: 2017年10月11日 星期三 15时49分10秒
#########################################################################
#!/bin/bash
log_print()
{
	logger -t LTE "chenyingchun" $*
}

main()
{
	log_print "OK:========================================="
	log_print "OK:arg0=$0"
	log_print "OK:arg1=$1"
	log_print "OK:arg2=$2"
}


log_print "Start ('$0 $*)"
main $* 2>&1 || exit 1
exit 0
