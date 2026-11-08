#pragma once

#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"

class ScrollableChatController
{
public:
	ScrollableChatController(slint::ComponentHandle<MainWindow> window);

private:
	slint::ComponentHandle<MainWindow> m_window;
	std::vector<Message> m_messages;
};
