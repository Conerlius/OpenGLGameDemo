#pragma once
#include "Common/MEngine.h"
#include <memory>

#include "Logic/core/GameObject.h"
#include "Logic/core/Level.h"

NS_BEGIN
/**
 * \brief 游戏场景
 */
class Scene : public Level
{
public:
    void AddGameObject(std::shared_ptr<GameObject> gameObject);
    void RemoveGameObject(std::shared_ptr<GameObject> gameObject);
};


NS_END