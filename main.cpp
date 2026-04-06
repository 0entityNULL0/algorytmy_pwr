#include <iostream>
#include "sources/sortowania.h"
#include "sources/dane_zadaniowe.h"
#include <fstream>

int czy_wieksze(int a,int b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

int main()
{
	film_z_ratingiem a;
	std::string linia;
	std::ifstream plik("dane/basics.tsv");
	getline(plik,linia);
	int c = 0;
	while(linia.length()!=0)
	{
		getline(plik,linia);
		c++;
		if(linia.length()!=0)
			if(a.wczytaj_z_linii(linia)==-1) std::cout<<c<<'\n';
		//else
		//std::cout<<"aaas"<<'\n';
		
		//a.wczytaj_z_linii(linia);
		//a.wypisz();
	}
	std::cout<<c<<'\n';
	return 0;
}
