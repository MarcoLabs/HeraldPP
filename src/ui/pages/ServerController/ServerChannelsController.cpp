#include "ui/pages/ServerController/ServerChannelsController.h"
#include "MainWindow_ui.h"
#include "private/slint_models.h"
#include "private/slint_string.h"
#include <memory>

ServerChannelsController::ServerChannelsController(std::shared_ptr<int> currentChannelIndex, std::shared_ptr<slint::VectorModel<Channel>> channels, std::shared_ptr<slint::VectorModel<slint::SharedString>> members):
	m_currentChannelIndex(std::move(currentChannelIndex)),
	m_channels(std::move(channels)),
	m_members(std::move(members)),
	m_serverChatController(nullptr)
{ }

void ServerChannelsController::ChangeChannelTo(size_t channelIndex)
{
	if (channelIndex >= this->m_channels->row_count())
	{
		return;
	}

	auto messages = this->GetMessagesByChannel(channelIndex);
	if (! messages)
	{
		return;
	}
	
	auto currentChannel = this->m_channels->row_data(static_cast<size_t>(*this->m_currentChannelIndex));
	currentChannel->selected = false;

	auto selectedChannel = this->m_channels->row_data(channelIndex);
	selectedChannel->selected = true;

	this->m_channels->set_row_data(static_cast<size_t>(*this->m_currentChannelIndex), currentChannel.value());
	this->m_channels->set_row_data(channelIndex, selectedChannel.value());

	*this->m_currentChannelIndex = static_cast<int>(channelIndex);
	m_serverChatController.SetMessages(std::move(messages));
}

void ServerChannelsController::AttemptSendMessageToCurrentChat(const Message& message)
{
	m_serverChatController.AttemptSendMessage(message);
}

void ServerChannelsController::BindCurrentChannel()
{
	this->EvaluateCurrentChannelIndex();
	this->m_serverChatController.SetMessages(this->GetMessagesByChannel(static_cast<size_t>(*this->m_currentChannelIndex)));
}

std::shared_ptr<slint::VectorModel<Message>> ServerChannelsController::GetMessagesByChannel(size_t index)
{
	auto channel = this->m_channels->row_data(index);
	if (! channel)
	{
		return nullptr;
	}

	return std::dynamic_pointer_cast<slint::VectorModel<Message>>(channel->messages);
}

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
