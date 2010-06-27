
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the AUDIO_CONVERTER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// AUDIO_CONVERTER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef AUDIO_CONVERTER_EXPORTS
#define AUDIO_CONVERTER_API __declspec(dllexport)
#else
#define AUDIO_CONVERTER_API __declspec(dllimport)
#endif

class AUDIO_CONVERTER_API CAudioResource {
public:
	const unsigned char *data;
	unsigned int len;
	int format;
	CAudioResource();
	virtual ~CAudioResource();
};

// This class is exported from the Audio_Converter.dll
class AUDIO_CONVERTER_API CAudioConverter {
public:
	CAudioConverter();
   /*
   * sAudioFileName:
   *   filename with full path
   * compress_MIDI:
   *   0 = no compress (use this as default)
   *   1 = compress MIDI for DSP synthesizer
   *   2 = compress MIDI for software synthesizer
   * pError:
   *   0 = OK
   *   1 = invalid file format
   *   2 = can't open file
   *   3 = can't malloc
   *   4 = read file fail
   *   5 = convert cmidi fail
   * return value:
   *   NULL = fail
   *   non-NULL = a pointer of CAudioResource, please delete the object when it's no longer used
   */
	CAudioResource* GetAudioResource( const char* sAudioFileName, int compress_MIDI, int* pError );
};