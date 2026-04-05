#include <iostream>
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
			std::cout<<kolumny[i]<<'\n';
			if(linia[end]=='\n' && i!=8) return 1;
			end++;
			begin=end;
		}
		if(kolumny[0].length()==9)
		{
			int mnoznik=1;
			id=0;
			for(int i = 8; i>1; i--){
				if(kolumny[0][i]<'0'||kolumny[0][i]>'9') return 1;
				id=id+(mnoznik*(kolumny[0][i]-'0'));
				mnoznik*=10;
			}
		}else return 1;
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
		
		if(kolumny[5].length()>=2 && kolumny[5][0]==92 && kolumny[5][1]=='N') rok1=-1;
		else
		if(kolumny[5].length()==4)
		{
			std::cout<<"rok--------------\n";
			int mnoznik=1;
			rok1=0;
			for(int i = 3; i>=0; i--){
				if(kolumny[5][i]<'0'||kolumny[5][i]>'9') return 1;
				rok1=rok1+(mnoznik*(kolumny[5][i]-'0'));
				mnoznik*=10;
			}
		}else return 1;
			std::cout<<"rok--------------2\n";
		
		if(kolumny[5].length()>=2 && kolumny[5][0]=='\\' && kolumny[5][1]=='N') rok2=-1;
		else
		if(kolumny[6].length()==4)
		{
			int mnoznik=1;
			rok2=0;
			for(int i = 3; i>=0; i--){
				if(kolumny[6][i]<'0'||kolumny[6][i]>'9') return 1;
				rok2=rok2+(mnoznik*(kolumny[6][i]-'0'));
				mnoznik*=10;
			}
		}else return 1;
		
		if(kolumny[7].length()>=2 && kolumny[7][0]=='\\' && kolumny[7][1]=='N') dlugosc=-1;
		else
		if(kolumny[7].length()>0)
		{
			int mnoznik=1;
			dlugosc=0;
			for(int i = 3; i>=0; i--){
				if(kolumny[7][i]<'0'||kolumny[7][i]>'9') return 1;
				dlugosc=dlugosc+(mnoznik*(kolumny[7][i]-'0'));
				mnoznik*=10;
			}
		}else return 1;
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
};
















