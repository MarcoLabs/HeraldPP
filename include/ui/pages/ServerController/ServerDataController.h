#pragma once

#include "private/slint_string.h"
#include <memory>

class ServerDataController
{
public:
	ServerDataController(std::shared_ptr<int> currentServerId, std::shared_ptr<slint::SharedString> serverName);

	void AttemptServerChange(int serverId);
	
private:
	void ChangeServerTo(int serverId);
	
	std::shared_ptr<int> m_currentServerId;
	std::shared_ptr<slint::SharedString> m_serverName;
};
