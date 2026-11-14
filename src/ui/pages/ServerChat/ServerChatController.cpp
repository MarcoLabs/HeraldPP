#include "ui/pages/ServerChat/ServerChatController.h"
#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

ServerChatController::ServerChatController(const ServerState& serverState, const ServerActions& serverActions):
	m_serverState(serverState),
	m_serverActions(serverActions),
	m_serverName(""),
	m_channels(std::make_shared<slint::VectorModel<Channel>>()),
	m_messages(std::make_shared<slint::VectorModel<Message>>()),
	m_chatController(m_messages)
{
	this->m_serverActions.on_send_message([this](const slint::SharedString& author, const slint::SharedString& messageContent)
	{
		this->AttemptSend(author, messageContent);
	});

	
	
	this->m_serverState.set_channels(this->m_channels);
	this->m_serverState.set_messages(this->m_messages);
}
