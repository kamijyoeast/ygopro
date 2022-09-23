#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include "config.h"
#include "client_card.h"
#include <unordered_map>
#include <vector>
#ifndef YGOPRO_SERVER_MODE
#include <sstream>
#endif

namespace ygo {

struct LFList {
	unsigned int hash;
	std::wstring listName;
	std::unordered_map<int, int> content;
};
struct Deck {
	std::vector<code_pointer> main;
	std::vector<code_pointer> extra;
	std::vector<code_pointer> side;
	Deck() {}
	Deck(const Deck& ndeck) {
		main = ndeck.main;
		extra = ndeck.extra;
		side = ndeck.side;
	}
	void clear() {
		main.clear();
		extra.clear();
		side.clear();
	}
};

class DeckManager {
public:
	Deck current_deck;
	std::vector<LFList> _lfList;

#ifndef YGOPRO_SERVER_MODE
	static char deckBuffer[0x10000];
#endif

	void LoadLFListSingle(const char* path);
	void LoadLFList();
	const wchar_t* GetLFListName(int lfhash);
	const std::unordered_map<int, int>* GetLFListContent(int lfhash);
	int CheckDeck(Deck& deck, int lfhash, int rule);
	int LoadDeck(Deck& deck, int* dbuf, int mainc, int sidec, bool is_packlist = false);
	bool LoadSide(Deck& deck, int* dbuf, int mainc, int sidec);
#ifndef YGOPRO_SERVER_MODE
	void GetCategoryPath(wchar_t* ret, int index, const wchar_t* text);
	void GetDeckFile(wchar_t* ret, irr::gui::IGUIComboBox* cbCategory, irr::gui::IGUIComboBox* cbDeck);
	bool LoadDeck(irr::gui::IGUIComboBox* cbCategory, irr::gui::IGUIComboBox* cbDeck);
	FILE* OpenDeckFile(const wchar_t* file, const char* mode);
	IReadFile* OpenDeckReader(const wchar_t* file);
	bool LoadDeck(const wchar_t* file, bool is_packlist = false);
	bool LoadDeck(std::istringstream* deckStream, bool is_packlist = false);
	bool SaveDeck(Deck& deck, const wchar_t* file);
	bool DeleteDeck(const wchar_t* file);
	wchar_t DeckFormatBuffer[128];
	int TypeCount(std::vector<code_pointer> list, unsigned int ctype);
	bool LoadDeckFromCode(Deck& deck, const char *code, int len);
	int SaveDeckToCode(Deck &deck, char *code);
	bool CreateCategory(const wchar_t* name);
	bool RenameCategory(const wchar_t* oldname, const wchar_t* newname);
	bool DeleteCategory(const wchar_t* name);
#endif //YGOPRO_SERVER_MODE
};

extern DeckManager deckManager;

}

#ifdef YGOPRO_SERVER_MODE

#ifndef DECKCOUNT_MAIN_MIN
#define DECKCOUNT_MAIN_MIN 40
#endif

#ifndef DECKCOUNT_MAIN_MAX
#define DECKCOUNT_MAIN_MAX 60
#endif

#ifndef DECKCOUNT_SIDE
#define DECKCOUNT_SIDE 15
#endif

#ifndef DECKCOUNT_EXTRA
#define DECKCOUNT_EXTRA 15
#endif

#endif //YGOPRO_SERVER_MODE

#endif //DECKMANAGER_H
