#include "MainWindow_ui.h"
#include "ui/MainWindowController.h"

int main()
{
	auto mainWindow = MainWindow::create();

	MainWindowController mainWindowController(mainWindow);
	
	mainWindow->run();

	return 0;
}
