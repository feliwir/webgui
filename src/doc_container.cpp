#define STBI_NO_HDR
#define STBI_NO_PSD
#define STBI_NO_PNM
#define LITEHTML_UTF8
#include "doc_container.hpp"
#include "stb_image.h"
#include "stb_truetype.h"

using namespace wg;
unsigned char ttf_buffer[1 << 20];
unsigned char temp_bitmap[512 * 512];
stbtt_bakedchar cdata[96];

litehtml::uint_ptr	doc_container::create_font(const litehtml::tchar_t* faceName, int size, int weight,
	litehtml::font_style italic, unsigned int decoration, litehtml::font_metrics* fm)
{
	litehtml::uint_ptr texHandle = 0;
	stbtt_BakeFontBitmap(ttf_buffer, 0, 32.0, temp_bitmap, 512, 512, 32, 96, cdata);

	//create texture here when not in atlas already

	//return texture handle
	m_atlasCache[faceName] = texHandle;
	return texHandle;
}


void doc_container::delete_font(litehtml::uint_ptr hFont)
{
	//delete texture handle
}


void  doc_container::load_image(const litehtml::tchar_t* src, const litehtml::tchar_t* baseurl, bool redraw_on_ready)
{
	int x = 0, y = 0,n = 0;
	unsigned char* data = stbi_load(src, &x, &y, &n, 0);

	//create texture in renderer
	stbi_image_free(data);
}