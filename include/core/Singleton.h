#ifndef SINGLETON_H
#define SINGLETON_H

/**
 * @brief Singleton class
 *
 * This class is used to create a single instance of a class. It is
 * implemented as a template, so it can be used with any class.
 * 
 * Only one instance of the class can exist at a time. To access the
 * single instance, use the Instance() function.
 *
 * @tparam T - Type of the class to be made singleton
 *
 * @note I ripped this from Tails Engine (which I also made)
 */
template <typename T>
class Singleton
{
public:
    // Creates singleton instance if it doesn't exist, otherwise returns existing instance
    static T &Instance()
    {
        static T instance;
        return instance;
    }

protected:
    Singleton() {}
    virtual ~Singleton() {}

public: 
    Singleton(Singleton const&) = delete;
    Singleton& operator=(Singleton const&) = delete;
};

#endif // SINGLETON_H