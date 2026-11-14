#include "ui/MainWindowController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "ui/states/UserStateController.h"

MainWindowController::MainWindowController(slint::ComponentHandle<MainWindow> window):
	m_userStateController(window->global<UserState>()),
	m_serverChatController(window->global<ServerState>(), window->global<ServerActions>()) { }
