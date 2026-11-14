#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

class ServerChatController
{
public:
	ServerChatController(const ServerState& serverState, const ServerActions& serverActions);

	void AttemptSend(const slint::SharedString& author, const slint::SharedString& messageContent);
	
private:
	const ServerState& m_serverState;
	const ServerActions& m_serverActions;

	slint::SharedString m_serverName;
	std::shared_ptr<slint::VectorModel<Channel>> m_channels;
	std::shared_ptr<slint::VectorModel<Message>> m_messages;
};
