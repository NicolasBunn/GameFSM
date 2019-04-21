#include "GoToHomeState.h"
#include "GoToRiverState.h"
#include "GoToBankState.h"
#include "GoToBarState.h"

GoToHomeState* GoToHomeState::Instance()
{
	static GoToHomeState instance;
	return &instance;
}

void GoToHomeState::Enter(Player* entity)
{
	std::cout << "Enter GoToHomeState " << std::endl;
	DisplayMessage();
}

void GoToHomeState::UpdateState(Player* entity, int decision)
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
			entity->ChangeState(GoToBarState::Instance());
			break;
	}
}

void GoToHomeState::Execute(Player* entity)
{
	std::cout << "ZZZZZZzzzzz  " << std::endl;
	entity->energy += 10;
	entity->thirst -= 1;
	entity->DisplayStat();
	DisplayMessage();
}

void GoToHomeState::Exit(Player* entity)
{
	std::cout << "Exit GoToHomeState state " << std::endl;
}

bool GoToHomeState::OnMessage(Player* entity, const Message& msg)
{
	return false;
}

void GoToHomeState::DisplayMessage()
{
	std::cout << "1) Stay in bed " << std::endl;
	std::cout << "2) Go to find gold at the river" << std::endl;
	std::cout << "3) Go to the bank to give gold " << std::endl;
	std::cout << "4) Go to the bar drink " << std::endl;
}
