#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "ui/pages/Chat/ChatController.h"
#include <memory>
class ServerChatController
{
public:
	ServerChatController(std::shared_ptr<slint::VectorModel<Message>> messages);

	void AttemptSendMessage(const Message& message);
	
private:
	std::shared_ptr<slint::VectorModel<Message>> m_messages;

	ChatController m_chatController;
};
