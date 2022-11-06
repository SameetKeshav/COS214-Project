#include "Siege.h"

Siege::Siege(int stealth,Kingdom* myKingdom,Kingdom* enemyKingdom,Bannerman* myBannerman, Bannerman* enemyBannerman,string name,int min,int minFavour, Historian* h, HistoryBook* hb):Strategy(myKingdom,enemyKingdom,myBannerman,enemyBannerman,"Siege",min,minFavour, h, hb){
    this->stealth=stealth;
}

Siege::~Siege(){

}

bool Siege::attack(Bannerman* myBannerman, Bannerman* enemyBannerman) {
    int advantage=(stealth-60)/2;
    srand(time(0));
    int val=advantage;
    if (stealth>60)
    {
        cout<<"You approach the enemy's location and make camp outside. The enemy was caught unprepared and are low on supplies."<<endl;
        cout<<"You wait them out for two days, before starting your advance."<<endl;
        myBannerman->decreaseFood();
        enemyBannerman->decreaseFood();
        enemyBannerman->decreaseFood();
    }else{
        cout<<"You approach the enemy's location and make camp outside. They had received word of your plan and stocked up on supplies. They initiate the fight."<<endl;
    }
    while (myBannerman->getHP()>0&&enemyBannerman->getHP()>0)
    {
        //getDamage is how much damage the bannerman can inflict
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
        enemyBannerman->receiveDamage(myBannerman->getDamage()+val);
        cout<<"You deal "<<(myBannerman->getDamage()+val)<<" damage to the enemy. Enemy HP:"<<enemyBannerman->getHP()<<endl;
        if (enemyBannerman->getHP()<0)
		{
			myBannerman->decreaseWeapons();
			break;
		}
        if ((enemyBannerman->getFood()+enemyBannerman->getMedical())<0)
        {
            enemyBannerman->receiveDamage(myBannerman->getDamage()+val);
            cout<<"The enemy's supplies are low! They take extra damage. Enemy HP:"<<enemyBannerman->getHP()<<endl;
        } else {
            enemyBannerman->decreaseMedical();
            enemyBannerman->decreaseFood();
        }
        myBannerman->decreaseWeapons();
        if (enemyBannerman->getHP()<0)
		{
			break;
		}
        myBannerman->receiveDamage(enemyBannerman->getDamage()-val);
        cout<<"The enemy delivers their blow! The bannerman from "<<myBannerman->getName()<<" takes "<<(enemyBannerman->getDamage()-val)<<" damage. Our HP: "<<myBannerman->getHP()<<endl;
        if (myBannerman->getHP()<0)
		{
			enemyBannerman->decreaseWeapons();
			break;
		}
        if ((myBannerman->getFood()+myBannerman->getMedical())<0)
        {
            myBannerman->receiveDamage(enemyBannerman->getDamage()-val);
            cout<<"Our supplies are low! We take extra damage. Enemy HP:"<<myBannerman->getHP()<<endl;
        } else {
            myBannerman->decreaseMedical();
            myBannerman->decreaseFood();
        }
        enemyBannerman->decreaseWeapons();
        if (myBannerman->getHP()<0)
		{
			break;
		}
    }

    if (myBannerman->getHP()>0&&enemyBannerman->getHP()<=0)
    {
        //tell Jules about the decrease favour implementation
        if(myBannerman->getFood()>enemyBannerman->getFood()){
            myBannerman->increaseFavour();
            list<Bannerman*> s = myKingdom->getKingdom();
            bool winner = false;
            for (list<Bannerman*>::iterator it = s.begin(); it != s.end(); ++it){
                Bannerman* a = *it;
                if (a->getFavour() >= 9){
                    winner = true;
                }else{
                    winner = false;
                }
            }
            if (winner == true && defectedAllies != 0){
                Bannerman* returned = Greg->restoreAlly(BookOfDura->getAlly());
                myKingdom->add(returned);
                enemyKingdom->remove(returned);
                cout<<returned->getName()<<"'s commander asks yor forgiveness and joins your fight once again."<<endl;
            }
        }
        else
        {
            myBannerman->decreaseFavour();
            if (myBannerman->getFavour()<minFavour)
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
                cout<<"The commanders are losing faith in your cause. "<<myBannerman->getName()<<" has defected to the other side."<<endl;
                return false;
            }

        }

        if (myBannerman->getWeapons()<=minSupplies)
        {
            //tell sameet to add pointer asterisk in treasury class's notify
            cout<<"The fight has ended. The commander took inventory of the supplies and sends for more."<<endl;
            m->notify(this);
        }
        enemyKingdom->remove(enemyBannerman);
        cout<<"The enemy kingdom's bannerman has been defeated. "<<enemyBannerman->getName()<<" is now under your kingdom's rule."<<endl;
        return true;
    }
    else if (myBannerman->getHP()<=0&&enemyBannerman->getHP()>0)
    {
        myKingdom->remove(myBannerman);
        cout<<myBannerman->getName()<<" fought bravely in the name of Dura. They were sadly lost in the battle."<<endl;
        return false;
    }
    else
    {
        cout<<"==================================================================================="<<endl;
        return false;
    }
}
