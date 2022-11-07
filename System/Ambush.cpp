#include "Ambush.h"
#include <windows.h>
bool Ambush::attack(Bannerman* myBannerman, Bannerman* enemyBannerman){
	if ((myBannerman->getFavour()<minFavour)||((enemyKingdom->getSize()-myKingdom->getSize())>1))
	{
		Greg->setAlly(myBannerman);
		BookOfDura->add(Greg->Store());
		defectedAllies++;
		//add a remove(Bannerman* myBannerman) and add(Bannerman* myBannerman) method to
		//remove/add a particular bannerman
		myKingdom->remove(myBannerman);
		//tell thapelo to add id attribute and a getter, we must
		//formulate a way to make bannerman ids unique
		enemyKingdom->add(myBannerman);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout<<"The commanders are losing faith in your cause. "<<myBannerman->getName()<<" has defected to the other side."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return false;
	}
	int advantage=(stealth-60)/2;
    srand(time(0));
    int val=advantage;
	if (stealth>60)
	{
        cout<<"You approach your enemy's location. They don't notice your advance and you manage to do extra damage as you spring attack from your position."<<endl;
	}else{
        cout<<"You approach your enemy's location. They notice your men and jump to attack!"<<endl;
    }
	 
	while (myBannerman->getHP()>0&&enemyBannerman->getHP()>0)
	{
		if (advantage>0)
        {
            val=rand()%advantage+0;
        }
        else if(advantage<0)
        {
            val=rand()%(0-advantage)+advantage;
        }
        else{
            val=rand()%(myBannerman->getDamage()/2)+(-(myBannerman->getDamage()/4));
        }
		//getDamage is how much damage the bannerman can inflict
		enemyBannerman->receiveDamage(myBannerman->getDamage()+val);
        cout<<"You deal "<<(myBannerman->getDamage()+val)<<" damage to the enemy. Enemy HP:"<<enemyBannerman->getHP()<<endl;
		if (enemyBannerman->getHP()<=0)
		{
			myBannerman->decreaseWeapons();
			break;
		}
		if ((enemyBannerman->getFood()+enemyBannerman->getMedical())<0 && myBannerman->getHP() > 0 && enemyBannerman->getHP() > 0)
		{
			enemyBannerman->receiveDamage(myBannerman->getDamage()+val);
            cout<<"The enemy's supplies are low! They take extra damage. Enemy HP:"<<enemyBannerman->getHP()<<endl;
		} else {
			enemyBannerman->decreaseMedical();
			enemyBannerman->decreaseFood();
		}
		myBannerman->decreaseWeapons();
		if (enemyBannerman->getHP()<=0)
		{
			break;
		}
		myBannerman->receiveDamage(enemyBannerman->getDamage()-val);
        cout<<"The enemy delivers their blow! The bannerman from "<<myBannerman->getName()<<" takes "<<(enemyBannerman->getDamage()-val)<<" damage. Our HP: "<<myBannerman->getHP()<<endl;
        if (myBannerman->getHP()<=0)
		{
			enemyBannerman->decreaseWeapons();
			break;
		}
		if ((myBannerman->getFood()+myBannerman->getMedical())<0 && myBannerman->getHP()>0 && enemyBannerman->getHP()>0)
		{
			myBannerman->receiveDamage(enemyBannerman->getDamage()-val);
            cout<<"Our supplies are low! We take extra damage. Enemy HP:"<<myBannerman->getHP()<<endl;
        } else {
			myBannerman->decreaseMedical();
			myBannerman->decreaseFood();
		}
		enemyBannerman->decreaseWeapons();
		if (myBannerman->getHP()<=0)
		{
			break;
		}
	}
	
	if (myBannerman->getHP()>0&&enemyBannerman->getHP()<=0)
	{
        list<Bannerman*> s = myKingdom->getKingdom();
        list<Bannerman*> e = enemyKingdom->getKingdom();

        for (list<Bannerman*>::iterator it = s.begin(); it != s.end(); ++it) {
            (*it)->increaseFavour();
        }
        for (std::list<Bannerman*>::iterator it = e.begin(); it != e.end(); ++it){
            (*it)->decreaseFavour();
        }

		if(myBannerman->getFood()>enemyBannerman->getFood()){

            for (std::list<Bannerman*>::iterator it = e.begin(); it != e.end(); ++it){
                (*it)->decreaseFavour();
            }

		}
		else
		{
			list<Bannerman*> s = myKingdom->getKingdom();
            for (std::list<Bannerman*>::iterator it = s.begin(); it != s.end(); ++it){
                (*it)->decreaseFavour();
            }
		}


        bool winner = false;
        for (list<Bannerman*>::iterator it = s.begin(); it != s.end(); ++it){
            (*it)->increaseFavour();
            Bannerman* a = *it;
            if (a->getFavour() >= 8){
                winner = true;
            }else{
                winner = false;
            }
        }
        if (winner == true && defectedAllies != 0){
            Bannerman* returned = Greg->restoreAlly(BookOfDura->getAlly());
            myKingdom->add(returned);
            enemyKingdom->remove(returned);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
            cout<<returned->getName()<<"'s commander asks yor forgiveness and joins your fight once again."<<endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }




		if ((myBannerman->getFavour()<=minFavour)&&((enemyKingdom->getSize()-myKingdom->getSize())>=1)) //bannerman defects
		{
			Greg->setAlly(myBannerman);
			BookOfDura->add(Greg->Store());
			defectedAllies++;
			//add a remove(Bannerman* myBannerman) and add(Bannerman* myBannerman) method to 
			//remove/add a particular bannerman 
			myKingdom->remove(myBannerman);
			//tell thapelo to add id attribute and a getter, we must
			//formulate a way to make bannerman ids unique
			enemyKingdom->add(myBannerman);
            cout<<"The enemy kingdom's bannerman has been defeated. "<<enemyBannerman->getName()<<" is now under your kingdom's rule."<<endl;
            cout<<"But the commanders are losing faith in your cause. "<<myBannerman->getName()<<" has defected to the other side."<<endl;
            enemyKingdom->remove(enemyBannerman);
            return false;
		}
		if (myBannerman->getWeapons()<=(minSupplies+2))
		{
			//tell sameet to add pointer asterisk in treasury class's notify
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            cout<<"The fight has ended. The commander took inventory of the supplies and sends for more."<<endl;
			m->notify(this);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
		enemyKingdom->remove(enemyBannerman);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout<<"The enemy kingdom's bannerman has been defeated. "<<enemyBannerman->getName()<<" is now under your kingdom's rule."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return true;
	}
	else if (myBannerman->getHP()<=0&&enemyBannerman->getHP()>0)
	{
		myKingdom->remove(myBannerman);
        list<Bannerman*> s = myKingdom->getKingdom();
        for (std::list<Bannerman*>::iterator it = s.begin(); it != s.end(); ++it){
            (*it)->decreaseFavour();
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout<<myBannerman->getName()<<" fought bravely in the name of Dura. They were sadly lost in the battle."<<endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		return false;
	}
	else
	{
		return false;
	}
}

Ambush::Ambush(int stealth,Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb):Strategy(myKingdom,enemyKingdom,myBannerman,enemyBannerman,"Ambush",min,minFavour, h, hb)  {
	this->stealth=stealth;
}

Ambush::~Ambush(){

}