#ifndef _BUFFER_
#define _BUFFER_

#include "Core.h"

#include <memory>

namespace Wongo
{

	class VertexBuffer : private Wongo::RenderObjectBase
	{
	public:

		struct Description
		{
			int size = 0;
			DataType dataType = DataType::None;
			void const* data = nullptr;
		};

		struct Attribute
		{
			int count = 0;
			bool normalize = false;
		};

		static std::shared_ptr<VertexBuffer> Create(Description desc);

		virtual void AddAttribute(int count, bool normalized = false) = 0;
	};

	class IndexBuffer : private Wongo::RenderObjectBase
	{
	public:
		struct Description
		{
			int count = 0;
			DataType dataType = DataType::None;
			void const* data = nullptr;
		};

		static std::shared_ptr<IndexBuffer> Create(Description desc);
	};

	class UniformBuffer : private Wongo::RenderObjectBase
	{
	public:
		
		struct Description
		{
			int size = 0;
		};

		static std::shared_ptr<UniformBuffer> Create(Description desc);

        virtual void Set(int offset, int size, void const* data) = 0;
        virtual void Bind(unsigned int index) = 0;
	};

}

#endif
