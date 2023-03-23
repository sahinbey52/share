#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct ogrenci
	{
		struct ogrenci *next;
		int numara;
		char isim_soyisim[];
	}NODE;
	
NODE *ilk=NULL, *son=NULL;

void ekle(int num, char isim[]);
void ara(int num);
void sil(int num);
void listele();

int main()
{
	setlocale(LC_ALL, "Turkish");
	
	ekle(123456,"Serpil Üstebay");
	ekle(123457,"Ayþe Gül");
	
	int secenek=0;
	char isim[30];
	int numara=0;
	
	do
	{
		secenek=0;
		numara=0;
		strcpy(isim,"");
		
		printf("\nLütfen yapmak istediðiniz iþlemi aþaðýdaki sayýlarý kullanarak belirtin.\n");
		printf("(1) Öðrenci ekleme\n");
		printf("(2) Öðrenci arama\n");
		printf("(3) Öðrenci silme\n");
		printf("(4) Öðrencileri listeleme\n");
		printf("(5) Çýkýþ\n");
		printf("Seçiminiz: ");
		
		scanf("%d",&secenek);
		
		switch (secenek)
		{
			case 1:
				printf("Eklemek istediðiniz öðrencinin numarasýný girin:\n");
				scanf("%d",&numara);
				printf("Eklemek istediðiniz öðrencinin isim ve soyismini girin:\n");
				fflush(stdin);
				gets(isim);
				ekle(numara,isim);
				printf("Kayýt tamamlandý.\n");
				break;
			case 2:
				printf("Aramak istediðiniz öðrencinin numarasýný girin:\n");
				scanf("%d",&numara);
				ara(numara);
				break;
			case 3:
				printf("Silmek istediðiniz öðrencinin numarasýný girin:\n");
				scanf("%d",&numara);
				sil(numara);
				break;
			case 4:
				listele();
				break;
			case 5:
				break;
			default:
				printf("Geçersiz bir seçenek girdiniz!\n");
		}
	}
	while (secenek!=5);
	
	
	return 0;
}

void ekle(int num, char isim[])
{
	if (ilk==NULL)
	{
		NODE *yeni=(NODE *)malloc(sizeof(NODE));
		yeni->numara=num;
		strcpy(yeni->isim_soyisim,isim);
		yeni->next=NULL;
		ilk=yeni;
		son=ilk;
	}
	else
	{
		NODE *yeni=(NODE *)malloc(sizeof(NODE));
		son->next=yeni;
		yeni->numara=num;
		strcpy(yeni->isim_soyisim,isim);
		son=yeni;
		son->next=NULL;
	}
}

void ara(int num)
{
	NODE *arama;
	arama=ilk;
	printf("Bulunan Sonuçlar:\n");
	int flag=0;
	while (arama!=NULL)
	{
		if (arama->numara==num)
		{
			printf("Ýsim-Soyisim: %s\nNumara: %d\n",arama->isim_soyisim,arama->numara);
			flag=1;
			break;
		}
		arama=arama->next;
	}
	if (flag==0)
	printf("Herhangi bir kayýt bulunamadý!\n");
}

void sil(int num)
{
	NODE *simdiki=ilk;
	NODE *onceki=NULL;
	int flag=0;
	while (simdiki!=NULL)
	{
		if (simdiki->numara==num)
		{
			flag=1;
			if (onceki==NULL)
			{
				ilk=simdiki->next;
				free(simdiki);
				break;
			}
			else if (simdiki->next==NULL)
			{
				onceki->next=NULL;
				son=onceki;
				free(simdiki);
				break;
			}
			else
			{
				onceki->next=simdiki->next;
				free(simdiki);
				break;
			}
		}
		onceki=simdiki;
		simdiki=simdiki->next;
	}
	if (flag==1)
	printf("Silme iþlemi baþarýyla gerçekleþti.\n");
	else
	printf("Kayýt bulunamadý!\n");
}

void listele()
{
	NODE *liste=ilk;
	printf("Kayýtlý Öðrenciler\nNumara\tÝsim-Soyisim\n\n");
	while (liste!=NULL)
	{
		printf("%d\t%s\n",liste->numara,liste->isim_soyisim);
		liste=liste->next;
	}
}

