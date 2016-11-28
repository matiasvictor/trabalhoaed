#include "projeto.h"


// ******************************************* Constutores ****************************************************
	
Books::Books()
{
   	
}

Books::Books(string bookname, string autorname, int ano)
{
   	bookname = this->bookname;
   	autorname = this->bookwriter;
   	ano = this->year;
}	

// ******************************************* Métodos get e set ****************************************************

string Books::get_nome()
{
	return bookname;
	
}

void Books::set_nome(string nome)
{
	this->bookname = nome;
	
}

string Books::get_autor()
{
	return this->bookwriter;
}

int Books::get_ano()
{
	return this->year;
}

bool Books::get_situacao()
{
	return this->flag;
}

void Books::set_flag(bool flag)
{
	this->flag = flag;
}

// ******************************************* Função de inicio do programa ****************************************************

void Books::iniciodoprograma()
{

int escolha1;

cout << "Seja bem vindo a biblioteca da UNB" << endl;
cout << "Você é funcionário ou estudante?" << endl;
cout << "Digite: 1 - Estudante" << endl;
cout << "Digite: 2 - Funcionario" << endl;

cin >> escolha1;

if (escolha1 == 1)
	menuEstudante();
else	
	menuFuncionario();

}

// ******************************************* Lista de opções disponiveis para o estudante ****************************************************

void Books::menuEstudante()
{

int escolha;

cout << "Escoha uma das opções no menu abaixo para começar:" << endl;
cout << "Digite: 1 - Empréstimo" << endl;
cout << "Digite: 2 - Devolução" << endl;
cout << "Digite: 3 - Consulta" << endl;
cout << "Digite: 4 - Retornar ao menu anterior" << endl;


cin >> escolha;

if(escolha == 1)
emprestarLivros();
else if (escolha == 2)
devolverLivros();
else if (escolha == 3)
consultarLivrosbio();
else
iniciodoprograma();

//consultarlivros


 } 
 
 // ******************************************* Lista de opções disponíveis para o Funcionário  ****************************************************
 
void Books::menuFuncionario()
{

int escolha;

cout << "Escoha uma das opções no menu abaixo para começar:" << endl;
cout << "Digite: 1 - Registrar livro" << endl;
cout << "Digite: 2 - Cadastro de usuário" << endl;
cout << "Digite: 3 - Retornar ao menu anterior" << endl;


cin >> escolha;

if(escolha == 1)
registrarLivros();
else if (escolha == 2)
devolverLivros();
else 
iniciodoprograma();


 } 
 

//************************************************** Métodos gerais ******************************************************************

void Books::emprestarLivros()
{
	string recentname;
	int recentcategory;
	cout << "Qual a categoria do livro?" << endl;
	cin >> recentcategory;
	cout << "Digite o nome do livro" << endl;
	cin >> recentname;
	
		if (recentcategory == 1)
		{
		 emprestaBiologia(recentname);
		} 
		else if (recentcategory == 2)
		{
		 emprestaHumanas(recentname);	
		}
		else if (recentcategory == 3)
		{
		 emprestaExatas(recentname);	
		}
		else if (recentcategory == 4)
		{
		 emprestaSaude(recentname);	
		}
	
	
	
 } 
 
 void Books::devolverLivros()
{
	string recentname;
	int recentcategory;
	cout << "Qual a categoria do livro?" << endl;
	cin >> recentcategory;
	cout << "Digite o nome do livro" << endl;
	cin >> recentname;
	
		if (recentcategory == 1)
		{
		 devolveBiologia(recentname);
		} 
		else if (recentcategory == 2)
		{
		 devolveHumanas(recentname);	
		}
		else if (recentcategory == 3)
		{
		 devolveExatas(recentname);	
		}
		else if (recentcategory == 4)
		{
		 devolveSaude(recentname);	
		}
	
	
	
 } 


void Books::registrarLivros()
	{
	
	     
		Books b;
		cout << "Registro" << endl;
		cout << "Para começar a adicionar, escolha a categoria do livro" << endl;
		cout << "Escolha 1 para Biologia" << endl;
		cout << "Escolha 2 para Humanas" << endl;
		cout << "Escolha 3 para Exatas" << endl;
		cout << "Escolha 4 para Saude" << endl;
		
		cin >> b.category;
		
		cout << "Coloque o nome do livro:"<<endl;
		
		cin >> b.bookname;
		
		cout << "Coloque o nome do autor do livro" << endl;
		
		cin >> b.bookwriter;
		
		cout << "Coloque o ano de publicação" << endl;
		
		cin >> b.year;
		
		b.flag = false;
		
		if (b.category == 1)
		{
			
			
		/* b.set_nome("joao");
		 c.set_nome("lins");
		 d.set_nome("paulo");
		 e.set_nome("xebra");
		 f.set_nome("zebra");
		 
		 this->biobooks.push_back(e);
		 this->biobooks.push_back(c);
		 this->biobooks.push_back(b);
		 this->biobooks.push_back(d);
		 this->biobooks.push_back(f);
		 quicksort();
		 binarysearchbio("jose");
		*/
		 addBiologia(b);
		} 
		else if (category == 2)
		{
		 addHumanas(b);	
		}
		else if (category == 3)
		{
		 addExatas(b);	
		}
		else if (category == 4)
		{
		 addSaude(b);	
		}
	}
	
	
	
	

