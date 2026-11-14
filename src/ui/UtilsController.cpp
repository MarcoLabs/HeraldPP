#include "ui/UtilsController.h"
#include "MainWindow_ui.h"
#include "Utils.h"
#include "private/slint_string.h"

UtilsController::UtilsController(const slint::ComponentHandle<MainWindow>&mainWindow)
{
	const auto& utils = mainWindow->global<Utils>();

	utils.on_first_two([](const slint::SharedString& s)
	{
		return slint::SharedString(utils::FirstTwo(std::string_view(s)));
	});
}
