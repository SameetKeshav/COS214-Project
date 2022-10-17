#ifndef TOPOLOGY_H
#define TOPOLOGY_H

class Topology : Conditions {

public:
	char chosen;

	Topology* getTopology();

	Topology();

	Strategy* getStrategy();
};

#endif
