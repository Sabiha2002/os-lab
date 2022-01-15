#include <stdio.h>
#include <string.h>
struct File{
    char file_name[10];
    int start_block, no_of_blocks;
}f[50];

int main(){
    int block[200];
    for(int i = 0; i < 200; i++){
        block[i] = 0;
    }
    int choice = 1;
    int k = 0;
    do{
        char name[10];
        int s, l;
        printf("Enter the name of the file: ");
        scanf("%s", name);
        printf("Enter the start block: ");
        scanf("%d", &s);
        printf("Enter the number of blocks to allocate: ");
        scanf("%d", &l);
        int flag;
        for(int i = 0; i < l; i++){
            flag = 1;
            if(block[s+i]){
                flag = 0;
                break;
            }
        }
        if(!flag){
            printf("File not allocated\n");
        }else{
            for(int i = 0; i < l; i++){
                block[s+i] = 1;
            }
            strcpy(f[k].file_name, name);
            f[k].start_block = s;
            f[k].no_of_blocks = l;
            printf("File allocated\n");
            k++;
        }
        printf("Enter 1 if you want to allocate more files: ");
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
                printf("File found\n");
                printf("Start block: %d\n", f[i].start_block);
                printf("Blocks allocated are: ");
                for(int j = 0; j < f[i].no_of_blocks; j++){
                    printf("%d ", f[i].start_block + j);
                }
                printf("\n");
            }
        }
        if(!found){
            printf("File not found.\n");
        }
        printf("Enter 1 to search more files: ");
        scanf("%d", &choice);
    }while(choice == 1);
}