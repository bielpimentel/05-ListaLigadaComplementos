#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* anterior = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* buscadorDeElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL) // Não havendo elementos na lista, o novo elemento será o primeiro.
	{
		primeiro = novo;
	}
	else if (primeiro->valor > novo->valor) // Checa se o primeiro elemento da lista atual é maior que o novo
	{
		NO* aux = primeiro;
		primeiro = novo;
		novo->prox = aux;
	}
	else // Adiciona o novo elemento de forma ordenada na lista
	{
		NO* aux = primeiro;
		while (aux->prox != NULL && novo->valor > aux->prox->valor) {
			aux = aux->prox;
		}
		novo->prox = aux->prox;
		aux->prox = novo;
	}
}

void excluirElemento()
{
	int numero;
	cout << "Digite o numero a ser excluido da lista: ";
	cin >> numero;
	NO* paraExcluir = buscadorDeElemento(numero);
	
	if (paraExcluir->valor != numero) {
		cout << "O numero digitado nao existe na lista." << endl;
		return;
	}
	else if (primeiro == paraExcluir) {
		primeiro = paraExcluir->prox;
		free(paraExcluir);
	}
	else {
		anterior->prox = paraExcluir->prox;
		free(paraExcluir);
	}
	cout << "Elemento excluido!" << endl;
}

void buscarElemento()
{
	int numero;
	cout << "Digite o numero a ser buscado na lista: ";
	cin >> numero;
	int paraBuscar = buscadorDeElemento(numero)->valor;

	if (paraBuscar == numero) {
		cout << "Elemento ENCONTRADO na lista!" << endl;
	}
	else {
		cout << "Elemento NAO encontrado na lista!" << endl;
	}
}

NO* buscadorDeElemento(int numero){

	NO* aux = primeiro;
	while (aux != NULL && numero > aux->valor) {
		anterior = aux;
		aux = aux->prox;
	}
	if (aux != NULL) {
		return aux;
	}
	else {
		return anterior;
	}
}


