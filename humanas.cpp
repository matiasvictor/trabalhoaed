#include "projeto.h"
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