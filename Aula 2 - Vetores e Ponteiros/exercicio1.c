#include <stdio.h>

void menor_maior(int* menor, int* maior, int* nums, int n) {

    *maior = nums[0], *menor = nums[0];
    for(int i = 1; i < n; i++) {
        if(nums[i] > *maior) {
            *maior = nums[i];
        } else if(nums[i] < *menor) {
            *menor = nums[i];
        }
    }

}

int main() {
    int n = 0;
    scanf("%d", &n);
    int nums[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int menor, maior;
    menor_maior(&menor, &maior, nums, n);

    printf("%d %d\n", menor, maior);

    return 0;
}
