using namespace std;

#include <iostream>
#include <string.h>

class CString
{
	private:
		char *s;
		int size;
		static int nbrChaines;
	
	public:
		CString();
		CString(const char *chaine);
		CString(const char c);
		~CString();
		static int nbrChaine(){ return CString::nbrChaines; }
		const char* getString();
		char getChar(int i);
		int getSize();
		CString plus(const char c);
		bool plusGrandQue(CString s);
		bool infOuEgale(CString s);
		CString plusGrand(CString s);
};

int CString::nbrChaines = 0;
CString::CString::CString()
{
	size = 0;
	s = new char[1];
	s[0] = '\0';
	nbrChaines++;
}

CString::CString(const char *chaine)
{
	size = strlen(chaine);
	s = new char[size + 1];
	strcpy(this->s, chaine);
	nbrChaines++;
}

CString::CString(const char c)
{
	size = 1;
	s = new char[2];
	s[0] = c;
	s[1] = '\0';
	nbrChaines++;
}

const char* CString::getString(){ return s; }
int CString::getSize(){ return size; }
char CString::getChar(int i){ return s[i]; }

CString::~CString()
{
	cout << "destruction de la chaine " << s << endl;
	delete[] s;
	nbrChaines--;
}

CString CString::plus(const char c)
{
	char *s2 = new char[2];
	s2[0] = c;
	s2[1] = '\0';
	
	strcat(this->s, s2);
	size++;
	
	delete[] s2;
	return *this;
}

bool CString::plusGrandQue(CString chaine)
{ 
	return strcmp(this->getString(), chaine.getString()) > 0;
}

bool CString::infOuEgale(CString chaine)
{	
	return !(this->plusGrandQue(chaine)); 
}

CString CString::plusGrand(CString chaine)
{
	if(this->plusGrandQue(chaine))
		return *this;
	return chaine;
}

int main()
{
	CString s1( "toto" ), s2( 'q' ), s3;
	
	cout << "nbrChaines" << CString::nbrChaine() << endl;
	
	//~ s3 = s1.plus( 'w' );
	//~ cout << "s3=" << s3.getString() << endl;
	//~ 
	//~ if(s1.plusGrandQue(s2))
		//~ cout << "plus grand" << endl;
		//~ 
	//~ if(s1.infOuEgale(s2))
		//~ cout << "plus petit" << endl;
	//~ 
	//~ s3 = s1.plusGrand(s2); //marche pas
	cout << "s3=" << endl;
	return 0;
}
