#include <stdio.h>

main (){
int tahun;
 
 printf("\xB1 ------------Tahun Kabisat-------------- \xB1\n\n");
 printf("   Inputkan Tahun : ");
 scanf("%d",&tahun);
 
    if((tahun%400==0) || (tahun%4==0 && tahun%100!=0))
       printf("\x3  Tahun %d adalah tahun kabisat  \x3",tahun);
      else 
            printf("-- Tahun %d bukan tahun kabisat --",tahun); 
getche();            
return 0;     
}
