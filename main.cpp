#include <iostream>
#include <ctime>
#include "stog_polje.h"
//#include "stog_pokazivac.h"
#include <cstring>

using namespace std;
void utovar(stack *stog);
void istovar(stack *stog);
void istovar2(stack* stog,int dan, int mj, int god);
void sifra(int a, roba tele);

int main(){
	int izbor,dan,mj,god;
	stack *stog=InitS(stog);
	do{
		cout<<"***********************************************"<<endl;
		cout<<"1. Ukrcaj robe (unos)"<<endl;
		cout<<"2. Istovar na prvoj stanici"<<endl;
		cout<<"3. Istovar zelenih proizvoda skupljih od 5000"<<endl;
		cout<<"9. Izlaz iz programa"<<endl;
		cout<<"Izaberite opciju: ";
		cin>>izbor;
		cout<<endl;
		switch(izbor){
			case 1:
				utovar(stog);
				break;
			case 2:
				istovar(stog);
				break;
			case 3: 
				cout<<"Unesite danasnji datum: ";
				do{cout<<"Dan: "; cin>>dan;}while(dan<1||dan>31);
				do{cout<<"Mjesec: "; cin>>mj;}while(mj<1||mj>12);
				cout<<"Godina: "; cin>>god;
				istovar2(stog,dan,mj,god);
			case 4: ispis(stog); break;
			case 9: cout<<"Izlaz iz programa"<<endl;
		}
	}while(izbor!=9);
	return 0;
}
void sifra(int a, roba* tele){
	char vrsta[6];
	char mod[3];
	memset(tele->sifra,0,10);
	if(a==0||a==4){//dvoznamenkasti
		strncpy(vrsta, tele->vrsta.c_str(), 4);
		strcat(tele->sifra, vrsta);
		vrsta[3]='\0';
		itoa(tele->model,mod,10);
		strcat(tele->sifra,mod);
		strncpy(vrsta, tele->boja.c_str(), 3);
		strcat(tele->sifra, vrsta);
	}else{//jednoznamenkasti
		strncpy(vrsta, tele->vrsta.c_str(), 5);
		strcat(tele->sifra, vrsta);
		vrsta[3]='\0';
		vrsta[4]='\0';
		itoa(tele->model,mod,10);
		strcat(tele->sifra,mod);
		strncpy(vrsta, tele->boja.c_str(), 3);
		strcat(tele->sifra, vrsta);
	}
}
void utovar(stack *stog){
	roba tele;
	string vrsta[]={"monitor", "smartphone", "tablet", "ereader", "laptop"};
	int tv[]={31, 32, 33};
	int sp[]={4, 5, 6};
	int tablet[]={7,8,9};
	int laptop[]={14,15,16};
	int ereader[]={5,6,9};
	string boja[]={"bijela", "zelena", "crvena"};
	srand(time(0));
	int g,a,m,b;
	cout<<"Proizvoda za utovar: "; cin>>g;
	for(int i=0; i<g; i++){
		cout<<"Unesite datum proizvodnje=> "<<endl;
		do{cout<<"\tDan: "; cin>>tele.dan;}while(tele.dan<1||tele.dan>31);
		do{cout<<"\tMjesec: "; cin>>tele.mj;}while(tele.mj<1||tele.mj>12);
		cout<<"\tGodina: "; cin>>tele.god;
		a=rand()%5;
		tele.vrsta=vrsta[a];
		tele.boja=boja[rand()%3];
		if(a==0){
			m=rand()%3;
			tele.model=tv[m];
			if(m==0) tele.cijena=1001;
			if(m==1) tele.cijena=2001;
			if(m==2) tele.cijena=3001;
		}
		if(a==1){
			m=rand()%3;
			tele.model=sp[m];
			if(m==0) tele.cijena=4001;
			if(m==1) tele.cijena=5001;
			if(m==2) tele.cijena=6001;
		}
		if(a==2){
			m=rand()%3;
			tele.model=tablet[m];
			if(m==0) tele.cijena=1001;
			if(m==1) tele.cijena=3001;
			if(m==2) tele.cijena=4001;
		}
		if(a==3){
			m=rand()%3;
			tele.model=ereader[m];
			if(m==0) tele.cijena=700;
			if(m==1) tele.cijena=800;
			if(m==2) tele.cijena=900;
		}
		if(a==4){
			m=rand()%3;
			tele.model=laptop[m];
			if(m==0) tele.cijena=4001;
			if(m==1) tele.cijena=6001;
			if(m==2) tele.cijena=7001;
		}
		sifra(a, &tele);
		PushS(tele, stog);
		roba n=TopS(stog);
	}
}
void istovar(stack *stog){
	roba tele, pele;
	stack* pstog=InitS(pstog);
	if(IsEmptyS(stog)) return;
	while(IsEmptyS(stog)==false){
		tele=TopS(stog);
		if(strcmp(tele.vrsta.c_str(), "ereader")!=0) PushS(tele, pstog);
		PopS(stog);	
	}
	while(IsEmptyS(pstog)==false){
		pele=TopS(pstog);
		PushS(pele, stog);
		PopS(pstog);
	}
	ispis(stog);
}
bool provjera (int dan, int mj, int god,int d, int m, int g){
	if(g==god&&m>=mj){
		if(m==mj&&d>=dan) return true;
		if(m-1==mj) return true;
		if(m-2==mj) return true;
		if(m-3==mj&&dan>=d) return true;
	}
	if(g-1==god&&m==3&&mj==12)
		if(dan>=d) return true;
	if(g-1==god&&m==2&&mj>=11){
		if(mj==11&&dan>=d) return true;
		if(mj==12) return true;
	}
	if(g-1==god&&m==1&&mj>=10){
		if(mj==10&&dan>=d) return true;
		if(mj==11||mj==12) return true;
	}
	return false;
}
int b=0;
void istovar2(stack *stog,int dan, int mj, int god){
	if(IsEmptyS(stog))return;
	roba tele=TopS(stog);
	PopS(stog);
	istovar2(stog,dan,mj,god);
	if(tele.cijena<5000 || strcmp(tele.boja.c_str(),"zelena")!=0||(provjera(tele.dan,tele.mj,tele.god,dan,mj,god)==false)){ 
		PushS(tele,stog);
	}
}
