#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Oyun sonucu döndürür: 0 -> Beraberlik, 1 -> Kazandın, -1 -> Kaybettin
int determineWinner(char userChoice, char computerChoice) {
    if (userChoice == computerChoice) {
        return 0;  // Beraberlik
    }

    // Taş (T) -> Makas (M) Kazanır
    if (userChoice == 'T' && computerChoice == 'M') {
        return 1;
    } else if (userChoice == 'M' && computerChoice == 'T') {
        return -1;
    }

    // Kağıt (K) -> Taş (T) Kazanır
    if (userChoice == 'K' && computerChoice == 'T') {
        return 1;
    } else if (userChoice == 'T' && computerChoice == 'K') {
        return -1;
    }

    // Makas (M) -> Kağıt (K) Kazanır
    if (userChoice == 'M' && computerChoice == 'K') {
        return 1;
    } else if (userChoice == 'K' && computerChoice == 'M') {
        return -1;
    }

    return 0;  // Hatalı girişler için varsayılan olarak beraberlik dönüyoruz
}

char getComputerChoice() {
    int random = rand() % 3;  // 0, 1 veya 2 üret
    switch (random) {
        case 0:
            return 'T';  // Taş
        case 1:
            return 'K';  // Kağıt
        case 2:
            return 'M';  // Makas
    }
    return 'T';  // Varsayılan olarak taş döndür
}

void printChoice(char choice) {
    if (choice == 'T') {
        printf("Taş");
    } else if (choice == 'K') {
        printf("Kağıt");
    } else if (choice == 'M') {
        printf("Makas");
    }
}

int main() {
    char userChoice, computerChoice;
    int result;

    srand(time(0));  // Rastgele seçim için zaman tohumunu kullan

    // Kullanıcıdan giriş al
    printf("Lütfen seçiminizi yapın (T: Taş, K: Kağıt, M: Makas): ");
    scanf(" %c", &userChoice);

    // Bilgisayarın rastgele seçimi
    computerChoice = getComputerChoice();

    // Sonucu belirle
    result = determineWinner(userChoice, computerChoice);

    // Seçimleri ve sonucu göster
    printf("\nSiz ");
    printChoice(userChoice);
    printf(" seçtiniz. Bilgisayar ");
    printChoice(computerChoice);
    printf(" seçti.\n");

    // Kazanma, kaybetme veya beraberlik durumu
    if (result == 0) {
        printf("Beraberlik!\n");
    } else if (result == 1) {
        printf("Tebrikler, kazandınız!\n");
    } else {
        printf("Maalesef, kaybettiniz.\n");
    }

    return 0;
}
