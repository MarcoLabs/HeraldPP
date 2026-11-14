#include "ui/pages/ServerController/ServerController.h"
#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

ServerController::ServerController(const ServerState& serverState, const ServerActions& serverActions):
	m_serverState(serverState),
	m_serverActions(serverActions),
	m_currentChannelIndex(std::make_shared<int>(0)),
	m_channels(std::make_shared<slint::VectorModel<Channel>>()),
	m_currentServerId(std::make_shared<int>(0)),
	m_serverName(std::make_shared<slint::SharedString>("Server name")),
	m_serverChannelsController(m_currentChannelIndex, m_channels, m_members),
	m_serverDataController(m_currentServerId, m_serverName)
{
	m_channels->push_back(Channel{"channel a", true, std::make_shared<slint::VectorModel<slint::SharedString>>(std::vector<slint::SharedString>{ "alice", "bob", "charlie" }), std::make_shared<slint::VectorModel<Message>>()});
	m_channels->push_back(Channel{"channel b", false, std::make_shared<slint::VectorModel<slint::SharedString>>(std::vector<slint::SharedString>{ "Wiktor", "Leon", "peDla" }), std::make_shared<slint::VectorModel<Message>>()});

	this->m_serverChannelsController.BindCurrentChannel();
	
	this->m_serverActions.on_send_message([this](const slint::SharedString& author, const slint::SharedString& messageContent)
	{
		this->SendMessage(author, messageContent);
	});

	this->m_serverActions.on_channel_changed([this](int channelIndex)
	{
		this->ChangeChannelTo(channelIndex);

		this->UpdateUiWithScalarValues();
	});

	this->m_serverState.set_channels(this->m_channels);

	this->UpdateUiWithScalarValues();
}

void ServerController::SendMessage(const slint::SharedString& author, const slint::SharedString& messageContent)
{
	this->m_serverChannelsController.AttemptSendMessageToCurrentChannel(Message{author, messageContent});
}

void ServerController::ChangeServerTo(int serverId)
{
	this->m_serverDataController.AttemptServerChange(serverId);
	this->UpdateUiWithScalarValues();
}

void ServerController::ChangeChannelTo(int channelIndex)
{
	this->m_serverChannelsController.ChangeChannelTo(channelIndex);
}

void ServerController::UpdateUiWithScalarValues()
{
	this->m_serverState.set_server_name(*this->m_serverName);
	this->m_serverState.set_current_channel_index(*this->m_currentChannelIndex);
}
