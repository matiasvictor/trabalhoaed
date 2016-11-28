#include "projeto.h"


using namespace std;

// ******************************************* Função main ****************************************************

int main()
{
	setlocale(LC_ALL, "Portuguese");
    Books b;
	b.iniciodoprograma();
    
}

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
 
// *************************************************** Métodos para alterar livros da Biologia *********************************************************
 
// ******* Método para consultar os livros *********
 
void Books::consultarLivrosbio()
{
	string name;
	string escolha;
	cout << "Digite o nome do livro a ser consultado" << endl;
	cin >> name;
	if (buscabinariabio(name))
	{
		
		for (int i=0; i < this->biobooks.size(); i++)
		{
			if (name == this->biobooks.at(i).get_nome())
			{
			cout << "Nome:" << this->biobooks.at(i).get_nome() << endl;
			cout << "Autor:" << this->biobooks.at(i).get_autor() << endl;
			cout << "Ano:" << this->biobooks.at(i).get_ano() << endl;
			if (this->biobooks.at(i).get_situacao() == true)
			cout << "Situação: Emprestado" << endl;
			else
			cout << "Situação: Disponível" << endl;
		}	}
		
	}	
	
	else 
	{	
	
	cout << "Tente outro livro, este não consta em nossa base de dados" << endl;
	iniciodoprograma();
}
		
	cout << "Deseja consultar outro livro? (y/n)" << endl;
	cin >> escolha;
	if (escolha == "y")
	consultarLivrosbio();
	else
	iniciodoprograma();
	
	
}

// ******* Método para ordernar os livros *********

void Books::bubblesortbio ()
{
	int tamanho, troca = 1;
	string temp;
	tamanho = this->biobooks.size();
	while(troca && tamanho > 0){
		troca = 0;
		for (int j=0; j< (tamanho-1); j++){
			if (this->biobooks.at(j).get_nome() > this->biobooks.at(j+1).get_nome())
			{
			 /* troca */
				temp = this->biobooks.at(j).get_nome();
			this->biobooks.at(j).set_nome(this->biobooks.at(j+1).get_nome());
				this->biobooks.at(j+1).set_nome(temp);
				troca = 1;
			}
		}
		tamanho = tamanho-1;
	}

	
}

// ******* Método para buscar no vetor dos livros *********

bool Books::buscabinariabio(string recentname)
{
    string name;
	int tamanho = this->biobooks.size() -1;
	int metade;
	int inicio = 0;
	
	 
	
	while (inicio <= tamanho)
{
	metade = (inicio + tamanho)/2;
	name = this->biobooks.at(metade).get_nome(); 
	if (recentname == name)
	{
	cout << "Livro encontrado" << endl;
	return true;
	
	}
	else if (recentname < name)
	{
	tamanho = metade -1;
	}else 
	inicio = metade+1;
}
cout << "Livro nao encontrado" << endl;
return false;
}

// ******* Método para mudar a flag e sinalizar que o livro está emprestado *********

void Books::mudarflagemprestabio (string name)
{
	
	cout << "Deseja mesmo pegar o livro emprestado? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->biobooks.size(); i++)
	{
		if (name == this->biobooks.at(i).get_nome())
		this->biobooks.at(i).set_flag(true);
		
		
	}
	

	cout << "Livro emprestado com sucesso" << endl;
	iniciodoprograma();
	
	
}

// ******* Método para mudar a flag e sinalizar que o livro não está emprestado *********

void Books::mudarflagdevolvebio (string name)
{
	
	cout << "Deseja mesmo devolver o livro? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->biobooks.size(); i++)
	{
		if (name == this->biobooks.at(i).get_nome())
		this->biobooks.at(i).set_flag(false);
		
		
	}
}

// ******* Método para emprestar os livros *********	
	
void Books::emprestaBiologia(string name)
{
		if (buscabinariabio(name) == true)
		mudarflagemprestabio(name);
		
	
 } 
 
 // ******* Método para devolver os livros *********

