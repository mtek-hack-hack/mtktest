/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * main.c
 *
 * Project:
 * --------
 *   AudioResGen
 *
 * Description:
 * ------------
 *   main program.
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
// avoid the annoying 4786 compile warning in Win32/VC
#ifdef WIN32
#pragma warning( disable: 4786 )
#endif

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <iterator>
#include <map>
#include <vector>
#include "Audio_Converter.h"
using namespace std;

/*================================================================*
 *                  Type & Init Data definitions                  *
 =================================================================*/
typedef enum
{
	IMY_GROUP,
	EMS_IMY_GROUP,
	MIDI_GROUP,
	SOUND_GROUP,
	MESSAGE_GROUP,
	EMS_GROUP,
	MMS_SND_GROUP,
	HUMAN_VOICE_TONE_GROUP_1,
	HUMAN_VOICE_TONE_GROUP_2,
	HUMAN_VOICE_TONE_GROUP_3,
	HUMAN_VOICE_TONE_GROUP_4,
	HUMAN_VOICE_TONE_GROUP_5,
	HUMAN_VOICE_TONE_GROUP_6,
	TTS_GROUP,
	KEYPAD_TONE_GROUP,
	NUM_OF_GROUP,
} audio_group_enum;

typedef struct
{
	char filename[80];
	char meta_dataname[80];
	char ringidname[80];
	int startringid;
	char* compile_option_symbol;
} audio_group_init_struct;

audio_group_init_struct audio_group_init[NUM_OF_GROUP] =
{
	{"imy.txt", "mtk_resource_imelodys", "RING_TONE_ID", 101, ""},
	{"ems_imy.txt", "mtk_resource_ems_imelodys", "EMS_IMY_ID", 141, ""},
	{"midi.txt", "mtk_resource_midis", "MIDI_ID", 151, ""},
	{"sound.txt", "mtk_resource_sounds", "SND_ID", 201, ""},
	{"message.txt", "mtk_resource_message_sounds", "MSG_SND_ID", 221, ""},
	{"ems.txt", "mtk_resource_ems_sounds", "EMS_SND_ID", -1, ""}, // its startringid is not used here because it's defined in template_h
	{"mms_snd.txt", "mtk_resource_mms_sounds", "MMS_SND_ID", 241, ""},
	{"human_voice_tone_1.txt", "mtk_resource_human_voice_tones", "HUMAN_VOICE_ID", 1024, "DIGIT_TONE_SUPPORT"},
	{"human_voice_tone_2.txt", "mtk_resource_human_voice_tones", "HUMAN_VOICE_ID", 1024, "DIGIT_TONE_SUPPORT"},
	{"human_voice_tone_3.txt", "mtk_resource_human_voice_tones", "HUMAN_VOICE_ID", 1024, "DIGIT_TONE_SUPPORT"},
	{"human_voice_tone_4.txt", "mtk_resource_human_voice_tones", "HUMAN_VOICE_ID", 1024, "DIGIT_TONE_SUPPORT"},
	{"human_voice_tone_5.txt", "mtk_resource_human_voice_tones", "HUMAN_VOICE_ID", 1024, "DIGIT_TONE_SUPPORT"},
	{"human_voice_tone_6.txt", "mtk_resource_human_voice_tones", "HUMAN_VOICE_ID", 1024, "DIGIT_TONE_SUPPORT"},
	{"tts.txt", "mtk_resource_tts_sounds", "TTS_SND_ID", 2048, "SIMPLE_TTS"},
	{"keypad_tone.txt", "mtk_resource_keypad_tones", "KEYPAD_TONE_ID", 4096, "CUST_KEYPAD_TONE_SUPPORT"}
};

char* common_include_begin_tag = "//<==== common include begin: don't modify this line ====>";
char* common_include_end_tag = "//<==== common include end: don't modify this line ====>";
char* insert_audio_id_tag = "//<==== insert audio id here: don't modify this line ====>";
char* comment_tag = "//";
char* define_tag = "#define";
char* custpack_define_tags[NUM_OF_GROUP] = 
{
	"IMY_IN_CUSTPACK_BIN",
	"EMS_IMY_IN_CUSTPACK_BIN",
	"MIDI_IN_CUSTPACK_BIN",
	"SND_IN_CUSTPACK_BIN",
	"MSG_SND_IN_CUSTPACK_BIN",
	"EMS_SND_IN_CUSTPACK_BIN",
	"MMS_SND_IN_CUSTPACK_BIN",
	"HUMAN_VOICE_IN_CUSTPACK_BIN",
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	"CUST_KEYPAD_TONE_IN_CUSTPACK_BIN"
};

