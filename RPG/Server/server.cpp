#include "server.h"

#include <windows.h>
#include <tchar.h>
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>

//Defines
#define MaxPlayersInGame 5 
#define PIPE_NAME TEXT("\\\\.\\pipe\\pipe1")
#define PIPE_NAME2 TEXT("\\\\.\\pipe\\pipe2")
#define REGISTRY_KEY TEXT("Software\\TPSO2\\");

//Declaracao da funcoes
DWORD WINAPI ThreadReadAndWriteInformation(LPVOID param);

//Declaração de variaveis
HANDLE hPipeAct[MaxPlayersInGame], hEvent;
int NumberGamesActive = 0;
BOOL fim = FALSE;
int numero = 1;


using namespace std;
#ifdef UNICODE 
#define tcout wcout
#define tcin wcin
#else
#define tcout cout
#define tcin cin
#endif

typedef basic_string<TCHAR, char_traits<TCHAR>, allocator<TCHAR> >tstring;
#ifdef UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif

//Declaracoes das estruturas
struct resposta
{
	int ID_Cliente;
	bool JogoCriado;
	bool JogoIniciado;
	int EsperaPlayers;
<<<<<<< HEAD
	char nome[100];

=======
	char nome[50];
>>>>>>> origin/master
};
struct resposta res;

struct cliente {

	TCHAR nome[256];
<<<<<<< HEAD
	HANDLE Hpipe;

};
struct cliente c[MaxPlayersInGame];

int numero = 0;
=======
	HANDLE hpipe;
};
struct cliente c[MaxPlayersInGame]; 


>>>>>>> origin/master

int _tmain(int argc, LPTSTR argv[]) {

	HANDLE hThread = NULL;
	HANDLE hThreadMap = NULL;
	HANDLE hPipe;
	HANDLE hPipe2;
	OVERLAPPED Ovl;
	int i;
	string Comando;

#ifdef UNICODE 
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
	_setmode(_fileno(stderr), _O_WTEXT);
#endif

	hEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	Ovl.hEvent = hEvent;

	_tprintf(TEXT("\n-------------- Waiting for clients to connect! --------------\n"));

	for (i = 0; i < MaxPlayersInGame && !fim; i++) {

		//Duplex communication between PIPE
		hPipe = CreateNamedPipe(PIPE_NAME, PIPE_ACCESS_DUPLEX | FILE_FLAG_OVERLAPPED, PIPE_WAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE, 5 /*Variavel (MaxPlayersInGame)*/, 256, 256,1000, NULL);

		//Generic write Pipe created
		hPipeAct[i] = CreateNamedPipe(PIPE_NAME2, PIPE_ACCESS_OUTBOUND | FILE_FLAG_OVERLAPPED, PIPE_WAIT | PIPE_TYPE_MESSAGE| PIPE_READMODE_MESSAGE, 5 /*Variavel (MaxPlayersInGame)*/, 256, 256, 1000, NULL);

		if (hPipeAct[i] == INVALID_HANDLE_VALUE) {
			tcout << TEXT("Error when client try to connect\n") << hPipeAct[i];
			exit(-1);
		}
		
		ConnectNamedPipe(hPipeAct[i], &Ovl);
		WaitForSingleObject(Ovl.hEvent, INFINITE);
		
		//Thread para ler e escever
		hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadReadAndWriteInformation, (LPVOID)hPipe, 0, NULL);
	}

	WaitForSingleObject(hThread, INFINITE);
	tcout << TEXT("[Servidor] System will shutdown");
	Sleep(10000);
	
	return 0;
}


void UpdateMap() {



}

bool Authentication(LPCWSTR nome, LPCWSTR pass) {

	HKEY hKey;
	DWORD queAconteceu, versao, tamanho;
	TCHAR autor[200];
	TCHAR keyName[200] = REGISTRY_KEY;
	wcscat_s(keyName, nome);

	//Criar/abrir uma chave em HKEY_CURRENT_USER\Software\MinhaAplicacao
	if (RegCreateKeyEx(HKEY_CURRENT_USER, keyName, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &queAconteceu) != ERROR_SUCCESS) {
		tcout << TEXT("Erro ao criar/abrir chave (%d)\n"), GetLastError();
		return false;
	}

	//Se a chave foi criada, inicializar os valores

	RegSetValueEx(hKey, TEXT("Nome"), 0, REG_SZ, (LPBYTE)nome, _tcslen(nome)*sizeof(TCHAR));

	RegSetValueEx(hKey, TEXT("Pass"), 0, REG_SZ, (LPBYTE)pass, _tcslen(pass)*sizeof(TCHAR));

	return true;

}

