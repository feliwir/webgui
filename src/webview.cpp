#include "../include/webgui/webview.hpp"
#include "../include/webgui/webcore.hpp"

using namespace wg;

WebView::WebView(std::shared_ptr<Core> core) : m_core(core), m_document(nullptr)
{

}

WebView::~WebView()
{

}

bool WebView::LoadDocument(const std::string& path)
{
	m_document = litehtml::document::createFromString(path.c_str(), m_core->GetContainer().get(),
		m_core->GetContext().get());

	return true;
}
