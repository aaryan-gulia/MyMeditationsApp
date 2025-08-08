#include "App.h"
#include <cstdint>
#include <string>
  
void App::run(){

	bool run = true;
	uint64_t numInput;
	std::string strInput;

	while(run){
		ui.displayMainMenu();
		numInput = ui.getNumberInput();

		switch (numInput) {
			case 1:{
				try{
				db.addMeditation(ui.getNewMeditation());
				} catch (std::exception) {}
				break;
			}
			case 2:{
				ui.displayMeditationList(db.getMeditations());
				uint64_t meditationSelection;
				meditationSelection = ui.getNumberInput(
					"Enter a valid meditation number to view it"
				);
				if (meditationSelection > db.getMeditations().size()){
					ui.displayError("You entered an invalid meditation number");
				}
				else{
					ui.displayMeditation(db.getMeditationAt(meditationSelection-1));
					ui.displayMeditationMenu();
					ui.getNumberInput();
					//TODO
				}
				break;
			} 
			case 3:{
				ui.displayMeditation(db.getMeditationAt(db.getMeditations().size()-1));
				ui.displayMeditationMenu();
				ui.getNumberInput();
				//TODO
				break;
				
			}
			case 4:{
				ui.displayError("Randomizor feature is not yet available");
				run = false;
				break;
			}
			default : {
				ui.displayError();
			}
		
		}
	}
}
