#include "../include/gamemanager.h"

GameManager::GameManager()
{
    player = Player();
}

void GameManager::addChapter(Chapter chapter) {
    pair<string, Chapter> tmp(chapter.getChapterName(), chapter);
    this->story.insert(tmp);
}

Chapter *GameManager::findChapter(string key) {
    if (this->story.find(key) != this->story.end()){ //iterator check
        return &(this->story[key]);
    }
    else
        return NULL;
}

Player& GameManager::getPlayer() {
    this->player;
}

void GameManager::setPlayer(Player p) {
    this->player = p;

}


