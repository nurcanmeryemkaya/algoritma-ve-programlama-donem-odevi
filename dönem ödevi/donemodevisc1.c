//Ýlk basta kutuphanelerimiz ekliyoruz. Kutuphaneler birden cok islevli islemler icin kurulmus hazir kod depolaridir.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//stdio.h ekrana yazi yazdirmak icin kullanilir. printf ve scanf gibi araclari kullanmak icin sarttir.
//stdlib.h Rastgele sayi uretmek ve ayni zamanda hafiza yonetimi, programin kontrolu icin sarttir.
//time.h bilgisayar saatine erisimi saglar ayni zamanda programi her calistirdigimizda birbirinden farkli sayilar vermesini saglar.
int main() {
    //int main kodun okunmaya basladigi kisimdir ve ilgili kodlar buradan yonetilir.
    int cirolar[12];
    //int yani integer'ý ise tam sayilari kullanirken kullaniriz. cirolar[12] deme sebebimiz ise 12 bize aylari temsil eder. ciro1, ciro2, ciro3 ... ciro12 gibi 12 tane deger tanimlamak yerine dizileri kullanarak kodumuzu daha kisa ve efektif kullanabiliriz.
char *aylar[] = {"Oca", "Sub", "Mar", "Nis", "May", "Haz", "Tem", "Agu", "Eyl", "Eki", "Kas", "Ara"};
    //char, characterin kisaltimidir. char'i da aylari belirtirken 1, 2, 3 gibi rakam yerine ay isimlerini kullandigimiz icin kullanacagiz.
    int i, j;
    //i ve j bizim sayaclarimiz. Bunlarla dongude kacinci adimda oldugumuzu anliyoruz. i'yi ana dongude j'yi ise ic ice dongude kullanacagiz. Yani mesela hangi ayin satirina kac tane * koyacagimizi belirleyecek.
    srand(time(NULL));
    //srand(time(NULL)) komutunu rastgele secim yapmak için kullaniyoruz. Bu komut bilgisayarin o an sahip oldugu saate gore farkli bir rastgele sayi verir. Bu komutu kullanmazsak hep ayni "rastgele" sayiyi verir bize.
    printf("--- STARTUP AYLIK CIRO VERILERI ---\n");
    //printfi ekrana yazi yazdirmak icin kullaniriz. Sondaki \n ise "bir alt satira gec" demektir.

    for (i = 0; i < 12; i++) {
        //for bir dongudur, kisaca bilgisayara verilen komutu tamamlanana kadar otomatik olarak yap der. Soruda da aylari tek tek gezmek icin ve her ay için grafik islemini tekrarlamak amaciyla kullanilmistir.
        //Bu satir bilgisayara verilen isi 12 kez tekrarlamasini soyler. i = 0 donguye 0'dan baslamasini soyler. i < 12 ise i sayisinin 12'den kucuk oldugu her sayida devam etmesini soyler. i++ kismi ise her adim sonunda i sayisini 1 artirmamizi soyler.
        //rand() % 10: 0 ile 9 arasi sayi üretir. + 1 ekleyince 1 ile 10 arasi olur.
        cirolar[i] = (rand() % 10) + 1;
        //Bu kisim sayi uretmek icin. rand() bilgisayardan rastgele buyuk bir sayi istiyor %10 ise bu sayiyi 10'a bolup kalanini aliyor ve kalan da 0 ile 9 arasinda oldugu icin sifir cikmasin diye 91 ekliyoruz. Bu sekilde sonuc kesin olarak hep 1 ile 10 arasinda olur.
        // %s metin (ay adi), %d tam sayi (ciro) basmak icin yer tutucudur.
        printf("%s: %dK  ", aylar[i], cirolar[i]);
        //printf ekrana yazi yazdirma komutudur. %s ifadesi yazi/metin gelecegini ifade eder yani Ocak, Subat... %d ise tam sayi yer tutucusudur. K ifadesi 1000 yerine geciyor daha toplu gorunmesi icin K olarak girdim.
    }
    printf("\n\n"); //\n\n Ýki kez alt satira gecerek bosluk birakir.

    printf("SEKIL 1: YATAY BAR GRAFIGI \n\n");

    for (i = 0; i < 12; i++) {
        //Buradaki for mantigi ust kisimda acikladigim ile ayni.
        printf("%s (%2dK) | ", aylar[i], cirolar[i]);
        //ic ice dongu ayin cirosu kac ise o kadar yildiz (*) koyar.
        for (j = 0; j < cirolar[i]; j++) {
            printf("*"); //Yan yana yildiz basar.
        }
        printf("\n"); //Yildizlar bitince sonraki aya gecmek icin alt satira iner.
    }
    printf("\n");

printf("--- SEKIL 2: DIKEY BAR GRAFIGI ---\n\n");
//printf basligi yazdirir. \n\n 2 satir asagiya indirir.

for (i = 10; i >= 1; i--) {
    //Bu dongu 10'dan baslar, i-- 1'er 1'er azaldigini ifade eder 10'dan geriye.

    printf("     ");
    //Satirin en basina bosluk koyar ve grafik sola yapismasin, ortali anlasilir durmasini saglar.

    for (j = 0; j < 12; j++) {
        //Bu dongu her ay icin * basilacak mi diye kontroller. Her 12 ayi da gezer.

        if (cirolar[j] >= i) {
            //Eger ayin cirosu satir seviyesinden büyükse veya esitse * basar.

            printf("  * ");
            //Ortada 1 tane * basar, 4 karakter kullaniyor hizali durmasi icin.
        } else {

            printf("    ");
            // Eger yildiz basilmayacaksa yine 4 bosluk basilmasini saglar hizanin bozulmamasi ve anlasilir olmasi icin.
        }
    }

    printf("\n");
    //Satir tamamlandiktan sonra bir alt satira gecmeyi saglar.
}

// Alt kisim: Ay numaralarini (1, 2, 3, ..., 12) seklinde yazdirir.

printf("       ");
//Grafik ve sayilarin hizali olmasý icin bosluk biraktik.

// 1’den 12’ye kadar sayilari yazdiran dongu
for (i = 1; i <= 12; i++) {

    printf("%-4d", i);
    //Sayiyi yazdirip sag kismini boslukla doldurur, 1 ve 10 ayni hizada durur yine 4 karakterlik yer kapladýgý icin.
}

printf("\n");
// En sona gelince alt satira gecmeyi saglar \n.

    return 0; // Programi sonlandirir.
}
