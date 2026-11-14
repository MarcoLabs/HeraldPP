#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include "ui/pages/Chat/ChatController.h"
#include "ui/pages/ServerController/ServerChannelsController.h"
#include "ui/pages/ServerController/ServerDataController.h"
#include <memory>

class ServerController
{
public:
	ServerController(const ServerState& serverState, const ServerActions& serverActions);

	ServerController(const ServerController&) = delete;
	ServerController& operator=(const ServerController&) = delete;

	ServerController(const ServerController&&) = delete;
	ServerController& operator=(const ServerController&&) = delete;

	void AttemptSend(const slint::SharedString& author, const slint::SharedString& messageContent);
	void ChangeServerTo(int serverId);

private:
	void UpdateUiWithScalarValues();

	const ServerState& m_serverState;
	const ServerActions& m_serverActions;

	std::shared_ptr<slint::VectorModel<Message>> m_messages;

	std::shared_ptr<int> m_currentChannelIndex;
	std::shared_ptr<slint::VectorModel<Channel>> m_channels;

	std::shared_ptr<int> m_currentServerId;
	std::shared_ptr<slint::SharedString> m_serverName;

	ChatController m_chatController;
	
	ServerChannelsController m_serverChannelsController;
	ServerDataController m_serverDataController;
};
