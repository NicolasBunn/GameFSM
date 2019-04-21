#include "GoToRiverState.h"
#include "GoToHomeState.h"
#include "GoToBarState.h"
#include "GoToBankState.h"


GoToRiverState* GoToRiverState::Instance()
{
	static GoToRiverState instance;
	return &instance;
}

void GoToRiverState::Enter(Player* entity)
{
	std::cout << "Enter to go to river state " << std::endl;
	DisplayMessage();
}

void GoToRiverState::UpdateState(Player* entity, int decision)
{
	switch (decision)
	{
		case 2:
			entity->ChangeState(GoToHomeState::Instance());
			break;

		case 3:
			entity->ChangeState(GoToBankState::Instance());
			break;

		case 4:
			entity->ChangeState(GoToBarState::Instance());
			break;
	}
}

void GoToRiverState::Execute(Player* entity)
{
	std::cout << "Searching gold in River " << std::endl;
	entity->thirst -= 10;
	entity->energy -= 5;

	int goldRandom = rand() % 5;
	if (goldRandom == 0)
	{
		std::cout << "Didn't find any gold " << std::endl;
	}
	else
	{
		std::cout << "Find " << goldRandom << " Gold " << std::endl;
		entity->goldCarried += goldRandom;
		entity->totalGold += goldRandom;
		if (entity->goldCarried > entity->maxGold)
		{
			std::cout << "Maxium Gold carried , go to the bank " << std::endl;
			entity->goldCarried = entity->maxGold;
		}
		entity->DisplayStat();

	}
	DisplayMessage();
}

void GoToRiverState::Exit(Player* entity)
{
	std::cout << "Exit GoToHomeState state " << std::endl;
}

bool GoToRiverState::OnMessage(Player* entity, const Message& msg)
{
	return false;
}

void GoToRiverState::DisplayMessage()
{
	std::cout << "1) Find Gold  " << std::endl;
	std::cout << "2) Go to home to rest" << std::endl;
	std::cout << "3) Go to the bank to give gold " << std::endl;
	std::cout << "4) Go to the bar drink " << std::endl;
}
