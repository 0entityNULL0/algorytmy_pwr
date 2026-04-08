#ifndef SORTOWANIA_H
#define SORTOWANIA_H
#include <utility>
#include <iostream>

template <typename T> class prosta_lista
{
	struct wezel
	{
		T dane;
		wezel* next;
		wezel* prev;
	};
	wezel* glowa;
	wezel* tyl;
	public:
	prosta_lista()
	{
		glowa=nullptr;
		tyl=nullptr;
	}
	int puste()
	{
		if(glowa==nullptr) return 1;
		return 0;
	}
	void dodaj(T element)
	{
		wezel *dodawany_element = new wezel;
		dodawany_element->dane = element;
		if(glowa==nullptr)
		{
			glowa=dodawany_element;
			tyl=dodawany_element;
			dodawany_element->next=nullptr;
			dodawany_element->prev=nullptr;
		}else
		{
			glowa->prev=dodawany_element;
			dodawany_element->next=glowa;
			glowa=dodawany_element;
		}
	}
	T zdejmij()
	{
		wezel *zdejmowany=tyl;
		tyl=tyl->prev;
		if(tyl==nullptr)
		{
			glowa=nullptr;
		}else
		{
			tyl->next=nullptr;
		}
		T dane = zdejmowany->dane;
		delete zdejmowany;
		return dane;
	}
};


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


template <typename T,typename B> void scal_tab( T *kolekcja, int a, int b, int c, int porownanie(B,B),T* kopia  ){
	int p1=a;
	int p2=b;
	int i = 0;
	while(p1<b&&p2<=c)
	{
		if(porownanie(kolekcja[p1],kolekcja[p2])==-1)
		{
			kopia[a+i]=kolekcja[p1];
			p1++;
			
		}else
		{
			kopia[a+i]=kolekcja[p2];
			p2++;
			
		}
		i++;
	}
	if(p1>=b)
	{
		while(p2<=c)
		{
			kopia[a+i]=kolekcja[p2];
			p2++;
			i++;
		}
	}else{
		
		while(p1<b)
		{
			kopia[a+i]=kolekcja[p1];
			p1++;
			i++;
		}
	}
	i=0;
	while(i+a<=c)
	{
		kolekcja[i+a]=kopia[i+a];
		i++;
	}
	return;
	
	
	
}

template <typename T,typename B> void dziel_tab( T *kolekcja, int a, int b, int porownanie(B,B),T* kopia  ){
	if(b-a==0) return;
	if(b-a==1) 
	{
		if(porownanie(kolekcja[a],kolekcja[b])==1)
		{
			B tmp=kolekcja[a];
			kolekcja[a]=kolekcja[b];
			kolekcja[b]=tmp;
		}
	}
	int c=(b-a)/2;
	dziel_tab(kolekcja,a,a+c,porownanie,kopia);
	dziel_tab(kolekcja,a+c+1,b,porownanie,kopia);
	scal_tab(kolekcja,a,a+c+1,b,porownanie,kopia);
	return;
	
}

template <typename T,typename B> void scal( T *kolekcja, int dlugosc, int porownanie(B,B)){
	T * kopia = new T[dlugosc];
	dziel_tab(kolekcja,0,dlugosc-1,porownanie,kopia);
}



template <typename T,typename B> void quick_sort( T *kolekcja, int a, int b, int porownanie(B,B)){
	if(b-a<=0) return;
	int czesc1=a;
	for(int i = a+1; i<=b; i++)
	{
		if(porownanie(kolekcja[a],kolekcja[i])==1)
		{
			czesc1++;
			B tmp=kolekcja[czesc1];
			kolekcja[czesc1]=kolekcja[i];
			kolekcja[i]=tmp;
		}
	}
	B tmp=kolekcja[a];
	kolekcja[a]=kolekcja[czesc1];
	kolekcja[czesc1]=tmp;
	quick_sort(kolekcja,a,czesc1-1,porownanie);
	quick_sort(kolekcja,czesc1+1,b,porownanie);
}
template <typename T,typename B> void quick( T *kolekcja, int dlugosc, int porownanie(B,B)){
	quick_sort(kolekcja,0,dlugosc-1,porownanie);
}



template <typename T,typename B> void introspec_s( T *kolekcja, int a, int b, int porownanie(B,B),int glebokosc,int lnrozmiar){
	if(b-a<=0) return;
	if(glebokosc>2	*lnrozmiar) {scal(kolekcja+a,b-a+1,porownanie); return;}
	
	int czesc1=a;
	for(int i = a+1; i<=b; i++)
	{
		if(porownanie(kolekcja[a],kolekcja[i])==1)
		{
			czesc1++;
			B tmp=kolekcja[czesc1];
			kolekcja[czesc1]=kolekcja[i];
			kolekcja[i]=tmp;
		}
	}
	B tmp=kolekcja[a];
	kolekcja[a]=kolekcja[czesc1];
	kolekcja[czesc1]=tmp;
	introspec_s(kolekcja,a,czesc1-1,porownanie,glebokosc+1,lnrozmiar);
	introspec_s(kolekcja,czesc1+1,b,porownanie,glebokosc+1,lnrozmiar);
}
template <typename T,typename B> void introspec( T *kolekcja, int dlugosc, int porownanie(B,B)){
	int ln=0;
	for(int i=1;i<dlugosc;i*=2)
		ln++;
	introspec_s(kolekcja,0,dlugosc-1,porownanie,0,ln);
}

template <typename T,typename B> void kubelkowe( T *kolekcja, int dlugosc, int wartosc(B),int max_kubel){
	prosta_lista <B> kubelki[max_kubel+1];
	for(int i = 0; i < dlugosc; i++)
	{
		kubelki[wartosc(kolekcja[i])].dodaj(kolekcja[i]);
	}
	int i_tab=0;
	for(int i = 0; i < max_kubel+1; i++)
	{
		while(kubelki[i].puste()==0)
		{
			kolekcja[i_tab]=kubelki[i].zdejmij();
			i_tab++;
		}
	}
}

#endif





















