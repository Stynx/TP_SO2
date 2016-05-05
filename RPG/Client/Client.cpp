#include "Interface.h"

#define MaxPlayersInGame 5 
#define PIPE_NAME TEXT("\\\\.\\pipe\\pipe1")
#define PIPE_NAME2 TEXT("\\\\.\\pipe\\pipe2")

#ifndef UNICODE  
typedef std::string String;
#else
typedef std::wstring String;
#endif


//Declaracoes das estruturas
struct resposta
{
	int ID_Cliente;
	bool JogoCriado;
	bool JogoIniciado;
	int EsperaPlayers;
	char nome[50];
<<<<<<< HEAD

=======
>>>>>>> origin/master
};
struct resposta res;

struct cliente {
<<<<<<< HEAD
	
	TCHAR nome[256];
	//HANDLE Hpipe;
=======
>>>>>>> origin/master

	TCHAR nome[256];
	HANDLE hpipe;
};
struct cliente c[MaxPlayersInGame];

//declaracoes de variaveis
static int ID_Client = 0;
static TCHAR Comand[256];
HANDLE hPipe;
HANDLE hPipe2;
DWORD WINAPI Read_Console(LPVOID param);


int _tmain(int argc, LPTSTR argv[]) {

	HANDLE hThread = NULL;

#ifdef UNICODE 
	_setmode(_fileno(stdin), _O_WTEXT);
	_setmode(_fileno(stdout), _O_WTEXT);
#endif

	if (!WaitNamedPipe(PIPE_NAME, NMPWAIT_WAIT_FOREVER)) {
		_tprintf(TEXT("[Information] Connecting... '%s'\n"), PIPE_NAME);
		exit(-1);
	}

	hPipe = CreateFile(PIPE_NAME, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	hPipe2 = CreateFile(PIPE_NAME2, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hPipe == NULL) {
		_tprintf(TEXT("[Information]Can't create connection with server %d, try later.\n"), PIPE_NAME);
		exit(-1);
	}

	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Read_Console, (LPVOID)hPipe2, 0, NULL);

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hPipe);
	Sleep(200);

	return 0;
}


DWORD WINAPI Read_Console(LPVOID param) {

		//Ver cliente

		HANDLE hpipelocal = (HANDLE)param;
		DWORD n;
		int i = 0;
		TCHAR buf[256];
		TCHAR name[256];
		BOOL ret;

		//Autenticação do cliente
		_tprintf(TEXT("[Autenticação - coloque o nome]: "));
		fflush(stdin);
		_fgetts(Comand, 256, stdin);
		Comand[_tcslen(Comand) - 1] = '\0';
		wcscpy_s(name, Comand);
		res.ID_Cliente = ID_Client;
		WriteFile(hPipe, Comand, _tcslen(Comand) * sizeof(TCHAR), &n, NULL);

		_tprintf(TEXT("[Autenticação - coloque a passe]: "));
		fflush(stdin);
		_fgetts(Comand, 256, stdin);
		Comand[_tcslen(Comand) - 1] = '\0';
		wcscpy_s(name, Comand);
		res.ID_Cliente = ID_Client;
		WriteFile(hPipe, Comand, _tcslen(Comand) * sizeof(TCHAR), &n, NULL);


		//Read
		ReadFile(hpipelocal, buf, sizeof(buf), &n, NULL);
		buf[n/sizeof(TCHAR)] = '\0';
		_tprintf(TEXT("%s"), buf);

<<<<<<< HEAD
=======
		/*ALTERADO
		_tprintf(TEXT("You need an authentication. Pls enter your name: "));
		fflush(stdin);
		_fgetts(name, 256, stdin);
		name[_tcslen(name) - 1] = '\0';
		res.ID_Cliente = ID_Client;
		WriteFile(hPipe, name, _tcslen(name) * sizeof(TCHAR), &n, NULL);
		*/
>>>>>>> origin/master
		while (1) {
			
			//Read
			ret = ReadFile(hpipelocal, &res, sizeof(struct resposta), &n, NULL);
			
			if (!ret || !n) {
				_tprintf(TEXT("[Client] Server has shutdown\n\n"));
			}
			if (ID_Client == 0) {
				ID_Client = res.ID_Cliente;
			}
			
			/*Corrigir isto */
			res.JogoCriado = TRUE;
			res.JogoIniciado = TRUE;
			
			if (res.JogoCriado == TRUE && res.JogoIniciado == TRUE) {

				_tprintf(TEXT("[%s - Comand]: "), name);
				fflush(stdin);
				_fgetts(Comand, 256, stdin);
				Comand[_tcslen(Comand) - 1] = '\0';
				res.ID_Cliente = ID_Client;

				//Write
				WriteFile(hPipe, Comand, _tcslen(Comand) * sizeof(TCHAR), &n, NULL);
			}
			else
				_tprintf(TEXT("[Client] ERROR"));
		}
	return 0;


}