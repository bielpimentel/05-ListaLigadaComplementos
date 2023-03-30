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

	cout << "Digite o elemento a ser inserido: ";
	cin >> novo->valor;

	if (primeiro == NULL || primeiro->valor > novo->valor)  // Não havendo elementos na lista ou o primeiro elemento sendo maior que o novo, este será definido como primeiro.
	{
		novo->prox = primeiro;
		primeiro = novo;
		cout << "Elemento adicionado!" << endl << endl;
		return;
	}

	NO* posicao = buscadorDeElemento(novo->valor);  // Função de busca personalizada.
	if (posicao && posicao->valor == novo->valor) {  // Checa se o elemento já existe na lista e impede que seja duplicado.
		cout << "O numero digitado ja existe na lista." << endl << endl;
	}
	else {  // Posiciona o novo elemento em ordem crescente na lista.
		novo->prox = anterior->prox;   
		anterior->prox = novo;
		cout << "Elemento adicionado!" << endl << endl;
	}
}

void excluirElemento()
{
	int numero;
	cout << "Digite o numero a ser excluido da lista: ";
	cin >> numero;
	NO* paraExcluir = buscadorDeElemento(numero);  // Função de busca personalizada.
	
	if (paraExcluir == NULL || paraExcluir->valor != numero) {  // Checa se o elemento já existe na lista.
		cout << "O numero digitado nao existe na lista." << endl << endl;
		return;
	}
	else if (primeiro == paraExcluir) {  // Checa se o elemento a ser excluído é o primeiro da lista.
		primeiro = paraExcluir->prox;
		free(paraExcluir);
	}
	else {
		anterior->prox = paraExcluir->prox;  // Prossegue normalmente com a exclusão, realocando os elementos e ponteiros.
		free(paraExcluir);
	}
	cout << "Elemento excluido!" << endl << endl;
}

void buscarElemento()
{
	int numero;
	cout << "Digite o numero a ser buscado na lista: ";
	cin >> numero;
	NO* paraBuscar = buscadorDeElemento(numero);

	if (paraBuscar && paraBuscar->valor == numero) {  
		cout << "Elemento ENCONTRADO na lista!" << endl << endl;
	}
	else {
		cout << "Elemento NAO encontrado na lista!" << endl << endl;
	}
}

NO* buscadorDeElemento(int numero){   // Função de busca personalizada.

	NO* aux = primeiro;
	while (aux != NULL && numero > aux->valor) {
		anterior = aux;
		aux = aux->prox;
	}
	return aux;
}


