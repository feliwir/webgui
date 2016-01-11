#pragma once
#include <string>
#include <memory>
#include <litehtml.h>
#include "visibility.hpp"
namespace wg
{
	class Core;

	class WG_API WebView
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