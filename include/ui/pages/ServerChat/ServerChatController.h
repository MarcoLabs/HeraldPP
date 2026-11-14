#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include "ui/pages/Chat/ChatController.h"
#include <memory>

class ServerChatController
{
public:
	ServerChatController(const ServerState& serverState, const ServerActions& serverActions);

	ServerChatController(const ServerChatController&) = delete;
	ServerChatController& operator=(const ServerChatController&) = delete;

	ServerChatController(const ServerChatController&&) = delete;
	ServerChatController& operator=(const ServerChatController&&) = delete;

	void AttemptSend(const slint::SharedString& author, const slint::SharedString& messageContent);

private:
	void UpdateUiWithScalarValues();



	const ServerState& m_serverState;
	const ServerActions& m_serverActions;

	slint::SharedString m_serverName;
	int m_currentChannelIndex;
	std::shared_ptr<slint::VectorModel<Channel>> m_channels;
	std::shared_ptr<slint::VectorModel<Message>> m_messages;

	ChatController m_chatController;
};
