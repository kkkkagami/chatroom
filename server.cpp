#include<iostream>
#include<cstring>
#include<unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main(){
    int server_fd,client_fd;                //监听套接字 和 客户端套接字
    struct sockaddr_in address;             //保存IPv4地址和端口信息
    char buffer[1024]={0};                  //收发缓冲区

    //1.创建套接字
    server_fd=socket(AF_INET,SOCK_STREAM,0);
    if(server_fd==-1){
        perror("socket failed");
        return 1;
    }

    //2.生成地址和端口信息
    address.sin_family=AF_INET;             //指定地址族: IPv4
    address.sin_addr.s_addr=INADDR_ANY;     //监听本机的所有网卡
    address.sin_port=htons(PORT);           //指定要监听的端口号

    //IP&端口绑定到套接字上
    if(bind(server_fd,(struct sockaddr*)&address,sizeof(address))<0){           //绑定IP,端口 到监听套接字
        perror("bind failed");
        return 1;
    }

    //3.监听
    if(listen(server_fd, 1)<0){
        perror("listen failed");
        return 1;
    }
    std::cout<<"Server listening on port: "<<PORT<<"...\n";

    //4.等待客户端连接
    socklen_t addrlen=sizeof(address);      //地址结构体的长度
    

}