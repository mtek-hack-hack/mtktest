#ifndef __L_VWLIB_ERROR_H__
#define __L_VWLIB_ERROR_H__

#ifndef __L_VWLIB_CONFIG_H__
#	error do not include this file in your project. 
#endif

#ifndef __VW_ERROR_TYPE_DECLARE__
#define __VW_ERROR_TYPE_DECLARE__
typedef vwsint32	VWRESULT;
#endif

/************************************************************************/
/*  |	31	|	24 - 30		| 16 - 23 |		0 - 15		|				*/
/*   failbit  error type      reserved    error code                    */
/************************************************************************/
#define		VWSUCCEEDED(hr)					( ((VWRESULT)(hr)) >= 0 )
#define		VWFAILED(hr)					( ((VWRESULT)(hr)) <  0 )

#define		VWERROR_S_OK					0X00000000L
#define		VWERROR_S_FALSE					0X00000001L

#define		VWERROR_E_FAIL					0X80000001L
#define		VWERROR_E_NOMEM					0X80000002L
#define		VWERROR_E_INVALIDDATA			0X80000003L
#define		VWERROR_E_IOFAILED				0X80000004L
#define		VWERROR_E_OUTOFRANGE			0X80000005L
#define		VWERROR_E_DIVBYZERO				0X80000006L
#define		VWERROR_E_NOTIMPL				0X80000007L
#define		VWERROR_E_UNEXPECTED			0X80000008L
#define		VWERROR_E_ENDOFFILE				0X80000009L
#define		VWERROR_E_INVALIDARG			0X8000000AL

#define		VWERROR_S_USER					0X00001000L
#define		VWERROR_E_USER					0X80001000L

#define		VWMK_ERROR_CODE( ty , code )	( 0X80000000 | ( ( (ty) << 24 ) + code ) )
#define		VWMK_SUC_CODE( ty , code )		( ( (ty) << 24 ) + code )

#define		VWERROR_TYPE( hr )				( ( (hr) >> 24 ) & 0X7F )
#define		VWERROR_CODE( hr )				( (hr) & 0XFFFF )

#define		VWE_S_OK						VWERROR_S_OK
#define		VWE_S_FALSE						VWERROR_S_FALSE
#define		VWE_E_NOMEM						VWERROR_E_NOMEM
#define		VWE_E_UNEXPECTED				VWERROR_E_UNEXPECTED

#endif