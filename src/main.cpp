#include "MainWindow_ui.h"

int main()
{
	auto mainWindow = MainWindow::create();
	mainWindow->set_myLabel("Hello from C++");
	
	mainWindow->run();

	return 0;
}
