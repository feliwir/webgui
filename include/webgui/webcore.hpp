#pragma once
#include <litehtml.h>
#include <memory>
#include <stdint.h>
#include "../../src/doc_container.hpp"
#include "visibility.hpp"

namespace wg
{
	class WebView;

	class WG_API Core
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

		inline void SetRenderer(std::shared_ptr<RenderInterface> renderer)
		{
			m_container->set_renderer(renderer);
		}

		bool AddFontFromFile(const std::string& file);
		bool AddFontFromMemory(const std::uint8_t* data);
	private:
		std::shared_ptr<litehtml::context> m_context;
		std::shared_ptr<wg::doc_container> m_container;
	};
}