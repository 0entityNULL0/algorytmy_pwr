#include <iostream>
#include "sources/sortowanie_b.h"

int czy_wieksze(int a,int b)
{
	if(a>b) return 1;
	if(a<b) return -1;
	return 0;
}

int main()
{
	
	int a[5]={3,2,7,4,5};
	for(int i=0;i<5; i++)
		std::cout<<a[i]<<' ';
	std::cout<<'\n';
	wstaw(a,5,czy_wieksze);
	for(int i=0;i<5; i++)
		std::cout<<a[i]<<' ';
	std::cout<<'\n';
	return 0;
}
