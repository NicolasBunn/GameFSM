#include "Player.h"
#include "State.h"

Player::Player(int energy_,int thirst_)
	: energy{ energy_ }, thirst{ thirst_ }, goldCarried{ 0 }, totalGold{ 0 }, GameEntity{ 0 }
{
	
}

Player::~Player()
{
	delete fsm;
}

void Player::CreateFSM()
{
	fsm = new StateMachine<Player>(this);
}

void Player::Update()
{

}

void Player::ChangeState(State<Player>* newState)
{
	fsm->ChangeState(newState);
}

void Player::DisplayStat() const
{
	std::cout << "Energy " << energy << std::endl;
	if (energy <= 10)
	{
		std::cout << "You are tired go to sleep at home !" << std::endl;
	}
	std::cout << "Thirst " << thirst << std::endl;
	if (thirst <= 10)
	{
		std::cout << "You are thirsty, go to the bar drink !" << std::endl;
	}
	std::cout << "Gold carried " << goldCarried << std::endl;
	std::cout << "Total gold " << totalGold << std::endl;
}

bool Player::HandleMessage(const Message& msg)
{
	return fsm->HandleMessage(msg);
}