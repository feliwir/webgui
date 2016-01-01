#include "webcore.hpp"
#include "doc_container.hpp"
using namespace wg;

core::core() 
{
	m_context = std::make_shared<litehtml::context>();
	m_context->load_master_stylesheet("master.css");

	m_container = std::make_shared<doc_container>();
}

core::~core()
{

}

std::shared_ptr<webview> core::CreateView()
{
	auto view = std::make_shared<webview>();
}
