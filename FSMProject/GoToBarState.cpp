#include "GoToBarState.h"
#include "GoToHomeState.h"
#include "GoToRiverState.h"
#include "GoToBankState.h"
#include "MessageDispatcher.h"
#include "Message.h"

GoToBarState* GoToBarState::Instance()
{
	static GoToBarState instance;
	return &instance;
}

void GoToBarState::Enter(Player* entity)
{
	std::cout << "Enter GoToBarState " << std::endl;
	DisplayMessage();
}

void GoToBarState::UpdateState(Player* entity, int decision)
{
	switch (decision)
	{
		case 2:
			entity->ChangeState(GoToRiverState::Instance());
			break;

		case 3:
			entity->ChangeState(GoToBankState::Instance());
			break;

		case 4:
			entity->ChangeState(GoToHomeState::Instance());
			break;
	}
}

void GoToBarState::Execute(Player* entity)
{
	if (entity->goldCarried > 0)
	{
		entity->goldCarried--;
		std::cout << "Barman ! A drink please " << std::endl;
		MessageDispatcher::Instance()->DispatchMessage(entity->GetId(), 1, Message::MessageType::drinkInPreparation);
	}
	else
	{
		std::cout << "No enough money ! " << std::endl;
	}
}

void GoToBarState::Exit(Player* entity)
{
	std::cout << "Exit GoToBarState " << std::endl;
}

bool GoToBarState::OnMessage(Player* entity, const Message& msg)
{
	std::cout << "glou glou " << std::endl;

	entity->thirst += 50;
	entity->energy -= 10;

	entity->DisplayStat();
	DisplayMessage();

	return false;
}

void GoToBarState::DisplayMessage()
{
	std::cout << "1) Another drink ! " << std::endl;
	std::cout << "2) Go to find gold at the river " << std::endl;
	std::cout << "3) Go to the bank give money " << std::endl;
	std::cout << "4) Go to the home sleep " << std::endl;
}

