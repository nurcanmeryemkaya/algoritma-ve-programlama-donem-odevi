#include <stdio.h> // printf scanf kullanmak icin gerekli kutuphane

int asal_mi(int x) {
    if (x < 2) //2'den kucuk sayilari aliriz cunku 0 ve 1 asal degildir
        return 0;

    for (int i = 2; i * i <= x; i++) { //sayinin karekokune kadar bolunmesi asalligini anlamak icin yeterlidir yani 2'den karekokune kadar bolunurse 0 bolunmezse 1'dir yani asaldir
        if (x % i == 0)
            return 0;
    }
    return 1;
}

int unlu_mu(char c) { //verilen char sesli mi degil mi diye bakar
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    char a, b;    // a 1 ve 3, b ise ortadaki 2. harftir
    int sayac = 0; // sartlari saglayan kac gecerli isim oldugunu sayar

    printf("Gecerli Isimler:\n");

    for (a = 'a'; a <= 'z'; a++) { //ilk harhi a'dan z'ye kadar tek tek dener

        for (b = 'a'; b <= 'z'; b++) { // ikinci harfi a'dan z'ye tek tek dener

            if ((unlu_mu(a) && !unlu_mu(b)) || (!unlu_mu(a) && unlu_mu(b))) {
                //bu kisim harflerden sadece bir tanesinin unlu olmasini saglar

                int ascii_toplam = a + b + a;
                //harflerin ASCII degerlerini toplar isimler uc harfli oldugu icin a + b+ a olur

                if (asal_mi(ascii_toplam)) {
                    sayac++; // Geçerli bir isim bulundu, sayacý artýr.

                    printf("%2d. %c%c%c\n", sayac, a, b, a); //%2d sayiyi 2 hanelik yer ayirip yazar sirali duzgun durmasi icin. %c%c%c ise uc karakteri yan yana yazarak ismini olusturmamizi saglar.
                }
            }
        }
    }

    printf("\nToplam gecerli isim sayisi: %d\n", sayac); //donguler bittikten sonra toplam kac tane oldugunu sayip yazdirir

    return 0; //programi bitirir.
}
