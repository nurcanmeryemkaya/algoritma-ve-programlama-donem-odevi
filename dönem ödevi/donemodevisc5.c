#include <stdio.h> //printf scanf gibi araclari kullanmamiz icin gereken kutuphane
#include <stdbool.h> //bu kutuphane de dogru yanlis anahtar kelimelerini kullanmamiz icindir

#define B 5 //labirent boyutu olusturduk 5'e 5'lik

int L[B][B] = { //bu kisim labirentin yapisidir 1'ler yollari 0'lar ise duvari ifade eder
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

int C[B][B] = {0}; //C cozum yoludur gecilen yerler 1 yapilacak

bool coz(int x, int y) {
    if (x < 0 || y < 0 || x >= B || y >= B || L[x][y] == 0 || C[x][y] == 1)
    //burda da labirentten saf disi edildiyse duvarla karsilasildiysa veya ziyaret edilmis bir yola tekrar gelinirse o kismi birakir
        return false;

    C[x][y] = 1; //mevcut hucreyi de yola dahil eder

    if (x == B - 1 && y == B - 1) //eger hedefe ulasildiysa fonksiyon son bulur
        return true;

    if (coz(x + 1, y) || coz(x, y + 1) || coz(x - 1, y) || coz(x, y - 1))
    //burda da sirayla 1 adim olacak sekilde asagi, sag, yukari ve sola gitmeyi dener
        return true;

    C[x][y] = 0; //hicbir yon cikisa gitmiyorsa calisir
    return false;

}

int main() {
    if (coz(0, 0)) { // (0,0)dan aramayi baslatir
        printf("Cikis yolu bulundu:\n");
        for (int i = 0; i < B; i++) {
            for (int j = 0; j < B; j++) {
                printf("%d ", C[i][j]); // cozum matrisini yazdirir
            }
            printf("\n");
        }
    } else {
        printf("Cikis yolu yok..\n");
    }
    return 0; //programi bitirir
}
