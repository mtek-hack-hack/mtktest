#ifndef _TLG1100APP_H_
#define _TLG1100APP_H_
/****************************************************************************/
/*!@file  tlg1100App.h
 *
 * @brief Example application code for using TLG1100 API.
 *
 * This file contains the api definitions for the TLG1100 Example Application
 * procedures. These procedures assume that TLG_EMBEDDED_TIMERS is defined.
 * The simplest application that can be written is (assuming TLGAPP_Init() has
 * been customized correctly):
 * 
  @verbatim
  main()
  {
       TLGAPP_TurnOnTestPattern();
  }
 
  OR
 
  main()
  {
       TLGAPP_Init(TLGI2C_DEFAULT_BASE_ADDR);
       TLGAPP_SetChannelMapNTSC();
       TLGAPP_SetChannel(48);
  }
  @endverbatim
 *
 *
 ****************************************************************************/
/* Revision Information:
 *
 * $Revision: 1.9 $
 *
 * (c) 2006 Telegent Systems
 ****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/** Example data structure of an entry in a channel map.
 * @typedef tlg_channel_t
 *
 * This datastructure defines an example format for entries in a channel map.
 * A channel map is defined as an array of these structures that is terminated
 * with an entry whose "chn" field is set to "0". For instance:
 *
 * tlg_channel_t small_ntsc_chn_map[] = {
 *
 *  {2, 101000000, 6},
 *
 *  {0, 0, 0}
 *
 * };
 *
 * @param chn   integer value to describe the channel number (e.g. 2,3...).
 * @param hz    center frequency in Hz of the channel.
 * @param bw    bandwidth in MHz of the channel. Values are (5,6,7,8)
 * @param chstd channel standard 
 *              TLG_VSTD_NTSC_M
 *              TLG_VSTD_PAL_M
 *              TLG_VSTD_PAL_B
 *              TLG_VSTD_PAL_D
 *              TLG_VSTD_PAL_D1
 *              TLG_VSTD_PAL_G
 *              TLG_VSTD_PAL_H
 *              TLG_VSTD_PAL_K
 *              TLG_VSTD_PAL_N
 *              TLG_VSTD_PAL_I
 *              TLG_VSTD_PAL_N
 */
#define SUPPORT_STRUCT
#ifdef SUPPORT_STRUCT
/** Pointer to a tlg_channel_t.
 * @typedef p_tlg_channel_t
 */
typedef struct tlg_channel_s {

    int     chn;
    uint32  hz;
    int     bw;
    int     chstd;

} tlg_channel_t, *p_tlg_channel_t;
#define CHN_S .chn
#define HZ_S  .hz
#define BW_S  .bw
#define STD_S .chstd
#else
/*
 * moving to no structures since some C compilers don't support them
 */
#define tlg_channel_t(a)    uint32 a[][4]
#define p_tlg_channel_t(a)  uint32 (*a)[4]
#define CHN_S [0]
#define HZ_S  [1]
#define BW_S  [2]
#define STD_S [3]
#endif

#define TLG_NEW_INIT        (0) /*!< indicates first Init of TLG1100        */
#define TLG_INIT_DEEP_SLEEP (1) /*!< indicates re-init from deep sleep      */
/*
 * @defgroup Procedures TLGAPI procedures
 * @{
 */

/** Restart the TLGAPP API.
 *
 * This procedure resets all the TLGAPP API state variables so that the
 * TLG1100 may be restarted using TLGAPP_Init(). An external chip reset
 * procedure may also be employed to physically reset the chip as well.
 *
 */
TLG1100DLL_API void TLGAPP_Restart(void);

/** Initialize the TLG1100 to be ready to perform channel changes.
 *
 * This procedure performs all tasks necessary to initialize the TLG1100
 * chip and have it perform calibration. Upon return from this procedure the
 * TLG1100 is ready to perform channel changes.
 */
TLG1100DLL_API int TLGAPP_Init(uint32 base_addr);

