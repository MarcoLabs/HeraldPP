#include "ui/pages/ScrollableChatController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <iostream>
#include <memory>

ScrollableChatController::ScrollableChatController(slint::ComponentHandle<MainWindow> window): m_window(std::move(window))
{
	auto& actions = this->m_window->global<ChatActions>();
	actions.on_send([this](slint::SharedString messageContent)
	{
		this->Send(messageContent);
	});
}

void ScrollableChatController::Send(const slint::SharedString& messageContent)
{
	Message message{"random", messageContent};
	
	const auto& chatState = this->m_window->global<ChatState>();
	
	std::shared_ptr<slint::Model<Message>> messages = chatState.get_messages();
	if (! messages)
	{
		return;
	}
	
	messages->push_row(message);
	
	chatState.set_messages(messages);
}
