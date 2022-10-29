#include "Topology.h"

Topology* Topology::getTopology() {
	// TODO - implement Topology::getTopology
	//throw "Not yet implemented";
    return *this;
}

Topology::Topology(char choose) {
	// TODO - implement Topology::Topology
	//throw "Not yet implemented";
    chosen = c;
}

void topology::setTopology()
{
    switch (chosen)
    {
        case 'a':
            cout << "The battle is at an open war field" << endl;
            difficulty =+ 2;
            break;
        case 'b' :
            cout << "The battle is at the enemy's fortress" << endl; //you can use getEnemyBannerman() to get their name for this
            difficulty =+ 4;
            break;
        case 'c':
            cout << "The battle is at the enemy campsite" << endl; //look @ above comment
            difficulty =+ 3;
            break;
        case 'd':
            cout << "The battle is at the enemy castle" << endl; //look at above comment
            difficulty =+ 5;
            break;
    }
}

void Topology::sendScout()  {
	// TODO - implement Topology::getStrategy
	//throw "Not yet implemented";
    setTopology();
}