void Books::devolveBiologia(string name)
{
		if (buscabinariabio(name))
		mudarflagdevolvebio(name);

	
	
	
 } 
 
 // ******* Método para adicionar livros ao vetor *********
 
void Books::addBiologia(Books b)
{

  this->biobooks.push_back(b);
  for (int k=0; k < this->biobooks.size(); k++)
  	{
  		cout << this->biobooks.at(k).get_nome();
  	}
  cout << "Adicionar outro livro (1 /0)?" << endl; 
  int escolha;
  cin >> escolha; 
  if (escolha == 1)
  registrarLivros();
  else
  bubblesortbio();


  std::ofstream myfile("livrosbiologia.txt", std::ios_base::app | std::ios_base::out);

  if (myfile.is_open())
  {
  	for (int i=0; i < this->biobooks.size(); i++)
  	{
	  
  	
    myfile << this->biobooks.at(i).get_nome() << endl;
    myfile << this->biobooks.at(i).get_autor() << endl;
    myfile << this->biobooks.at(i).get_ano() << endl;
    myfile << this->biobooks.at(i).get_situacao() << endl;
    myfile.close();
  
  }}
  
  else cout << "Unable to open file";
  
  menuFuncionario();
  
	
}


// **************************************************** Métodos para livros de humanas *****************************************************************

// ******* Método para consultar os livros *********
 
void Books::consultarLivroshum()
{
	string name;
	string escolha;
	cout << "Digite o nome do livro a ser consultado" << endl;
	cin >> name;
	if (buscabinariahum(name))
	{
		
		for (int i=0; i < this->humanbooks.size(); i++)
		{
			if (name == this->humanbooks.at(i).get_nome())
			{
			cout << "Nome:" << this->humanbooks.at(i).get_nome() << endl;
			cout << "Autor:" << this->humanbooks.at(i).get_autor() << endl;
			cout << "Ano:" << this->humanbooks.at(i).get_ano() << endl;
			if (this->humanbooks.at(i).get_situacao() == true)
			cout << "Situação: Emprestado" << endl;
			else
			cout << "Situação: Disponível" << endl;
		}	}
		
	}	
	
	else 
	{	
	
	cout << "Tente outro livro, este não consta em nossa base de dados" << endl;
	iniciodoprograma();
}
		
	cout << "Deseja consultar outro livro? (y/n)" << endl;
	cin >> escolha;
	if (escolha == "y")
	consultarLivroshum();
	else
	iniciodoprograma();
	
	
}

// ******* Método para ordernar os livros *********

void Books::bubblesorthum ()
{
	int tamanho, troca = 1;
	string temp;
	tamanho = this->humanbooks.size();
	while(troca && tamanho > 0){
		troca = 0;
		for (int j=0; j< (tamanho-1); j++){
			if (this->humanbooks.at(j).get_nome() > this->humanbooks.at(j+1).get_nome())
			{
			 /* troca */
				temp = this->humanbooks.at(j).get_nome();
			this->humanbooks.at(j).set_nome(this->humanbooks.at(j+1).get_nome());
				this->humanbooks.at(j+1).set_nome(temp);
				troca = 1;
			}
		}
		tamanho = tamanho-1;
	}

	
}

// ******* Método para buscar no vetor dos livros *********

bool Books::buscabinariahum(string recentname)
{
    string name;
	int tamanho = this->humanbooks.size() -1;
	int metade;
	int inicio = 0;
	
	 
	
	while (inicio <= tamanho)
{
	metade = (inicio + tamanho)/2;
	name = this->humanbooks.at(metade).get_nome(); 
	if (recentname == name)
	{
	cout << "Livro encontrado" << endl;
	return true;
	
	}
	else if (recentname < name)
	{
	tamanho = metade -1;
	}else 
	inicio = metade+1;
}
cout << "Livro nao encontrado" << endl;
return false;
}

// ******* Método para mudar a flag e sinalizar que o livro está emprestado *********

void Books::mudarflagemprestahum (string name)
{
	
	cout << "Deseja mesmo pegar o livro emprestado? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->humanbooks.size(); i++)
	{
		if (name == this->humanbooks.at(i).get_nome())
		this->humanbooks.at(i).set_flag(true);
		
		
	}
	

	cout << "Livro emprestado com sucesso" << endl;
	iniciodoprograma();
	
	
}

