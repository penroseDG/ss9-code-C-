#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, indexToUpdate, newValue;

    printf("Nhap so luong phan tu cua mang (toi da 100): ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    printf("Nhap %d phan tu cua mang:\n", n);
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Nhap vi tri can sua (0 - %d): ", n - 1);
    scanf("%d", &indexToUpdate);

    if (indexToUpdate < 0 || indexToUpdate >= n) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[indexToUpdate] = newValue;

    printf("Mang sau khi sua:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

