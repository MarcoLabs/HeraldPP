#pragma once

#include "MainWindow_ui.h"
#include "private/slint_string.h"

class ScrollableChatController
{
public:
	ScrollableChatController(const ChatState& chatState, const ChatActions& chatActions, std::shared_ptr<slint::VectorModel<Message>> messages);

private:
	void Send(const slint::SharedString& author, const slint::SharedString& messageContent);
	
	const ChatState& m_chatState;
	const ChatActions& m_chatActions;

	std::shared_ptr<slint::VectorModel<Message>> m_messages;
};