// ******* Método para mudar a flag e sinalizar que o livro não está emprestado *********

void Books::mudarflagdevolvehum (string name)
{
	
	cout << "Deseja mesmo devolver o livro? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->humanbooks.size(); i++)
	{
		if (name == this->humanbooks.at(i).get_nome())
		this->humanbooks.at(i).set_flag(false);
		
		
	}
}

// ******* Método para emprestar os livros *********	
	
void Books::emprestaHumanas(string name)
{
		if (buscabinariahum(name) == true)
		mudarflagemprestahum(name);
		
	
 } 
 
 // ******* Método para devolver os livros *********

void Books::devolveHumanas(string name)
{
		if (buscabinariahum(name))
		mudarflagdevolvehum(name);

	
	
	
 } 
 
 // ******* Método para adicionar livros ao vetor *********
 
void Books::addHumanas(Books b)
{

  this->humanbooks.push_back(b);
  for (int k=0; k < this->humanbooks.size(); k++)
  	{
  		cout << this->humanbooks.at(k).get_nome();
  	}
  cout << "Adicionar outro livro (1 /0)?" << endl; 
  int escolha;
  cin >> escolha; 
  if (escolha == 1)
  registrarLivros();
  else
  bubblesorthum();


  std::ofstream myfile("livrosbiologia.txt", std::ios_base::app | std::ios_base::out);

  if (myfile.is_open())
  {
  	for (int i=0; i < this->humanbooks.size(); i++)
  	{
	  
  	
    myfile << this->humanbooks.at(i).get_nome() << endl;
    myfile << this->humanbooks.at(i).get_autor() << endl;
    myfile << this->humanbooks.at(i).get_ano() << endl;
    myfile << this->humanbooks.at(i).get_situacao() << endl;
    myfile.close();
  
  }}
  
  else cout << "Unable to open file";
  
  menuFuncionario();
  
	
}


// ********************************************************* Métodos para livros de saude *****************************************************************

// ******* Método para consultar os livros *********
 
void Books::consultarLivrossaude()
{
	string name;
	string escolha;
	cout << "Digite o nome do livro a ser consultado" << endl;
	cin >> name;
	if (buscabinariasaude(name))
	{
		
		for (int i=0; i < this->healthbooks.size(); i++)
		{
			if (name == this->healthbooks.at(i).get_nome())
			{
			cout << "Nome:" << this->healthbooks.at(i).get_nome() << endl;
			cout << "Autor:" << this->healthbooks.at(i).get_autor() << endl;
			cout << "Ano:" << this->healthbooks.at(i).get_ano() << endl;
			if (this->healthbooks.at(i).get_situacao() == true)
			cout << "Situação: Emprestado" << endl;
			else
			cout << "Situação: Disponível" << endl;
		}	}
		
	}	
	
	else 
	{	
	
	cout << "Tente outro livro, este não consta em nossa base de dados" << endl;
	iniciodoprograma();
}
		
	cout << "Deseja consultar outro livro? (y/n)" << endl;
	cin >> escolha;
	if (escolha == "y")
	consultarLivrossaude();
	else
	iniciodoprograma();
	
	
}

// ******* Método para ordernar os livros *********

void Books::bubblesortsaude ()
{
	int tamanho, troca = 1;
	string temp;
	tamanho = this->healthbooks.size();
	while(troca && tamanho > 0){
		troca = 0;
		for (int j=0; j< (tamanho-1); j++){
			if (this->healthbooks.at(j).get_nome() > this->healthbooks.at(j+1).get_nome())
			{
			 /* troca */
				temp = this->healthbooks.at(j).get_nome();
			this->healthbooks.at(j).set_nome(this->healthbooks.at(j+1).get_nome());
				this->healthbooks.at(j+1).set_nome(temp);
				troca = 1;
			}
		}
		tamanho = tamanho-1;
	}

	
}

