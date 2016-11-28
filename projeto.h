/* Matheus Henrique e Jo�o Vitor*/
#ifndef LIST_GUARD
#define LIST_GUARD

#include <iostream>
#include <string>
#include <vector>
#include <locale.h>
#include <fstream>
#include <ios>


using namespace std;

class users
{
	private:
		string user;
		int password;
	public:
		users *next;
		users *previous;
		//m�todos
		void setuser(string name);
		void setpassword(int pass);

	
	
};

class usersbank
{
	public:
		usersbank();
		~usersbank();
		//metodos;
  bool isEmpty();
  bool checkuser(string,int);
  void addHead(/*ainda n�o sei o enfiar aqui*/);
  void ordena();
  

};

class Books 
{
	private:
		string bookname;
		string bookwriter;
		int year;
		int category;
		bool flag;
		int day,month;
		vector <Books> biobooks;
		vector <Books> mathbooks;
		vector <Books> humanbooks;
		vector <Books> healthbooks;
		
		
	public:	
	
	    //M�todos gerais do programa

		void registrarLivros();
		Books();
		Books(string bookname, string autorname, int ano);
		void emprestarLivros();
		void iniciodoprograma();
		void devolverLivros();
		void menuEstudante();
		void menuFuncionario();

		// M�todos get e set 

		string get_nome();
		void set_nome(string);
		string get_autor();
		int get_ano();
		bool get_situacao();
		void set_flag(bool);

		// M�todos dos livros de biologia

		void addBiologia(Books b);
		bool buscabinariabio(string);
		void emprestaBiologia(string);
		void mudarflagemprestabio (string);
		void mudarflagdevolvebio (string);
		void devolveBiologia(string);
		void bubblesortbio ();
	    void consultarLivrosbio();
		
		// M�todos dos livros de humanas

		void consultarLivroshum();
		void bubblesorthum();
		bool buscabinariahum(string);
		void mudarflagemprestahum(string);
		void mudarflagdevolvehum (string);
		void emprestaHumanas(string name);
		void devolveHumanas(string name);
		void addHumanas(Books b);

		// M�todos dos livros de Sa�de 

		void emprestaSaude(string, Books);
	    void addSaude(Books b);
	    void devolveSaude(string name);
	    void emprestaSaude(string name);
	    void mudarflagdevolvesaude (string name);
	    void mudarflagemprestasaude(string name);
	    bool buscabinariasaude(string recentname);
	    void bubblesortsaude ();
	    void consultarLivrossaude();
	
	    // M�todos dos livros de Exatas 

	    void addExatas(Books b);
	    void devolveExatas(string name);
	    void emprestaExatas(string name);
	    void mudarflagdevolvemat (string name);
	    void mudarflagemprestamat (string name);
	    bool buscabinariamat(string recentname);
	    void bubblesortmat ();
	    void consultarLivrosmat();
	
};


#endif
