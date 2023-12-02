#include "ApplicationManager.h"

///////////// no thing
int main()
{

	ActionType ActType;
	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);

		//Update the interface
		AppManager.UpdateInterface();	

	} while(ActType != FUNC_EXIT);
	

	
	return 0;
}