extern void AddPingYing( char* name );
extern void GenPingYingTables( FILE* fpo );

/*================================================================*
 *                       Utility functions                        *
 =================================================================*/
void replace_file_name_with_data_name( char *filename )
{
	char *file_p;
	if( file_p = strrchr(filename,'.') )
		*file_p = '_';
	if( file_p = strrchr(filename,'-') )
		*file_p = '_';
}

bool read_line( FILE* fptr, char* line, int max_len )
{
	long fpos;
	char* ptr;
	
	if( feof( fptr ) )
		return false;
	if( (fpos = ftell( fptr )) < 0 )
		return false;
	
	line[0] = 0;
	fgets( line, max_len, fptr );
	if( (ptr = strstr( line, "\n" )) == NULL )
		return true;
	
	*ptr = 0;
	fpos += (long) (ptr + 2 - line);
	fseek( fptr, fpos, SEEK_SET );
	
	return true;
}

/*================================================================*
 *                      Exception definitions                     *
 =================================================================*/
class CException
{
public:
	char sErrorMessage[200];

protected:
	CException()
	{
		sErrorMessage[0] = 0;
	}

public:
	CException( char* error )
	{
		sprintf( sErrorMessage, "Exception: %s", error );
	}
	virtual ~CException()
	{
	}
	
	void println()
	{
		printf( "%s\n", sErrorMessage );
	}
};

/*================================================================*
 *                       Class definitions                        *
 =================================================================*/
class CAudioResourceMetaData
{
public:
	char* sName;
	const unsigned char *pData;
	unsigned int nLen;
	int nFormat;
	CAudioResourceMetaData( char* name, CAudioResource *res )
	{
		if( name == NULL )
			throw new CException( "CAudioResourceMetaData: null name" );
		sName = _strdup( name );
		pData = res->data;
		nLen = res->len;
		nFormat = res->format;
	}
	virtual ~CAudioResourceMetaData()
	{
		free( sName );
	}
};

typedef vector< string > CStringVector;
typedef map< string, CAudioResourceMetaData * > CAudioResourceMetaDataTable;
typedef vector< CAudioResourceMetaData * > CAudioResourceMetaDataVector;

class CAudioFileGroup
{
public:
	char sFileName[1024];
	char sMetaDataName[200];
	char sRingID[80];
	char sCompileOptionSymbol[80];
	int nStartRingID;
	FILE* pFile;
	CStringVector vFileNames;
	CStringVector vDataNames;
	CAudioResourceMetaDataVector vMetaData;
	
public:
	CAudioFileGroup( audio_group_init_struct* init_data, bool allow_list_not_found )
	{
		char buf[1024];
		
		strcpy( sFileName, init_data->filename );
		strcpy( sMetaDataName, init_data->meta_dataname );
		strcpy( sRingID, init_data->ringidname );
		strcpy( sCompileOptionSymbol, init_data->compile_option_symbol );
		nStartRingID = init_data->startringid;
		pFile = NULL;
		if( (pFile = fopen( sFileName, "r" )) == NULL )
		{
			if( !allow_list_not_found )
				throw new CException( "CAudioFileGroup: open file fail" );
		}
		else
		{
			do
			{
				char* ptr;
				buf[0] = 0;
				fscanf( pFile, "%s\n", buf );
				if( buf[0] != 0 )
				{
					string audioFileName = buf;
					vFileNames.push_back( audioFileName );
					if( (ptr = strrchr( buf,'\\' )) == NULL )
					{
						char error_msg[1024];
						sprintf( error_msg, "CAudioFileGroup: sAudioDataName not found in %s", buf );
						throw new CException( error_msg );
					}
					ptr++;
					replace_file_name_with_data_name( ptr );
					string audioDataName = ptr;
					vDataNames.push_back( audioDataName );
				}
				else
					break;
			} while( 1 );
		
			fclose( pFile );
		}
	}
	virtual ~CAudioFileGroup()
	{
		if( pFile != NULL )
			fclose( pFile );
		vFileNames.clear();
		vDataNames.clear();
		vMetaData.clear();
	}
	
