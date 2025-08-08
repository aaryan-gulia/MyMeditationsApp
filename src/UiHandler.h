#pragma once

#include "Meditation.h"
#include <cstdint>
#include <string>
#include <vector>

class CliHandler{
public:

  void clearScreen();
  void displayWelcomeScreen();
  void displayMainMenu();
  void displayMeditationMenu();
  void displayMeditation(const Meditation& meditation);
  void displayMeditationList(const std::vector<Meditation>& meditations);
  void displayError(std::string error = "invalid input");

  uint64_t getNumberInput(std::string prompt = "Enter your valid integer input");
  std::string getStringInput(std::string prompt = "Enter your valid string input");
  Meditation getNewMeditation();

  Meditation getEditedMeditation(const Meditation& meditation);
private:
};
