#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "core/Singleton.h"

/**
 * A level manager is responsible for loading and unloading levels.
 * 
 * Levels are stored as .lvl files in the levels/ directory.
 */
class LevelController : public Singleton<LevelController>
{
    public:
        LevelController();

        void loadLevel(const char *level_name);
        void unloadLevel();

        void update();
        void draw();

    private:
        
};

#endif // LEVELMANAGER_H