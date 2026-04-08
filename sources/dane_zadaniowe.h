#ifndef DANE_ZADANIOWE_H
#define DANE_ZADANIOWE_H

#include <iostream>
#include <fstream>

int czytaj_int(std::string linia)
{
	int a = 0;
	int p = 1;
	for(int i = linia.length()-1; i>=0; i--)
	{
		if(linia[i]<'0'||linia[i]>'9')
			return -1;
		a+=(linia[i]-'0')*p;
		p*=10;
	}
	return a;
}

int czytaj_id(std::string linia)
{
	int a = 0;
	int p = 1;
	for(int i = linia.length()-1; i>=2; i--)
	{
		if(linia[i]<'0'||linia[i]>'9')
			return -1;
		a+=(linia[i]-'0')*p;
		p*=10;
	}
	return a;
}

struct ratings
{
	int id;
	int avg;
	int c;
	void wypisz()
	{
		std::cout<<"id: "<<id<<"; avg: "<<avg<<"; c: "<<c<<"\n";
	}
	int wczytaj_z_linii(std::string linia)
	{
		if(linia.length()==0) return 1;
		int begin=0;
		int end=0;
		
		std::string kolumny[3];
		for(int i = 0; i<3; i++){
			if(end>=linia.length()) return 1;
			while(linia[end]!='\t'&&linia[end]!='\t'&&end<linia.length())
				end++;
			kolumny[i]="";
			while(begin<end){
				kolumny[i]=kolumny[i]+linia[begin];
				begin++;
			}
			if(linia[end]=='\n' && i!=3) return 1;
			end++;
			begin=end;
		}
		id=czytaj_id(kolumny[0]);
		avg=0;
		int mnoznik=1;
		for(int i = kolumny[1].length(); i >=0;i--)
		{
			if(kolumny[1][i]>='0'&&kolumny[1][i]<='9')
			{
				avg=avg+(mnoznik*(kolumny[1][i]-'0'));
				mnoznik*=10;
			}
		}
		c=czytaj_int(kolumny[2]);
		return 0;
	}
};

struct film_z_ratingiem
{
	int czy_dodany;
	int id;
	std::string typ;
	std::string tytul1;
	std::string tytul2;
	int dla_doroslych;
	int rok1;
	int rok2;
	int dlugosc;
	std::string rodzaj;
	int rating;
	int glosy;
	int czy_rating;
	film_z_ratingiem()
	{
		czy_dodany=0;
		czy_rating=0;
	}
	int wczytaj_z_linii(std::string linia)
	{
		if(linia.length()==0) return 1;
		int begin=0;
		int end=0;
		std::string kolumny[9];
		for(int i = 0; i<9; i++){
			if(end>=linia.length()) return 1;
			while(linia[end]!='\t'&&linia[end]!='\t'&&end<linia.length())
				end++;
			kolumny[i]="";
			while(begin<end){
				kolumny[i]=kolumny[i]+linia[begin];
				begin++;
			}
			//std::cout<<kolumny[i]<<'\n';
			if(linia[end]=='\n' && i!=8) return 1;
			end++;
			begin=end;
		}
		id=czytaj_id(kolumny[0]);
		typ=kolumny[1];
		tytul1=kolumny[2];
		tytul2=kolumny[3];
		if(kolumny[4].length()>=2 && kolumny[4][0]=='\\' && kolumny[4][1]=='N') dla_doroslych=-1;
		else
		if(kolumny[4].length()==1)
		{
			if(kolumny[0][0]<'0'||kolumny[4][0]>'9') return 1;
				dla_doroslych=kolumny[4][0]-'0';
		}else return 1;
		
		
		rok1=czytaj_int(kolumny[5]);
		
		rok2=czytaj_int(kolumny[6]);
		
		
		if(kolumny[7].length()>=2 && kolumny[7][0]=='\\' && kolumny[7][1]=='N') dlugosc=-1;
		else
		if(kolumny[7].length()>0)
		{
			dlugosc=czytaj_int(kolumny[7]);
		}else{ return 1;
			std::cout<<"rok--------------2\n";
		}
		rodzaj=kolumny[8];
	czy_dodany=1;
	return 0;
	}
	void wypisz()
	{
		/*if(czy_dodany!=1){
			std::cout<<"film_nie_zostal_dodany\n";
			return;
		}*/
		std::cout<<"id: "<<id<<'\n';
		std::cout<<"typ: "<<typ<<'\n';
		std::cout<<"tytul: "<<tytul1<<'\n';
		std::cout<<"tytul oryginalny: "<<tytul2<<'\n';
		std::cout<<"czy dla doroslych: "<<dla_doroslych<<'\n';
		std::cout<<"rok rozpoczecia: "<<rok1<<'\n';
		std::cout<<"rok zakonczenia: "<<rok2<<'\n';
		std::cout<<"dlugosc: "<<dlugosc<<'\n';
		std::cout<<"rodzaj: "<<rodzaj<<'\n';
	}
	void wpisz(std::ofstream *plik)
	{
		*plik<<"tt";
		int a = id;
		while(a<1000000)
		{
			*plik<<0;
			a*=10;
		}
		*plik<<id<<"\t"<<typ<<"\t"<<tytul1<<"\t"<<tytul2<<"\t";
		if(dla_doroslych==-1) *plik<<"\\N\t";
		else *plik<<dla_doroslych<<"\t";
		if(rok1==-1) *plik<<"\\N\t";
		else *plik<<rok1<<"\t";
		if(rok2==-1) *plik<<"\\N\t";
		else *plik<<rok2<<"\t";
		if(dlugosc==-1) *plik<<"\\N\t";
		else *plik<<dlugosc<<"\t";
		*plik<<rodzaj<<"\t";
		*plik<<rating/10<<'.'<<rating%10<<"\t"<<glosy<<"\n";
		
	}
};
//drzewo_zbalansowane <film_z_ratingiem>* wczytaj_ratingi(std::string nazwa_pliku)

#endif











