#include "ui/pages/ServerChat/ServerDataController.h"
#include <format>

ServerDataController::ServerDataController(std::shared_ptr<int> currentServerId, std::shared_ptr<slint::SharedString> serverName):
	m_currentServerId(std::move(currentServerId)),
	m_serverName(std::move(serverName))
{ }

void ServerDataController::AttemptServerChange(int serverId)
{
	this->ChangeServerTo(serverId); // hardcoded since now backend
}

void ServerDataController::ChangeServerTo(int serverId)
{
	*this->m_currentServerId = serverId;
	*this->m_serverName = std::format("Server name {}", serverId);
}
