clang++ -std=c++14 -O3 ipc_send.cpp -o ipc_send.cpp.o -lrt
clang++ -std=c++14 -O3 ipc_recv.cpp -o ipc_recv.cpp.o -lrt
echo "make complete, you need to stop this two process from exiting .."
