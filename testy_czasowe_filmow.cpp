#include <iostream>
#include "sources/sortowania.h"
#include "sources/dane_zadaniowe.h"
#include "sources/drzewo.h"
#include <fstream>
#include <chrono>


int czy_wieksze(int a,int b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}
int porownanie_filmy(film_z_ratingiem* a,film_z_ratingiem* b)
{
	if(a->id>b->id) return 1;
	if(a->id<b->id) return -1;
	return 0;
}

int porownanie_len(film_z_ratingiem* a,film_z_ratingiem* b)
{
	if(a->dlugosc>b->dlugosc) return 1;
	if(a->dlugosc<b->dlugosc) return -1;
	return 0;
}

int porownanie_id(film_z_ratingiem* a,int b)
{
	if(a->id>b) return 1;
	if(a->id<b) return -1;
	return 0;
}

int wartosc(film_z_ratingiem*a)
{
	return a->dlugosc+1;
}

int id_filmu(film_z_ratingiem* a)
{
	return a->id;
}
film_z_ratingiem **kopia_tablicy(film_z_ratingiem ** a,int len)
{
	film_z_ratingiem **wynik = new  film_z_ratingiem*[len];
	for (int i = 0; i < len; i++)
	{
		wynik[i]=a[i];
	}
	return wynik;
}
int main()
{
	drzewo_zbalansowane <film_z_ratingiem> drzewo_filmow(porownanie_filmy);
	std::string linia;
	std::ifstream plik("dane/basics.tsv");
	int c = 0;
				
	film_z_ratingiem *film=new film_z_ratingiem();
		getline(plik,linia);
	while(linia.length()!=0&&c<500000)
	{
		getline(plik,linia);
	//std::cout<<c<<'\n';
	//std::cout<<linia<<'\n';
		c++;
		if(linia.length()!=0){
			if(film->wczytaj_z_linii(linia)==0) {
				drzewo_filmow.dodaj(film);
				film=new film_z_ratingiem();
				}
			}
	}
	delete film;
	c=drzewo_filmow.rozmiar();
	std::cout<<"Rozmiar danych: "<<c<<'\n';
	
	film_z_ratingiem **tablica=drzewo_filmow.zrob_tablice_danych();
	
	
	long long czas;
	
	film_z_ratingiem **kopia= kopia_tablicy(tablica,c);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	scal(kopia,c,porownanie_len);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie przez scalanie: "<<czas<<"ms\n";
	delete[] kopia;
	kopia= kopia_tablicy(tablica,c);
	begin = std::chrono::steady_clock::now();
	introspec(kopia,c,porownanie_len);
	 end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie introspektywne: "<<czas<<"ms\n";
	delete[] kopia;
	kopia= kopia_tablicy(tablica,c);
	 begin = std::chrono::steady_clock::now();
	kubelkowe(kopia,c,wartosc,20000);
	end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie kubelkowe: "<<czas<<"ms\n";
	delete[] kopia;
	kopia= kopia_tablicy(tablica,c);
	 begin = std::chrono::steady_clock::now();
	quick(kopia,c,porownanie_len);
	 end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie szybkie: "<<czas<<"ms\n";
	delete[] kopia;
	
	return 0;
}
