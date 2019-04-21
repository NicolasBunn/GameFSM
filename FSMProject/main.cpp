#include <iostream>

#include "Player.h"
#include "Barman.h"
#include "EntityManager.h"
#include "StateMachine.h"
#include "GoToRiverState.h"
#include "GoToHomeState.h"
#include "CleanBarState.h"

int main()
{
	constexpr int goalAim = 10;
	int turn = 0;

	Barman barman;
	Player player(100, 100);

	player.CreateFSM();
	barman.CreateFSM();

	barman.fsm->SetCurrentState(CleanBarState::Instance());

	std::cout << "Welcome to FSM Game : Try to get " << goalAim << " golds as fast as possible " << std::endl;

	player.fsm->ChangeState(GoToHomeState::Instance());
	player.fsm->Update();
	
	EntityManager::Instance()->RegisterEntity(&player);
	EntityManager::Instance()->RegisterEntity(&barman);

	char input = 0;
	bool exit = false;
	while (!exit && player.totalGold < goalAim)
	{
		std::cin >> input;
		bool valid = false;
		int decision = 0;
		turn++;
		if (input >=48 && input <=53) //accepting 2-9
		{
			int decision = input - '0';
			//std::cout << "Input is number " << decision << std::endl;
			switch (decision)
			{
				case 0:
					exit = true;
					break;

				case 1:
				case 2:
				case 3:
				case 4:
					valid = true;
					break;
			}

			if (valid)
			{
				player.fsm->UpdateDecision(decision);
				player.fsm->Update();
				barman.fsm->Update();
			}
		}
	}

	if (player.energy <= 0 || player.thirst <= 0)
	{
		std::cout << "Game Over ! " << std::endl;
	}

	if (player.totalGold >= goalAim)
	{
		std::cout << "You win in " << turn << " ! " << std::endl;
	}

	int end;

	std::cout << "Input a value to qui the game " << std::endl;

	std::cin >> end;

	return 0;
}