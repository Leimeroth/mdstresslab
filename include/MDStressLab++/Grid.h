/*
 * Grid.h
 *
 *  Created on: Nov 5, 2019
 *      Author: Nikhil
 */

#include "typedef.h"
#include <vector>
#include "SubConfiguration.h"
#include <set>

class GridBase
{
public:
	std::vector<Vector3d> coordinates;
	static int numberOfReferenceGrids;
	static int numberOfCurrentGrids;
};


/*!
 * Describes a grid on which stress is computed.
 * @tparam T - StressType (Cauchy/Piola)
 */
template<ConfigType T>
class Grid : public GridBase{
public:
	Grid(int);
	Grid(Vector3d,
		 Vector3d,
		 int ngridx, int ngridy=1,int ngridz=1);
    Grid(std::string);
	virtual ~Grid();
	int ngrid;

	void read(std::string);
	void write(std::string) const;
	void setCounter();
	std::vector<std::set<int>> getGridNeighborLists(const SubConfiguration&, const double&) const;
};
