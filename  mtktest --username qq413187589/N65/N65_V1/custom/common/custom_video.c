/*****************************************************************************
 * Filename:
 * ---------
 * custom_video.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customize some video parameters.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"

/* this must be sync with med_api.h */
enum
{
    VID_REC_QTY_LOW = 0,
    VID_REC_QTY_NORMAL,
    VID_REC_QTY_HIGH,
    VID_REC_QTY_FINE,
    VID_NO_OF_REC_QTY
};


/*****************************************************************************
 * FUNCTION
 *  vid_convert_quality_to_bitrate
 * DESCRIPTION
 *  This function is to convert quality to bitrate
 * PARAMETERS
 *  width               [IN]        record image width
 *  height              [IN]        record image height
 *  quality             [IN]        required encode quality
 *  bitrate_p           [?]         the pointer to output bitrate
 *  skip_frame_p        [?]         a flag to indicate skip frame
 * RETURNS
 *  void
 *****************************************************************************/
void vid_convert_quality_to_bitrate(
        kal_uint16 width,
        kal_uint16 height,
        kal_uint8 quality,
        kal_uint32 *bitrate_p,
        kal_uint8 *skip_frame_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 area;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    area = width * height;

    if (area <= 128 * 96)
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 32000;
                *skip_frame_p = 1;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 64000;
                *skip_frame_p = 1;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 96000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 128000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 128000;
                *skip_frame_p = 0;
                break;
        }
    }
    else if (area <= 160 * 120)
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 50000;
                *skip_frame_p = 1;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 100000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 150000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 200000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 200000;
                *skip_frame_p = 0;
                break;
        }
    }
    else if (area <= 176 * 144)
    {
#if ( defined(MT6219) || defined(MT6226) || defined(MT6227) || defined(MT6226M) )
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 64000;
                *skip_frame_p = 1;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 128000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 192000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 256000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 256000;
                *skip_frame_p = 0;
                break;
        }
#else
      /*MT6228, MT6229*/
      switch(quality)
      {
         case VID_REC_QTY_LOW:
            *bitrate_p=128000;
            *skip_frame_p=1;
            break;
         case VID_REC_QTY_NORMAL:
            *bitrate_p=256000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_HIGH:
            *bitrate_p=384000; 
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_FINE:
            *bitrate_p=512000;
            *skip_frame_p=0;
            break;
         default:
            ASSERT(0);
            *bitrate_p=256000;
            *skip_frame_p=0;
            break;
      }
#endif
   }
    else if (area <= 352 * 288)
    {
      switch(quality)
      {
         case VID_REC_QTY_LOW:
            *bitrate_p=350000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_NORMAL:
            *bitrate_p=500000;
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_HIGH:
            *bitrate_p=650000; 
            *skip_frame_p=0;
            break;
         case VID_REC_QTY_FINE:
            *bitrate_p=800000;
            *skip_frame_p=0;
            break;
         default:
            ASSERT(0);
            *bitrate_p=600000;
            *skip_frame_p=0;
            break;
      }
    }
    else    /* larger than 352*288 */
    {
        switch (quality)
        {
            case VID_REC_QTY_LOW:
                *bitrate_p = 150000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_NORMAL:
                *bitrate_p = 300000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_HIGH:
                *bitrate_p = 450000;
                *skip_frame_p = 0;
                break;
            case VID_REC_QTY_FINE:
                *bitrate_p = 600000;
                *skip_frame_p = 0;
                break;
            default:
                ASSERT(0);
                *bitrate_p = 600000;
                *skip_frame_p = 0;
                break;
        }
    }

}

