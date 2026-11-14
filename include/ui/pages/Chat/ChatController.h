#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include <memory>

class ChatController
{
public:
	ChatController(std::shared_ptr<slint::VectorModel<Message>> messages);

	void Send(const Message& message);

private:
	std::shared_ptr<slint::VectorModel<Message>> m_messages;
};
