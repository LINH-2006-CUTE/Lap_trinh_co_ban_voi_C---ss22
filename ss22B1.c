
#include <stdio.h>
#include <string.h>

struct SinhVien {
    char id[50];
    char name[50];
    int age;
};

struct SinhVien sv[100];
int numberStudent = 0;

void loadFileSinhVien();
void printStudent();
void addStudent();
void saveStudent();
void updateStudent();
void deleteStudent();
void searchStudent();
void sortStudent();

int main() {
    loadFileSinhVien();

    int choose;
    do {
        printf("\nMENU\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choose);
        getchar(); // Clear input buffer

        switch (choose) {
            case 1:
                printStudent();
                break;
            case 2:
                addStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                searchStudent();
                break;
            case 6:
                sortStudent();
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Nhap lai.\n");
        }
    } while (choose != 7);

    return 0;
}

void loadFileSinhVien() {
    FILE *file = fopen("student.bin", "rb");
    if (file == NULL) {
        printf("Khong mo duoc file!\n");
        return;
    }
    numberStudent = fread(sv, sizeof(struct SinhVien), 100, file);
    fclose(file);
}

void printStudent(){
    if (numberStudent == 0){
        printf("Danh sach sinh vien trong!\n");
        return;
    }
    for (int i = 0; i < numberStudent; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        printf("ID: %s\n", sv[i].id);
        printf("Ten: %s\n", sv[i].name);
        printf("Tuoi: %d\n", sv[i].age);
    }
}

void addStudent(){
    if (numberStudent >= 100){
        printf("Danh sach da day!\n");
        return;
    }
    struct SinhVien sv1;

    printf("Nhap thong tin sinh vien:\n");
    printf("ID: ");
    fgets(sv1.id, sizeof(sv1.id), stdin);
    sv1.id[strcspn(sv1.id, "\n")] = '\0';

    printf("Ten: ");
    fgets(sv1.name, sizeof(sv1.name), stdin);
    sv1.name[strcspn(sv1.name, "\n")] = '\0';

    printf("Tuoi: ");
    scanf("%d", &sv1.age);
    getchar();

    sv[numberStudent++] = sv1;
    saveStudent();
    printf("Them sinh vien thanh cong!\n");
}

void saveStudent(){
    FILE *file = fopen("student.bin", "wb");
    if (file == NULL){
        printf("Khong luu duoc file!\n");
        return;
    }
    fwrite(sv, sizeof(struct SinhVien), numberStudent, file);
    fclose(file);
}

void updateStudent(){
    if (numberStudent == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }
    char id[50];
    printf("Nhap ID sinh vien can sua: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < numberStudent; i++){
        if (strcmp(id, sv[i].id) == 0){
            printf("Nhap ten moi: ");
            fgets(sv[i].name, sizeof(sv[i].name), stdin);
            sv[i].name[strcspn(sv[i].name, "\n")] = '\0';

            printf("Nhap tuoi moi: ");
            scanf("%d", &sv[i].age);
            getchar();

            saveStudent();
            printf("Cap nhat thong tin thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID: %s\n", id);
}

void deleteStudent(){
    if (numberStudent == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }
    char id[50];
    printf("Nhap ID sinh vien can xoa: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < numberStudent; i++){
        if (strcmp(id, sv[i].id) == 0) {
            for (int j = i; j < numberStudent - 1; j++){
                sv[j] = sv[j + 1];
            }
            numberStudent--;
            saveStudent();
            printf("Xoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID: %s\n", id);
}

void searchStudent(){
    if (numberStudent == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }
    char id[50];
    printf("Nhap ID sinh vien can tim: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < numberStudent; i++){
        if (strcmp(id, sv[i].id) == 0) {
            printf("Thong tin sinh vien tim thay:\n");
            printf("ID: %s\n", sv[i].id);
            printf("Ten: %s\n", sv[i].name);
            printf("Tuoi: %d\n", sv[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID: %s\n", id);
}

void sortStudent() {
    for (int i = 0; i < numberStudent - 1; i++){
        for (int j = i + 1; j < numberStudent; j++){
            if (strcmp(sv[i].id, sv[j].id) > 0){
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    saveStudent();
    printf("Sap xep thanh cong!\n");
}
    
	return 0;
}