/** USER CUSTOMIZABLE procedure to set up audio and video portions of TLG1100.
 *
 * This procedure is a USER CUSTOMIZABLE procedure where all audio and video
 * initialization should be done. The code resides in tlg1100customize.c
 */
void TLGAPP_InitVideoAndAudio(void);

/** Initialize registers to their desired default values.
 *
 * This procedure loads selected registers to their default values as
 * defined in the tlg1100.ini file. It is called by TLGAPP_Init() and should
 * not need to be called by itself.
 *
 * @sa TLGAPP_Init.
 */
TLG1100DLL_API void TLGAPP_Ini_Reg(int start);

/** Setup channel mode, video standard and bandwidth for channel.
 *
 * This procedure checks the input parameters against the currently 
 * configured values and, if necessary, sets the TLG100 to these values.
 *
 * @param mode          The desired mode. Valid values are:
 *                      - TLG_MODE_ANALOG_TV
 *                      - TLG_MODE_FM_RADIO
 * @param std           The desired video standard. Valid values are:
 *                      - TLG_VSTD_NTSC_M
 *                      - TLG_VSTD_PAL_M 
 *                      - TLG_VSTD_PAL_B
 *                      - TLG_VSTD_PAL_B1
 *                      - TLG_VSTD_PAL_D
 *                      - TLG_VSTD_PAL_D1
 *                      - TLG_VSTD_PAL_G
 *                      - TLG_VSTD_PAL_H
 *                      - TLG_VSTD_PAL_K
 *                      - TLG_VSTD_PAL_N
 *                      - TLG_VSTD_PAL_I
 *                      - TLG_VSTD_PAL_NC
 * @param bw            The new bandwidth setting. Values are:
 *                      - TLG_BW_5
 *                      - TLG_BW_6
 *                      - TLG_BW_7
 *                      - TLG_BW_8
 * 
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
TLG1100DLL_API int TLGAPP_ChannelSetup(int mode, int std, int bw);

/** Set the channel map for the system along with its default settings.
 *
 * This procedure sets the default channel map for the system as well as
 * checking its mode, video standard and bandwidth settings and updating 
 * the TLG1100 registers if necessary. Note, if the channel map is a FM Radio
 * channel map, TLGAPP_SetChannelMapFM() should be called instead as this
 * will also set the proper slope and offset settings for the system.
 *
 * @param map       Pointer to an array of tlg_channel_t entries. The list
 *                  should be terminated with an entry whose .chn field is set
 *                  to 0.
 * @param mode      the mode for the channel map. See TLGAPP_ChannelSetup() for
 *                  a description of this parameter.
 * @param std       The default video standard for this channel map. See
 *                  TLGAPP_ChannelSetup() for a descrition of this parameter.
 *                  TLGAPP_ChannelSetup() for a descrition of this parameter.
 * @param bw        The default bandwidth for this channel map. See
 * 
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
TLG1100DLL_API int TLGAPP_SetChannelMap(p_tlg_channel_t(map), int mode, int std, int bw);


/** Set the Channel map, mode, bandwidth, video standard to PAL-D settings.
 *
 * This procedure sets the default channel map to the PAL-D channel map and
 * sets up the mode to TLG_MODE_ANALOG_TV, the standard to TLG_VSTD_PAL_D
 * and the bandwidth to TLG_BW_8 (if not already set up).
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
TLG1100DLL_API int TLGAPP_SetChannelMapPALD(void);


/** Set the Channel map, mode, bandwidth, video standard to NTSC settings.
 *
 * This procedure sets the default channel map to the NTSC channel map and
 * sets up the mode to TLG_MODE_ANALOG_TV, the standard to TLG_VSTD_NTSC_M
 * and the bandwidth to TLG_BW_6 (if not already set up).
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
TLG1100DLL_API int TLGAPP_SetChannelMapNTSC(void);

/** Set the Channel map, mode, bandwidth, video standard to FM Radio settings.
 *
 * This procedure sets the default channel map to the NTSC channel map and
 * sets up the mode to TLG_MODE_FM_RADIO, the standard to TLG_VSTD_NTSC_M
 * and the bandwidth to TLG_BW_6 (if not already set up). It will also
 * perform TLG_InitScanFMChn() to obtain slope and offset settings that will
 * be used in subsequent calls to TLGAPP_SetChannel() and TLGAPP_ScanChannels().
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
TLG1100DLL_API int TLGAPP_SetChannelMapFM(void);

/** Switch the default channel map to the specified channel map.
 *
 * This procedure sets the default channel map to the specified map. Note that
 * the mode, video standard and bandwidth are not changed so this procedure
 * should only be called to switch maps with the same attributes (e.g.
 * a map retured from TLGAPP_ScanChannels().
 *
 * @param map       The channel map to set the default map to.
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 */
TLG1100DLL_API int TLGAPP_SwitchChannelMap(p_tlg_channel_t(map));