	virtual int getAudioDataAlign( int data_index)
	{
		return 2;
	}
	
	virtual bool writeCompileOptionBegin( FILE* outfile )
	{
		if( strlen( sCompileOptionSymbol ) > 0 )
		{
			fprintf( outfile, "\n#ifdef %s\n", sCompileOptionSymbol );
			return true;
		}
		else
			return false;
	}
	
	virtual bool writeCompileOptionEnd( FILE* outfile )
	{
		if( strlen( sCompileOptionSymbol ) > 0 )
		{
			fprintf( outfile, "#endif /* %s */\n\n", sCompileOptionSymbol );
			return true;
		}
		else
			return false;
	}
	
	int writeAudioData( FILE* outfile, CAudioResourceMetaDataTable* globalDataTable, int compress_MIDI )
	{
		int i, j, k, n, error, count;
		char buf[1024];
		char* error_msg[] = { "invalid file format", "can't open file", "can't malloc", "read file fail", "convert cmidi fail" };
		CAudioConverter converter;
		CAudioResourceMetaDataTable::iterator it;
		CAudioResourceMetaData *pMetaData;
		CAudioResource* pAudioResource;
		
		n = vDataNames.size();
		for( i = 0; i < n; i++ )
		{
			string dataName = vDataNames[i];
			char* filename = (char*)vFileNames[i].c_str();
			char* dataname = (char*)vDataNames[i].c_str();
			
			it = globalDataTable->find( dataName );
			if( it != globalDataTable->end() )
				pMetaData = it->second;
			else
			{
				pAudioResource = converter.GetAudioResource( filename, compress_MIDI, &error );
				if( pAudioResource == NULL )
				{
					if( error > 5 )
						sprintf( buf, "%s: GetAudioResource -> unknown error -> \"%s\"", sFileName, filename );
					else
						sprintf( buf, "%s: GetAudioResource -> %s -> \"%s\"", sFileName, error_msg[error-1], filename );
					throw new CException( (char*)buf );
				}
			
				fprintf( outfile, "\n__align(%d) static const unsigned char %s[] = {\n", getAudioDataAlign(i), dataname );
				for( j = 0; j < pAudioResource->len; j += count )
				{
					fprintf( outfile, "\t" );
					if( j + 8 < pAudioResource->len )
						count = 8;
					else
						count = pAudioResource->len - j;
					for( k = 0; k < count; k++ )
						fprintf( outfile, "0x%02X,", pAudioResource->data[j + k] );
					fprintf( outfile, "\n" );
				}
				fprintf( outfile, "};\n" );
				
				pMetaData = new CAudioResourceMetaData( dataname, pAudioResource );
				globalDataTable->insert( CAudioResourceMetaDataTable::value_type(dataName, pMetaData) );
				
				delete pAudioResource;
			}
			vMetaData.push_back( pMetaData );
		}
		
		return count;
	}
	
	virtual int writeMetaDataList( FILE* outfile )
	{
		int count = vMetaData.size();
		
		fprintf( outfile, "\n\nconst audio_resource_struct %s[]={\n", sMetaDataName );

		for( int i = 0; i < count; i++ )
			fprintf( outfile, "\t{%s, sizeof(%s), %d},\n", vMetaData[i]->sName, vMetaData[i]->sName, vMetaData[i]->nFormat );

		if( count > 0 )
			fprintf( outfile,"};\n" );
		else
			fprintf( outfile,"{NULL, 0x00, 0} };\n" );

		return count;
	}
	
	int writeRingIDs( FILE* outfile )
	{
		int nEndID = -1;
		
		if( nStartRingID >= 0 )
		{
			nEndID = nStartRingID + vMetaData.size() - 1;
			fprintf( outfile, "#define MIN_%s	%d\n", sRingID, nStartRingID );
			fprintf( outfile, "#define MAX_%s	%d\n", sRingID, nEndID );
		}
		
		return nEndID;
	}
	
	void append( CAudioFileGroup* other )
	{
		int count = other->vDataNames.size();
		for( int i = 0; i < count; i++ )
		{
			vFileNames.push_back( other->vFileNames[i] );
			vDataNames.push_back( other->vDataNames[i] );
		}
	}
};

