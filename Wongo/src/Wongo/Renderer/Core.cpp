#include "Core.h"

int Wongo::GetDataTypeSize(Wongo::DataType type)
{
    switch (type)
    {
        case Wongo::DataType::UnsignedInt:
        case Wongo::DataType::Float:
            return 4;
        default: return 0;
    }
}
