#include "ui/MainWindowController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "ui/pages/ScrollableChatController.h"

MainWindowController::MainWindowController(slint::ComponentHandle<MainWindow> window): scrollableChatController(std::move(window)) { }
