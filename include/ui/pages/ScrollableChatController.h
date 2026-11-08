#pragma once

#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "private/slint_string.h"

class ScrollableChatController
{
public:
	ScrollableChatController(slint::ComponentHandle<MainWindow> window);

private:
	void Send(const slint::SharedString& messageContent);
	
	slint::ComponentHandle<MainWindow> m_window;
};
