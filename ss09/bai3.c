#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;  
    int n, i, deleteIndex;

    printf("Nhap so phan tu ban dau (toi da 100): ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

   
    printf("Nhap %d phan tu:\n", n);
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    
    printf("Nhap vi tri can xoa (0 - %d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

 
    for (i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1];  
    }
    currentLength--;  


    printf("Mang sau khi xoa:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

