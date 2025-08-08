#include "UiHandler.h"
#include "Meditation.h"
#include <cstdint>
#include <print>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void CliHandler::displayWelcomeScreen(){
	std::println("welcome to MyMeditationsCli - Your CLI tool to save, review, and search through your thoughts.");
}

void CliHandler::displayMainMenu(){
	std::println("MAIN MENU");

	std::print(
		"1. Save New Meditation\n"
		"2. Open All Meditations Menu\n"
		"3. View Latest Meditation\n"
		"4. View Random Meditation\n"
	);
};

void CliHandler::displayMeditationMenu(){
	std::println("Meditation Menu");

	std::print("1. Edit Meditation\t" "2. Delete Meditation\t" "3. Back\n");
}

void CliHandler::displayMeditation(const Meditation& meditation){
	std::println("Title: {}",meditation.getTitle());
	std::println("\n{}",meditation.getContent());
}

void CliHandler::displayMeditationList(const std::vector<Meditation>& meditations){
	uint64_t meditationIndex = 0;

	for(auto& meditation : meditations){
		std::println("{}. {}", ++meditationIndex, meditation.getTitle());
	}
}

void CliHandler::displayError(std::string error){
	std::println("{}",error);
}

uint64_t CliHandler::getNumberInput(std::string prompt){
	uint64_t input;

	while(true){
	std::println("{}",prompt);
	try {
		std::cin >> input;
	} catch (std::exception) {
		std::println(std::cerr, "the above input is not a valid integer. ");
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		continue;
	}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	return input;
	}
}

std::string CliHandler::getStringInput(std::string prompt){
	std::string input;
	std::println("{}",prompt);

	while(true) {
		std::getline(std::cin,input);
		if(input.size() == 0){
			println(std::cerr, "the above string is empty. ");
		std::cin.clear();
		std::cin.ignore(1000, '\n');
			continue;
		}
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		return input;
	}
}

Meditation CliHandler::getNewMeditation(){

	Meditation newMeditation("","");

	while(true){
	newMeditation.setTitle(getStringInput("Enter your meditation's Title:\n"));
	newMeditation.setContent(getStringInput("Enter your meditation's Content:\n"));
	
	displayMeditation(newMeditation);
	std::println("Enter 'yes' to confirm the meditation title and content. 'no' to enter title and content again. 'back' to leave this edit meditation screen");
	
	auto input = getStringInput("");
	if (input ==  "yes"){ return newMeditation;}
	else if (input == "no"){continue;}
	else if (input == "back"){
		throw std::logic_error {"back entered"};
	}
	else {
		std::println("your input is invalid");
	}
	}
}

Meditation CliHandler::getEditedMeditation(const Meditation& meditation){
	std::println("Meditations Can't be Edited");
	return Meditation("","");
}
