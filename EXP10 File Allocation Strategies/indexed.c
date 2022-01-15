#include <stdio.h>
#include <string.h>
struct File{
    char file_name[10];
    int index_block;
    int total_blocks;
    int blocks_allocated[10];
}f[50];

int main(){
    int block[200];
    for(int i = 0; i < 200; i++){
        block[i] = 0;
    }
    int choice = 1, k = 0;
    do{
        char name[10];
        printf("Enter the name of the file: ");
        scanf("%s", name);
        int ind;
        printf("Enter the index block: ");
        scanf("%d", &ind);
        if(block[ind]) {
            printf("File not allocated!\n");
        }else{
            block[ind] = 1;
            int n;
            printf("Enter number of blocks to allocate: ");
            scanf("%d", &n);
            int b[n];
            printf("Enter the block numbers: ");
            for(int i = 0; i < n; i++){
                scanf("%d", &b[i]);
            }
            int flag = 1;
            for(int i = 0; i < n; i++){
                if(block[b[i]]){
                    flag = 0;
                    break;
                }
            }
            if(!flag){
                printf("File not allocated!\n");
            }else{
                printf("File allocated!\n");
                for(int i = 0; i < n; i++){
                    block[b[i]] = 1;
                    f[k].blocks_allocated[i] = b[i];
                }
                strcpy(f[k].file_name, name);
                f[k].index_block = ind;
                f[k].total_blocks = n;
                k++;
            }
        }
        printf("Enter 1 to allocate more files: ");
        scanf("%d", &choice);
    }while(choice == 1);
    do{
        char name[10];
        printf("Enter the name of the file to be searched: ");
        scanf("%s", name);
        int found = 0;
        for(int i = 0; i < k; i++){
            if(strcmp(name, f[i].file_name) == 0){
                found = 1;
                printf("File found!\n");
                printf("Index block: %d\n", f[i].index_block);
                for(int j = 0; j < f[i].total_blocks; j++){
                    printf("%d ", f[i].blocks_allocated[j]);
                }
                printf("\n");
                break;
            }
        }
        if(!found){
            printf("File not found!\n");
        }
        printf("Enter 1 to search more files: ");
        scanf("%d", &choice);
    }while(choice == 1);
}