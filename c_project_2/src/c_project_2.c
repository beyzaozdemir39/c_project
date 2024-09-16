#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
	char book_name[20];
	char author[20];
	int pages;
	float price;
};

int main() {

	struct library lib[100];
	int i = 0, input = 0;

	while(input != 5){
		printf("\n\n******######Kutuphane Yonetim Sistemi######******\n\n\n");
		printf("1. Kitap Bilgisi Ekleyiniz \n");
		printf("2. Kitap Bilgilerini Goster \n");
		printf("3. Yazara Ait Tum Kitaplari Listele \n");
		printf("4. Kutuphanedeki Toplam Kitap Sayisini Goster \n");
		printf("5. Cikis \n");

		printf("\nLutfen seciminizi yapiniz: ");
		scanf("%d", &input);

		switch(input) {
			case 1:
				printf("Kitabın adını giriniz: ");
				scanf("%s", lib[i].book_name);
				printf("Kitabın yazarını giriniz: ");
				scanf("%s", lib[i].author);
				printf("Kitabın sayfa sayısını giriniz: ");
				scanf("%d", &lib[i].pages);
				printf("Kitabın fiyatını giriniz: ");
				scanf("%f", &lib[i].price);
				i++;
				break;

			case 2:
				printf("\nKitap Listesi:\n");
				for (int j = 0; j < i; j++) {
					printf("Kitap Adı: %s, Yazar: %s, Sayfa Sayısı: %d, Fiyat: %.2f\n",
						lib[j].book_name, lib[j].author, lib[j].pages, lib[j].price);
				}
				break;

			case 3: {
				char author[20];
				printf("Yazarı giriniz: ");
				scanf("%s", author);
				int found = 0;
				printf("\n%s yazarına ait kitaplar:\n", author);
				for(int j = 0; j < i; j++){
					if(strcmp(author, lib[j].author) == 0){
						printf("Kitap ismi: %s\n", lib[j].book_name);
						found = 1;
					}
				}
				if (!found) {
					printf("Bu yazara ait kitap bulunamadı.\n");
				}
				break;
			}

			case 4:
				printf("\nToplam Kitap Sayısı: %d\n", i);
				break;

			case 5:
				exit(0);

			default:
				printf("Lütfen geçerli bir seçim yapınız.\n");
		}
	}

	return 0;
}
