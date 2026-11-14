#include "ui/pages/Chat/ChatController.h"

ChatController::ChatController(std::shared_ptr<slint::VectorModel<Message>> messages): m_messages(std::move(messages)) { }

void ChatController::Send(const slint::SharedString& author, const slint::SharedString& messageContent)
{
	this->m_messages->push_back(Message{author, messageContent});
}
