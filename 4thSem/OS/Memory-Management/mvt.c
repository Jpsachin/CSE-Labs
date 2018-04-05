#include <stdio.h>
int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a1,a2,a3,a4,count=1;
    int r[1000000]={0},p[100][2];
    for(a1=1;a1<100;++a1){p[a1][0]=-1;}
    while(1){
        int ps;
        printf("Enter process size: ");
        scanf("%d",&ps);
        if(ps>n || ps==0){
            printf("\nFinish\n");
            for(a1=1;a1<100;++a1){
                if(p[a1][0]!=-1){
                    printf("\nProcess: %d from-to %d %d",a1,p[a1][0],p[a1][1]);
                }
            }
            printf("\n");
            return 0;
        }
        int store;
        while(1){
            int f1=1;
            for(a1=1;a1<=n;++a1){
                int f3=1;
                for(a2=a1;a2<=a1+ps-1;++a2){
                    if(r[a2]==1 || a2>n){f3=0;break;}
                }
                if(f3){f1=0;store=a1;break;}
            }
            if(f1==1){
                int ext=0;
                for(a1=1;a1<=n;++a1)if(!r[a1])++ext;
                int f2=0;
                if(ext>=ps){
                    printf("\nExternal: %d\n",ext);
                    for(a1=1;a1<=n;++a1){
                        if((r[a1]==0)&&(f2==0)){
                            printf("%d",a1);f2=1;continue;
                        }
                        if((r[a1]==1)&&(f2==1)){
                            f2=0;
                            printf(" %d\n",a1-1);
                        }
                        
                    }
                    if(r[n]==0){printf(" %d\n",n);}
                }
            
                    printf("Process to be deleted: ");
                    int del;
                    scanf("%d",&del);
                    for(a1=p[del][0];a1<=p[del][1];++a1)r[a1]=0;
                    p[del][0]=-1;
            }
            else break;
        }
        p[count][0]=store;
        p[count][1]=store+ps-1;
        for(a1=store;a1<=store+ps-1;++a1)r[a1]=1;
        printf("\nAssigned: %d to %d\n",store,store+ps-1);
        ++count;
    }

    return 0;
}
