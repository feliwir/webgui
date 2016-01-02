#pragma once
#include "litehtml.h"
#include <string>
#include <map>
namespace wg
{
	class doc_container : public litehtml::document_container
	{
	public:
		litehtml::uint_ptr	create_font(const litehtml::tchar_t* faceName, int size, int weight, 
										litehtml::font_style italic, unsigned int decoration, litehtml::font_metrics* fm);

		void delete_font(litehtml::uint_ptr hFont);

		void load_image(const litehtml::tchar_t* src, const litehtml::tchar_t* baseurl, bool redraw_on_ready);
	private:
		std::map<std::string, litehtml::uint_ptr> m_imageCache;
		std::map<std::string, litehtml::uint_ptr> m_atlasCache;
	};
}