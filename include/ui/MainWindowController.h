#pragma once

#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "ui/pages/ScrollableChatController.h"
class MainWindowController
{
public:
	MainWindowController(slint::ComponentHandle<MainWindow> window);

private:
	ScrollableChatController scrollableChatController;
};
