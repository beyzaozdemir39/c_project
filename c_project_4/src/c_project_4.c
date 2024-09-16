#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hospital {
    char name[50];
    char city[50];
    int beds;
    float price;
    float rating;
    int reviews;
};

struct Patient {
    char name[50];
    int age;
};

void printHospitals(struct Hospital hospitals[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Hastane Adi: %s, Sehir: %s, Yatak Sayisi: %d, Fiyat: %.2f, Puan: %.1f, Yorum Sayisi: %d\n",
               hospitals[i].name, hospitals[i].city, hospitals[i].beds, hospitals[i].price, hospitals[i].rating, hospitals[i].reviews);
    }
}

void printPatients(struct Patient patients[][3], int hospitalIndex) {
    printf("Hastanedeki Hastalar:\n");
    for (int i = 0; i < 3; i++) {
        printf("Hasta Adi: %s, Yasi: %d\n", patients[hospitalIndex][i].name, patients[hospitalIndex][i].age);
    }
}

void sortHospitalsByPrice(struct Hospital hospitals[], int size) {
    struct Hospital temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (hospitals[j].price > hospitals[j + 1].price) {
                temp = hospitals[j];
                hospitals[j] = hospitals[j + 1];
                hospitals[j + 1] = temp;
            }
        }
    }
    printf("\nHastaneler Fiyata Gore Siralandi:\n");
    printHospitals(hospitals, size);
}

void sortHospitalsByBeds(struct Hospital hospitals[], int size) {
    struct Hospital temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (hospitals[j].beds < hospitals[j + 1].beds) {
                temp = hospitals[j];
                hospitals[j] = hospitals[j + 1];
                hospitals[j + 1] = temp;
            }
        }
    }
    printf("\nHastaneler Yatak Sayisina Gore Siralandi:\n");
    printHospitals(hospitals, size);
}

void sortHospitalsByName(struct Hospital hospitals[], int size) {
    struct Hospital temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(hospitals[j].name, hospitals[j + 1].name) > 0) {
                temp = hospitals[j];
                hospitals[j] = hospitals[j + 1];
                hospitals[j + 1] = temp;
            }
        }
    }

    printf("\nHastaneler Ada Gore Siralandi:\n");
    printHospitals(hospitals, size);
}

void sortHospitalsByRating(struct Hospital hospitals[], int size) {
    struct Hospital temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (hospitals[j].rating < hospitals[j + 1].rating ||
                (hospitals[j].rating == hospitals[j + 1].rating && hospitals[j].reviews < hospitals[j + 1].reviews)) {
                temp = hospitals[j];
                hospitals[j] = hospitals[j + 1];
                hospitals[j + 1] = temp;
            }
        }
    }
    printf("\nHastaneler Puan ve Yorum Sayisina Gore Siralandi:\n");
    printHospitals(hospitals, size);
}

void printHospitalsByCity(struct Hospital hospitals[], int size, char city[]) {
    printf("\n%s Sehirdeki Hastaneler:\n", city);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(hospitals[i].city, city) == 0) {
            printf("Hastane Adi: %s, Sehir: %s, Yatak Sayisi: %d, Fiyat: %.2f, Puan: %.1f, Yorum Sayisi: %d\n",
                   hospitals[i].name, hospitals[i].city, hospitals[i].beds, hospitals[i].price, hospitals[i].rating, hospitals[i].reviews);
            found = 1;
        }
    }
    if (!found) {
        printf("Bu sehirde hastane bulunamadi.\n");
    }
}

int main() {

    int choice;
    struct Hospital hospitals[5] = {
        {"Can", "Istanbul", 100, 250.0, 4.5, 100},
        {"Balkan", "Ankara", 150, 200.0, 4.2, 80},
        {"Balbadem", "Istanbul", 200, 180.0, 4.0, 120},
        {"Edikol", "Izmir", 80, 300.0, 4.8, 90},
        {"Mekol", "Ankara", 120, 220.0, 4.6, 110}
    };

    struct Patient patients[5][3] = {
        {{"Osman", 35}, {"Hakan", 45}, {"Elif", 28}},
        {{"Can", 35}, {"Kerem", 45}, {"Mazlum", 28}},
        {{"Zafer", 35}, {"Melis", 45}, {"Fulya", 28}},
        {{"Mert", 35}, {"Asli", 45}, {"Beyza", 28}},
        {{"Ada", 35}, {"Celil", 45}, {"Ozan", 28}}
    };

    do {
        printf("\n\n\n*************** Hastane Yönetim Sistemi ***************\n\n\n");
        printf("1. Hastane Bilgilerini Bastir\n");
        printf("2. Hasta Bilgilerini Bastir\n");
        printf("3. Hastaneleri Gunluk Kalma Ucretine Gore Sirala\n");
        printf("4. Hastaneleri Yatak Sayisina Gore Sirala\n");
        printf("5. Hastaneleri Adina Gore Sirala\n");
        printf("6. Hastaneleri Puanina ve Yorum Sayisina Gore Sirala\n");
        printf("7. Girilen Sehirdeki Hastaneleri Bastir\n");
        printf("8. Cikis Yap\n");

        printf("Seciminizi Yapiniz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printHospitals(hospitals, 5);
                break;
            case 2: {
                int hospitalIndex;
                printf("Hasta bilgilerini bastirmak istediginiz hastanenin numarasini giriniz (1-5): ");
                scanf("%d", &hospitalIndex);
                if (hospitalIndex >= 1 && hospitalIndex <= 5) {
                    printPatients(patients, hospitalIndex - 1);
                } else {
                    printf("Gecersiz hastane numarasi.\n");
                }
                break;
            }
            case 3:
                sortHospitalsByPrice(hospitals, 5);
                break;
            case 4:
                sortHospitalsByBeds(hospitals, 5);
                break;
            case 5:
                sortHospitalsByName(hospitals, 5);
                break;
            case 6:
                sortHospitalsByRating(hospitals, 5);
                break;
            case 7: {
                char city[50];
                printf("Hastaneleri listelemek istediginiz sehri giriniz: ");
                scanf("%s", city);
                printHospitalsByCity(hospitals, 5, city);
                break;
            }
            case 8:
                printf("Programimiz sonlandi.\n");
                break;
            default:
                printf("Gecersiz secim, lutfen tekrar deneyin.\n");
        }
    } while (choice != 8); // Eksik noktalı virgül düzeltildi

    return 0;
}