// ******* Método para buscar no vetor dos livros *********

bool Books::buscabinariasaude(string recentname)
{
    string name;
	int tamanho = this->healthbooks.size() -1;
	int metade;
	int inicio = 0;
	
	 
	
	while (inicio <= tamanho)
{
	metade = (inicio + tamanho)/2;
	name = this->healthbooks.at(metade).get_nome(); 
	if (recentname == name)
	{
	cout << "Livro encontrado" << endl;
	return true;
	
	}
	else if (recentname < name)
	{
	tamanho = metade -1;
	}else 
	inicio = metade+1;
}
cout << "Livro nao encontrado" << endl;
return false;
}

// ******* Método para mudar a flag e sinalizar que o livro está emprestado *********

void Books::mudarflagemprestasaude (string name)
{
	
	cout << "Deseja mesmo pegar o livro emprestado? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->healthbooks.size(); i++)
	{
		if (name == this->healthbooks.at(i).get_nome())
		this->healthbooks.at(i).set_flag(true);
		
		
	}
	

	cout << "Livro emprestado com sucesso" << endl;
	iniciodoprograma();
	
	
}

// ******* Método para mudar a flag e sinalizar que o livro não está emprestado *********

void Books::mudarflagdevolvesaude (string name)
{
	
	cout << "Deseja mesmo devolver o livro? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->healthbooks.size(); i++)
	{
		if (name == this->healthbooks.at(i).get_nome())
		this->healthbooks.at(i).set_flag(false);
		
		
	}
}

// ******* Método para emprestar os livros *********	
	
void Books::emprestaSaude(string name)
{
		if (buscabinariasaude(name) == true)
		mudarflagemprestasaude(name);
		
	
 } 
 
 // ******* Método para devolver os livros *********

void Books::devolveSaude(string name)
{
		if (buscabinariasaude(name))
		mudarflagdevolvesaude(name);

	
	
	
 } 
 
 // ******* Método para adicionar livros ao vetor *********
 
void Books::addSaude(Books b)
{

  this->healthbooks.push_back(b);
  for (int k=0; k < this->healthbooks.size(); k++)
  	{
  		cout << this->healthbooks.at(k).get_nome();
  	}
  cout << "Adicionar outro livro (1 /0)?" << endl; 
  int escolha;
  cin >> escolha; 
  if (escolha == 1)
  registrarLivros();
  else
  bubblesortsaude();


  std::ofstream myfile("livrosbiologia.txt", std::ios_base::app | std::ios_base::out);

  if (myfile.is_open())
  {
  	for (int i=0; i < this->healthbooks.size(); i++)
  	{
	  
  	
    myfile << this->healthbooks.at(i).get_nome() << endl;
    myfile << this->healthbooks.at(i).get_autor() << endl;
    myfile << this->healthbooks.at(i).get_ano() << endl;
    myfile << this->healthbooks.at(i).get_situacao() << endl;
    myfile.close();
  
  }}
  
  else cout << "Unable to open file";
  
  menuFuncionario();
  
	
}

// ***************************************************** Métodos para os livros de matemática ************************************************************

// ******* Método para consultar os livros *********
 
void Books::consultarLivrosmat()
{
	string name;
	string escolha;
	cout << "Digite o nome do livro a ser consultado" << endl;
	cin >> name;
	if (buscabinariamat(name))
	{
		
		for (int i=0; i < this->mathbooks.size(); i++)
		{
			if (name == this->mathbooks.at(i).get_nome())
			{
			cout << "Nome:" << this->mathbooks.at(i).get_nome() << endl;
			cout << "Autor:" << this->mathbooks.at(i).get_autor() << endl;
			cout << "Ano:" << this->mathbooks.at(i).get_ano() << endl;
			if (this->mathbooks.at(i).get_situacao() == true)
			cout << "Situação: Emprestado" << endl;
			else
			cout << "Situação: Disponível" << endl;
		}	}
		
	}	
	
	else 
	{	
	
	cout << "Tente outro livro, este não consta em nossa base de dados" << endl;
	iniciodoprograma();
}
		
	cout << "Deseja consultar outro livro? (y/n)" << endl;
	cin >> escolha;
	if (escolha == "y")
	consultarLivrosmat();
	else
	iniciodoprograma();
	
	
}

