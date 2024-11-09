#include <stdio.h>

int main(){
    int a[5], b[20], idx = 0, size = 1, count = 0, n, hit = 0;
    char f = 'F';
    
    printf("enter no, of pages : ");
    scanf("%d", &n);
    printf("\n");
    
    printf("enter %d page numbers : ", n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    
    printf("\n");
    
    printf("page \t frames \t status\n");
    
    for(int i = 0; i < n; i++){
        hit = 0;
        
        for(int j = 0; j < size; j++){
            if(b[i] == a[j]){
                hit = 1;
                break;
            }
        }
        
        if(hit == 0){
            if(idx >= 3){
                idx = 0;
            }
            a[idx] = b[i];
            idx++;
            if(size < 3){
                size = idx;
            }
            
            printf("%d\t", b[i]);
            for(int j = 0; j < size; j++){
                printf("%d",a[j]);
            }
            printf("--> %c\n", f);
            
            count++;
        }
        else{
            printf("%d\t", b[i]);
            for(int j = 0; j < size; j++){
                printf("%d",a[j]);
            }
            printf("\n");
        }
        
    }
    printf("total pages faults : %d", count);
    
    return 0;
}