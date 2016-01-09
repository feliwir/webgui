#include "../include/webgui/webview.hpp"
#include "../include/webgui/webcore.hpp"
#include <fstream>
using namespace wg;

WebView::WebView(std::shared_ptr<Core> core) : m_core(core), m_document(nullptr)
{

}

WebView::~WebView()
{

}

bool WebView::LoadDocument(const std::string& path)
{
	std::ifstream fin(path);
	if(fin.fail())
		return false;

	fin.seekg(0,std::ios::end);
	auto size = fin.tellg();
	fin.seekg(0,std::ios::beg);
	char* buffer = new char[size];
	fin.read(buffer,size);

	m_document = litehtml::document::createFromUTF8(buffer, m_core->GetContainer().get(),
		m_core->GetContext().get());

	delete[] buffer;
	return true;
}