class CCustPackAudioFileGroup : public CAudioFileGroup
{
public:
	CCustPackAudioFileGroup( audio_group_init_struct* init_data, bool allow_list_not_found ) : CAudioFileGroup( init_data, allow_list_not_found )
	{
	}
	virtual ~CCustPackAudioFileGroup()
	{
	}
	
	virtual int getAudioDataAlign( int data_index)
	{
		if( data_index == 0 )
			return 4;
		else
			return 2;
	}
	
	virtual int writeMetaDataList( FILE* outfile )
	{
		int count = vMetaData.size();
		char* wrap_begins[] = { "{", "", "" };
		char* wrap_ends[] = { ",\n", ",\n", "},\n" };
		char* wrap_begin;
		char* wrap_end;
		
		writeCompileOptionBegin( outfile );
		fprintf( outfile, "// %s\n", sMetaDataName );
		
		for( int i = 0; i < count; i++ )
		{
			// wrap_begin
			if( i == 0 )
			{
				fprintf( outfile, "\t%d,\n", count );
				wrap_begin = wrap_begins[0];
			}
			else 
				wrap_begin = wrap_begins[1];
			
			// wrap_end
			if( i == count-1 )
				wrap_end = wrap_ends[2];
			else
				wrap_end = wrap_ends[1];
			
			fprintf( outfile, "\t%s{%s, sizeof(%s), %d}%s", wrap_begin, vMetaData[i]->sName, vMetaData[i]->sName, vMetaData[i]->nFormat, wrap_end );
		}

		writeCompileOptionEnd( outfile );

		return count;
	}
};

typedef vector< CAudioFileGroup * > CAudioFileGroupVector;

/*================================================================*
 *                       Main program                             *
 =================================================================*/
