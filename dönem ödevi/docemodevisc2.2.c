#include <stdio.h>

int main() {
    int n;
    int sayac = 1;
    //ucgenin icine yazacagimiz sayinin 1'den baslayacagini soyler
    int i, j, bosluk;

    printf("Ucgenin satir sayisini (n) giriniz: ");
    scanf("%d", &n);//scanf içindeki &n ifadesi, kullanýcýdan alýnan verinin kaydedileceði deðiþkenin bellekteki adresini temsil eder.

    for (i = 1; i <= n; i++) {//dis dongu, her bir satiri temsil ediyor

        for (bosluk = 1; bosluk <= n - i; bosluk++) {
            printf(" ");
            //ic dpngu ucgenin eskenar gorunmesi icin. printf ise her satirin basina bosluk koyar satir arttikca bosluk azalir
        }

        for (j = 1; j <= i; j++) { //o satira kac yazi yazilacagini soyler, 1. satira 1 tane 2. satira 2 tane sayi atar
            printf("%d ", sayac); //mevcut sayiyi yazdirir
            sayac++; //1'er 1'er artirarak bir sonraki sayiya gecmeyi soyler
        }

        printf("\n");//satir bitince bi alt satira gecirir
    }

    return 0; //programi bitirir

}
