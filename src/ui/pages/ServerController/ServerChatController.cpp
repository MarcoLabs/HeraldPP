#include "ui/pages/ServerController/ServerChatController.h"

ServerChatController::ServerChatController(std::shared_ptr<slint::VectorModel<Message>> messages): m_messages(std::move(messages)), m_chatController(m_messages) { }

void ServerChatController::SetMessages(std::shared_ptr<slint::VectorModel<Message>> messages)
{
	this->m_messages = std::move(messages);
	this->m_chatController.SetMessage(this->m_messages);
}

void ServerChatController::AttemptSendMessage(const Message& message)
{
	if (! this->m_messages)
	{
		return;
	}
	
	this->m_chatController.Send(message); // hardcoded for now
}