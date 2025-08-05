#include"Database.h"
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>

void addMeditation(Database& database,
		   std::string title = "Test", 
		   std::string content = "This is a test"){
	database.addMeditation({title, content});
}
void saveToDatabaseFile(){
	Database database;
	addMeditation(database);
}

int main(){
	saveToDatabaseFile();

	Database database;
	auto meditations = database.getMeditations();

	assert(meditations.size() > 0);

	addMeditation(database);

	assert(database.getMeditationAt(0).getTitle() 
	== database.getMeditationAt(1).getTitle());
	
	assert(database.getMeditationAt(0).getContent() 
	== database.getMeditationAt(1).getContent());
	
	database.setMeditationAt(0, {"dif", "dif"});

	assert(database.getMeditationAt(0).getTitle() 
	!= database.getMeditationAt(1).getTitle());
	
	assert(database.getMeditationAt(0).getContent() 
	!= database.getMeditationAt(1).getContent());

	database.deleteMeditationAt(1);
	database.deleteMeditationAt(0);
	
	assert(database.getMeditations().size() == 0);

}


