using namespace std;

struct roba {
       char sifra[10];
       string vrsta, boja;
       int dan, mj, god, model;
       float cijena;
       };
       
struct stg {
       roba node;
       stg *sljedeci;
       };

typedef stg stack;
typedef stack *element;

roba TopS(stack *S) {
       return S->sljedeci->node;
       }

void PushS(roba x, stack *S) {
     element novi=new stg;
     novi->node=x;
     novi->sljedeci=S->sljedeci;
     S->sljedeci=novi;
     }
     
void PopS(stack *S) {
     element pom=S->sljedeci;
     S->sljedeci=pom->sljedeci;
     delete pom;
     }
 
element InitS(stack *S){
	S=new stg;
	S->sljedeci=nullptr;
	return S;
}
bool IsEmptyS(stack *S){
     if(S->sljedeci==nullptr) return true;
     else return false;
     }
void ispis(stack *s){
	if(IsEmptyS(s)) return;
	element tekuci=s->sljedeci;
	cout<<"Sifra \t\tVrsta \t\t\tModel \tCijena \tBoja \tDatum "<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	while(tekuci){
		cout<<tekuci->node.sifra<<"\t"<<tekuci->node.vrsta<<"\t\t";
		cout<<tekuci->node.model<<"\t"<<tekuci->node.cijena<<"\t";
		cout<<tekuci->node.boja<<"\t"<<tekuci->node.dan<<"."<<tekuci->node.mj<<"."<<tekuci->node.god<<endl;
		tekuci=tekuci->sljedeci;
	}
}
