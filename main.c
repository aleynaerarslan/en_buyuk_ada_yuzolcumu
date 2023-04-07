#include <stdio.h>
#include <stdlib.h>
//Aleyna Erarslan
//Bu kodda, verilen matrisin her bir hücresi gezilerek, bulunan 1 hücreleri üzerinde dikey ve yatay yönde bitiþik diðer 1 hücrelerini bulunur ve böylece bir ada tespit edilir. 
//Her adanýn alaný hesaplanýr ve bulunan tüm adalarýn alanlarý karþýlaþtýrýlarak en büyük ada bulunur. Bu adanýn alaný ekrana yazdýrýlýr.

int main() {
    int m, n; //matrixte m=satir , n=sutun sayisini tutacak
    
    printf("satir ve sutun sayisini girin: ");
    scanf("%d %d", &m, &n);  //orneðin 2 3 sayilarý girildiyse bu matris 2 satýr 3 sutundan oluþan sayýlardan meydana gelecektir.
    // matrisin deðerleri 1 ise kara 0 ise denizi temsil etmekteydi
    // örneðe göre bir matris yazacak olursak mesela: {1,0,1},
    //                                                {0,1,1} gibi kullanýcýnýn girmesi gereken format.
	
	   
    int max_alan = 0; //maximum alaný 0'a eþitledik istediðimiz þartlar saðlandýðýnda arttýracaðýz.
    int alan, i, j, k, l;

    int matrix[m][n]; 
    printf("matrixin degerlerini girin:\n"); // 1 ve 0 dan oluþan deðerler girilir. 
    
    
    //i ve j Matrisin her bir hücresini gezmede kullanýlan döngülerdeki indis deðiþkenleridir. Ýlk döngü i için satýr, j için sütun indekslerini gezdirir.
    for(i=0; i<m; i++) {  //girilen m satýrýna göre i 0'dan baþlayýp 1 artarak indeksleri gezecek.
        for(j=0; j<n; j++) { ////girilen n sutununa göre j 0'dan baþlayýp 1 artarak indeksleri gezecek.
            scanf("%d", &matrix[i][j]); // dizimize yani matrise deðerler atanýr.
        }
    }
    //Bu kod bloðu, matrix adlý ikili matrisin her bir elemanýný kontrol ederek, 1 olan bir hücre bulduðunda, bu hücreden baþlayarak adanýn yüzölçümünü hesaplamaya baþlar.
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if(matrix[i][j] == 1) { //Bu satýr, eðer matristeki (i,j) konumundaki eleman 1 ise, 'alan' deðiþkenine 1 deðerini atar. 
                alan = 1;
                //k ve l Mevcut adanýn kenarlarýný aramakta kullanýlan döngülerdeki indis deðiþkenleridir. k satýr, l sütun indekslerini gezdirir.
                for(k=i+1; k<m; k++) { // bu elemandan aþaðý doðru sýralý bir þekilde 1 olan tüm elemanlarý saymak için kullanýlýr ve asaðý doðru iner.
                    if(matrix[k][j] == 1) { // Eðer matrix[k][j] == 1 ise, yani bu konumdaki eleman 1 ise, 'alan' deðiþkeni bir artýrýlýr. 
                    //                         Bu þekilde, (i,j) elemanýndan aþaðý doðru sýralý bir þekilde olan tüm 1'leri sayarýz.
                        alan++;
                    } else { // deðilse sonlandýr.
                        break;
                    }
                }
                for(l=j+1; l<n; l++) { //Bu döngü, matrisin belirli bir hücresinde 1 deðerinin olduðu tespit edildiðinde, bu hücrenin altýndaki ve sað tarafýndaki diðer hücreleri kontrol eder.
                    if(matrix[i][l] == 1) {
                        alan++; //Eðer bu hücrelerde de 1 deðeri varsa, alan deðiþkeni arttýrýlýr ve adanýn alaný hesaplanýr. 
                    } else {
                        break;
                    }
                }
                if(alan > max_alan) { // eðer alan max alandan büyük ise max alan da alana eþitlenir
                    max_alan = alan;
                }
            }
        }
    }

    printf("Max alan: %d\n", max_alan); //maximum alan yazdýrýlýr.

    return 0;
}

