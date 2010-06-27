#include "kal_release.h"

kal_uint32 crc_table[256];

/* Flag: has the table been computed? Initially false. */
int crc_table_computed = 0;

/* Make the table for a fast CRC. */
static void make_crc_table(void)
{
  unsigned long c;
  int n, k;

  for (n = 0; n < 256; n++) {
    c = (unsigned long) n;
    for (k = 0; k < 8; k++) {
      if (c & 1)
        c = 0xedb88320L ^ (c >> 1);
      else
        c = c >> 1;
    }
    crc_table[n] = c;
  }
  crc_table_computed = 1;
}

/* Update a running CRC with the bytes buf[0..len-1]--the CRC
   should be initialized to all 1's, and the transmitted value
   is the 1's complement of the final running CRC (see the
   crc() routine below)). */

kal_uint32 png_update_crc(kal_uint32 crc, kal_uint8 *buf,
                         kal_uint32 len)
{
  unsigned long c = crc;
  int n;

  if (!crc_table_computed)
    make_crc_table();
  for (n = 0; n < len; n++) {
    c = crc_table[(c ^ buf[n]) & 0xff] ^ (c >> 8);
  }
  return c;
}

/* Return the CRC of the bytes buf[0..len-1]. */
kal_uint32 png_crc32(kal_uint8 *buf, kal_uint32 len)
{
  return png_update_crc(0xffffffffL, buf, len) ^ 0xffffffffL;
}

/* ========================================================================= */
#define DO1(buf) crc = crc_table[((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8);
#define DO2(buf)  DO1(buf); DO1(buf);
#define DO4(buf)  DO2(buf); DO2(buf);
#define DO8(buf)  DO4(buf); DO4(buf);

/* ========================================================================= */

#if defined(__MTK_TARGET__)&& defined(PNG_SW_USE_ISRAM)
#pragma arm section code = "INTERNCODE"
#endif /* __MTK_TARGET__ */

kal_uint32  png_crc32_sw(crc, buf, len)
    kal_uint32 crc;
    const kal_uint8 *buf;
    kal_uint32 len;
{
   if (buf == NULL) return 0L;
  	if (!crc_table_computed)
   	make_crc_table();
	crc = crc ^ 0xffffffffL;
	while (len >= 8)
	{
		DO8(buf);
		len -= 8;
	}
	if (len) do {
		DO1(buf);
	} while (--len);
	
	return crc ^ 0xffffffffL;
}

#if defined(__MTK_TARGET__)&& defined(PNG_SW_USE_ISRAM)
#pragma arm section code
#endif /* __MTK_TARGET__ */

