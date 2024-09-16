#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[20];
    int code;
    char job[20];
    int exp;
    int age;
};

struct employee emp[20];
int num = 0, max = 20;

void build() {
    int i;
    printf("Maksimum calisan sayisi : %d\n", max);
    printf("Lutfen calisan sayisini giriniz: ");
    scanf("%d", &num);

    if (num > max) {
        printf("Maksimum calisan sayisini astiniz. Calisan sayisi maksimum %d olabilir\n", max);
        num = max;
    }

    printf("Lutfen calisan bilgilerini giriniz\n");
    for (i = 0; i < num; i++) {
        printf("%d. calisan bilgilerini giriniz:\n", i + 1);
        printf("Ad: ");
        scanf("%s", emp[i].name);
        printf("Calisan ID: ");
        scanf("%d", &emp[i].code);
        printf("Meslek: ");
        scanf("%s", emp[i].job);
        printf("Tecrube (yil): ");
        scanf("%d", &emp[i].exp);
        printf("Yas: ");
        scanf("%d", &emp[i].age);
        printf("\n");
    }
}

void addEmployee() {
    if (num >= max) {
        printf("Calisan sayisi maksimuma ulasti, daha fazla calisan eklenemez.\n");
        return;
    }

    printf("Yeni calisan bilgilerini giriniz:\n");
    printf("Ad: ");
    scanf("%s", emp[num].name);
    printf("Calisan ID: ");
    scanf("%d", &emp[num].code);
    printf("Meslek: ");
    scanf("%s", emp[num].job);
    printf("Tecrube (yil): ");
    scanf("%d", &emp[num].exp);
    printf("Yas: ");
    scanf("%d", &emp[num].age);
    num++;
    printf("Yeni calisan basariyla eklendi.\n");
}

void deleteEmployee() {
    int id, i, found = 0;
    printf("Silmek istediginiz calisanin ID'sini giriniz: ");
    scanf("%d", &id);

    for (i = 0; i < num; i++) {
        if (emp[i].code == id) {
            found = 1;
            for (int j = i; j < num - 1; j++) {
                emp[j] = emp[j + 1];
            }
            num--;
            printf("Calisan basariyla silindi.\n");
            break;
        }
    }

    if (!found) {
        printf("Bu ID'ye sahip calisan bulunamadi.\n");
    }
}

void displayEmployee() {
    int id, i, found = 0;
    printf("Bilgilerini gormek istediginiz calisanin ID'sini giriniz: ");
    scanf("%d", &id);

    for (i = 0; i < num; i++) {
        if (emp[i].code == id) {
            printf("\nCalisan Bilgileri:\n");
            printf("Ad: %s\n", emp[i].name);
            printf("ID: %d\n", emp[i].code);
            printf("Meslek: %s\n", emp[i].job);
            printf("Tecrube: %d yil\n", emp[i].exp);
            printf("Yas: %d\n", emp[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Bu ID'ye sahip calisan bulunamadi.\n");
    }
}

void showMenu() {
    int option;

    while (1) {
        printf("\n\n---------------Calisan Yonetim Sistemi---------------\n\n");
        printf("1. Calisan tablosu olusturunuz\n");
        printf("2. Yeni calisan ekleyiniz\n");
        printf("3. Calisan siliniz\n");
        printf("4. Calisan bilgilerini getiriniz\n");
        printf("5. Cikis yapiniz\n");
        printf("Secim: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                build();
                break;
            case 2:
                addEmployee();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                displayEmployee();
                break;
            case 5:
                printf("Programdan cikiliyor...\n");
                exit(0);
            default:
                printf("Yanlis bir secim yaptiniz. Lutfen tekrar deneyiniz.\n");
        }
    }
}

int main() {
    showMenu();
    return 0;
}
