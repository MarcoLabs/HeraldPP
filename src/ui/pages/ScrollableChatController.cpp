#include "ui/pages/ScrollableChatController.h"
#include "MainWindow_ui.h"
#include "private/slint_item_tree.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

ScrollableChatController::ScrollableChatController(slint::ComponentHandle<MainWindow> window): m_window(std::move(window)), m_messages(std::make_shared<slint::VectorModel<Message>>())
{
	const auto& actions = this->m_window->global<ChatActions>();
	actions.on_send([this](slint::SharedString author, slint::SharedString messageContent)
	{
		this->Send(author, messageContent);
	});

	const auto& chatState = this->m_window->global<ChatState>();

	chatState.set_messages(this->m_messages);
}

void ScrollableChatController::Send(const slint::SharedString& author, const slint::SharedString& messageContent)
{
	if (this->m_messages == nullptr)
	{
		return;
	}
	
	Message message{author, messageContent};
	
	this->m_messages->push_back(message);
}
