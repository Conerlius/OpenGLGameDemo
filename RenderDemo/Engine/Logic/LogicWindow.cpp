#include "LogicWindow.h"

#include "Configure/GConfig.h"
NS_BEGIN

    void LogicWindow::Start()
    {
    // 初始化引擎配置
    auto conf = GConfig::get("GameConfig");
    // delete conf;
    }

    void LogicWindow::Destroy()
    {
    }

    void LogicWindow::update(float detla)
    {
    }

NS_END
