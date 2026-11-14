#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

class ChatController
{
public:
	ChatController(std::shared_ptr<slint::VectorModel<Message>> messages);

	void Send(const slint::SharedString& author, const slint::SharedString& messageContent);

private:
	std::shared_ptr<slint::VectorModel<Message>> m_messages;
};
