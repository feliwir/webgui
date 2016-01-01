#pragma once
#define LITEHTML_UTF8
#include <litehtml.h>
#include <memory>
#include "webview.hpp"

namespace wg
{
	class core
	{
	public:
		core();
		~core();

		std::shared_ptr<webview> CreateView();
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