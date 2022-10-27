#include "HistoryBook.h"
#include<bits/stdc++.h>

/// @brief add memento object to the list of defecetded allies
/// @param h the memento object added
void HistoryBook::add(History* h) {
	defectedAllies.push_back(h);
}

/// @brief restore the state of an ally returning
/// @param h the ally that wants to return
/// @return the state of the ally to be returning
History* HistoryBook::restoreAlly(History* h) {
	list<History*>::iterator it;
	it = find(defectedAllies.begin(), defectedAllies.end(), h);
	if (it != defectedAllies.end()){
		
		return *it;
	}else{
		cout<<"This kingdom is not an ally of yours"<<endl;
	}
}
