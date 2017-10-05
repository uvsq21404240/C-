using namespace std;

#include <iostream>

class Noeud
{
	private:
		int val;
		Noeud *nextNoeud;
	
	public:
	
	Noeud(int valeur)
	{
		val = valeur ;
		nextNoeud = NULL ;
	}
	int getVal(){
		return val;
	}
	Noeud* getNext()
	{ return nextNoeud; }
	
	void setNext(Noeud *next)
	{ nextNoeud = next; }
	~Noeud();
	
};

	
	class Liste
{
	private:
		Noeud *tete;
		int taille;
		
	public:
	Liste()
	{
	tete = new Noeud(0) ;
	taille = 1;	
	}
	Noeud* getTete() const
	{ return tete; }
	int getTaille() const
	{ return taille; }
	Liste(const Liste& l)
{
	if(l.getTete() != NULL)
	{
		Noeud *tete_tmp = l.getTete();
		taille = l.getTaille();

		Noeud *ptr = new Noeud(tete_tmp->getVal());
		tete_tmp = tete_tmp->getNext();
		tete = ptr;
		while(tete_tmp != NULL)
		{
			ptr->setNext(new Noeud(tete_tmp->getVal()));
			tete_tmp = tete_tmp->getNext();
			ptr = ptr->getNext();
		}
	}
	else
	{
		taille = 0;
		tete = NULL;
	}
}
	
};


int main()
{
	Liste *l1 = new Liste();
	Liste *l2 = new Liste(*l1);
	return 0;
}
