#include "to_playmood.h"
#include "ApplicationManager.h"
to_playmood::to_playmood(ApplicationManager*pApp):Action(pApp)
{}
 void to_playmood::Execute()
{
	 Output* pout = pManager->GetOutput();
	 pout->CreatePlayToolBar();
}
 void to_playmood::ReadActionParameters()
 {}