#ifndef __L_VWLIB_LOGFILE__
#define __L_VWLIB_LOGFILE__

#ifndef __L_VWLIB_CONFIG_H__
#	error do not include this file in your project. 
#endif

#ifdef __VW_FINAL_RELEASE_VERSION__

#define VW_LogFile_SetLevel( lvl )				((void)0)
#define VW_LogFile_Write						(void)
#define VW_LogFile_WriteData( lvl , pv , len )	((void)0)

#else

/* log level : .le. 0 or lvl <= curlvl. then */
VW_EXTERN_C	int		VW_LogFile_SetLevel( int level );
VW_EXTERN_C	void	VW_LogFile_Write( int lvl , const char* fmt , ... );
VW_EXTERN_C void	VW_LogFile_WriteData( int lvl , vwvoidcp pv , size_t len );

#endif

#endif