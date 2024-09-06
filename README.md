cd /monitor_linux/docker/scripts 
启动容器
./monitor_docker_run.sh 
进入容器
./monitor_docker_into.sh

需要先运行rpc的服务器
cd /work/build/rpc_manager/server
./server

新建一个终端，cd到项目的scripts路径中，启动监控服务
cd /monitor_linux/docker/scripts 
./monitor_docker_into.sh  # 进入docker容器。
cd work/build/test_monitor/src
./monitor 

新建终端
cd /monitor_linux/docker/scripts 
./monitor_docker_into.sh  # 进入docker容器。
cd work/build/display_monitor
./display 
