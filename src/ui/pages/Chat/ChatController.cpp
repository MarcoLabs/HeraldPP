#include "ui/pages/Chat/ChatController.h"

ChatController::ChatController(std::shared_ptr<slint::VectorModel<Message>> messages): m_messages(std::move(messages)) { }

void ChatController::Send(const Message& message)
{
	this->m_messages->push_back(message);
}