DWORD WINAPI ThreadReadAndWriteInformation(LPVOID param) {

	DWORD n;
	BOOL ret;
	int i;
	TCHAR buf[256];
<<<<<<< HEAD
	TCHAR buf2[256];
	TCHAR buffer[256];
=======
	TCHAR nome[256];
	TCHAR password[256];
>>>>>>> origin/master
	int aux;
	HANDLE client = (HANDLE)param;
	int ValidarCmd = -1;
	tstring sub1;
	tstring sub2;
	LPCTSTR pStr;
	string Comando = "";
	string TipoComando = "";
	bool logged = false;
<<<<<<< HEAD

	//ALTERADO
	_tcscpy_s(buf2, 256, (TEXT("")));

	ret = ReadFile(client, buf2, sizeof(buf2), &n, NULL);
	buf2[n / sizeof(TCHAR)] = '\0';
	wcscpy_s(c[numero].nome, buf2);
	c[numero].Hpipe = client;
	_tprintf(TEXT("[Servidor] O cliente tem o nome como: %s\n"), c[numero].nome);
=======
	
	_tcscpy_s(nome, 256, (TEXT("")));

	ret = ReadFile(client, nome, sizeof(nome), &n, NULL);
	nome[n / sizeof(TCHAR)] = '\0';
	ret = ReadFile(client, password, sizeof(password), &n, NULL);
	password[n / sizeof(TCHAR)] = '\0';
	Authentication(nome, password);
	wcscpy_s(c[numero].nome, nome);
	c[numero].hpipe = client;
	_tprintf(TEXT("[Servidor] O cliente tem o nome como: %s\n\n"), c[numero].nome);
>>>>>>> origin/master
	numero++;

	do {
		sub1 = TEXT("");
		sub2 = TEXT("");
		ValidarCmd = -1;
		_tcscpy_s(buf, 256, (TEXT("[Servidor] Connected to server!!!\n")));

		Comando = "";
		TipoComando = "";
		sub1.clear();
		sub2.clear();
		
		for (int i = 0; i < MaxPlayersInGame; i++) {
			logged = WriteFile(hPipeAct[i], buf, _tcslen(buf) * sizeof(TCHAR), &n, NULL);
<<<<<<< HEAD
			if (logged == true) {
				_tprintf(TEXT("\nClient connected!!!\n"));

=======
			if (logged == true) {			
				_tprintf(TEXT("[Server] Name of client[%d] is %s\n"), i,c[i].nome); 
>>>>>>> origin/master
			}
		}

		_tprintf(TEXT("\n\n"));

		for (int i = 0; i < MaxPlayersInGame; i++) {
			res.JogoCriado = TRUE;
			res.JogoIniciado = TRUE;
<<<<<<< HEAD
			//Write
=======
>>>>>>> origin/master
			WriteFile(hPipeAct[i], &res, sizeof(struct resposta), &n, NULL);
		}

		ret = ReadFile(client, buf, sizeof(buf), &n, NULL);
		if (!ret || !n) {
<<<<<<< HEAD
			for (int j = 0; j < MaxPlayersInGame; j++) {
				if (client == c[numero].Hpipe) {
					_tprintf(TEXT("[Server] Cliente nº %d, %s, has disconnected"), c, c[numero].nome);
					for (int i = 0; i < MaxPlayersInGame; i++) {
						wcscpy_s(c[i].nome, c[i + 1].nome);
						c[i].Hpipe = c[i + 1].Hpipe;
=======
			for (int i = 0; i < MaxPlayersInGame; i++) {
				if (client == c[i].hpipe) {
					_tprintf(TEXT("[Servidor] O cliente %d, o %s desligou-se\n\n"), c, c[i].nome);
					for (int k = i; k < MaxPlayersInGame; k++) {
						wcscpy_s(c[k].nome, c[k + 1].nome);
						c[k].hpipe = c[k + 1].hpipe;
>>>>>>> origin/master
					}
				}
			}
			break;
		}		

		//Ver a partir de aqui 
		buf[n / sizeof(TCHAR)] = '\0';
		for (int y = 0; y < MaxPlayersInGame; y++) {
			if (client == c[y].hpipe) {
				_tprintf(TEXT("[Servidor] O cliente %d, o %s mandou o comando: %s\n\n"), y, c[y].nome, buf);
			}
		}

		pStr = buf;
		tstring str(pStr);
		sub1 = str.substr(str.find(TEXT(" ")) + 1);// ultima palavra
		sub2 = str.substr(0, str.length() - sub1.length() - 1);  //primeira palavra
		for (int i = 0; i < sub1.length(); i++)
			Comando += sub1.at(i);
		for (int i = 0; i < sub2.length(); i++)
			TipoComando += sub2.at(i);

	} while (_tcsncmp(buf, TEXT("[Servidor] End!!!\n"), 100));

	return 0;
}