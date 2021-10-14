#include <stdio.h>
#define maxn 1000
struct aaaaaaaa{
    char c[5];
    int r1, c1, r2, c2;
    int a, x[20];
} cmds[maxn];
int r, c, n;
int simulate(int * r0,int * c0){
    int i,j;
    for(i = 0;i < n;i++){
        if(cmds[i].c[0] == 'E'){
            if(cmds[i].r1 == * r0 && cmds[i].c1 == * c0){
                * r0 = cmds[i].r2;
		* c0 = cmds[i].c2;
            }
            else if(cmds[i].r2 == * r0 && cmds[i].c2 == * c0){
                * r0 = cmds[i].r1;
		* c0 = cmds[i].c1;
            }        
        } 
	else{
            int r1, c1; r1 = c1 = 0;
            for(j = 0; j < cmds[i].a; j++){
                if(cmds[i].c[0] == 'I'){
                    if(cmds[i].c[1] == 'R'){
                        if(cmds[i].x[j] <= * r0) r1++;
                    }else{
                        if(cmds[i].x[j] <= * c0) c1++;
                    }
                }else if(cmds[i].c[0] == 'D'){
                    if(cmds[i].c[1] == 'R'){
                        if(cmds[i].x[j] == * r0) return 0;
                        if(cmds[i].x[j] < * r0) r1--;
                    } else{
                        if(cmds[i].x[j] == * c0) return 0;
                        if(cmds[i].x[j] < * c0) c1--;
                    }   
                }
            }
            * r0 += r1; 
	    * c0 += c1;
        }
    }
    return 1;
}
int main(void){
    int r0,c0,q,kase=0,i,j;
    while(scanf("%d%d%d", &r, &c, &n) == 3 && r){
        if(kase++) printf("\n");
        printf("Spreadsheet #%d\n", kase);
        for(i = 0;i < n;i++){
            scanf("%s", cmds[i].c);
            if(cmds[i].c[0] == 'E'){
                scanf("%d%d%d%d", &cmds[i].r1, &cmds[i].c1, &cmds[i].r2, &cmds[i].c2);
            }
	    else {
                scanf("%d", &cmds[i].a);
                for(j = 0; j < cmds[i].a;j++){
                    scanf("%d",&cmds[i].x[j]);
                }
            }
        }
        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &r0, &c0);
            printf("Cell data in (%d,%d) ", r0, c0);
            if(!simulate(&r0,&c0)) printf("GONE\n");
            else printf("moved to (%d,%d)\n", r0, c0);
        }
    }
    return 0;
}
