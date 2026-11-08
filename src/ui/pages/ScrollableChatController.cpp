#include "ui/pages/ScrollableChatController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"

ScrollableChatController::ScrollableChatController(slint::ComponentHandle<MainWindow> window): m_window(std::move(window)) {}
