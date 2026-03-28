#ifndef STACKALLOCATOR_H
#define STACKALLOCATOR_H

#include <cstring>

/**
 * @brief Stack allocator
 *
 * This class is used to allocate memory on the stack. This should be preferred
 * for allocating persistent data ahead of time for performance reasons.
 *
 * All sizes are in bytes.
 *
 * Avoid using this class for dynamic allocations, as it is not thread-safe.
 *
 * @example Loading textures, models, levels, etc.
 *
 */
class StackAllocator
{
public:
#pragma region Constructors
    StackAllocator();
    ~StackAllocator();
#pragma endregion

#pragma region Accessors
    /**
     * @brief Returns the saved marker position.
     * @return Pointer to the address saved by the last Mark() call.
     */
    unsigned char *GetMarker() { return m_marker; }

    /**
     * @brief Returns the number of bytes currently in use.
     * @return Bytes between the start of the block and the current stack top.
     */
    int GetBytesUsed() { return m_stackPosition - m_stackStart; }
#pragma endregion

#pragma region Methods
    /**
     * @brief Allocates a memory block of the given size for the stack to use.
     * @param _sizeInBytes Size of the memory block in bytes.
     */
    void Allocate(unsigned int _sizeInBytes);

    /**
     * @brief Returns a pointer to the next available memory of the given size
     *        and advances the stack position forward.
     * @param _sizeInBytes Number of bytes to claim.
     * @return Pointer to the start of the claimed memory.
     */
    unsigned char *ClaimMemory(unsigned int _sizeInBytes);

    /**
     * @brief Saves the current stack position as a marker.
     *        Use FreeToMarker() to rewind back to this point.
     */
    void Mark();

    /**
     * @brief Rewinds the stack position back to the last saved marker,
     *        freeing everything allocated since Mark() was called.
     */
    void FreeToMarker();

    /**
     * @brief Resets the stack position to the start, freeing all allocations.
     */
    void ClearMemory();
#pragma endregion

private:
    /** @brief Saved snapshot of m_stackPosition at the time Mark() was called.
     *         FreeToMarker() rewinds m_stackPosition back to this address. */
    unsigned char *m_marker;

    /** @brief Pointer to the start of the allocated memory block.
     *         Fixed after Allocate(). Used as the baseline for GetBytesUsed(). */
    unsigned char *m_stackStart;

    /** @brief Pointer to the current top of the stack.
     *         Advances forward on each ClaimMemory() call. */
    unsigned char *m_stackPosition;

    /** @brief Pointer to the end of the allocated memory block.
     *         Fixed after Allocate(). Used to detect out-of-memory. */
    unsigned char *m_stackEnd;
};

#endif // STACKALLOCATOR_H
