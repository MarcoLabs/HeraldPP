#pragma once

#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include <memory>

class ServerChannelsController
{
public:
	ServerChannelsController(std::shared_ptr<int> currentChannelIndex, std::shared_ptr<slint::VectorModel<Channel>> channels);

	void ChangeChannelTo(size_t channelIndex);

private:
	std::shared_ptr<int> m_currentChannelIndex;
	std::shared_ptr<slint::VectorModel<Channel>> m_channels;
};
