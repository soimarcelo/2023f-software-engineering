#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int size, int target){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(void){
    int size = 1000000;
    int *arr = (int *)malloc(size * sizeof(int));
    int target_index = 500000;
    int i;

    srand(time(NULL));
    arr[0] = rand() % 10;
    
    // 前の項に乱数を足したものを配列に格納していく
    for(i = 0; i < size; i++){
        arr[i] = arr[i-1]+rand()%10;
    }

    int target = arr[target_index -1];
    int result = binary_search(arr, size, target);
    if (result != -1){
        printf("ターゲットを左から%d番目に発見しました\n", result + 1);
    } else {
        printf("ターゲットは与えられた配列の中にはありませんでした\n");
    }

    free(arr);

    return 0;
}