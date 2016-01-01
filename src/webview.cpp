#include "webview.hpp"
using namespace wg;

webview::webview(std::shared_ptr<core> core) : m_core(core), m_document(nullptr)
{

}

webview::~webview()
{

}

bool webview::LoadDocument(const std::string& path)
{
	m_document = litehtml::document::createFromString(path.c_str(), m_core->GetContainer().get(),
		m_core->GetContext().get());
}
