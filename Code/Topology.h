#ifndef TOPOLOGY_H
#define TOPOLOGY_H

class Topology : public Conditions {

public:
	char chosen;

	Topology* getTopology();

    void setTopology();

	Topology();

	//Strategy* getStrategy();
    void sendScout();
};

#endif
