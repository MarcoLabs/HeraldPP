#include "ui/pages/ServerChat/ServerChatController.h"
#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

ServerChatController::ServerChatController(const ServerState& serverState, const ServerActions& serverActions):
	m_serverState(serverState),
	m_serverActions(serverActions),
	m_messages(std::make_shared<slint::VectorModel<Message>>()),
	m_currentChannelIndex(std::make_shared<int>(0)),
	m_channels(std::make_shared<slint::VectorModel<Channel>>()),
	m_currentServerId(std::make_shared<int>(0)),
	m_serverName(std::make_shared<slint::SharedString>("Server name")),
	m_chatController(m_messages),
	m_serverChannelsController(m_currentChannelIndex, m_channels),
	m_serverDataController(m_currentServerId, m_serverName)
{
	this->m_serverActions.on_send_message([this](const slint::SharedString& author, const slint::SharedString& messageContent)
	{
		this->AttemptSend(author, messageContent);
	});

	this->m_serverState.set_channels(this->m_channels);
	this->m_serverState.set_messages(this->m_messages);

	this->UpdateUiWithScalarValues();
}

void ServerChatController::AttemptSend(const slint::SharedString& author, const slint::SharedString& messageContent)
{
	this->m_chatController.Send(author, messageContent);
}

void ServerChatController::ChangeServerTo(int serverId)
{
	this->m_serverDataController.AttemptServerChange(serverId);
}

void ServerChatController::UpdateUiWithScalarValues()
{
	this->m_serverState.set_server_name(*this->m_serverName);
	this->m_serverState.set_current_channel_index(*this->m_currentChannelIndex);
}
