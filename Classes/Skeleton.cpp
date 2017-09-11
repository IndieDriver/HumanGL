#include "Skeleton.hpp"

Skeleton::Skeleton(void) {

}

Skeleton::Skeleton(Skeleton const & src) {
	*this = src;
}

Skeleton::~Skeleton(void) {

}

Skeleton &	Skeleton::operator=(Skeleton const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

std::vector<MemberElement>	readMembre(std::fstream &skelFile) {
	std::string line;
	std::vector<MemberElement> members;
	while (getline(skelFile, line))	{
		char lineChar[line.size() + 1];
		strcpy(lineChar, line.c_str());
		if (lineChar[0] == '#')
			continue;
		MemberElement el;
		int ret = std::sscanf(lineChar,
				"(%f,%f,%f) (%f,%f,%f) (%f,%f,%f) (%f,%f,%f) (%f,%f,%f)",
				&el.ori.x, &el.ori.y, &el.ori.z,
				&el.transform.position.x, &el.transform.position.y,
				&el.transform.position.z,
				&el.transform.rotation.x, &el.transform.rotation.y,
				&el.transform.rotation.z,
				&el.transform.scale.x, &el.transform.scale.y,
				&el.transform.scale.z,
				&el.col.x, &el.col.y, &el.col.z);
		if (ret > 0) {
			members.push_back(el);
		} else {
			return (members);
		}
	}
	return (members);
}

void		readJoint(std::fstream &skelFile, Model *model,
				std::vector<MemberElement> members) {
	std::string line;
	std::vector<Membre*> membreVector;
	for (MemberElement &me : members) {
		Membre *newMembre = new Membre();
		newMembre->transform = me.transform;
		newMembre->color = me.col;
		newMembre->origin = me.ori;
		membreVector.push_back(newMembre);
	}
	while (getline(skelFile, line))	{
		char lineChar[line.size() + 1];
		strcpy(lineChar, line.c_str());
		if (lineChar[0] == '#')
			continue;
		int parentID;
		int childID;
		Vec3 joint;
		int ret = std::sscanf(lineChar, "%d : %d (%f,%f,%f)",
				&parentID, &childID, &joint.x, &joint.y, &joint.z);
		if (ret <= 0)
			continue;
		if (parentID != childID) {
			Child child;
			child.membre = membreVector[childID];
			child.jointure = joint;
			if (parentID < membreVector.size())
				membreVector[parentID]->childrens.push_back(child);
			else {
				std::cerr << "Invalid skeleton file" << std::endl;
				exit(0);
			}
		} else {
			if (parentID < membreVector.size())
				model->mainMembre = membreVector[parentID];
			else {
				std::cerr << "Invalid skeleton file" << std::endl;
				exit(0);
			}

		}
	}
}

void	Skeleton::loadSkeleton(std::string filename, Model *model) {
	std::string line;
	std::fstream skelFile(filename);
	std::vector<MemberElement> members;
	if (skelFile) {
		members = readMembre(skelFile);
		model->nb_membres = members.size();
		readJoint(skelFile, model, members);
		skelFile.close();
	} else {
		std::cerr << "Invalid skeleton file " << filename << std::endl;
		exit(0);
	}
}