/** Tune to the specified channel.
 *
 * This procedure will scan the default channel map for the specified channel
 * and then perform a TLG_ScanTVChn() or TLG_ScanFMChn() depending on what
 * mode has been set.
 *
 * @param chn   channel number of the entry in the channel map to change to.
 *
 * @retval  TRUE    channel change succeeded and frequency is locked.
 * @retval  FALSE   channel change failed.
 */
TLG1100DLL_API int TLGAPP_SetChannel(int chn);

/** Tune to the specified channel using the "fast" lock detection code.
 *
 * This procedure will scan the default channel map for the specified channel
 * and then perform a TLG_FastScanTVChn() or TLG_ScanFMChn() depending on what
 * mode has been set.
 *
 * @param chn   channel number of the entry in the channel map to change to.
 *
 * @retval  TRUE    channel change succeeded and frequency is locked.
 * @retval  FALSE   channel change failed.
 */
TLG1100DLL_API int TLGAPP_FastSetChannel(int chn);

/** Scan the default channel map and return the channels that locked.
 *
 * This procedure scans the default channel map and populates the supplied 
 * channel map with all entries that locked. It will terminate the map with
 * an entry with map[i].chn = 0.
 *
 * @param tlg_scan_map  map to fill with locked channels.
 * @param max_scan      total number of channel entries in tlg_scan_map
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_PARAM    Bad parameter value passed.
 * @retval TLG_ERR_FAIL     Error during call.
 *
 * @sa TLGAPP_ScanChanFound
 */ 
TLG1100DLL_API void TLGAPP_ScanChannels(p_tlg_channel_t(tlg_scan_map), int max_scan);

/** Turn on Test Pattern.
 *
 * This procedure will turn on the test pattern after making sure the TLG1100
 * is properly initialized.
 */
TLG1100DLL_API void TLGAPP_TurnOnTestPattern(void);

/** Turn off Test Pattern.
 *
 * This procedure will turn off the test pattern.
 */
TLG1100DLL_API void TLGAPP_TurnOffTestPattern(void);

/** Turn on Test Tone Mode and set Gain to minimum.
 *
 * This procedure will turn on the Audio Test Tone Mode if the mode is set
 * to a digital mode (TLG_MASTER, TLG_SLAVE). It will also temporarily set
 * the Audio Gain to the mininum (TLG_MIN_AUD_GAIN). Once Test Tone Mode
 * has been enabled the calls TLG_GetAudioTestToneL(), TLG_SetAudioTestToneL()
 * TLG_GetAudioTestToneR(), TLG_SetAudioTestToneR() may be used to manipulate
 * the test tones. When Test Tone Mode is disabled 
 * (TLGAPP_TurnOffTestToneMode()) the gain will be restored.
 * 
 *
 * @sa TLG_GetAudioTestToneL
 * @sa TLG_SetAudioTestToneL
 * @sa TLG_GetAudioTestToneR
 * @sa TLG_SetAudioTestToneR
 * @sa TLGAPP_TurnOffTestToneMode
 */
