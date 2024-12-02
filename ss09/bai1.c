#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;  // So luong ph?n t? hi?n có trong m?ng
    int n, i, addValue, addIndex;

    // Bu?c 1: Nh?p s? lu?ng ph?n t? mu?n nh?p
    printf("Nhap so phan tu ban dau (toi da 100): ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n < 0) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }

    // Bu?c 2: Nh?p các ph?n t? vào m?ng
    printf("Nhap %d phan tu:\n", n);
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    currentLength = n;

    // Bu?c 3: Thêm ph?n t? m?i vào m?ng
    printf("Nhap gia tri can them: ");
    scanf("%d", &addValue);
    printf("Nhap vi tri can them (0 - %d): ", MAX_SIZE - 1);
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex >= MAX_SIZE) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    if (addIndex >= currentLength) {
        // N?u v? trí thêm >= currentLength
        arr[addIndex] = addValue;
        currentLength = addIndex + 1;
    } else {
        // N?u v? trí thêm < currentLength
        for (i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1];  // D?ch các ph?n t? sang ph?i
        }
        arr[addIndex] = addValue;
        currentLength++;
    }

    // Bu?c 4: In mang sau khi thêm phan tu
    printf("Mang sau khi them phan tu:\n");
    for (i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

