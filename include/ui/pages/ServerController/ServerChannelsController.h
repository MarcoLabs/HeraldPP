#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include "ui/pages/ServerController/ServerChatController.h"
#include <memory>

class ServerChannelsController
{
public:
	ServerChannelsController(std::shared_ptr<int> currentChannelIndex, std::shared_ptr<slint::VectorModel<Channel>> channels, std::shared_ptr<slint::VectorModel<slint::SharedString>> members);

	void EvaluateCurrentChannelIndex();
	
	void ChangeChannelTo(size_t channelIndex);
	void AttemptSendMessageToCurrentChannel(const Message& message);

	void BindCurrentChannel();

private:
	std::shared_ptr<slint::VectorModel<Message>> GetMessagesByChannel(size_t index);
	
	std::shared_ptr<int> m_currentChannelIndex;
	std::shared_ptr<slint::VectorModel<Channel>> m_channels;
	std::shared_ptr<slint::VectorModel<slint::SharedString>> m_members;

	ServerChatController m_serverChatController;
};
