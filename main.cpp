#include "MyForm.h"

using namespace Blackjack;

[STAThreadAttribute]
int main(array< System::String^ >^ args)
{
	// Enabling Windows XP visual effects before any changes are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Create the main window and run it 
	Application::Run(gcnew MyForm());
	return 0;
}