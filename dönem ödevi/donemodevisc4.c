#include <stdio.h> //printf scanf kullanmak icin gerekli kutuphane
#include <string.h> //metin uzunlugunu olcmek icin gerekli kutuphane

int main() {

    char mesaj[100]; // kullanicidan alacagimiz veri icin hafizada 100 karakterlik bir alan acar
    int anahtar; //int tam sayi oldugunu ifade eder

    int i; // i dongude kacinci harfte oldugumuzu saymak icin bir sayactir

    printf("Sifrelenecek mesaji giriniz (sadece kucuk harf): "); //ekrana yazi yazdirir

    fgets(mesaj, sizeof(mesaj), stdin); // scanf yerine fgets kullaniyoruz. Bosluklar dahil tum satiri okumasi icin fgetsi kullandik.

    printf("Anahtar (kaydirma) miktarini giriniz: ");

    scanf("%d", &anahtar); //& adres belirtir. &anahtar da girilen sayiyi adrese goturur

    for (i = 0; i < strlen(mesaj); i++) { //strlen(mesaj) mesajin kac harften olustugunu sayar

        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') { //sadece a ve z arasindaki harfleri sifrelememizi soyler???????????

            mesaj[i] = (mesaj[i] - 'a' + anahtar) % 26 + 'a'; //harfin alfabedeki yerini bulur ve anahtar deger kadar kaydirir eger z gelirse tekrar basa doondurmek icin %26 ifadesini kullandik
        }
    }

    printf("Sifrelenmis Yeni Mesaj: %s\n", mesaj); //%s bir metni ekrana yazdirmak icin kullanilir

    for (i = 0; i < strlen(mesaj); i++) {
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {

            mesaj[i] = (mesaj[i] - 'a' - anahtar + 26) % 26 + 'a'; //+26 ekleme sebebimiz cikarma yapinca sayi negatif gelirse program rastgele degerler vermesin, alfabe cemberinde donsun diye.
        }
    }

    printf("Orijinal Mesaj: %s\n", mesaj);

    return 0; //programý bitirir
}
