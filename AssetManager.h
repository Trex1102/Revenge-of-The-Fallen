//hello saikat
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <map>
#include <iostream>
#include <cassert>
using namespace std;
using namespace sf;

namespace GameEngine {
	template <typename Resource>
	class AssetManager {
	public:
		AssetManager() {}
		~AssetManager() {}
		void load(const string name, const string& filepath) {
			unique_ptr<Resource> object(new Resource);
			if (!object->loadFromFile(filepath)) {
				throw runtime_error("AssetManager::load- Failed to load " + filepath);
			}
			
			auto it = list.find(name);

			if (it != list.end()) {
				return;
			}
			
			auto inserted = list.insert(make_pair(name, move(object)));



			//assert(inserted.second);
		}
		Resource& get(const string name) {
			auto it = list.find(name);
			assert(it != list.end());
			return *it->second;
		}
	private:
		map <const string, unique_ptr<Resource>> list;
	};

}
