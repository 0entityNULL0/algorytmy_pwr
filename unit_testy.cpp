#include <iostream>
#include "sources/sortowania.h"
#include <ctime>

void wypisz(int *a,int roz)
{
	for(int i = 0 ; i < roz; i++)
		std::cout<<a[i]<<" ";
	std::cout<<'\n';
}

int czy_wieksze(int a,int b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

int test_sortowania(void sortowanie(int* , int , int (int,int)), int rozmiar_testu	)
{
	int *tablica = new int[rozmiar_testu];
	std::srand(std::time({}));
	for(int i = 0;i<rozmiar_testu;i++)
		tablica[i]=std::rand()%rozmiar_testu;
	
	sortowanie(tablica,rozmiar_testu,czy_wieksze);
	for(int i = 0;i<rozmiar_testu-1;i++)\
	{
		if(czy_wieksze(tablica[i],tablica[i+1])==1){
			wypisz(tablica,rozmiar_testu);
			return 1;
		}
	}
	
	
	return 0;
}

int wartosc(int a)
{
	return a;
}

int test_sortowania_kubelkowego(int rozmiar_testu	)
{
	int *tablica = new int[rozmiar_testu];
	std::srand(std::time({}));
	for(int i = 0;i<rozmiar_testu;i++)
		tablica[i]=std::rand()%(rozmiar_testu*2);
	
	kubelkowe(tablica,rozmiar_testu,wartosc,(rozmiar_testu*2)-1);
	for(int i = 0;i<rozmiar_testu-1;i++)
	{
		if(czy_wieksze(tablica[i],tablica[i+1])==1){
			wypisz(tablica,rozmiar_testu);
			return 1;
		}
	}
	
	
	return 0;
}


int main()
{
	std::cout<<"testuje sortowanie kubelkowe\n";
	if(test_sortowania_kubelkowego(50)==1){
		std::cout<<"funkcja nie dziala\n";
		return 0;
	}
	std::cout<<"funkcja dziala poprawnie\n";
	std::cout<<"testuje sortowanie introspektywne\n";
	if(test_sortowania(introspec,50)==1){
		std::cout<<"funkcja nie dziala\n";
		return 0;
	}
	std::cout<<"funkcja dziala poprawnie\n";
	std::cout<<"testuje sortowanie quicksort\n";
	if(test_sortowania(quick,50)==1){
		std::cout<<"funkcja nie dziala\n";
		return 0;
	}
	std::cout<<"funkcja dziala poprawnie\n";
	std::cout<<"testuje sortowanie scaleniowe\n";
	if(test_sortowania(scal,50)==1){
		std::cout<<"funkcja nie dziala\n";
		return 0;
	}
	std::cout<<"funkcja dziala poprawnie\n";
	std::cout<<"testuje sortowanie bombelkowe\n";
	if(test_sortowania(bombel,50)==1){
		std::cout<<"funkcja nie dziala\n";
		return 0;
	}
	std::cout<<"funkcja dziala poprawnie\n";
	std::cout<<"testuje sortowanie przez wstawianie\n";
	if(test_sortowania(wstaw,50)==1){
		std::cout<<"funkcja nie dziala\n";
		return 0;
	}
	std::cout<<"funkcja dziala poprawnie\n";
	
	return 0;
}
