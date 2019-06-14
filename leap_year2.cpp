#include <iostream.h>
#include <conio.h>

int main()
{
    int awal, akhir, tahun;
    
    
    cout<<"Masukkan Tahun Awal: ";
    cin>>awal;
    cout<<"Masukkan Tahun Akhir: ";
    cin>>akhir;
    
    
    cout<<"Tahun Kabisat Antara"<<awal<<"dan"<<akhir<<"adalah: ";
    cout<<endl<<endl;
    for(tahun=awal; tahun<=akhir; tahun++)
    {
      if ((tahun%4==0)||(tahun%400==0)&&(tahun%100!=0))
        cout<<tahun<<endl;
        else
          cout<<"";
    }
 getche();
}               
