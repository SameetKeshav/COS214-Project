#ifndef HISTORYBOOK_H
#define HISTORYBOOK_H

class HistoryBook {

private:
	History* defectedAllies[];

public:
	void add(History* m);

	Bannerman* restoreAlly(History* m);

	void ~Caretaker();
};

#endif