TLG1100DLL_API void TLGAPP_TurnOnTestToneMode(void);

/** Turn off Test Tone Mode and restore the Audio Gain.
 * 
 * This procedure turns the Test Tone Mode off and restores the Audio Gain to
 * the value that was set in TLGAPP_Init().
 *
 * @sa TLGAPP_Init
 */
TLG1100DLL_API void TLGAPP_TurnOffTestToneMode(void);

/** Switch the antenna to the proper LNA.
 *
 * This procedure provides a framework to manage an antenna switch. This may
 * be done through the GPIOs available on the TLG1100, or by some other means.
 * THIS PROCEDURE REQUIRES CUSTIMIZATION TO WORK PROPERLY.
 *
 * @param hz    The frequency, in hertz, of the channel being tuned.
 *
 * @sa TLGAPP_SetChannel
 */
TLG1100DLL_API void TLGAPP_SetLnaGpio(uint32 hz);

/** Perform custom actions when TLGAPP_ScanChannels() has found a new channel.
 *
 * This procedure is called by TLGAPP_ScanChannels() when it has encounterd a
 * new channel. It is intended to be customized for a given customer's product
 * implementation.
 * THIS PROCEDURE REQUIRES CUSTIMIZATION TO WORK PROPERLY.
 *
 * @param chn   The channel number of the channel that has passed scan.
 *
 * @sa TLGAPP_ScanChannels
 */
TLG1100DLL_API void TLGAPP_ScanChanFound(int chn);

/** Put the TLG1100 into low power mode.
 *
 * This procedure may be called to put the TLG1100 into low power mode
 * also called "Deep Sleep" mode. To return from this mode
 * TLGAPP_ReInitFromPowerDown() should be called. Note these calls are only
 * supported in chip revision 1.3 and later and the I2C must be configured
 * for Asynchronous mode (GPIO5 tied to ground).
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_FAIL     Error during call.
 *
 * @sa TLG_DeepSleep
 * @sa TLG_ReturnFromDeepSleep
 * @sa TLG_ReInitFromDeepSleep
 */
TLG1100DLL_API int TLGAPP_PowerDown(void);

/** Return from the Power Down (Deep Sleep) state.
 *
 * This procedure powers up and re-initializes the TLG1100 after it has been
 * put into its low power state with TLGAPP_PowerDown().
 *
 * @retval TLG_ERR_SUCCESS  Call succeeded.
 * @retval TLG_ERR_FAIL     Error during call.
 *
 * @sa TLG_DeepSleep
 * @sa TLG_ReturnFromDeepSleep
 * @sa TLG_ReInitFromDeepSleep
 */
TLG1100DLL_API int TLGAPP_ReInitFromPowerDown(void);

extern TLG1100DLL_API p_tlg_channel_t(p_tlg_cur_map);/*!< Current Default Channel Map*/
extern int              tlg_cur_bw;         /*!< Current Bandwidth          */
extern int              tlg_cur_mode;       /*!< current Mode               */
extern int              tlg_cur_std;        /*!< Current Video Std          */
extern int              tlg_slope;          /*!< Current FM Slope           */
extern int              tlg_offset;         /*!< Current FM Offset          */
extern int              tlg_init_done;      /*!< Flag Init called           */
extern int              tlg_cur_lna;        /*!< LNA Setting                */
extern uint16           tlg_cur_gain;       /*!< audio gain                 */
extern uint16           tlg_cur_aud_mode;   /*!< audio mode                 */
extern uint32           tlg_i2c_addr;       /*!< i2c address of TLG1100     */
extern tlg_statep       tlg_power_state;    /*!< state for Deep Sleep       */

/*@}*/

#ifdef __cplusplus
};
#endif


#endif /* _TLG1100APP_H_*/
