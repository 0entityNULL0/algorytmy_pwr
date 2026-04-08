#include <iostream>
#include "sources/sortowania.h"
#include <fstream>
#include <chrono>
#include <ctime>


int *kopia_tablicy(int * a,int len)
{
	int *wynik = new  int[len];
	for (int i = 0; i < len; i++)
	{
		wynik[i]=a[i];
	}
	return wynik;
}

int czy_wieksze(int a,int b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

int* losowa_tablica(int size, int max)
{
	
	int *tablica = new int[size];
	std::srand(std::time({}));
	for(int i = 0;i<size;i++)
		tablica[i]=std::rand()%max;
	return tablica;
}


int wartosc(int a)
{
	return a;
}

void test_sortowan(int rozmiar_testu,int  max)
{
	long long czas;
	int * tablica = losowa_tablica(rozmiar_testu,max);
	int * kopia= kopia_tablicy(tablica,rozmiar_testu);
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	scal(kopia,rozmiar_testu,czy_wieksze);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie przez scalanie: "<<czas<<"ms\n";
	delete kopia;
	kopia= kopia_tablicy(tablica,rozmiar_testu);
	begin = std::chrono::steady_clock::now();
	introspec(kopia,rozmiar_testu,czy_wieksze);
	 end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie introspektywne: "<<czas<<"ms\n";
	delete kopia;
	kopia= kopia_tablicy(tablica,rozmiar_testu);
	 begin = std::chrono::steady_clock::now();
	kubelkowe(kopia,rozmiar_testu,wartosc,max*2);
	end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie kubelkowe: "<<czas<<"ms\n";
	delete kopia;
	kopia= kopia_tablicy(tablica,rozmiar_testu);
	 begin = std::chrono::steady_clock::now();
	quick(kopia,rozmiar_testu,czy_wieksze);
	 end = std::chrono::steady_clock::now();
	czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	std::cout<<"sortowanie szybkie: "<<czas<<"ms\n";
	delete kopia;
	
	///kopia= kopia_tablicy(tablica,rozmiar_testu);
	///begin = std::chrono::steady_clock::now();
	///wstaw(kopia,rozmiar_testu,czy_wieksze);
	/// end = std::chrono::steady_clock::now();
	///czas=std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();
	///std::cout<<"sortowanie wstawianie: "<<czas<<"ms\n";
	///delete kopia;
	delete tablica;
	
	
	return;
}


int main()
{
	std::cout<<"dla 10000:\n";
	test_sortowan(10000,20000);
	std::cout<<"dla 100000:\n";
	test_sortowan(100000,20000);
	std::cout<<"dla 500000:\n";
	test_sortowan(500000,20000);
	std::cout<<"dla 1000000:\n";
	test_sortowan(1000000,20000);
	
	return 0;
}
