#include <iostream>
#include "sources/sortowania.h"
#include "sources/dane_zadaniowe.h"
#include "sources/drzewo.h"
#include <fstream>

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

int porownanie_avrg(film_z_ratingiem* a,film_z_ratingiem* b)
{
	if(a->rating>b->rating) return 1;
	if(a->rating<b->rating) return -1;
	return 0;
}

int porownanie_id(film_z_ratingiem* a,int b)
{
	if(a->id>b) return 1;
	if(a->id<b) return -1;
	return 0;
}

int id_filmu(film_z_ratingiem* a)
{
	return a->id;
}

int main()
{
	drzewo_zbalansowane <film_z_ratingiem> drzewo_filmow(porownanie_filmy);
	ratings a;
	std::string linia;
	std::ifstream plik("dane/basics.tsv");
	std::ifstream plik2("dane/ratings.tsv");
	getline(plik2,linia);
	int c = 0;
	film_z_ratingiem *film;
	while(linia.length()!=0&&c<100000000)
	{
		getline(plik2,linia);
		c++;
		if(linia.length()!=0){
				//std::cout<<"sprawdzam film"<<'\n';
				//std::cout<<linia<<'\n';
			if(a.wczytaj_z_linii(linia)==0) {
				film=new film_z_ratingiem();
				film->id=a.id;
				film->rating=a.avg;
				film->glosy=a.c;
				film->czy_rating=1;
				drzewo_filmow.dodaj(film);
				//std::cout<<"dodaje film"<<'\n';
				//a.wypisz();
				
			}
		}
	}
	std::cout<<drzewo_filmow.rozmiar()<<'\n';
	film_z_ratingiem b;
	c=0;
	getline(plik,linia);
	while(linia.length()!=0&&c<100000000)
	{
		getline(plik,linia);
	//std::cout<<c<<'\n';
	//std::cout<<linia<<'\n';
		c++;
		if(linia.length()!=0)
			if(b.wczytaj_z_linii(linia)==0) {
				film_z_ratingiem *w_drzewie = drzewo_filmow.szukaj_elementu(porownanie_id,b.id);
				//std::cout<<"aaa"<<'\n';
				if(w_drzewie!=nullptr){
					w_drzewie->czy_dodany=1;
					w_drzewie->typ=b.typ;
					w_drzewie->tytul1=b.tytul1;
					w_drzewie->tytul2=b.tytul2;
					w_drzewie->dla_doroslych=b.dla_doroslych;
					w_drzewie->rok1=b.rok1;
					w_drzewie->rok2=b.rok2;
					w_drzewie->dlugosc=b.dlugosc;
					w_drzewie->rodzaj=b.rodzaj;
				}
			}
	}
	c=drzewo_filmow.rozmiar();
	
	film_z_ratingiem **tablica=drzewo_filmow.zrob_tablice_danych();
	//for(int i = 0; i<c; i++)
	//	tablica[i]->wypisz();
	//c=drzewo_filmow.filtruj();
	scal(tablica,c,porownanie_avrg);
	std::ofstream plik3("dane/wynik.tsv");
	plik3<<"tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\tendYear\truntimeMinutes\tgenres\taverageRating\tnumVotes";
	for(int i = 0; i<c; i++)
		tablica[i]->wpisz(&plik3);
	std::cout<<c<<'\n';
	return 0;
}
