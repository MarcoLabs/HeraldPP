#include "ui/pages/ScrollableChatController.h"
#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

ScrollableChatController::ScrollableChatController(const ChatState& chatState, const ChatActions& chatActions): m_chatState(chatState), m_chatActions(chatActions), m_messages(std::make_shared<slint::VectorModel<Message>>())
{
	this->m_chatActions.on_send([this](slint::SharedString author, slint::SharedString messageContent)
	{
		this->Send(author, messageContent);
	});

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
