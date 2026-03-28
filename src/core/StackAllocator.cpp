#include "core/StackAllocator.h"


StackAllocator::StackAllocator()
{
    ClearMemory();
}

StackAllocator::~StackAllocator()
{
    ClearMemory();
}

void StackAllocator::Allocate(unsigned int _sizeInBytes)
{
    m_stackStart = new unsigned char[_sizeInBytes];
    memset(m_stackStart, 0, _sizeInBytes);
    m_stackPosition = m_stackStart;
    m_stackEnd = m_stackStart + _sizeInBytes;
}

unsigned char *StackAllocator::ClaimMemory(unsigned int _sizeInBytes)
{
    unsigned char *hold = m_stackPosition;
    if (m_stackPosition + _sizeInBytes <= m_stackEnd)
    {
        m_stackPosition += _sizeInBytes;
        return hold;
    }
    return nullptr;  // Out of memory
}

void StackAllocator::Mark()
{
    m_marker = m_stackPosition;
}

void StackAllocator::FreeToMarker()
{
    m_stackPosition = m_marker;
    *m_stackPosition = 0;
}

void StackAllocator::ClearMemory()
{
    if (m_stackStart != nullptr)
    {
        delete[] m_stackStart;
        m_stackStart = nullptr;
        m_stackPosition = nullptr;
        m_stackEnd = nullptr;
        m_marker = nullptr;
    }
}