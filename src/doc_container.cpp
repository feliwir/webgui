#define STBI_NO_HDR
#define STBI_NO_PSD
#define STBI_NO_PNM
#include "doc_container.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"
#include <stdint.h>
using namespace wg;
unsigned char ttf_buffer[1 << 20];
unsigned char temp_bitmap[512 * 512];
stbtt_bakedchar cdata[96];

litehtml::uint_ptr	doc_container::create_font(const litehtml::tchar_t* faceName, int size, int weight,
	litehtml::font_style italic, unsigned int decoration, litehtml::font_metrics* fm)
{
	litehtml::uint_ptr texHandle = 0;
	stbtt_BakeFontBitmap(ttf_buffer, 0, size, temp_bitmap, 512, 512, 32, 96, cdata);

	//create texture here when not in atlas already
	texHandle = (litehtml::uint_ptr)m_renderer->CreateTexture(512,512,temp_bitmap);
	//return texture handle
	m_atlasCache[faceName] = texHandle;
	return texHandle;
}


void doc_container::delete_font(litehtml::uint_ptr hFont)
{
	//delete texture handle
}

int doc_container::text_width(const litehtml::tchar_t * text, litehtml::uint_ptr hFont)
{
	return 0;
}

void doc_container::draw_text(litehtml::uint_ptr hdc, const litehtml::tchar_t * text, litehtml::uint_ptr hFont, litehtml::web_color color, const litehtml::position & pos)
{
}

int doc_container::pt_to_px(int pt)
{
	return 0;
}

int doc_container::get_default_font_size() const
{
	return 0;
}

const litehtml::tchar_t * doc_container::get_default_font_name() const
{
	return "arial";
}


void doc_container::draw_list_marker(litehtml::uint_ptr hdc, const litehtml::list_marker & marker)
{
}

void  doc_container::load_image(const litehtml::tchar_t* src, const litehtml::tchar_t* baseurl, bool redraw_on_ready)
{
	int x = 0, y = 0,n = 0;
	unsigned char* data = stbi_load(src, &x, &y, &n, 0);

	//create texture in renderer
	stbi_image_free(data);
}

void doc_container::get_image_size(const litehtml::tchar_t * src, const litehtml::tchar_t * baseurl, litehtml::size & sz)
{
}

void doc_container::draw_background(litehtml::uint_ptr hdc, const litehtml::background_paint & bg)
{
}

void doc_container::draw_borders(litehtml::uint_ptr hdc, const litehtml::borders & borders, const litehtml::position & draw_pos, bool root)
{
}

void doc_container::set_caption(const litehtml::tchar_t * caption)
{
}

void doc_container::set_base_url(const litehtml::tchar_t * base_url)
{
}

void doc_container::link(const std::shared_ptr<litehtml::document>& doc, const litehtml::element::ptr & el)
{
}

void doc_container::on_anchor_click(const litehtml::tchar_t * url, const litehtml::element::ptr & el)
{
}

void doc_container::set_cursor(const litehtml::tchar_t * cursor)
{
}

void doc_container::transform_text(litehtml::tstring & text, litehtml::text_transform tt)
{
}

void doc_container::import_css(litehtml::tstring & text, const litehtml::tstring & url, litehtml::tstring & baseurl)
{
}

void doc_container::set_clip(const litehtml::position & pos, const litehtml::border_radiuses & bdr_radius, bool valid_x, bool valid_y)
{
}

void doc_container::del_clip()
{
}

void doc_container::get_client_rect(litehtml::position & client) const
{
}

std::shared_ptr<litehtml::element> doc_container::create_element(const litehtml::tchar_t * tag_name, const litehtml::string_map & attributes, const std::shared_ptr<litehtml::document>& doc)
{
	return std::shared_ptr<litehtml::element>();
}

void doc_container::get_media_features(litehtml::media_features & media) const
{
}

void doc_container::get_language(litehtml::tstring & language, litehtml::tstring & culture) const
{
}

void doc_container::set_renderer(std::shared_ptr<RenderInterface> renderer)
{
	m_renderer = renderer;
}

bool doc_container::add_font(const std::uint8_t *data,bool def)
{
	if(m_defaultFont.size()==0)
		def = true;

	stbtt_fontinfo* font = new stbtt_fontinfo();
	int result = stbtt_InitFont(font,data,0);
	if(result==0)
		return false;

	int length = 0;
	const char* buf = stbtt_GetFontNameString(font,&length,STBTT_PLATFORM_ID_MAC,STBTT_MAC_EID_ROMAN,
											   STBTT_MAC_LANG_ENGLISH,1);

	std::string name(buf,length);
	m_fonts[name] = font;
	if(def)
		m_defaultFont = name;

	return true;
}