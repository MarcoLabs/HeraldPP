#include "ui/MainWindowController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "ui/pages/ScrollableChatController.h"
#include "ui/states/UserStateController.h"

MainWindowController::MainWindowController(slint::ComponentHandle<MainWindow> window): userStateController(window->global<UserState>()), scrollableChatController(window) { }
