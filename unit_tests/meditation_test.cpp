#include "Meditation.h"
#include <cassert>

int main(){

	Meditation meditation1("Test-1", "Test-1 Content");

	std::string testTitle = "Test-2";
	std::string testContent = "Test-2 Content";

	Meditation meditation2(testTitle, testContent);
	
	meditation1.setTitle(testTitle);
	meditation1.setContent(testContent);

	assert(meditation1.getTitle() == meditation2.getTitle());
	assert(meditation1.getContent() == meditation2.getContent());


}
