#pragma once
#include <string>
#include "webcore.hpp"

namespace wg
{
	class WebView
	{
	public:
		WebView(std::shared_ptr<wg::Core> core);
		~WebView();

		bool LoadDocument(const std::string& path);
	private:
		std::shared_ptr<wg::Core> m_core;
		litehtml::document::ptr m_document;
	};
}