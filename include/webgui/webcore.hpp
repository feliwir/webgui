#pragma once
#include <litehtml.h>
#include <memory>

namespace wg
{
	class WebView;

	class Core
	{
	public:
		Core();
		~Core();

		std::shared_ptr<WebView> CreateView();
		inline std::shared_ptr<litehtml::document_container> GetContainer()
		{
			return m_container;
		}

		inline std::shared_ptr<litehtml::context> GetContext()
		{
			return m_context;
		}

	private:
		std::shared_ptr<litehtml::context> m_context;
		std::shared_ptr<litehtml::document_container> m_container;
	};
}