int main()
{
	FILE *out_file_c[2], *out_file_h;
	FILE *temp_c, *temp_h;
	char buf[1024];
	int compress_MIDI = 0;
	int i, j, k, max_ring_id;
	int out_file_c_index;
	bool common_include;
	CAudioResourceMetaDataTable table;
	CAudioFileGroup *audioFileGroup, *nextAudioFileGroup;
	CAudioFileGroupVector vCustPacks;
	bool custpack_flags[NUM_OF_GROUP];

	// open input & output files
	out_file_c[0] = fopen( "resource_audio.c","w" );
	out_file_c[1] = fopen( "custpack_audio.c","w" );
	out_file_h = fopen( "resource_audio.h","w" );
	temp_c = fopen ( "template_c","r" );
	temp_h = fopen ( "template_h","r" );
	
	// initialize audio_resource.c from template_c
	common_include = false;
	while( read_line( temp_c, (char*)buf, 1024 ) ) // a line should not exceed 1023 chars
	{
		if( strcmp( buf, common_include_begin_tag ) == 0 )
			common_include = true;
		else if( strcmp( buf, common_include_end_tag ) == 0 )
			common_include = false;
		else
		{
			fprintf( out_file_c[0], "%s\n", buf ); // resource_audio.c
			if( common_include )
				fprintf( out_file_c[1], "%s\n", buf ); // custpack_audio.c
		}
	}

	// initialize audio_resource.h from template_h
	for( i = 0; i < NUM_OF_GROUP; i++ )
		custpack_flags[i] = false; // set custpack off
	while( read_line( temp_h, (char*)buf, 1024 ) ) // a line should not exceed 1023 chars
	{
		char *define_tag_ptr, *comment_tag_ptr, *custpack_define_tag_ptr;
		
		if( strcmp( buf, insert_audio_id_tag ) == 0 )
			break;
		else
			fprintf( out_file_h, "%s\n", buf );
		
		// check "#define" pos
		if( (define_tag_ptr = strstr( buf, define_tag )) != NULL )
		{
			// check "//" pos
			comment_tag_ptr = strstr( buf, comment_tag );
			if( comment_tag_ptr == NULL || comment_tag_ptr > define_tag_ptr )
			{
				// check all define tags
				for( i = 0; i < NUM_OF_GROUP; i++ )
				{
					if( custpack_define_tags[i] != NULL && 
						(custpack_define_tag_ptr = strstr( buf, custpack_define_tags[i] )) > define_tag_ptr )
					{
						if( comment_tag_ptr == NULL || comment_tag_ptr > custpack_define_tag_ptr )
							custpack_flags[i] = true; // set custpack on
					}
				}
			}
		}
	}

	fclose( temp_c );
	
	try
	{
		/*==================================================================*
		 * populate MIDI, SOUND, IMY, EMS_IMY, MESSAGE, EMS, MMS_SND groups *
		 *==================================================================*/
		for( i = 0; i <= MMS_SND_GROUP; i++ )
		{
			if( custpack_flags[i] )
			{
				audioFileGroup = new CCustPackAudioFileGroup( &audio_group_init[i], false );
				out_file_c_index = 1; // custpack_audio.c
			}
			else
			{
				audioFileGroup = new CAudioFileGroup( &audio_group_init[i], false );
				out_file_c_index = 0; // resource_audio.c
			}
			// populate compile option begin
			audioFileGroup->writeCompileOptionBegin( out_file_c[out_file_c_index] );
			
			// populate audio raw data
			audioFileGroup->writeAudioData( out_file_c[out_file_c_index], &table, compress_MIDI );	
			
			// populate meta data list, but if it's in custpack, we will populate it later
			if( custpack_flags[i] )
				vCustPacks.push_back( audioFileGroup );
			else
				audioFileGroup->writeMetaDataList( out_file_c[out_file_c_index] );
			
			// populate compile option end
			audioFileGroup->writeCompileOptionEnd( out_file_c[out_file_c_index] );
			
			// populate ring id min & max to header file
			max_ring_id = audioFileGroup->writeRingIDs( out_file_h );
			switch( i )
			{
			case MIDI_GROUP:
				for( j = audio_group_init[i].startringid, k = 1; j <= max_ring_id; j++, k++ )
					fprintf( out_file_h, "#define MIDI_%d  %d\n", k, j );
				break;
			case SOUND_GROUP:
				for( j = audio_group_init[i].startringid, k = 1; j <= max_ring_id; j++, k++ )
					fprintf( out_file_h, "#define SOUND_%d  %d\n", k, j );
				break;
			case IMY_GROUP:
				for( j = audio_group_init[i].startringid, k = 1; j <= max_ring_id; j++, k++ )
					fprintf( out_file_h, "#define RING_TONE_%d  %d\n", k, j );
				break;
			}
			if( !custpack_flags[i] )
				delete audioFileGroup;
		}
		
		/*==================================================================*
		 *            populate HUMAN_VOICE_TONE_GROUP_1 ~ 6 groups          *
		 *==================================================================*/
		if( custpack_flags[HUMAN_VOICE_TONE_GROUP_1] )
			out_file_c_index = 1; // custpack_audio.c
		else
			out_file_c_index = 0; // resource_audio.c

		// loop through human_voce_tone_1 ~ 6 and add files to the list
		nextAudioFileGroup = audioFileGroup = NULL;
		for( i = HUMAN_VOICE_TONE_GROUP_6; i >= HUMAN_VOICE_TONE_GROUP_1; i-- ) // the loop order is from 6 to 1
		{
			if( custpack_flags[HUMAN_VOICE_TONE_GROUP_1] )
				audioFileGroup = new CCustPackAudioFileGroup( &audio_group_init[i], true );
			else
				audioFileGroup = new CAudioFileGroup( &audio_group_init[i], true );
			if( nextAudioFileGroup != NULL )
			{
				audioFileGroup->append( nextAudioFileGroup );
				delete nextAudioFileGroup;
			}
			nextAudioFileGroup = audioFileGroup;
		}
		// populate compile option begin
		audioFileGroup->writeCompileOptionBegin( out_file_c[out_file_c_index] );
			
		// populate audio raw data
		audioFileGroup->writeAudioData( out_file_c[out_file_c_index], &table, compress_MIDI );

		// populate meta data list, but if it's in custpack, we will populate it later
		if( custpack_flags[HUMAN_VOICE_TONE_GROUP_1] )
			vCustPacks.push_back( audioFileGroup );
		else
			audioFileGroup->writeMetaDataList( out_file_c[out_file_c_index] );

		// populate compile option end
		audioFileGroup->writeCompileOptionEnd( out_file_c[out_file_c_index] );
			
		// populate ring id min & max to header file
		audioFileGroup->writeRingIDs( out_file_h );
		if( !custpack_flags[HUMAN_VOICE_TONE_GROUP_1] )
			delete audioFileGroup;

		/*==================================================================*
		 *                     populate TTS group                           *
		 *==================================================================*/
		out_file_c_index = 0; // resource_audio.c
		audioFileGroup = new CAudioFileGroup( &audio_group_init[TTS_GROUP], true );

		// populate compile option begin
		audioFileGroup->writeCompileOptionBegin( out_file_c[out_file_c_index] );

		// populate audio raw data
		audioFileGroup->writeAudioData( out_file_c[out_file_c_index], &table, compress_MIDI );

		// populate meta data list
		audioFileGroup->writeMetaDataList( out_file_c[out_file_c_index] );

		// populate ring id min & max to header file
		audioFileGroup->writeRingIDs( out_file_h );

		// populate TTS two-level index tables
		for( i = 0; i < audioFileGroup->vFileNames.size(); i++ )
		{
			char *sPingYing, *sDot;
			
			strcpy( buf, audioFileGroup->vFileNames[i].c_str() );
			sPingYing = strrchr( buf, '\\' ) + 1;
			sDot = strrchr( sPingYing, '.' );
			if( sDot )
				*sDot = 0;
			AddPingYing( sPingYing );
		}
		if( audioFileGroup->vFileNames.size() > 0 )
			GenPingYingTables( out_file_c[out_file_c_index] );

		// populate compile option end
		audioFileGroup->writeCompileOptionEnd( out_file_c[out_file_c_index] );
		
		delete audioFileGroup;
		
		/*==================================================================*
		 *                     populate KEYPAD_TONE group                   *
		 *==================================================================*/
		if( custpack_flags[KEYPAD_TONE_GROUP] )
		{
			audioFileGroup = new CCustPackAudioFileGroup( &audio_group_init[KEYPAD_TONE_GROUP], true );
			out_file_c_index = 1; // custpack_audio.c
		}
		else
		{
			audioFileGroup = new CAudioFileGroup( &audio_group_init[KEYPAD_TONE_GROUP], true );
			out_file_c_index = 0; // resource_audio.c
		}

		// populate compile option begin
		audioFileGroup->writeCompileOptionBegin( out_file_c[out_file_c_index] );

		// populate audio raw data
		audioFileGroup->writeAudioData( out_file_c[out_file_c_index], &table, compress_MIDI );

		// populate meta data list, but if it's in custpack, we will populate it later
		if( custpack_flags[KEYPAD_TONE_GROUP] )
			vCustPacks.push_back( audioFileGroup );
		else
			audioFileGroup->writeMetaDataList( out_file_c[out_file_c_index] );

		// populate compile option end
		audioFileGroup->writeCompileOptionEnd( out_file_c[out_file_c_index] );
			
		// populate ring id min & max to header file
		audioFileGroup->writeRingIDs( out_file_h );
		if( !custpack_flags[KEYPAD_TONE_GROUP] )
			delete audioFileGroup;

		/*==================================================================*
		 *                     populate CUST PACK                           *
		 *==================================================================*/
		if( !vCustPacks.empty() )
		{
			fprintf( out_file_c[1], "\n\nconst custpack_audio_header custpack_audio =\n{\n" );
			for( i = 0; i < vCustPacks.size(); i++ )
				vCustPacks[i]->writeMetaDataList( out_file_c[1] );
			fprintf( out_file_c[1],"};\n\n" );
			vCustPacks.clear();
		}
	}
	catch ( CException *ex )
	{
		ex->println();
		delete ex;
	}

	//add file ending for resoruce_audio.c, custpack_audio.c
	fprintf( out_file_c[0],"#endif /* !__L1_STANDALONE__ */\n" );
	fprintf( out_file_c[1],"#endif /* !__L1_STANDALONE__ */\n" );
	
	//add lines after inser audio id tag for audio_reosource.h
	while( read_line( temp_h, (char*)buf, 1024 ) ) // a line should not exceed 1023 chars
		fprintf( out_file_h, "%s\n", buf );
	fclose( temp_h );
	
	table.clear();
	
	// close output files
	fclose( out_file_h );
	fclose( out_file_c[0] );
	fclose( out_file_c[1] );
	
	return 0;
}
