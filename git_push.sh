#!/usr/bin/expect  
set timeout 30
spawn git push
expect "*Username*"
send "brucecyc@163.com\n"
expect "*Password*"  
send "cyc19900312\n"  
interact  
