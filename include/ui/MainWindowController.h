#pragma once

#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "ui/pages/ServerChat/ServerChatController.h"
#include "ui/states/UserStateController.h"

class MainWindowController
{
public:
	MainWindowController(slint::ComponentHandle<MainWindow> window);

private:
	UserStateController m_userStateController;
	
	ServerChatController m_serverChatController;
};
