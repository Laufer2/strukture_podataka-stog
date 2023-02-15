using namespace std;

typedef int element;

struct roba {
       char sifra[10];
       string vrsta, boja;
       int dan, mj, god, model;
       float cijena;
       };
       
struct stg {
       roba node[100];
       element top;
       };
       
typedef stg stack;

roba TopS(stack *S) {//citanje s vrha
       return S->node[S->top+1];
       }
       
void PushS(roba x, stack *S) {//unos
     S->node[S->top]=x;
     S->top--;
     }
     
void PopS(stack *S) {//brisanje
     S->top++;
     }
     
stack* InitS(stack *S) {
     S=new stg;
	S->top=99;
     return S;
     }
     
bool IsEmptyS(stack *S) {
     if(S->top==99) return true;
     else return false;
     }
     
void ispis(stack *s){
	if(s->top==99) return;
	cout<<"Sifra \t\tVrsta \t\tModel \tCijena \tBoja \tDatum "<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	for(int i=s->top+1; i<100;i++){
	cout<<s->node[i].sifra<<"\t"<<s->node[i].vrsta<<"\t\t";
	cout<<s->node[i].model<<"\t"<<s->node[i].cijena<<"\t";
	cout<<s->node[i].boja<<"\t"<<s->node[i].dan<<"."<<s->node[i].mj<<"."<<s->node[i].god<<endl;
	}
}
