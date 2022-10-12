#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 50
#define MAX_LINE 100

int pair_finder(int length_list, char list[], int target) {
    int x = length_list, y = 0;
    
    for (int x = length_list; x >= 0 ; x--) {
        for (int y = 0; y < length_list; y++) {
            if (list[x] >= target || list[y] >= target) {
                continue;
            }
            if (list[x] == list[y]) {
                continue;
            }
            if (list[x] + list[y] == target) {
                printf("[%d, %d]\n", x, y);
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char list[MAX_LINE] = {0};
    int num = 0, target, input_num;

    printf("Target: ");
    scanf("%d", &target);
    fflush(stdin);

    do {
        printf("\nInput Number: ");
        scanf("%d", &input_num);
        fflush(stdin);
        if (input_num != 0) {
            list[num] = input_num;
            num++;
        }
    } while (input_num != 0);

    int length_list = num;

    printf("Your list: ");
    
    for (int i = 0; i < length_list; i++) {
        printf("%d, ", list[i]);
    }
    printf("\n");

    int x = length_list, y = 0;
    
    if (pair_finder(length_list, list, target) == 1) {
        printf("\ncould not find a pair\n");
    }
    printf("\n");
    
    system("pause");
    return 0;
}