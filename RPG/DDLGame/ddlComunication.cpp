#include "ddlComunication.h"
#include <sstream>


typedef basic_string<TCHAR, char_traits<TCHAR>, allocator<TCHAR> >tstring;
#ifdef UNICODE
typedef wstring tstring;
#else
typedef string tstring;
#endif


char ponteiro[40960];
int PlayersActive = 0;

int ShowActivePlayers() {
	return PlayersActive;
}

void RemovePlayer() {
	PlayersActive--;
}

void AddActivePlayer() {
	PlayersActive++;
}