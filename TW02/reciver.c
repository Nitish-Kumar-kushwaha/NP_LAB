#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 4444

int main(void)
{
	int sockfd,newSocket,ret,n;
	struct sockaddr_in serverAddr,newSddr;
	socklen_t addr_size;
	char buffer[1024],msg[1024]="exit";
	pid_t childpid;
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		printf("[-1]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server socket is created.\n");
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	ret = bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	if(ret<0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n",4444);
	
	if(listen(sockfd,10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}
	
	newSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);
	if(newSocket < 0){
		printf("Connection not accepted\n");
		exit(1);
	}
	printf("Connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
	
	while(1){
		recv(newSocket,buffer,sizeof(buffer),0);
		if(strcmp(buffer,msg) == 0){
			printf("Disconnected from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));
			break;
		}else{
			printf("Client:%s\n",buffer);
			printf("Enter message to reply:");
			fgets(buffer,sizeof(buffer),0);
			n= strlen(buffer);
			buffer[n-1]='\0';
			send(newSocket, buffer, sizeof(buffer), 0);
			buffer[0] = '\0';
		}
	}
	close(newSocket);
	return 0;
}
