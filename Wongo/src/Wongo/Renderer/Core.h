#ifndef _RENDERER_CORE_
#define _RENDERER_CORE_

namespace Wongo
{

    class RenderObjectBase
    {
    public:
        virtual ~RenderObjectBase() = default;

    protected:
        RenderObjectBase() = default;

        RenderObjectBase(RenderObjectBase const&) = delete;
        RenderObjectBase(RenderObjectBase&&) noexcept = delete;
        
        RenderObjectBase& operator=(RenderObjectBase const&) = delete;
        RenderObjectBase& operator=(RenderObjectBase&&) noexcept = delete;
    };

    enum class DataType
	{
		None = 0,
		Float,
        UnsignedInt,
	};

    int GetDataTypeSize(DataType type);

}

#endif
