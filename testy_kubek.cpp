#include <iostream>
#include "sources/sortowania.h"
#include <fstream>
#include <chrono>
#include <ctime>

int wartosc(int a)
{
	return a;
}
int main()
{
	int * tab= new int [10000];
	for(int i = 0 ; i < 10000; i++)
		tab[i]=i;
	kubelkowe(tab,100,wartosc,16000);
	return 0;
}
