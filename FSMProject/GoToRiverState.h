#pragma once

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Player.h"

class GoToRiverState : public State<Player>
{
	public:
		static GoToRiverState* Instance();

		virtual void Enter(Player* entity) override;
		virtual void Execute(Player* entity) override;
		virtual void Exit(Player* entity) override;
		virtual void UpdateState(Player* entity, int decision) override;

		virtual bool OnMessage(Player* entity, const Message& msg) override;
		virtual void DisplayMessage() override;
};