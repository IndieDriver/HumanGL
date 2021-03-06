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
			if (lineChar[0] == '#')
				continue;
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
			rot.x = rot.x * (M_PI / 180.0f);
			rot.y = rot.y * (M_PI / 180.0f);
			rot.z = rot.z * (M_PI / 180.0f);

			int child;
			std::vector<int> childStack;
			i = 0;
			while (lineChar[i] && lineChar[i] != ':') {
				ret = std::sscanf(&lineChar[i],"%d:", &child);
				i++;
				if (ret == 0)
					continue;
				childStack.push_back(child);
			}
			if (childStack.size() == 0) {
				continue;
			}
			Membre *membre = model->mainMembre;
			for (child = 1; child < childStack.size(); child++) {
				if (childStack[child] < membre->childrens.size()) {
					membre = membre->childrens[childStack[child]].membre;
				}
			}
			KeyFrame keyframe;
			keyframe.frame = frame;
			keyframe.transform.position = pos;
			keyframe.transform.rotation = rot;
			keyframe.transform.scale = sca;
			bool found = false;
			for (Animation &animation : membre->animations) {
				if (animation.name == filename) {
					animation.keyFrames.push_back(keyframe);
					found = true;
				}
			}
			if (found == false) {
				Animation anim(filename);
				membre->animations.push_back(anim);
				membre->animations.back().keyFrames.push_back(keyframe);
			}
		}
		animFile.close();
	}
}

void	Animator::playAnim(std::string name, Model *model) {
	model->nextAnimation = name;
	model->mainMembre->endAnimation();
}
