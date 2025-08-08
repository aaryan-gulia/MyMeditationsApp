#pragma once

#include "UiHandler.h"
#include "Database.h"


enum class State{
  
};

class App{
public:
  void run();

private:
  Database db;
  CliHandler ui;

};
