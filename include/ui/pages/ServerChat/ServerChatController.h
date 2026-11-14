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
	void ChangeServerTo(int serverId);

private:
	void UpdateUiWithScalarValues();

	const ServerState& m_serverState;
	const ServerActions& m_serverActions;

	int m_currentServerId;
	
	slint::SharedString m_serverName;
	int m_currentChannelIndex;
	std::shared_ptr<slint::VectorModel<Channel>> m_channels;
	std::shared_ptr<slint::VectorModel<Message>> m_messages;

	// TODO: ServerDataController, which controls the m_serverName and the m_currentServerId
	ChatController m_chatController;
	// TODO: ChannelsController, which controls the m_channels and m_currentChannelIndex
};
