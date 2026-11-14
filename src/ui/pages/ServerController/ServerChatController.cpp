#include "ui/pages/ServerController/ServerChatController.h"

ServerChatController::ServerChatController(std::shared_ptr<slint::VectorModel<Message>> messages): m_messages(std::move(messages)), m_chatController(m_messages) { }

void ServerChatController::AttemptSendMessage(const Message& message)
{
	this->m_chatController.Send(message); // hardcoded for now
}