// ******* Método para ordernar os livros *********

void Books::bubblesortmat ()
{
	int tamanho, troca = 1;
	string temp;
	tamanho = this->mathbooks.size();
	while(troca && tamanho > 0){
		troca = 0;
		for (int j=0; j< (tamanho-1); j++){
			if (this->mathbooks.at(j).get_nome() > this->mathbooks.at(j+1).get_nome())
			{
			 /* troca */
				temp = this->mathbooks.at(j).get_nome();
			this->mathbooks.at(j).set_nome(this->mathbooks.at(j+1).get_nome());
				this->mathbooks.at(j+1).set_nome(temp);
				troca = 1;
			}
		}
		tamanho = tamanho-1;
	}

	
}

// ******* Método para buscar no vetor dos livros *********

bool Books::buscabinariamat(string recentname)
{
    string name;
	int tamanho = this->mathbooks.size() -1;
	int metade;
	int inicio = 0;
	
	 
	
	while (inicio <= tamanho)
{
	metade = (inicio + tamanho)/2;
	name = this->mathbooks.at(metade).get_nome(); 
	if (recentname == name)
	{
	cout << "Livro encontrado" << endl;
	return true;
	
	}
	else if (recentname < name)
	{
	tamanho = metade -1;
	}else 
	inicio = metade+1;
}
cout << "Livro nao encontrado" << endl;
return false;
}

// ******* Método para mudar a flag e sinalizar que o livro está emprestado *********

void Books::mudarflagemprestamat (string name)
{
	
	cout << "Deseja mesmo pegar o livro emprestado? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->mathbooks.size(); i++)
	{
		if (name == this->mathbooks.at(i).get_nome())
		this->mathbooks.at(i).set_flag(true);
		
		
	}
	

	cout << "Livro emprestado com sucesso" << endl;
	iniciodoprograma();
	
	
}

// ******* Método para mudar a flag e sinalizar que o livro não está emprestado *********

void Books::mudarflagdevolvemat (string name)
{
	
	cout << "Deseja mesmo devolver o livro? (y/n)" << endl;
	string escolha;
	cin >> escolha; 
	if (escolha == "y")
	for (int i =0; i < this->mathbooks.size(); i++)
	{
		if (name == this->mathbooks.at(i).get_nome())
		this->mathbooks.at(i).set_flag(false);
		
		
	}
}

// ******* Método para emprestar os livros *********	
	
void Books::emprestaExatas(string name)
{
		if (buscabinariamat(name) == true)
		mudarflagemprestamat(name);
		
	
 } 
 
 // ******* Método para devolver os livros *********

void Books::devolveExatas(string name)
{
		if (buscabinariamat(name))
		mudarflagdevolvemat(name);

	
	
	
 } 
 
 // ******* Método para adicionar livros ao vetor *********
 
void Books::addExatas(Books b)
{

  this->mathbooks.push_back(b);
  for (int k=0; k < this->mathbooks.size(); k++)
  	{
  		cout << this->mathbooks.at(k).get_nome();
  	}
  cout << "Adicionar outro livro (1 /0)?" << endl; 
  int escolha;
  cin >> escolha; 
  if (escolha == 1)
  registrarLivros();
  else
  bubblesortmat();


  std::ofstream myfile("livrosbiologia.txt", std::ios_base::app | std::ios_base::out);

  if (myfile.is_open())
  {
  	for (int i=0; i < this->mathbooks.size(); i++)
  	{
	  
  	
    myfile << this->mathbooks.at(i).get_nome() << endl;
    myfile << this->mathbooks.at(i).get_autor() << endl;
    myfile << this->mathbooks.at(i).get_ano() << endl;
    myfile << this->mathbooks.at(i).get_situacao() << endl;
    myfile.close();
  
  }}
  
  else cout << "Unable to open file";
  
  menuFuncionario();
  
	
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
	
	
	
	

