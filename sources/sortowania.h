#include <utility>
template <typename T,typename B> void bombel( T *kolekcja, int dlugosc, int porownanie(B,B) ){
	if (dlugosc<=1) return;
	int poprawnie=1;
	do{
		
		poprawnie=1;
		B tmp;
		for(int i=0; i<dlugosc-1;i++)
		{
			if(porownanie(kolekcja[i],kolekcja[i+1])==1){
				tmp = std::move(kolekcja[i]);
				kolekcja[i] = std::move(kolekcja[i+1]);
				kolekcja[i+1] = std::move(tmp);
				poprawnie=0;
			}
		} 
			
	}
	while(poprawnie==0);
	return;
}

template <typename T,typename B> void wstaw( T *kolekcja, int dlugosc, int porownanie(B,B) ){
	if (dlugosc<=1) return;
	for(int i = 1; i < dlugosc; i++)
	{
		B tmp;
		int pozycja=i;
		while(pozycja>0&&porownanie(kolekcja[pozycja-1],kolekcja[pozycja])==1)
		{
			tmp = std::move(kolekcja[pozycja]);
			kolekcja[pozycja] = std::move(kolekcja[pozycja-1]);
			kolekcja[pozycja-1] = std::move(tmp);
			pozycja--;
		}
	}
	return;
}
/*
template <typename T,typename B> void scal( T *kolekcja, int dlugosc, int porownanie(B,B) ){
	if (dlugosc<=1) return;
	int podmiana[dlugosc];
	B tablice[2][dlugosc][2];
	parzyste_tablice=0;
	int dlugosc_tablice[2]=i;
	for(int i=0; i<dlugosc; i++)
	{
		podmiana[i]
		tablice[0][i][0]=i;
		tablice[0][i][1]=i;
	}
	dlugosc_tablice[0]=dlugosc;
	while(dlugosc_tablice[parzyste_tablice]>1)
		aktualnie_scalana=0;
		dlugosc_tablice[!(parzyste_tablice)]=0;
		while()
		
	return;
}
template <typename T,typename B> void scal_tab( T *kolekcja, int a, int b int c, int porownanie(B,B) ){
	int 
	
	
}


*/





















