#pragma once
#include <string>
#include "webcore.hpp"

namespace wg
{
	class webview
	{
	public:
		webview(std::shared_ptr<wg::core> core);
		~webview();

		bool LoadDocument(const std::string& path);
	private:
		std::shared_ptr<wg::core> m_core;
		litehtml::document::ptr m_document;
	};
}