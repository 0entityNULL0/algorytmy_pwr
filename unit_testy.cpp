#include <iostream>
#include "sources/sortowanie_b.h"
#include <ctime>


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

			return 1;
		}
	}
	
	return 0;
}


int main()
{
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
