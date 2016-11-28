
#include "projeto.h"

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
