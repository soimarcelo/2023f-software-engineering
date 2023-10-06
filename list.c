#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
    struct list *next;
    int data;
};

int main(){
    struct list *head = NULL;
    struct list *current = NULL;

    for(int i = 1; i <= 100; i++){
        struct list *new_node = malloc(sizeof(struct list));
        if(!new_node){
            printf("メモリ確保に失敗しました\n");
            return 1;
        }
        new_node->data = i;
        new_node->next = NULL;

        if(head == NULL){
            head = new_node;
            current = new_node;
        }else{
            current->next = new_node;
            current = new_node;
        }
    }
    current = head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");

    current = head;
    while(current != NULL){
        struct list *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}