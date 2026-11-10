#include "ui/MainWindowController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "private/slint_models.h"
#include "ui/states/UserStateController.h"
#include <memory>

MainWindowController::MainWindowController(slint::ComponentHandle<MainWindow> window):
	userStateController(window->global<UserState>()),
	scrollableChatController(window->global<ChatState>(), window->global<ChatActions>(), std::make_shared<slint::VectorModel<Message>>()) { }
