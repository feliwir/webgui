#include "../include/webgui/webcore.hpp"
#include "../include/webgui/webview.hpp"
#include "doc_container.hpp"
using namespace wg;

Core::Core()
{
	m_context = std::make_shared<litehtml::context>();
	m_context->load_master_stylesheet("master.css");

	m_container = std::make_shared<doc_container>();
}

Core::~Core()
{

}

std::shared_ptr<WebView> Core::CreateView()
{
	auto view = std::make_shared<WebView>(std::shared_ptr<Core>(this));

	return view;
}
