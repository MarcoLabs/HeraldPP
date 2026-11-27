#include "ui/states/UserStateController.h"
#include "MainWindow_ui.h"
#include <climits>
#include <cstdlib>
#include <unistd.h>

UserStateController::UserStateController(const UserState& userState): m_userState(userState)
{
	User currentUser = User{getlogin(), rand() % INT_MAX};
	
	userState.set_current_user(currentUser);
}
