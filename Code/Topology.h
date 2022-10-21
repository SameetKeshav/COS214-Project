#ifndef TOPOLOGY_H
#define TOPOLOGY_H

class Topology : public Conditions {

public:
	char chosen;

	Topology* getTopology();

	Topology();

	Strategy* getStrategy();
};

#endif
