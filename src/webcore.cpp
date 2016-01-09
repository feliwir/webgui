#include "../include/webgui/webcore.hpp"
#include "../include/webgui/webview.hpp"
#include "doc_container.hpp"
#include <fstream>
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

bool Core::AddFontFromFile(const std::string& file)
{
	std::ifstream fin(file,std::ios::binary);
	fin.seekg(0,std::ios::end);
	auto size = fin.tellg();
	fin.seekg(0,std::ios::beg);
	std::uint8_t* data = new std::uint8_t[size];
	fin.read(reinterpret_cast<char*>(data),size);
	bool result = m_container->add_font(data);
	delete[] data;
	return result;
}

bool Core::AddFontFromMemory(const std::uint8_t* data)
{
	return m_container->add_font(data);
}