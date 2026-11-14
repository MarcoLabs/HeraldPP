#include "ui/pages/ServerController/ServerChannelsController.h"

ServerChannelsController::ServerChannelsController(std::shared_ptr<int> currentChannelIndex, std::shared_ptr<slint::VectorModel<Channel>> channels):
	m_currentChannelIndex(std::move(currentChannelIndex)),
	m_channels(std::move(channels))
{ }

void ServerChannelsController::EvaluateCurrentChannelIndex()
{
	for (size_t i = 0; i < this->m_channels->row_count(); i++)
	{
		const auto& channel = m_channels->row_data(i);

		if (channel->selected)
		{
			*this->m_currentChannelIndex = static_cast<int>(i);
			
			break;
		}
	}
}

void ServerChannelsController::ChangeChannelTo(size_t channelIndex)
{
	if (channelIndex >= this->m_channels->row_count())
	{
		return;
	}
	
	auto currentChannel = this->m_channels->row_data(static_cast<size_t>(*this->m_currentChannelIndex));
	currentChannel->selected = false;

	auto selectedChannel = this->m_channels->row_data(channelIndex);
	selectedChannel->selected = true;

	this->m_channels->set_row_data(static_cast<size_t>(*this->m_currentChannelIndex), currentChannel.value());
	this->m_channels->set_row_data(channelIndex, selectedChannel.value());
}
