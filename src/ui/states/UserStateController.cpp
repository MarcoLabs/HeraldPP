#include "ui/states/UserStateController.h"
#include "MainWindow_ui.h"
#include <unistd.h>

UserStateController::UserStateController(const UserState& userState): m_userState(userState)
{
	userState.set_username(getlogin());

}
