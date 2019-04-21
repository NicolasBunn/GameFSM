#include "GoToBankState.h"
#include "GoToRiverState.h"
#include "GoToHomeState.h"
#include "GoToBarState.h"

GoToBankState* GoToBankState::Instance()
{
	static GoToBankState instance;
	return &instance;
}

void GoToBankState::Enter(Player* entity)
{
	std::cout << "Enter GoToBankState " << std::endl;
	DisplayMessage();
}


void GoToBankState::UpdateState(Player* entity, int decision)
{
	switch (decision)
	{
		case 2:
			entity->ChangeState(GoToRiverState::Instance());
			break;

		case 3:
			entity->ChangeState(GoToBarState::Instance());
			break;

		case 4:
			entity->ChangeState(GoToHomeState::Instance());
			break;
	}
}

void GoToBankState::Execute(Player* entity)
{
	goldInBank += entity->goldCarried;
	std::cout << "Put " << entity->goldCarried << " in bank" << std::endl;
	entity->goldCarried = 0;
	std::cout << "Total in bank " << goldInBank << std::endl;

	entity->energy -= 5;

	entity->DisplayStat();
	DisplayMessage();
}

void GoToBankState::Exit(Player* entity)
{
	std::cout << "Exit GoToBankState " << std::endl;
}

bool GoToBankState::OnMessage(Player* entity, const Message& msg)
{
	return false;
}

void GoToBankState::DisplayMessage()
{
	std::cout << "1) Stay at the bank ... " << std::endl;
	std::cout << "2) Go to find gold at the river " << std::endl;
	std::cout << "3) Go to the bar drink " << std::endl;
	std::cout << "4) Go to the home sleep " << std::endl;
}
