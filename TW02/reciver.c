#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<apra/inet.h>

#define PORT 4444

int main(void){
int sockfd,clientSocket,ret,n;
	struct sockaddr_in serverAddr;
	char buffer[1024],msg[1024]="exit";

	clientSocket = socket(AF_INET,SOCK_STREAM,0);
	if(clientSocket<0){
		printf("[-]Error in connection. \n");
		exit(1);
	}
	printf("[+]Client socket is created\n");
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family = AF_INET:
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr - inet_addr("127.0.0.1");
	ret = connet(clientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	if(ret<0){
		printf("[-]Error in coonection.\n");
		exit(1);
	}
	printf("[+]Connected to server\n");	
	while(1){
		printf("Enter the message to send to server:");
		fgets(buffer,sizeof(buffer),stdin);
		n = strlen(buffer);
		buffer[n-1] = '\0';
		send(clientSocket, buffer, sizeof(buffer),0);
		if(strcmp(buffer,msg)  == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}
	if(recv(clientSocket, buffer, sizeof(buffer),0) < 0){
		printf("[-]Error in receiving data.\n");
	}else{
		printf("Server: %s\n",buffer);
		buffer[0]='\0';
	}
	}
	return 0;
}
