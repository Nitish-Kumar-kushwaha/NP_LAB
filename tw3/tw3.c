#include<stdio.h>
#include<stdlib.h>
 
 
#define nul 1000
#define nodes 10
 
int no;
struct node{
    int a[nodes][4];
}router[nodes];
 
 
void init(int r){
    int i;
    
    for(i=1; i<=no; i++){
        router[r].a[i][1]=i;
        router[r].a[i][2]=999;
        router[r].a[i][3]=nul;
    }
    router[r].a[r][2]=0;
    router[r].a[r][3]=r;    
}
 
void inp(int r){
    printf("\nEnter Distance from Node %d to other nodes",r);
    printf("\n Please enter 999 if there is no direct route ");
 
    for(int i=1; i<=no; i++){
        if(i!=r){
            printf("\n\nEnter the distance to the node");
            scanf("%d",&router[r].a[i][2]);
            router[r].a[i][3] = i;      
        }       
    }   
}
 
void display(int r){
    int i,j;
    printf("\n\n the routing table for node %d is as follows : ", r);
    for(i=1; i<=no; i++){
        if(router[r].a[i][2>=999])
           printf("\n\t\t\t %d no link \t  no hop", router[r].a[i][1]);
        else
           printf("\n\t\t %d \t %d \t",router[r].a[i][2],router[r].a[i][3]);                
    }
}
 
void dv_algo(int r){
    int i,j,z;
    for(j=1; j<=no; j++){
        if(router[r].a[i][2]!=999 && router[r].a[i][2]!=0){
            for(j=1; j<=no; j++){
                z= router[r].a[i][2]+router[r].a[j][2];
                if(router[r].a[j][2]>z){
                    router[r].a[j][2] = z;
                    router[r].a[i][2] = i;              
                }           
            }
        }   
    }
}
 
 
int main(){
    int i,j,x,y;
    char choice;
    printf("Enter the no. of nodes required (less than 10 pls): ");
    scanf("%d", &no);
    for(i=1; i<=no; i++){
        init(i);
        inp(i);     
    }
 
    printf("\n The configuration of the node afer initialization is as follows");
   
 for(i=1; i<=no; i++){
        display(i); 
    }
    for(i=1; i<=no; i++){
        dv_algo(i); 
    }
 
    printf("\n the configuration of nodes after computation of paths is as follows: ");
    for(i=1; i<=no; i++){
        display(i); 
    }
 
    while(1){
        printf("\n\n Wanna Continue (y/n): ");
        scanf("%c",&choice);
        if(choice=='n')
          break;
        printf("\n\n Enter the nodes btn which shortest path is to befund : \n");
        scanf("%d %d",&x, &y);
        printf("\n the length of the shortest path is %d", router[x].a[y][2]);
    }

    }
