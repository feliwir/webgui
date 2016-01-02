#pragma once
#include <string>
#include <memory>
#define LITEHTML_UTF8
#include <litehtml.h>

namespace wg
{
	class Core;

	class WebView
	{
	public:
		WebView(std::shared_ptr<Core> core);
		~WebView();

		bool LoadDocument(const std::string& path);
	private:
		std::shared_ptr<Core> m_core;
		litehtml::document::ptr m_document;
	};

}