#include <stdio.h>
#include <stdlib.h>
//Aleyna Erarslan
//Bu kodda, verilen matrisin her bir h�cresi gezilerek, bulunan 1 h�creleri �zerinde dikey ve yatay y�nde biti�ik di�er 1 h�crelerini bulunur ve b�ylece bir ada tespit edilir. 
//Her adan�n alan� hesaplan�r ve bulunan t�m adalar�n alanlar� kar��la�t�r�larak en b�y�k ada bulunur. Bu adan�n alan� ekrana yazd�r�l�r.

int main() {
    int m, n; //matrixte m=satir , n=sutun sayisini tutacak
    
    printf("satir ve sutun sayisini girin: ");
    scanf("%d %d", &m, &n);  //orne�in 2 3 sayilar� girildiyse bu matris 2 sat�r 3 sutundan olu�an say�lardan meydana gelecektir.
    // matrisin de�erleri 1 ise kara 0 ise denizi temsil etmekteydi
    // �rne�e g�re bir matris yazacak olursak mesela: {1,0,1},
    //                                                {0,1,1} gibi kullan�c�n�n girmesi gereken format.
	
	   
    int max_alan = 0; //maximum alan� 0'a e�itledik istedi�imiz �artlar sa�land���nda artt�raca��z.
    int alan, i, j, k, l;

    int matrix[m][n]; 
    printf("matrixin degerlerini girin:\n"); // 1 ve 0 dan olu�an de�erler girilir. 
    
    
    //i ve j Matrisin her bir h�cresini gezmede kullan�lan d�ng�lerdeki indis de�i�kenleridir. �lk d�ng� i i�in sat�r, j i�in s�tun indekslerini gezdirir.
    for(i=0; i<m; i++) {  //girilen m sat�r�na g�re i 0'dan ba�lay�p 1 artarak indeksleri gezecek.
        for(j=0; j<n; j++) { ////girilen n sutununa g�re j 0'dan ba�lay�p 1 artarak indeksleri gezecek.
            scanf("%d", &matrix[i][j]); // dizimize yani matrise de�erler atan�r.
        }
    }
    //Bu kod blo�u, matrix adl� ikili matrisin her bir eleman�n� kontrol ederek, 1 olan bir h�cre buldu�unda, bu h�creden ba�layarak adan�n y�z�l��m�n� hesaplamaya ba�lar.
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(matrix[i][j] == 1) { //Bu sat�r, e�er matristeki (i,j) konumundaki eleman 1 ise, 'alan' de�i�kenine 1 de�erini atar. 
                alan = 1;
                //k ve l Mevcut adan�n kenarlar�n� aramakta kullan�lan d�ng�lerdeki indis de�i�kenleridir. k sat�r, l s�tun indekslerini gezdirir.
                for(k=i+1; k<m; k++) { // bu elemandan a�a�� do�ru s�ral� bir �ekilde 1 olan t�m elemanlar� saymak i�in kullan�l�r ve asa�� do�ru iner.
                    if(matrix[k][j] == 1) { // E�er matrix[k][j] == 1 ise, yani bu konumdaki eleman 1 ise, 'alan' de�i�keni bir art�r�l�r. 
                    //                         Bu �ekilde, (i,j) eleman�ndan a�a�� do�ru s�ral� bir �ekilde olan t�m 1'leri sayar�z.
                        alan++;
                    } else { // de�ilse sonland�r.
                        break;
                    }
                }
                for(l=j+1; l<n; l++) { //Bu d�ng�, matrisin belirli bir h�cresinde 1 de�erinin oldu�u tespit edildi�inde, bu h�crenin alt�ndaki ve sa� taraf�ndaki di�er h�creleri kontrol eder.
                    if(matrix[i][l] == 1) {
                        alan++; //E�er bu h�crelerde de 1 de�eri varsa, alan de�i�keni artt�r�l�r ve adan�n alan� hesaplan�r. 
                    } else {
                        break;
                    }
                }
                if(alan > max_alan) { // e�er alan max alandan b�y�k ise max alan da alana e�itlenir
                    max_alan = alan;
                }
            }
        }
    }

    printf("Max alan: %d\n", max_alan); //maximum alan yazd�r�l�r.

    return 0;
}

