#include "Database.h"
#include "Meditation.h"
#include "nlohmann/json.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <strings.h>

using json = nlohmann::json;

bool Database::load(){
	std::ifstream in(file);
	if (!in || in.peek() == std::ifstream::traits_type::eof()) {
        // File missing or empty
		std::cout << "no meditations to load";
		return false;
	}

	json j;
	
	in >> j;

	meditations.clear();

	for(const auto& meditation : j){
		meditations.emplace_back(
			meditation.at("title").get<std::string>(), 
			meditation.at("content").get<std::string>()
		);
	}

	std::cout << "meditations loaded successfully" << std::endl;

	return true;
}

void Database::save() const {
	std::ofstream out(file);

	json j = json::array();

	for(auto meditation : meditations){
		j.push_back({{"title", meditation.getTitle()},{"content", meditation.getContent()}});
	}
	
	std::cout << "meditations serialized before saving" << std::endl;

	out << j.dump(4);
	out.close();

	std::cout <<  "meditations saved" << std::endl;
}

Database::Database(){
	load();
}

Database::Database(std::string databaseFile) : file(databaseFile){
	load();
}

Database::~Database(){
	save();
}

size_t Database::addMeditation(Meditation meditation){
	std::cout << "adding meditation" << std::endl;
	meditations.push_back(meditation);
	return meditations.size() - 1;
	std::cout << "meditation added successfully" << std::endl;
}

void Database::deleteMeditationAt(size_t index){
	if (meditations.size() > index){
		meditations.erase(meditations.begin() + index);
	}
	else {
		throw (
			std::overflow_error("index is out of range")
		);
	}
}

const std::vector<Meditation>& Database::getMeditations() const {
	return meditations;
}

const Meditation& Database::getMeditationAt(size_t index) const {
	if (meditations.size() > index){
		return meditations[index];
	}
	else {
		throw (
			std::overflow_error("index is out of range")
		);
	}
}

void Database::setMeditationAt(size_t index, Meditation meditation) {
	if (meditations.size() > index){
		meditations[index] = std::move(meditation);
	}
	else {
		throw (
			std::overflow_error("index is out of range")
		);
	}
}
