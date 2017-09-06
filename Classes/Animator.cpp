#include "Animator.hpp"

Animator::Animator(void) {

}

Animator::Animator(Animator const & src) {
	*this = src;
}

Animator::~Animator(void) {

}

Animator &	Animator::operator=(Animator const & rhs) {
	if (this != &rhs){

	}
	return (*this);
}

void	Animator::loadAnim(std::string filename, Model *model) {
	std::string line;
	std::fstream animFile(filename);
	if (animFile) {
		while (getline(animFile, line)) {
			char lineChar[line.size() + 1];
			strcpy(lineChar, line.c_str());
			int i = 0;
			while (lineChar[i] && lineChar[i] != ':') {
				i++;
			}
			uint32_t frame;
			Vec3 pos;
			Vec3 rot;
			Vec3 sca;
			int ret = std::sscanf(&lineChar[i],
					": %d (%f,%f,%f) (%f,%f,%f) (%f,%f,%f)",
					&frame, &pos.x, &pos.y, &pos.z, &rot.x, &rot.y, &rot.z,
					&sca.x, &sca.y, &sca.z);
			std::cout << "ret: " << ret << std::endl;

			int child;
			std::vector<int> childStack;
			i = 0;
			while (lineChar[i] && lineChar[i] != ':') {
				ret = std::sscanf(&lineChar[i],"%d:", &child);
				i++;
				if (ret == 0)
					continue;
				std::cout << "child: " << child << std::endl;
				childStack.push_back(child);
			}
			if (childStack.size() == 0) {
				return ;
			}
			Membre *membre = model->mainMembre;
			for (child = 1; child < childStack.size(); child++) {
				if (childStack[child] < membre->childrens.size())
					membre = membre->childrens[childStack[child]].membre;
			}
			KeyFrame keyframe;
			keyframe.frame = frame;
			keyframe.transform.position = pos;
			keyframe.transform.rotation = rot;
			keyframe.transform.scale = sca;
			std::cout << frame << std::endl;
			pos.print();
			rot.print();
			sca.print();
			membre->animation.keyFrames.push_back(keyframe);
		}
		animFile.close();
	}

}
