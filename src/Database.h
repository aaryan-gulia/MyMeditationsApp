#pragma once 

#include "Meditation.h"
#include <cstddef>
#include <vector>

class Database{

public:
  Database();
  Database(std::string databaseFile); 
  ~Database();

  const std::vector<Meditation>& getMeditations() const;
  const Meditation& getMeditationAt(size_t index) const;

  void deleteMeditationAt(size_t index);
  void setMeditationAt(size_t index, Meditation meditation);
  size_t addMeditation(Meditation meditation);

private:
  std::vector<Meditation> meditations;
  const std::string file = "Database.json";

  bool load();
  void save() const;
};
