#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

/**
 * A level manager is responsible for loading and unloading levels.
 * 
 * Levels are stored as .lvl files in the levels/ directory.
 */
class LevelManager
{
    public:
        LevelManager();

        void loadLevel(const char *level_name);
        void unloadLevel();

        void update();
        void draw();

    private:
        
};

#endif // LEVELMANAGER_H