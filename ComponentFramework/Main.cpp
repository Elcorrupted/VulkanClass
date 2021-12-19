#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
#include <string>
#include "SceneManager.h"
#include "Debug.h"
#include "MMath.h"
using namespace MATH;
  
int main(int argc, char* args[]) {

//#pragma warning(disable : 4996)
//	if (const char* env_p = std::getenv("PATH")) {
//		std::cout << "Your PATH is: " << env_p << '\n';
//	}

	std::string name = { "Graphics Game Engine" };
	Debug::DebugInit(name + "_Log");
	Debug::Info("Starting the GameSceneManager", __FILE__, __LINE__);
	
	SceneManager* gsm = new SceneManager();
	if (gsm->Initialize(name, 1280, 720) ==  true) {
		gsm->Run();
	} 
	delete gsm;
	
	_CrtDumpMemoryLeaks();
	exit(0);

}