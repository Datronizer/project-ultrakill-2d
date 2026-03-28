#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include "StandardIncludes.h"

/**
 * @brief Object pool
 *
 * This class is used to allocate objects on the heap. This should be preferred
 * for dynamic allocations of data that changes often.
 */
template <class T>
class ObjectPool
{
public:
#pragma region Constructors
    ObjectPool() {}
    ~ObjectPool()
    {
        for (unsigned int i = 0; i < m_pool.size(); i++)
        {
            cout << "Deleting object " << i << endl;
            delete m_pool[i];
        }
        m_pool.clear();
        m_available.clear();
    }
#pragma endregion

#pragma region Methods
    T *GetResource()
    {
        if (m_available.empty())
        {
            cout << "Pool is empty, allocating new object" << endl;
            T *newObj = new T();
            m_pool.push_back(newObj);
            return newObj;
        }
        else
        {
            cout << "Object exists in pool, returning" << endl;
            T *obj = m_available[0];
            m_available.erase(m_available.begin()); // Remove from available
            return obj;
        }
    }

    void ReleaseResource(T *_obj)
    {
        cout << "Releasing object" << endl;
        _obj->Reset();
        m_available.push_back(_obj);
    }

#pragma endregion

private:
    vector<T> m_available;
    vector<T> m_pool;
};

#endif // OBJECTPOOL_H