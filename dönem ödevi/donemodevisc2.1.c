#include <stdio.h> // printf gibi temel komutlari kullanabilmek icin bu dosyayi "dahil" ediyoruz.

/* FONKSÝYON TANIMLAMA:
   Burada bilgisayara 'ucgenSayisi' adinda bir gorev ogretiyoruz.
   'int' yaziyoruz cunku bu gorev bize bir tam sayi sonucu verecek.
*/
int ucgenSayisi(int n) {

    // if (eger): Bilgisayara bir karar verme kurali koyuyoruz.
    // n == 1: "Eger sira 1 ise" demek. (cift esittir kontrol amaclidir)
    if (n == 1) { //ozyinelemeli fonk kullandik burada fonksiyon kendisini cagirip n den baslayip 1 e kadar azaltarak islem yapar
        return 1; //sonuc olarak 1 cevabini dondur ve islemi bitir
    }

    return n + ucgenSayisi(n - 1);
}

int main() { //bilgisayar okumaya buradan basliyor

    int N = 5; // Kaç tane üçgen sayýsý istediðimizi bir kutuya (N) koyduk.
    int i;    // Döngüde "kaçýncý turdayýz" diye saymak için bir sayaç hazýrladýk.

    printf("Ilk %d ucgen sayisi:\n", N); // %d yerine virgülden sonraki N sayýsý gelir.

       //for kullandik i = 1: i'yi 1'den baslat
       //i <= N: i, N sayisina ulasana kadar devam et
       //i++: Her tur bittiginde i'yi 1 artir
    for (i = 1; i <= N; i++) {
        printf("%d ", ucgenSayisi(i));
    }

    printf("\n"); //islem bitince bir alt satira gec
    return 0;    //programin sonlandigini ifade eder
}
