#include "MainWindow_ui.h"
#include "ui/MainWindowController.h"
#include "ui/UtilsController.h"

int main()
{
	auto mainWindow = MainWindow::create();

	MainWindowController mainWindowController(mainWindow);
	UtilsController utilsController(mainWindow);
	
	mainWindow->run();

	return 0;
}
