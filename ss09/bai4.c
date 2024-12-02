#include <stdio.h>

#define MAX_SIZE 100

void displayArray(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void addElement(int arr[], int *length) {
    if (*length >= MAX_SIZE) {
        printf("Mang da day, khong the them phan tu moi.\n");
        return;
    }

    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (0 - %d): ", *length);
    scanf("%d", &position);

    if (position < 0 || position > *length) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *length; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*length)++;
    printf("Da them phan tu thanh cong.\n");
}

void editElement(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong, khong the sua.\n");
        return;
    }

    int position, newValue;
    printf("Nhap vi tri can sua (0 - %d): ", length - 1);
    scanf("%d", &position);

    if (position < 0 || position >= length) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    arr[position] = newValue;
    printf("Da sua phan tu thanh cong.\n");
}

void deleteElement(int arr[], int *length) {
    if (*length == 0) {
        printf("Mang rong, khong the xoa.\n");
        return;
    }

    int position;
    printf("Nhap vi tri can xoa (0 - %d): ", *length - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *length) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = position; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
    printf("Da xoa phan tu thanh cong.\n");
}

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Nhap so luong phan tu (toi da 100): ");
                int n;
                scanf("%d", &n);
                if (n > MAX_SIZE || n <= 0) {
                    printf("So luong phan tu khong hop le.\n");
                } else {
                    printf("Nhap cac phan tu:\n");
                    for (int i = 0; i < n; i++) {
                        printf("Phan tu thu %d: ", i + 1);
                        scanf("%d", &arr[i]);
                    }
                    currentLength = n;
                    printf("Da nhap mang thanh cong.\n");
                }
                break;
            }
            case 2:
                displayArray(arr, currentLength);
                break;
            case 3:
                addElement(arr, &currentLength);
                break;
            case 4:
                editElement(arr, currentLength);
                break;
            case 5:
                deleteElement(arr, &currentLength);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

