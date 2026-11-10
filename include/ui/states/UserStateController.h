#pragma once

#include "MainWindow_ui.h"

class UserStateController
{
public:
	UserStateController(const UserState& userState);

	void Refresh();
private:
	
	const UserState& m_userState;
};
