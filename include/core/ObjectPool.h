#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

/**
 * @brief Object pool
 *
 * Manages a fixed set of reusable heap-allocated objects to avoid repeated
 * new/delete calls. Preferred for objects that are frequently created and destroyed.
 *
 * @details Two lists are maintained internally:
 *   - m_pool:      owns every object ever allocated. Never shrinks.
 *   - m_available: objects that have been released and are waiting to be reused.
 *
 * When an object is requested via GetResource(), an object from m_available is
 * returned if one exists. Otherwise a new object is allocated and added to m_pool.
 *
 * When an object is returned via ReleaseResource(), its state is reset and it is
 * moved to m_available, ready to be handed out again without a new allocation.
 *
 * @example
 *   ObjectPool<Enemy> pool;
 *   Enemy *e = pool.GetResource();   // allocates if pool is empty
 *   pool.ReleaseResource(e);         // resets e, marks it as available
 *   Enemy *e2 = pool.GetResource();  // returns the same object as e, no allocation
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
    /**
     * @brief Returns an object ready for use.
     *        Reuses a released object if one is available, otherwise allocates a new one.
     * @return Pointer to the object.
     */
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

    /**
     * @brief Returns an object back to the pool so it can be reused.
     *        Resets the object's state before marking it as available.
     * @param _obj Pointer to the object to release.
     */
    void ReleaseResource(T *_obj)
    {
        cout << "Releasing object" << endl;
        _obj->Reset();
        m_available.push_back(_obj);
    }

    /**
     * @brief Pre-allocates _count objects and parks them in m_available.
     *        Call this before the game loop to avoid allocations at runtime.
     * @param _count Number of objects to preallocate.
     */
    void Prewarm(unsigned int _count)
    {
        for (unsigned int i = 0; i < _count; i++)
        {
            T *obj = new T();
            m_pool.push_back(obj);
            m_available.push_back(obj);
        }
    }

#pragma endregion

private:
    /** @brief Objects that have been released and are ready to be reused.
     *         Handed out first by GetResource() before allocating new ones. */
    vector<T> m_available;

    /** @brief Every object ever allocated by this pool.
     *         Owns all memory — destructor deletes everything in here. */
    vector<T> m_pool;
};

#endif // OBJECTPOOL_H