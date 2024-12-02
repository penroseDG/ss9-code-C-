#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Hàm ki?m tra s? nguyên t?
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm nh?p giá tr? vào m?ng
void inputArray(int arr[], int *length) {
    printf("Nhap so luong phan tu (toi da 100): ");
    scanf("%d", length);

    if (*length <= 0 || *length > MAX_SIZE) {
        printf("So luong phan tu khong hop le!\n");
        *length = 0; // Ð?t l?i chi?u dài n?u không h?p l?
        return;
    }

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *length; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

// Hàm in giá tr? m?ng
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

// Hàm in s? ch?n và tính t?ng
void displayEvenAndSum(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong.\n");
        return;
    }
    int sum = 0;
    printf("Cac phan tu chan: ");
    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac so chan: %d\n", sum);
}

// Hàm tìm giá tr? l?n nh?t và nh? nh?t
void findMinMax(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong.\n");
        return;
    }
    int min = arr[0], max = arr[0];
    for (int i = 1; i < length; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("Gia tri nho nhat: %d\n", min);
    printf("Gia tri lon nhat: %d\n", max);
}

// Hàm in s? nguyên t? và tính t?ng
void displayPrimesAndSum(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong.\n");
        return;
    }
    int sum = 0;
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < length; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac so nguyen to: %d\n", sum);
}

// Hàm d?m s? l?n xu?t hi?n c?a m?t giá tr?
void countOccurrences(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong.\n");
        return;
    }
    int value, count = 0;
    printf("Nhap gia tri can thong ke: ");
    scanf("%d", &value);
    for (int i = 0; i < length; i++) {
        if (arr[i] == value) count++;
    }
    printf("Gia tri %d xuat hien %d lan.\n", value, count);
}

// Hàm thêm ph?n t? vào v? trí ch? d?nh
void addElementAtPosition(int arr[], int *length) {
    if (*length >= MAX_SIZE) {
        printf("Mang da day, khong the them phan tu.\n");
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

int main() {
    int arr[MAX_SIZE];
    int currentLength = 0;
    int choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &currentLength);
                break;
            case 2:
                displayArray(arr, currentLength);
                break;
            case 3:
                displayEvenAndSum(arr, currentLength);
                break;
            case 4:
                findMinMax(arr, currentLength);
                break;
            case 5:
                displayPrimesAndSum(arr, currentLength);
                break;
            case 6:
                countOccurrences(arr, currentLength);
                break;
            case 7:
                addElementAtPosition(arr, &currentLength);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}

