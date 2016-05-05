#include "Interface.h"

void start_menu() {

	int option;
	string nomePlayer;

	_tprintf(TEXT("\n-----Menu-----\n"));
	_tprintf(TEXT("\n1 - Jogar\n"));
	_tprintf(TEXT("\n2 - Sair\n"));
	_tprintf(TEXT("\nResposta: "));
	tcin >> option;

	if (option == 1) {
		//system("cls");
		//chamar a funcao de registar e introduzir os dados
	}
	else
		if (option == 2)
			exit(0);

}