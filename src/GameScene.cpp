#include "GameScene.h"

GameScene::GameScene(EventManager& p_eventManager, GameInfo& p_gameInfo)
	: Manager(), m_eventManager(p_eventManager), m_gameInfo(p_gameInfo)
{
}

GameScene::~GameScene()
{
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		delete (*iterator).second;
}

void GameScene::Setup()
{
	FixedActor* background = new FixedActor;
	background->Construct("Background/background.jpg", 0, 0);
	AddActor(0, background);

	FixedActor* block = new FixedActor;
	block->Construct("Tiles/block.png", 1000, 700);
	AddActor(1, block);

	AddActor(2, new Player);
}

void GameScene::Update()
{	
	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		(*iterator).second->Update(GetEventManager(), GetGameInfo());
}

void GameScene::Draw()
{
	DrawGrid();

	for (auto iterator = GetActors().begin(); iterator != GetActors().end(); ++iterator)
		(*iterator).second->Draw();
}

void GameScene::DrawGrid() const
{
	const int increment = GRID_INCREMENT;
	vec2 currentUp(0, 0);
	vec2 currentDown(0, WINDOW_HEIGHT);

	vec2 currentLeft(0, 0);
	vec2 currentRight(WINDOW_WIDTH, 0);

	if (SHOW_GRID)
	{
		gl::color(1, 1, 1, GRID_ALPHA);
		while (currentUp.x <= WINDOW_WIDTH)
		{
			gl::drawLine(currentUp, currentDown);
			currentUp.x += increment;
			currentDown.x += increment;
		}
		while (currentLeft.y <= WINDOW_HEIGHT)
		{
			gl::drawLine(currentLeft, currentRight);
			currentLeft.y += increment;
			currentRight.y += increment;
		}
	}
	gl::color(1, 1, 1, 1);
}
