/*****************************************************************************
* FILENAME
* tlg1100App.c
*
*
* ABSTRACT
* This file contains example procedures for initializing and managing the
* TLG1100. Note: This example code assumes that TLG_EMBEDDED_TIMERS is 
* enabled.
*
* $Revision: 1.19 $
*
* (c) 2006 Telegent Systems
*****************************************************************************/

#include "tlg1100Hal.h"
#include "tlg1100Api.h"
#include "tlg1100i2c.h"
#include "tlg1100App.h"



/* Default Channel Map for fm */
#if 1
tlg_channel_t tlg_fm_chn_map[] = {
	{875,	87500000,	6,	TLG_VSTD_NTSC_M},
	{876,	87600000,	6,	TLG_VSTD_NTSC_M},
	{877,	87700000,	6,	TLG_VSTD_NTSC_M},
	{878,	87800000,	6,	TLG_VSTD_NTSC_M},
	{879,	87900000,	6,	TLG_VSTD_NTSC_M},
	{880,	88000000,	6,	TLG_VSTD_NTSC_M},
	{881,	88100000,	6,	TLG_VSTD_NTSC_M},
	{882,	88200000,	6,	TLG_VSTD_NTSC_M},
	{883,	88300000,	6,	TLG_VSTD_NTSC_M},
	{884,	88400000,	6,	TLG_VSTD_NTSC_M},
	{885,	88500000,	6,	TLG_VSTD_NTSC_M},
	{886,	88600000,	6,	TLG_VSTD_NTSC_M},
	{887,	88700000,	6,	TLG_VSTD_NTSC_M},
	{888,	88800000,	6,	TLG_VSTD_NTSC_M},
	{889,	88900000,	6,	TLG_VSTD_NTSC_M},
	{890,	89000000,	6,	TLG_VSTD_NTSC_M},
	{891,	89100000,	6,	TLG_VSTD_NTSC_M},
	{892,	89200000,	6,	TLG_VSTD_NTSC_M},
	{893,	89300000,	6,	TLG_VSTD_NTSC_M},
	{894,	89400000,	6,	TLG_VSTD_NTSC_M},
	{895,	89500000,	6,	TLG_VSTD_NTSC_M},
	{896,	89600000,	6,	TLG_VSTD_NTSC_M},
	{897,	89700000,	6,	TLG_VSTD_NTSC_M},
	{898,	89800000,	6,	TLG_VSTD_NTSC_M},
	{899,	89900000,	6,	TLG_VSTD_NTSC_M},
	{900,	90000000,	6,	TLG_VSTD_NTSC_M},
	{901,	90100000,	6,	TLG_VSTD_NTSC_M},
	{902,	90200000,	6,	TLG_VSTD_NTSC_M},
	{903,	90300000,	6,	TLG_VSTD_NTSC_M},
	{904,	90400000,	6,	TLG_VSTD_NTSC_M},
	{905,	90500000,	6,	TLG_VSTD_NTSC_M},
	{906,	90600000,	6,	TLG_VSTD_NTSC_M},
	{907,	90700000,	6,	TLG_VSTD_NTSC_M},
	{908,	90800000,	6,	TLG_VSTD_NTSC_M},
	{909,	90900000,	6,	TLG_VSTD_NTSC_M},
	{910,	91000000,	6,	TLG_VSTD_NTSC_M},
	{911,	91100000,	6,	TLG_VSTD_NTSC_M},
	{912,	91200000,	6,	TLG_VSTD_NTSC_M},
	{913,	91300000,	6,	TLG_VSTD_NTSC_M},
	{914,	91400000,	6,	TLG_VSTD_NTSC_M},
	{915,	91500000,	6,	TLG_VSTD_NTSC_M},
	{916,	91600000,	6,	TLG_VSTD_NTSC_M},
	{917,	91700000,	6,	TLG_VSTD_NTSC_M},
	{918,	91800000,	6,	TLG_VSTD_NTSC_M},
	{919,	91900000,	6,	TLG_VSTD_NTSC_M},
	{920,	92000000,	6,	TLG_VSTD_NTSC_M},
	{921,	92100000,	6,	TLG_VSTD_NTSC_M},
	{922,	92200000,	6,	TLG_VSTD_NTSC_M},
	{923,	92300000,	6,	TLG_VSTD_NTSC_M},
	{924,	92400000,	6,	TLG_VSTD_NTSC_M},
	{925,	92500000,	6,	TLG_VSTD_NTSC_M},
	{926,	92600000,	6,	TLG_VSTD_NTSC_M},
	{927,	92700000,	6,	TLG_VSTD_NTSC_M},
	{928,	92800000,	6,	TLG_VSTD_NTSC_M},
	{929,	92900000,	6,	TLG_VSTD_NTSC_M},
	{930,	93000000,	6,	TLG_VSTD_NTSC_M},
	{931,	93100000,	6,	TLG_VSTD_NTSC_M},
	{932,	93200000,	6,	TLG_VSTD_NTSC_M},
	{933,	93300000,	6,	TLG_VSTD_NTSC_M},
	{934,	93400000,	6,	TLG_VSTD_NTSC_M},
	{935,	93500000,	6,	TLG_VSTD_NTSC_M},
	{936,	93600000,	6,	TLG_VSTD_NTSC_M},
	{937,	93700000,	6,	TLG_VSTD_NTSC_M},
	{938,	93800000,	6,	TLG_VSTD_NTSC_M},
	{939,	93900000,	6,	TLG_VSTD_NTSC_M},
	{940,	94000000,	6,	TLG_VSTD_NTSC_M},
	{941,	94100000,	6,	TLG_VSTD_NTSC_M},
	{942,	94200000,	6,	TLG_VSTD_NTSC_M},
	{943,	94300000,	6,	TLG_VSTD_NTSC_M},
	{944,	94400000,	6,	TLG_VSTD_NTSC_M},
	{945,	94500000,	6,	TLG_VSTD_NTSC_M},
	{946,	94600000,	6,	TLG_VSTD_NTSC_M},
	{947,	94700000,	6,	TLG_VSTD_NTSC_M},
	{948,	94800000,	6,	TLG_VSTD_NTSC_M},
	{949,	94900000,	6,	TLG_VSTD_NTSC_M},
	{950,	95000000,	6,	TLG_VSTD_NTSC_M},
	{951,	95100000,	6,	TLG_VSTD_NTSC_M},
	{952,	95200000,	6,	TLG_VSTD_NTSC_M},
	{953,	95300000,	6,	TLG_VSTD_NTSC_M},
	{954,	95400000,	6,	TLG_VSTD_NTSC_M},
	{955,	95500000,	6,	TLG_VSTD_NTSC_M},
	{956,	95600000,	6,	TLG_VSTD_NTSC_M},
	{957,	95700000,	6,	TLG_VSTD_NTSC_M},
	{958,	95800000,	6,	TLG_VSTD_NTSC_M},
	{959,	95900000,	6,	TLG_VSTD_NTSC_M},
	{960,	96000000,	6,	TLG_VSTD_NTSC_M},
	{961,	96100000,	6,	TLG_VSTD_NTSC_M},
	{962,	96200000,	6,	TLG_VSTD_NTSC_M},
	{963,	96300000,	6,	TLG_VSTD_NTSC_M},
	{964,	96400000,	6,	TLG_VSTD_NTSC_M},
	{965,	96500000,	6,	TLG_VSTD_NTSC_M},
	{966,	96600000,	6,	TLG_VSTD_NTSC_M},
	{967,	96700000,	6,	TLG_VSTD_NTSC_M},
	{968,	96800000,	6,	TLG_VSTD_NTSC_M},
	{969,	96900000,	6,	TLG_VSTD_NTSC_M},
	{970,	97000000,	6,	TLG_VSTD_NTSC_M},
	{971,	97100000,	6,	TLG_VSTD_NTSC_M},
	{972,	97200000,	6,	TLG_VSTD_NTSC_M},
	{973,	97300000,	6,	TLG_VSTD_NTSC_M},
	{974,	97400000,	6,	TLG_VSTD_NTSC_M},
	{975,	97500000,	6,	TLG_VSTD_NTSC_M},
	{976,	97600000,	6,	TLG_VSTD_NTSC_M},
	{977,	97700000,	6,	TLG_VSTD_NTSC_M},
	{978,	97800000,	6,	TLG_VSTD_NTSC_M},
	{979,	97900000,	6,	TLG_VSTD_NTSC_M},
	{980,	98000000,	6,	TLG_VSTD_NTSC_M},
	{981,	98100000,	6,	TLG_VSTD_NTSC_M},
	{982,	98200000,	6,	TLG_VSTD_NTSC_M},
	{983,	98300000,	6,	TLG_VSTD_NTSC_M},
	{984,	98400000,	6,	TLG_VSTD_NTSC_M},
	{985,	98500000,	6,	TLG_VSTD_NTSC_M},
	{986,	98600000,	6,	TLG_VSTD_NTSC_M},
	{987,	98700000,	6,	TLG_VSTD_NTSC_M},
	{988,	98800000,	6,	TLG_VSTD_NTSC_M},
	{989,	98900000,	6,	TLG_VSTD_NTSC_M},
	{990,	99000000,	6,	TLG_VSTD_NTSC_M},
	{991,	99100000,	6,	TLG_VSTD_NTSC_M},
	{992,	99200000,	6,	TLG_VSTD_NTSC_M},
	{993,	99300000,	6,	TLG_VSTD_NTSC_M},
	{994,	99400000,	6,	TLG_VSTD_NTSC_M},
	{995,	99500000,	6,	TLG_VSTD_NTSC_M},
	{996,	99600000,	6,	TLG_VSTD_NTSC_M},
	{997,	99700000,	6,	TLG_VSTD_NTSC_M},
	{998,	99800000,	6,	TLG_VSTD_NTSC_M},
	{999,	99900000,	6,	TLG_VSTD_NTSC_M},
	{1000,	100000000,	6,	TLG_VSTD_NTSC_M},
	{1001,	100100000,	6,	TLG_VSTD_NTSC_M},
	{1002,	100200000,	6,	TLG_VSTD_NTSC_M},
	{1003,	100300000,	6,	TLG_VSTD_NTSC_M},
	{1004,	100400000,	6,	TLG_VSTD_NTSC_M},
	{1005,	100500000,	6,	TLG_VSTD_NTSC_M},
	{1006,	100600000,	6,	TLG_VSTD_NTSC_M},
	{1007,	100700000,	6,	TLG_VSTD_NTSC_M},
	{1008,	100800000,	6,	TLG_VSTD_NTSC_M},
	{1009,	100900000,	6,	TLG_VSTD_NTSC_M},
	{1010,	101000000,	6,	TLG_VSTD_NTSC_M},
	{1011,	101100000,	6,	TLG_VSTD_NTSC_M},
	{1012,	101200000,	6,	TLG_VSTD_NTSC_M},
	{1013,	101300000,	6,	TLG_VSTD_NTSC_M},
	{1014,	101400000,	6,	TLG_VSTD_NTSC_M},
	{1015,	101500000,	6,	TLG_VSTD_NTSC_M},
	{1016,	101600000,	6,	TLG_VSTD_NTSC_M},
	{1017,	101700000,	6,	TLG_VSTD_NTSC_M},
	{1018,	101800000,	6,	TLG_VSTD_NTSC_M},
	{1019,	101900000,	6,	TLG_VSTD_NTSC_M},
	{1020,	102000000,	6,	TLG_VSTD_NTSC_M},
	{1021,	102100000,	6,	TLG_VSTD_NTSC_M},
	{1022,	102200000,	6,	TLG_VSTD_NTSC_M},
	{1023,	102300000,	6,	TLG_VSTD_NTSC_M},
	{1024,	102400000,	6,	TLG_VSTD_NTSC_M},
	{1025,	102500000,	6,	TLG_VSTD_NTSC_M},
	{1026,	102600000,	6,	TLG_VSTD_NTSC_M},
	{1027,	102700000,	6,	TLG_VSTD_NTSC_M},
	{1028,	102800000,	6,	TLG_VSTD_NTSC_M},
	{1029,	102900000,	6,	TLG_VSTD_NTSC_M},
	{1030,	103000000,	6,	TLG_VSTD_NTSC_M},
	{1031,	103100000,	6,	TLG_VSTD_NTSC_M},
	{1032,	103200000,	6,	TLG_VSTD_NTSC_M},
	{1033,	103300000,	6,	TLG_VSTD_NTSC_M},
	{1034,	103400000,	6,	TLG_VSTD_NTSC_M},
	{1035,	103500000,	6,	TLG_VSTD_NTSC_M},
	{1036,	103600000,	6,	TLG_VSTD_NTSC_M},
	{1037,	103700000,	6,	TLG_VSTD_NTSC_M},
	{1038,	103800000,	6,	TLG_VSTD_NTSC_M},
	{1039,	103900000,	6,	TLG_VSTD_NTSC_M},
	{1040,	104000000,	6,	TLG_VSTD_NTSC_M},
	{1041,	104100000,	6,	TLG_VSTD_NTSC_M},
	{1042,	104200000,	6,	TLG_VSTD_NTSC_M},
	{1043,	104300000,	6,	TLG_VSTD_NTSC_M},
	{1044,	104400000,	6,	TLG_VSTD_NTSC_M},
	{1045,	104500000,	6,	TLG_VSTD_NTSC_M},
	{1046,	104600000,	6,	TLG_VSTD_NTSC_M},
	{1047,	104700000,	6,	TLG_VSTD_NTSC_M},
	{1048,	104800000,	6,	TLG_VSTD_NTSC_M},
	{1049,	104900000,	6,	TLG_VSTD_NTSC_M},
	{1050,	105000000,	6,	TLG_VSTD_NTSC_M},
	{1051,	105100000,	6,	TLG_VSTD_NTSC_M},
	{1052,	105200000,	6,	TLG_VSTD_NTSC_M},
	{1053,	105300000,	6,	TLG_VSTD_NTSC_M},
	{1054,	105400000,	6,	TLG_VSTD_NTSC_M},
	{1055,	105500000,	6,	TLG_VSTD_NTSC_M},
	{1056,	105600000,	6,	TLG_VSTD_NTSC_M},
	{1057,	105700000,	6,	TLG_VSTD_NTSC_M},
	{1058,	105800000,	6,	TLG_VSTD_NTSC_M},
	{1059,	105900000,	6,	TLG_VSTD_NTSC_M},
	{1060,	106000000,	6,	TLG_VSTD_NTSC_M},
	{1061,	106100000,	6,	TLG_VSTD_NTSC_M},
	{1062,	106200000,	6,	TLG_VSTD_NTSC_M},
	{1063,	106300000,	6,	TLG_VSTD_NTSC_M},
	{1064,	106400000,	6,	TLG_VSTD_NTSC_M},
	{1065,	106500000,	6,	TLG_VSTD_NTSC_M},
	{1066,	106600000,	6,	TLG_VSTD_NTSC_M},
	{1067,	106700000,	6,	TLG_VSTD_NTSC_M},
	{1068,	106800000,	6,	TLG_VSTD_NTSC_M},
	{1069,	106900000,	6,	TLG_VSTD_NTSC_M},
	{1070,	107000000,	6,	TLG_VSTD_NTSC_M},
	{1071,	107100000,	6,	TLG_VSTD_NTSC_M},
	{1072,	107200000,	6,	TLG_VSTD_NTSC_M},
	{1073,	107300000,	6,	TLG_VSTD_NTSC_M},
	{1074,	107400000,	6,	TLG_VSTD_NTSC_M},
	{1075,	107500000,	6,	TLG_VSTD_NTSC_M},
	{1076,	107600000,	6,	TLG_VSTD_NTSC_M},
	{1077,	107700000,	6,	TLG_VSTD_NTSC_M},
	{1078,	107800000,	6,	TLG_VSTD_NTSC_M},
	{1079,	107900000,	6,	TLG_VSTD_NTSC_M},
	{1080,	108000000,	6,	TLG_VSTD_NTSC_M},
    {0, 0, 0, 0}
};

#else
tlg_channel_t tlg_fm_chn_map[] = {
    {879,    85148438,  6,    TLG_VSTD_NTSC_M  },
    {881,    85351562,  6,    TLG_VSTD_NTSC_M  },
    {883,    85546875,  6,    TLG_VSTD_NTSC_M  },
    {885,    85750000,  6,    TLG_VSTD_NTSC_M  },
    {887,    85953125,  6,    TLG_VSTD_NTSC_M  },
    {889,    86148438,  6,    TLG_VSTD_NTSC_M  },
    {891,    86351562,  6,    TLG_VSTD_NTSC_M  },
    {893,    86546875,  6,    TLG_VSTD_NTSC_M  },
    {895,    86750000,  6,    TLG_VSTD_NTSC_M  },
    {897,    86953125,  6,    TLG_VSTD_NTSC_M  },
    {899,    87148438,  6,    TLG_VSTD_NTSC_M  },
    {901,    87351562,  6,    TLG_VSTD_NTSC_M  },
    {903,    87546875,  6,    TLG_VSTD_NTSC_M  },
    {905,    87750000,  6,    TLG_VSTD_NTSC_M  },
    {907,    87953125,  6,    TLG_VSTD_NTSC_M  },
    {909,    88148438,  6,    TLG_VSTD_NTSC_M  },
    {911,    88351562,  6,    TLG_VSTD_NTSC_M  },
    {913,    88546875,  6,    TLG_VSTD_NTSC_M  },
    {915,    88750000,  6,    TLG_VSTD_NTSC_M  },
    {917,    88953125,  6,    TLG_VSTD_NTSC_M  },
    {919,    89148438,  6,    TLG_VSTD_NTSC_M  },
    {921,    89351562,  6,    TLG_VSTD_NTSC_M  },
    {923,    89546875,  6,    TLG_VSTD_NTSC_M  },
    {925,    89750000,  6,    TLG_VSTD_NTSC_M  },
    {927,    89953125,  6,    TLG_VSTD_NTSC_M  },
    {929,    90148438,  6,    TLG_VSTD_NTSC_M  },
    {931,    90351562,  6,    TLG_VSTD_NTSC_M  },
    {933,    90546875,  6,    TLG_VSTD_NTSC_M  },
    {935,    90750000,  6,    TLG_VSTD_NTSC_M  },
    {937,    90953125,  6,    TLG_VSTD_NTSC_M  },
    {939,    91148438,  6,    TLG_VSTD_NTSC_M  },
    {941,    91351562,  6,    TLG_VSTD_NTSC_M  },
    {943,    91546875,  6,    TLG_VSTD_NTSC_M  },
    {945,    91750000,  6,    TLG_VSTD_NTSC_M  },
    {947,    91953125,  6,    TLG_VSTD_NTSC_M  },
    {949,    92148438,  6,    TLG_VSTD_NTSC_M  },
    {951,    92351562,  6,    TLG_VSTD_NTSC_M  },
    {953,    92546875,  6,    TLG_VSTD_NTSC_M  },
    {955,    92750000,  6,    TLG_VSTD_NTSC_M  },
    {957,    92953125,  6,    TLG_VSTD_NTSC_M  },
    {959,    93148438,  6,    TLG_VSTD_NTSC_M  },
    {961,    93351562,  6,    TLG_VSTD_NTSC_M  },
    {963,    93546875,  6,    TLG_VSTD_NTSC_M  },
    {965,    93750000,  6,    TLG_VSTD_NTSC_M  },
    {967,    93953125,  6,    TLG_VSTD_NTSC_M  },
    {969,    94148438,  6,    TLG_VSTD_NTSC_M  },
    {971,    94351562,  6,    TLG_VSTD_NTSC_M  },
    {973,    94546875,  6,    TLG_VSTD_NTSC_M  },
    {975,    94750000,  6,    TLG_VSTD_NTSC_M  },
    {977,    94953125,  6,    TLG_VSTD_NTSC_M  },
    {979,    95148438,  6,    TLG_VSTD_NTSC_M  },
    {981,    95351562,  6,    TLG_VSTD_NTSC_M  },
    {983,    95546875,  6,    TLG_VSTD_NTSC_M  },
    {985,    95750000,  6,    TLG_VSTD_NTSC_M  },
    {987,    95953125,  6,    TLG_VSTD_NTSC_M  },
    {989,    96148438,  6,    TLG_VSTD_NTSC_M  },
    {991,    96351562,  6,    TLG_VSTD_NTSC_M  },
    {993,    96546875,  6,    TLG_VSTD_NTSC_M  },
    {995,    96750000,  6,    TLG_VSTD_NTSC_M  },
    {997,    96953125,  6,    TLG_VSTD_NTSC_M  },
    {999,    97148438,  6,    TLG_VSTD_NTSC_M  },
    {1001,   97351562,  6,    TLG_VSTD_NTSC_M  },
    {1003,   97546875,  6,    TLG_VSTD_NTSC_M  },
    {1005,   97750000,  6,    TLG_VSTD_NTSC_M  },
    {1007,   97953125,  6,    TLG_VSTD_NTSC_M  },
    {1009,   98148438,  6,    TLG_VSTD_NTSC_M  },
    {1011,   98351562,  6,    TLG_VSTD_NTSC_M  },
    {1013,   98546875,  6,    TLG_VSTD_NTSC_M  },
    {1015,   98750000,  6,    TLG_VSTD_NTSC_M  },
    {1017,   98953125,  6,    TLG_VSTD_NTSC_M  },
    {1019,   99148438,  6,    TLG_VSTD_NTSC_M  },
    {1021,   99351562,  6,    TLG_VSTD_NTSC_M  },
    {1023,   99546875,  6,    TLG_VSTD_NTSC_M  },
    {1025,   99750000,  6,    TLG_VSTD_NTSC_M  },
    {1027,   99953125,  6,    TLG_VSTD_NTSC_M  },
    {1029,  100156250,  6,    TLG_VSTD_NTSC_M  },
    {1031,  100343750,  6,    TLG_VSTD_NTSC_M  },
    {1033,  100546875,  6,    TLG_VSTD_NTSC_M  },
    {1035,  100750000,  6,    TLG_VSTD_NTSC_M  },
    {1037,  100953125,  6,    TLG_VSTD_NTSC_M  },
    {1039,  101156250,  6,    TLG_VSTD_NTSC_M  },
    {1041,  101343750,  6,    TLG_VSTD_NTSC_M  },
    {1043,  101546875,  6,    TLG_VSTD_NTSC_M  },
    {1045,  101750000,  6,    TLG_VSTD_NTSC_M  },
    {1047,  101953125,  6,    TLG_VSTD_NTSC_M  },
    {1049,  102156250,  6,    TLG_VSTD_NTSC_M  },
    {1051,  102343750,  6,    TLG_VSTD_NTSC_M  },
    {1053,  102546875,  6,    TLG_VSTD_NTSC_M  },
    {1055,  102750000,  6,    TLG_VSTD_NTSC_M  },
    {1057,  102953125,  6,    TLG_VSTD_NTSC_M  },
    {1059,  103156250,  6,    TLG_VSTD_NTSC_M  },
    {1061,  103343750,  6,    TLG_VSTD_NTSC_M  },
    {1063,  103546875,  6,    TLG_VSTD_NTSC_M  },
    {1065,  103750000,  6,    TLG_VSTD_NTSC_M  },
    {1067,  103953125,  6,    TLG_VSTD_NTSC_M  },
    {1069,  104156250,  6,    TLG_VSTD_NTSC_M  },
    {1071,  104343750,  6,    TLG_VSTD_NTSC_M  },
    {1073,  104546875,  6,    TLG_VSTD_NTSC_M  },
    {1075,  104750000,  6,    TLG_VSTD_NTSC_M  },
    {1077,  104953125,  6,    TLG_VSTD_NTSC_M  },
    {1079,  105156250,  6,    TLG_VSTD_NTSC_M  },
    {1081,  105343750,  6,    TLG_VSTD_NTSC_M  },
    {1083,  105546875,  6,    TLG_VSTD_NTSC_M  },
    {1085,  105750000,  6,    TLG_VSTD_NTSC_M  },
    {1087,  105953125,  6,    TLG_VSTD_NTSC_M  },
    {1089,  106156250,  6,    TLG_VSTD_NTSC_M  },
    {1091,  106343750,  6,    TLG_VSTD_NTSC_M  },
    {1093,  106546875,  6,    TLG_VSTD_NTSC_M  },
    {1095,  106750000,  6,    TLG_VSTD_NTSC_M  },
    {1097,  106953125,  6,    TLG_VSTD_NTSC_M  },
    {1099,  107156250,  6,    TLG_VSTD_NTSC_M  },
    {1101,  107343750,  6,    TLG_VSTD_NTSC_M  },
    {1103,  107546875,  6,    TLG_VSTD_NTSC_M  },
    {1105,  107750000,  6,    TLG_VSTD_NTSC_M  },
    {1107,  107953125,  6,    TLG_VSTD_NTSC_M  },
    {1109,  108156250,  6,    TLG_VSTD_NTSC_M  },
    {1111,  108343750,  6,    TLG_VSTD_NTSC_M  },
    {1113,  108546875,  6,    TLG_VSTD_NTSC_M  },
    {1115,  108750000,  6,    TLG_VSTD_NTSC_M  },
    {1117,  108953125,  6,    TLG_VSTD_NTSC_M  },
    {1119,  109156250,  6,    TLG_VSTD_NTSC_M  },
    {1121,  109343750,  6,    TLG_VSTD_NTSC_M  },
    {1123,  109546875,  6,    TLG_VSTD_NTSC_M  },
    {1125,  109750000,  6,    TLG_VSTD_NTSC_M  },
    {0, 0, 0, 0}
};
#endif
/* Default Channel Map for China shenzhen */ 

tlg_channel_t tlg_pal_I_shenzhen_chn_map[]= { 
    {1,      52500000,  8,  TLG_VSTD_PAL_I}, 
    {2,      60500000,  8,  TLG_VSTD_PAL_I}, 
    {3,      68500000,  8,  TLG_VSTD_PAL_I}, 
    {4,      80000000,  8,  TLG_VSTD_PAL_I}, 
    {5,      88000000,  8,  TLG_VSTD_PAL_I}, 
    {6,     171000000,  8,  TLG_VSTD_PAL_I}, 
    {7,     179000000,  8,  TLG_VSTD_PAL_I},// 
    {8,     187000000,  8,  TLG_VSTD_PAL_I},/// 
    {9,     195000000,  8,  TLG_VSTD_PAL_I},// 
    {10,    203000000,  8,  TLG_VSTD_PAL_I}, 
    {11,    211000000,  8,  TLG_VSTD_PAL_I}, 
    {12,    219000000,  8,  TLG_VSTD_PAL_I},// 
    {13,    474000000,  8,  TLG_VSTD_PAL_I},/// 
    {14,    482000000,  8,  TLG_VSTD_PAL_I}, 
    {15,    490000000,  8,  TLG_VSTD_PAL_I},// 
    {16,    498000000,  8,  TLG_VSTD_PAL_I}, 
    {17,    506000000,  8,  TLG_VSTD_PAL_I}, 
    {18,    514000000,  8,  TLG_VSTD_PAL_I},// 
    {19,    522000000,  8,  TLG_VSTD_PAL_I},/// 
    {20,    530000000,  8,  TLG_VSTD_PAL_I}, 
    {21,    538000000,  8,  TLG_VSTD_PAL_I}, 
    {22,    546000000,  8,  TLG_VSTD_PAL_I}, 
    {23,    554000000,  8,  TLG_VSTD_PAL_I},// 
    {24,    562000000,  8,  TLG_VSTD_PAL_I}, 
    {25,    610000000,  8,  TLG_VSTD_PAL_I},/// 
    {26,    618000000,  8,  TLG_VSTD_PAL_I}, 
    {27,    626000000,  8,  TLG_VSTD_PAL_I}, 
    {28,    634000000,  8,  TLG_VSTD_PAL_I},// 
    {29,    642000000,  8,  TLG_VSTD_PAL_I}, 
    {30,    650000000,  8,  TLG_VSTD_PAL_I}, 
    {31,    658000000,  8,  TLG_VSTD_PAL_I}, 
    {32,    666000000,  8,  TLG_VSTD_PAL_I}, 
    {33,    674000000,  8,  TLG_VSTD_PAL_I}, 
    {34,    682000000,  8,  TLG_VSTD_PAL_I}, 
    {35,    690000000,  8,  TLG_VSTD_PAL_I}, 
    {36,    698000000,  8,  TLG_VSTD_PAL_I}, 
    {37,    706000000,  8,  TLG_VSTD_PAL_I}, 
    {38,    714000000,  8,  TLG_VSTD_PAL_I},/// 
    {39,    722000000,  8,  TLG_VSTD_PAL_I},/// 
    {40,    730000000,  8,  TLG_VSTD_PAL_I},
    {41,    738000000,  8,  TLG_VSTD_PAL_I}, 
    {42,    746000000,  8,  TLG_VSTD_PAL_I}, 
    {43,    754000000,  8,  TLG_VSTD_PAL_I}, 
    {44,    762000000,  8,  TLG_VSTD_PAL_I}, 
    {45,    770000000,  8,  TLG_VSTD_PAL_I}, 
    {46,    778000000,  8,  TLG_VSTD_PAL_I}, 
    {47,    786000000,  8,  TLG_VSTD_PAL_I}, 
    {48,    794000000,  8,  TLG_VSTD_PAL_I}, 
    {49,    802000000,  8,  TLG_VSTD_PAL_I}, 
    {50,    810000000,  8,  TLG_VSTD_PAL_I}, 
    {51,    818000000,  8,  TLG_VSTD_PAL_I}, 
    {52,    826000000,  8,  TLG_VSTD_PAL_I}, 
    {53,    834000000,  8,  TLG_VSTD_PAL_I}, 
    {54,    842000000,  8,  TLG_VSTD_PAL_I}, 
    {55,    850000000,  8,  TLG_VSTD_PAL_I}, 
    {56,    858000000,  8,  TLG_VSTD_PAL_I}, 
    {57,    866000000,  8,  TLG_VSTD_PAL_I}, 
    {58,    874000000,  8,  TLG_VSTD_PAL_I}, 
    {59,    882000000,  8,  TLG_VSTD_PAL_I}, 
    {60,    890000000,  8,  TLG_VSTD_PAL_I}, 
    {61,    898000000,  8,  TLG_VSTD_PAL_I}, 
    {62,    906000000,  8,  TLG_VSTD_PAL_I}, 
    {63,    914000000,  8,  TLG_VSTD_PAL_I}, 
    {64,    922000000,  8,  TLG_VSTD_PAL_I}, 
    {65,    930000000,  8,  TLG_VSTD_PAL_I}, 
    {66,    938000000,  8,  TLG_VSTD_PAL_I}, 
    {67,    946000000,  8,  TLG_VSTD_PAL_I}, 
    {68,    954000000,  8,  TLG_VSTD_PAL_I}, 
    {69,    962000000,  8,  TLG_VSTD_PAL_I}, 
    {0, 0, 0,0} 

}; 
/* Default Channel Maps for USA, Canada, Korea, Taiwan, Mexico, 
Chile, Venezuela, the Philippines */

tlg_channel_t tlg_ntsc_chn_map[] = {
    {2,      57000000,  6,    TLG_VSTD_NTSC_M  },
    {3,      63000000,  6,    TLG_VSTD_NTSC_M  },
    {4,      69000000,  6,    TLG_VSTD_NTSC_M  },
    {5,      79000000,  6,    TLG_VSTD_NTSC_M  },
    {6,      85000000,  6,    TLG_VSTD_NTSC_M  },
    {7,     177000000,  6,    TLG_VSTD_NTSC_M  },
    {8,     183000000,  6,    TLG_VSTD_NTSC_M  },
    {9,     189000000,  6,    TLG_VSTD_NTSC_M  },
    {10,    195000000,  6,    TLG_VSTD_NTSC_M  },
    {11,    201000000,  6,    TLG_VSTD_NTSC_M  },
    {12,    207000000,  6,    TLG_VSTD_NTSC_M  },
    {13,    213000000,  6,    TLG_VSTD_NTSC_M  },
    {14,    473000000,  6,    TLG_VSTD_NTSC_M  },
    {15,    479000000,  6,    TLG_VSTD_NTSC_M  },
    {16,    485000000,  6,    TLG_VSTD_NTSC_M  },
    {17,    491000000,  6,    TLG_VSTD_NTSC_M  },
    {18,    497000000,  6,    TLG_VSTD_NTSC_M  },
    {19,    503000000,  6,    TLG_VSTD_NTSC_M  },
    {20,    509000000,  6,    TLG_VSTD_NTSC_M  },
    {21,    515000000,  6,    TLG_VSTD_NTSC_M  },
    {22,    521000000,  6,    TLG_VSTD_NTSC_M  },
    {23,    527000000,  6,    TLG_VSTD_NTSC_M  },
    {24,    533000000,  6,    TLG_VSTD_NTSC_M  },
    {25,    539000000,  6,    TLG_VSTD_NTSC_M  },
    {26,    545000000,  6,    TLG_VSTD_NTSC_M  },
    {27,    551000000,  6,    TLG_VSTD_NTSC_M  },
    {28,    557000000,  6,    TLG_VSTD_NTSC_M  },
    {29,    563000000,  6,    TLG_VSTD_NTSC_M  },
    {30,    569000000,  6,    TLG_VSTD_NTSC_M  },
    {31,    575000000,  6,    TLG_VSTD_NTSC_M  },
    {32,    581000000,  6,    TLG_VSTD_NTSC_M  },
    {33,    587000000,  6,    TLG_VSTD_NTSC_M  },
    {34,    593000000,  6,    TLG_VSTD_NTSC_M  },
    {35,    599000000,  6,    TLG_VSTD_NTSC_M  },
    {36,    605000000,  6,    TLG_VSTD_NTSC_M  },
    {37,    611000000,  6,    TLG_VSTD_NTSC_M  },
    {38,    617000000,  6,    TLG_VSTD_NTSC_M  },
    {39,    623000000,  6,    TLG_VSTD_NTSC_M  },
    {40,    629000000,  6,    TLG_VSTD_NTSC_M  },
    {41,    635000000,  6,    TLG_VSTD_NTSC_M  },
    {42,    641000000,  6,    TLG_VSTD_NTSC_M  },
    {43,    647000000,  6,    TLG_VSTD_NTSC_M  },
    {44,    653000000,  6,    TLG_VSTD_NTSC_M  },
    {45,    659000000,  6,    TLG_VSTD_NTSC_M  },
    {46,    665000000,  6,    TLG_VSTD_NTSC_M  },
    {47,    671000000,  6,    TLG_VSTD_NTSC_M  },
    {48,    677000000,  6,    TLG_VSTD_NTSC_M  },
    {49,    683000000,  6,    TLG_VSTD_NTSC_M  },
    {50,    689000000,  6,    TLG_VSTD_NTSC_M  },
    {51,    695000000,  6,    TLG_VSTD_NTSC_M  },
    {52,    701000000,  6,    TLG_VSTD_NTSC_M  },
    {53,    707000000,  6,    TLG_VSTD_NTSC_M  },
    {54,    713000000,  6,    TLG_VSTD_NTSC_M  },
    {55,    719000000,  6,    TLG_VSTD_NTSC_M  },
    {56,    725000000,  6,    TLG_VSTD_NTSC_M  },
    {57,    731000000,  6,    TLG_VSTD_NTSC_M  },
    {58,    737000000,  6,    TLG_VSTD_NTSC_M  },
    {59,    743000000,  6,    TLG_VSTD_NTSC_M  },
    {60,    749000000,  6,    TLG_VSTD_NTSC_M  },
    {61,    755000000,  6,    TLG_VSTD_NTSC_M  },
    {62,    761000000,  6,    TLG_VSTD_NTSC_M  },
    {63,    767000000,  6,    TLG_VSTD_NTSC_M  },
    {64,    773000000,  6,    TLG_VSTD_NTSC_M  },
    {65,    779000000,  6,    TLG_VSTD_NTSC_M  },
    {66,    785000000,  6,    TLG_VSTD_NTSC_M  },
    {67,    791000000,  6,    TLG_VSTD_NTSC_M  },
    {68,    797000000,  6,    TLG_VSTD_NTSC_M  },
    {69,    803000000,  6,    TLG_VSTD_NTSC_M  },
    {0, 0, 0, 0}
};

/* Default Channel Map for China */
tlg_channel_t tlg_pald_chn_map[] = {
    {1,      52500000,  8,    TLG_VSTD_PAL_D  },
    {2,      60500000,  8,    TLG_VSTD_PAL_D  },
    {3,      68500000,  8,    TLG_VSTD_PAL_D  },
    {4,      80000000,  8,    TLG_VSTD_PAL_D  },
    {5,      88000000,  8,    TLG_VSTD_PAL_D  },
    {6,     171000000,  8,    TLG_VSTD_PAL_D  },
    {7,     179000000,  8,    TLG_VSTD_PAL_D  },
    {8,     187000000,  8,    TLG_VSTD_PAL_D  },
    {9,     195000000,  8,    TLG_VSTD_PAL_D  },
    {10,    203000000,  8,    TLG_VSTD_PAL_D  },
    {11,    211000000,  8,    TLG_VSTD_PAL_D  },
    {12,    219000000,  8,    TLG_VSTD_PAL_D  },
    {13,    474000000,  8,    TLG_VSTD_PAL_D  },
    {14,    482000000,  8,    TLG_VSTD_PAL_D  },
    {15,    490000000,  8,    TLG_VSTD_PAL_D  },
    {16,    498000000,  8,    TLG_VSTD_PAL_D  },
    {17,    506000000,  8,    TLG_VSTD_PAL_D  },
    {18,    514000000,  8,    TLG_VSTD_PAL_D  },
    {19,    522000000,  8,    TLG_VSTD_PAL_D  },
    {20,    530000000,  8,    TLG_VSTD_PAL_D  },
    {21,    538000000,  8,    TLG_VSTD_PAL_D  },
    {22,    546000000,  8,    TLG_VSTD_PAL_D  },
    {23,    554000000,  8,    TLG_VSTD_PAL_D  },
    {24,    562000000,  8,    TLG_VSTD_PAL_D  },
    {25,    610000000,  8,    TLG_VSTD_PAL_D  },
    {26,    618000000,  8,    TLG_VSTD_PAL_D  },
    {27,    626000000,  8,    TLG_VSTD_PAL_D  },
    {28,    634000000,  8,    TLG_VSTD_PAL_D  },
    {29,    642000000,  8,    TLG_VSTD_PAL_D  },
    {30,    650000000,  8,    TLG_VSTD_PAL_D  },
    {31,    658000000,  8,    TLG_VSTD_PAL_D  },
    {32,    666000000,  8,    TLG_VSTD_PAL_D  },
    {33,    674000000,  8,    TLG_VSTD_PAL_D  },
    {34,    682000000,  8,    TLG_VSTD_PAL_D  },
    {35,    690000000,  8,    TLG_VSTD_PAL_D  },
    {36,    698000000,  8,    TLG_VSTD_PAL_D  },
    {37,    706000000,  8,    TLG_VSTD_PAL_D  },
    {38,    714000000,  8,    TLG_VSTD_PAL_D  },
    {39,    722000000,  8,    TLG_VSTD_PAL_D  },
    {40,    730000000,  8,    TLG_VSTD_PAL_D  },
    {41,    738000000,  8,    TLG_VSTD_PAL_D  },
    {42,    746000000,  8,    TLG_VSTD_PAL_D  },
    {43,    754000000,  8,    TLG_VSTD_PAL_D  },
    {44,    762000000,  8,    TLG_VSTD_PAL_D  },
    {45,    770000000,  8,    TLG_VSTD_PAL_D  },
    {46,    778000000,  8,    TLG_VSTD_PAL_D  },
    {47,    786000000,  8,    TLG_VSTD_PAL_D  },
    {48,    794000000,  8,    TLG_VSTD_PAL_D  },
    {49,    802000000,  8,    TLG_VSTD_PAL_D  },
    {50,    810000000,  8,    TLG_VSTD_PAL_D  },
    {51,    818000000,  8,    TLG_VSTD_PAL_D  },
    {52,    826000000,  8,    TLG_VSTD_PAL_D  },
    {53,    834000000,  8,    TLG_VSTD_PAL_D  },
    {54,    842000000,  8,    TLG_VSTD_PAL_D  },
    {55,    850000000,  8,    TLG_VSTD_PAL_D  },
    {56,    858000000,  8,    TLG_VSTD_PAL_D  },
    {57,    866000000,  8,    TLG_VSTD_PAL_D  },
    {58,    874000000,  8,    TLG_VSTD_PAL_D  },
    {59,    882000000,  8,    TLG_VSTD_PAL_D  },
    {60,    890000000,  8,    TLG_VSTD_PAL_D  },
    {61,    898000000,  8,    TLG_VSTD_PAL_D  },
    {62,    906000000,  8,    TLG_VSTD_PAL_D  },
    {63,    914000000,  8,    TLG_VSTD_PAL_D  },
    {64,    922000000,  8,    TLG_VSTD_PAL_D  },
    {65,    930000000,  8,    TLG_VSTD_PAL_D  },
    {66,    938000000,  8,    TLG_VSTD_PAL_D  },
    {67,    946000000,  8,    TLG_VSTD_PAL_D  },
    {68,    954000000,  8,    TLG_VSTD_PAL_D  },
    {69,    962000000,  8,    TLG_VSTD_PAL_D  },
    {0, 0, 0, 0}
};

/* Default Channel Map for Vietnam */
tlg_channel_t tlg_vietnam_chn_map[] = {
    {2,      52500000,  8,    TLG_VSTD_PAL_D  },
    {3,      62000000,  8,    TLG_VSTD_PAL_D  },
    {4,      80000000,  8,    TLG_VSTD_PAL_D  },
    {5,      96000000,  8,    TLG_VSTD_PAL_D  },
    {6,     178000000,  8,    TLG_VSTD_PAL_D  },
    {7,     186000000,  8,    TLG_VSTD_PAL_D  },
    {8,     194000000,  8,    TLG_VSTD_PAL_D  },
    {9,     202000000,  8,    TLG_VSTD_PAL_D  },
    {10,    210000000,  8,    TLG_VSTD_PAL_D  },
    {11,    218000000,  8,    TLG_VSTD_PAL_D  },
    {12,    226000000,  8,    TLG_VSTD_PAL_D  },
    {21,    474000000,  8,    TLG_VSTD_PAL_K  },
    {22,    482000000,  8,    TLG_VSTD_PAL_K  },
    {23,    490000000,  8,    TLG_VSTD_PAL_K  },
    {24,    498000000,  8,    TLG_VSTD_PAL_K  },
    {25,    506000000,  8,    TLG_VSTD_PAL_K  },
    {26,    514000000,  8,    TLG_VSTD_PAL_K  },
    {27,    522000000,  8,    TLG_VSTD_PAL_K  },
    {28,    530000000,  8,    TLG_VSTD_PAL_K  },
    {29,    538000000,  8,    TLG_VSTD_PAL_K  },
    {30,    546000000,  8,    TLG_VSTD_PAL_K  },
    {31,    554000000,  8,    TLG_VSTD_PAL_K  },
    {32,    562000000,  8,    TLG_VSTD_PAL_K  },
    {33,    570000000,  8,    TLG_VSTD_PAL_K  },
    {34,    578000000,  8,    TLG_VSTD_PAL_K  },
    {35,    586000000,  8,    TLG_VSTD_PAL_K  },
    {36,    594000000,  8,    TLG_VSTD_PAL_K  },
    {37,    602000000,  8,    TLG_VSTD_PAL_K  },
    {38,    610000000,  8,    TLG_VSTD_PAL_K  },
    {39,    618000000,  8,    TLG_VSTD_PAL_K  },
    {40,    626000000,  8,    TLG_VSTD_PAL_K  },
    {41,    634000000,  8,    TLG_VSTD_PAL_K  },
    {42,    642000000,  8,    TLG_VSTD_PAL_K  },
    {43,    650000000,  8,    TLG_VSTD_PAL_K  },
    {44,    658000000,  8,    TLG_VSTD_PAL_K  },
    {45,    666000000,  8,    TLG_VSTD_PAL_K  },
    {46,    674000000,  8,    TLG_VSTD_PAL_K  },
    {47,    682000000,  8,    TLG_VSTD_PAL_K  },
    {48,    690000000,  8,    TLG_VSTD_PAL_K  },
    {49,    698000000,  8,    TLG_VSTD_PAL_K  },
    {50,    706000000,  8,    TLG_VSTD_PAL_K  },
    {51,    714000000,  8,    TLG_VSTD_PAL_K  },
    {52,    722000000,  8,    TLG_VSTD_PAL_K  },
    {53,    730000000,  8,    TLG_VSTD_PAL_K  },
    {54,    738000000,  8,    TLG_VSTD_PAL_K  },
    {55,    746000000,  8,    TLG_VSTD_PAL_K  },
    {56,    754000000,  8,    TLG_VSTD_PAL_K  },
    {57,    762000000,  8,    TLG_VSTD_PAL_K  },
    {58,    770000000,  8,    TLG_VSTD_PAL_K  },
    {59,    778000000,  8,    TLG_VSTD_PAL_K  },
    {60,    786000000,  8,    TLG_VSTD_PAL_K  },
    {61,    794000000,  8,    TLG_VSTD_PAL_K  },
    {62,    802000000,  8,    TLG_VSTD_PAL_K  },
    {63,    810000000,  8,    TLG_VSTD_PAL_K  },
    {64,    818000000,  8,    TLG_VSTD_PAL_K  },
    {65,    826000000,  8,    TLG_VSTD_PAL_K  },
    {66,    834000000,  8,    TLG_VSTD_PAL_K  },
    {67,    842000000,  8,    TLG_VSTD_PAL_K  },
    {68,    850000000,  8,    TLG_VSTD_PAL_K  },
    {69,    858000000,  8,    TLG_VSTD_PAL_K  },
    {0, 0, 0, 0}
};
/* Default Channel Map for Western Europe, Turkey, UAE, Afghanistan,
Singapore, Thailand, Cambodia, Indonesia, Malaysia, Myanmar, and Laos */
tlg_channel_t tlg_w_europe_chn_map[] = {
    {2,      50500000,  7,    TLG_VSTD_PAL_B  },
    {3,      57500000,  7,    TLG_VSTD_PAL_B  },
    {4,      64500000,  7,    TLG_VSTD_PAL_B  },
    {5,     177500000,  7,    TLG_VSTD_PAL_B  },
    {6,     184500000,  7,    TLG_VSTD_PAL_B  },
    {7,     191500000,  7,    TLG_VSTD_PAL_B  },
    {8,     198500000,  7,    TLG_VSTD_PAL_B  },
    {9,     205500000,  7,    TLG_VSTD_PAL_B  },
    {10,    212500000,  7,    TLG_VSTD_PAL_B  },
    {11,    219500000,  7,    TLG_VSTD_PAL_B  },
    {12,    226500000,  7,    TLG_VSTD_PAL_B  },
    {21,    474000000,  8,    TLG_VSTD_PAL_G  },
    {22,    482000000,  8,    TLG_VSTD_PAL_G  },
    {23,    490000000,  8,    TLG_VSTD_PAL_G  },
    {24,    498000000,  8,    TLG_VSTD_PAL_G  },
    {25,    506000000,  8,    TLG_VSTD_PAL_G  },
    {26,    514000000,  8,    TLG_VSTD_PAL_G  },
    {27,    522000000,  8,    TLG_VSTD_PAL_G  },
    {28,    530000000,  8,    TLG_VSTD_PAL_G  },
    {29,    538000000,  8,    TLG_VSTD_PAL_G  },
    {30,    546000000,  8,    TLG_VSTD_PAL_G  },
    {31,    554000000,  8,    TLG_VSTD_PAL_G  },
    {32,    562000000,  8,    TLG_VSTD_PAL_G  },
    {33,    570000000,  8,    TLG_VSTD_PAL_G  },
    {34,    578000000,  8,    TLG_VSTD_PAL_G  },
    {35,    586000000,  8,    TLG_VSTD_PAL_G  },
    {36,    594000000,  8,    TLG_VSTD_PAL_G  },
    {37,    602000000,  8,    TLG_VSTD_PAL_G  },
    {38,    610000000,  8,    TLG_VSTD_PAL_G  },
    {39,    618000000,  8,    TLG_VSTD_PAL_G  },
    {40,    626000000,  8,    TLG_VSTD_PAL_G  },
    {41,    634000000,  8,    TLG_VSTD_PAL_G  },
    {42,    642000000,  8,    TLG_VSTD_PAL_G  },
    {43,    650000000,  8,    TLG_VSTD_PAL_G  },
    {44,    658000000,  8,    TLG_VSTD_PAL_G  },
    {45,    666000000,  8,    TLG_VSTD_PAL_G  },
    {46,    674000000,  8,    TLG_VSTD_PAL_G  },
    {47,    682000000,  8,    TLG_VSTD_PAL_G  },
    {48,    690000000,  8,    TLG_VSTD_PAL_G  },
    {49,    698000000,  8,    TLG_VSTD_PAL_G  },
    {50,    706000000,  8,    TLG_VSTD_PAL_G  },
    {51,    714000000,  8,    TLG_VSTD_PAL_G  },
    {52,    722000000,  8,    TLG_VSTD_PAL_G  },
    {53,    730000000,  8,    TLG_VSTD_PAL_G  },
    {54,    738000000,  8,    TLG_VSTD_PAL_G  },
    {55,    746000000,  8,    TLG_VSTD_PAL_G  },
    {56,    754000000,  8,    TLG_VSTD_PAL_G  },
    {57,    762000000,  8,    TLG_VSTD_PAL_G  },
    {58,    770000000,  8,    TLG_VSTD_PAL_G  },
    {59,    778000000,  8,    TLG_VSTD_PAL_G  },
    {60,    786000000,  8,    TLG_VSTD_PAL_G  },
    {61,    794000000,  8,    TLG_VSTD_PAL_G  },
    {62,    802000000,  8,    TLG_VSTD_PAL_G  },
    {63,    810000000,  8,    TLG_VSTD_PAL_G  },
    {64,    818000000,  8,    TLG_VSTD_PAL_G  },
    {65,    826000000,  8,    TLG_VSTD_PAL_G  },
    {66,    834000000,  8,    TLG_VSTD_PAL_G  },
    {67,    842000000,  8,    TLG_VSTD_PAL_G  },
    {68,    850000000,  8,    TLG_VSTD_PAL_G  },
    {69,    858000000,  8,    TLG_VSTD_PAL_G  },
    {0, 0, 0, 0}
};

/* Default Channel Map for ntsc_japan */
tlg_channel_t tlg_ntsc_japan_chn_map[] = {
    {1,      93000000,  6,    TLG_VSTD_NTSC_M  },
    {2,      99000000,  6,    TLG_VSTD_NTSC_M  },
    {3,     105000000,  6,    TLG_VSTD_NTSC_M  },
    {4,     173000000,  6,    TLG_VSTD_NTSC_M  },
    {5,     179000000,  6,    TLG_VSTD_NTSC_M  },
    {6,     185000000,  6,    TLG_VSTD_NTSC_M  },
    {7,     191000000,  6,    TLG_VSTD_NTSC_M  },
    {8,     195000000,  6,    TLG_VSTD_NTSC_M  },
    {9,     201000000,  6,    TLG_VSTD_NTSC_M  },
    {10,    207000000,  6,    TLG_VSTD_NTSC_M  },
    {11,    213000000,  6,    TLG_VSTD_NTSC_M  },
    {12,    219000000,  6,    TLG_VSTD_NTSC_M  },
    {13,    473000000,  6,    TLG_VSTD_NTSC_M  },
    {14,    479000000,  6,    TLG_VSTD_NTSC_M  },
    {15,    485000000,  6,    TLG_VSTD_NTSC_M  },
    {16,    491000000,  6,    TLG_VSTD_NTSC_M  },
    {17,    497000000,  6,    TLG_VSTD_NTSC_M  },
    {18,    503000000,  6,    TLG_VSTD_NTSC_M  },
    {19,    509000000,  6,    TLG_VSTD_NTSC_M  },
    {20,    515000000,  6,    TLG_VSTD_NTSC_M  },
    {21,    521000000,  6,    TLG_VSTD_NTSC_M  },
    {22,    527000000,  6,    TLG_VSTD_NTSC_M  },
    {23,    533000000,  6,    TLG_VSTD_NTSC_M  },
    {24,    539000000,  6,    TLG_VSTD_NTSC_M  },
    {25,    545000000,  6,    TLG_VSTD_NTSC_M  },
    {26,    551000000,  6,    TLG_VSTD_NTSC_M  },
    {27,    557000000,  6,    TLG_VSTD_NTSC_M  },
    {28,    563000000,  6,    TLG_VSTD_NTSC_M  },
    {29,    569000000,  6,    TLG_VSTD_NTSC_M  },
    {30,    575000000,  6,    TLG_VSTD_NTSC_M  },
    {31,    581000000,  6,    TLG_VSTD_NTSC_M  },
    {32,    587000000,  6,    TLG_VSTD_NTSC_M  },
    {33,    593000000,  6,    TLG_VSTD_NTSC_M  },
    {34,    599000000,  6,    TLG_VSTD_NTSC_M  },
    {35,    605000000,  6,    TLG_VSTD_NTSC_M  },
    {36,    611000000,  6,    TLG_VSTD_NTSC_M  },
    {37,    617000000,  6,    TLG_VSTD_NTSC_M  },
    {38,    623000000,  6,    TLG_VSTD_NTSC_M  },
    {39,    629000000,  6,    TLG_VSTD_NTSC_M  },
    {40,    635000000,  6,    TLG_VSTD_NTSC_M  },
    {41,    641000000,  6,    TLG_VSTD_NTSC_M  },
    {42,    647000000,  6,    TLG_VSTD_NTSC_M  },
    {43,    653000000,  6,    TLG_VSTD_NTSC_M  },
    {44,    659000000,  6,    TLG_VSTD_NTSC_M  },
    {45,    665000000,  6,    TLG_VSTD_NTSC_M  },
    {46,    671000000,  6,    TLG_VSTD_NTSC_M  },
    {47,    677000000,  6,    TLG_VSTD_NTSC_M  },
    {48,    683000000,  6,    TLG_VSTD_NTSC_M  },
    {49,    689000000,  6,    TLG_VSTD_NTSC_M  },
    {50,    695000000,  6,    TLG_VSTD_NTSC_M  },
    {51,    701000000,  6,    TLG_VSTD_NTSC_M  },
    {52,    707000000,  6,    TLG_VSTD_NTSC_M  },
    {53,    713000000,  6,    TLG_VSTD_NTSC_M  },
    {54,    719000000,  6,    TLG_VSTD_NTSC_M  },
    {55,    725000000,  6,    TLG_VSTD_NTSC_M  },
    {56,    731000000,  6,    TLG_VSTD_NTSC_M  },
    {57,    737000000,  6,    TLG_VSTD_NTSC_M  },
    {58,    743000000,  6,    TLG_VSTD_NTSC_M  },
    {59,    749000000,  6,    TLG_VSTD_NTSC_M  },
    {60,    755000000,  6,    TLG_VSTD_NTSC_M  },
    {61,    761000000,  6,    TLG_VSTD_NTSC_M  },
    {62,    767000000,  6,    TLG_VSTD_NTSC_M  },
    {0, 0, 0, 0}
};

/* Default Channel Maps for UK, Hong Kong, and South Africa */
tlg_channel_t tlg_a_uk_chn_map[] = {
    {2,      48000000,  7,    TLG_VSTD_PAL_B  },
    {3,      56000000,  7,    TLG_VSTD_PAL_B  },
    {4,      64000000,  7,    TLG_VSTD_PAL_B  },
    {5,     177500000,  7,    TLG_VSTD_PAL_B  },
    {6,     185500000,  7,    TLG_VSTD_PAL_B  },
    {7,     193500000,  7,    TLG_VSTD_PAL_B  },
    {8,     201500000,  7,    TLG_VSTD_PAL_B  },
    {9,     209500000,  7,    TLG_VSTD_PAL_B  },
    {10,    217500000,  7,    TLG_VSTD_PAL_B  },
    {21,    474000000,  8,    TLG_VSTD_PAL_I  },
    {22,    482000000,  8,    TLG_VSTD_PAL_I  },
    {23,    490000000,  8,    TLG_VSTD_PAL_I  },
    {24,    498000000,  8,    TLG_VSTD_PAL_I  },
    {25,    506000000,  8,    TLG_VSTD_PAL_I  },
    {26,    514000000,  8,    TLG_VSTD_PAL_I  },
    {27,    522000000,  8,    TLG_VSTD_PAL_I  },
    {28,    530000000,  8,    TLG_VSTD_PAL_I  },
    {29,    538000000,  8,    TLG_VSTD_PAL_I  },
    {30,    546000000,  8,    TLG_VSTD_PAL_I  },
    {31,    554000000,  8,    TLG_VSTD_PAL_I  },
    {32,    562000000,  8,    TLG_VSTD_PAL_I  },
    {33,    570000000,  8,    TLG_VSTD_PAL_I  },
    {34,    578000000,  8,    TLG_VSTD_PAL_I  },
    {35,    586000000,  8,    TLG_VSTD_PAL_I  },
    {36,    594000000,  8,    TLG_VSTD_PAL_I  },
    {37,    602000000,  8,    TLG_VSTD_PAL_I  },
    {38,    610000000,  8,    TLG_VSTD_PAL_I  },
    {39,    618000000,  8,    TLG_VSTD_PAL_I  },
    {40,    626000000,  8,    TLG_VSTD_PAL_I  },
    {41,    634000000,  8,    TLG_VSTD_PAL_I  },
    {42,    642000000,  8,    TLG_VSTD_PAL_I  },
    {43,    650000000,  8,    TLG_VSTD_PAL_I  },
    {44,    658000000,  8,    TLG_VSTD_PAL_I  },
    {45,    666000000,  8,    TLG_VSTD_PAL_I  },
    {46,    674000000,  8,    TLG_VSTD_PAL_I  },
    {47,    682000000,  8,    TLG_VSTD_PAL_I  },
    {48,    690000000,  8,    TLG_VSTD_PAL_I  },
    {49,    698000000,  8,    TLG_VSTD_PAL_I  },
    {50,    706000000,  8,    TLG_VSTD_PAL_I  },
    {51,    714000000,  8,    TLG_VSTD_PAL_I  },
    {52,    722000000,  8,    TLG_VSTD_PAL_I  },
    {53,    730000000,  8,    TLG_VSTD_PAL_I  },
    {54,    738000000,  8,    TLG_VSTD_PAL_I  },
    {55,    746000000,  8,    TLG_VSTD_PAL_I  },
    {56,    754000000,  8,    TLG_VSTD_PAL_I  },
    {57,    762000000,  8,    TLG_VSTD_PAL_I  },
    {58,    770000000,  8,    TLG_VSTD_PAL_I  },
    {59,    778000000,  8,    TLG_VSTD_PAL_I  },
    {60,    786000000,  8,    TLG_VSTD_PAL_I  },
    {61,    794000000,  8,    TLG_VSTD_PAL_I  },
    {62,    802000000,  8,    TLG_VSTD_PAL_I  },
    {63,    810000000,  8,    TLG_VSTD_PAL_I  },
    {64,    818000000,  8,    TLG_VSTD_PAL_I  },
    {65,    826000000,  8,    TLG_VSTD_PAL_I  },
    {66,    834000000,  8,    TLG_VSTD_PAL_I  },
    {67,    842000000,  8,    TLG_VSTD_PAL_I  },
    {68,    850000000,  8,    TLG_VSTD_PAL_I  },
    {69,    858000000,  8,    TLG_VSTD_PAL_I  },
    {0, 0, 0, 0}
};


/* Default Channel Map for Brazil */
tlg_channel_t tlg_brazil_chn_map[] = {
    {2,      57000000,  6,    TLG_VSTD_PAL_M  },
    {3,      63000000,  6,    TLG_VSTD_PAL_M  },
    {4,      69000000,  6,    TLG_VSTD_PAL_M  },
    {5,      79000000,  6,    TLG_VSTD_PAL_M  },
    {6,      85000000,  6,    TLG_VSTD_PAL_M  },
    {7,     177000000,  6,    TLG_VSTD_PAL_M  },
    {8,     183000000,  6,    TLG_VSTD_PAL_M  },
    {9,     189000000,  6,    TLG_VSTD_PAL_M  },
    {10,    195000000,  6,    TLG_VSTD_PAL_M  },
    {11,    201000000,  6,    TLG_VSTD_PAL_M  },
    {12,    207000000,  6,    TLG_VSTD_PAL_M  },
    {13,    213000000,  6,    TLG_VSTD_PAL_M  },
    {14,    473000000,  6,    TLG_VSTD_PAL_M  },
    {15,    479000000,  6,    TLG_VSTD_PAL_M  },
    {16,    485000000,  6,    TLG_VSTD_PAL_M  },
    {17,    491000000,  6,    TLG_VSTD_PAL_M  },
    {18,    497000000,  6,    TLG_VSTD_PAL_M  },
    {19,    503000000,  6,    TLG_VSTD_PAL_M  },
    {20,    509000000,  6,    TLG_VSTD_PAL_M  },
    {21,    515000000,  6,    TLG_VSTD_PAL_M  },
    {22,    521000000,  6,    TLG_VSTD_PAL_M  },
    {23,    527000000,  6,    TLG_VSTD_PAL_M  },
    {24,    533000000,  6,    TLG_VSTD_PAL_M  },
    {25,    539000000,  6,    TLG_VSTD_PAL_M  },
    {26,    545000000,  6,    TLG_VSTD_PAL_M  },
    {27,    551000000,  6,    TLG_VSTD_PAL_M  },
    {28,    557000000,  6,    TLG_VSTD_PAL_M  },
    {29,    563000000,  6,    TLG_VSTD_PAL_M  },
    {30,    569000000,  6,    TLG_VSTD_PAL_M  },
    {31,    575000000,  6,    TLG_VSTD_PAL_M  },
    {32,    581000000,  6,    TLG_VSTD_PAL_M  },
    {33,    587000000,  6,    TLG_VSTD_PAL_M  },
    {34,    593000000,  6,    TLG_VSTD_PAL_M  },
    {35,    599000000,  6,    TLG_VSTD_PAL_M  },
    {36,    605000000,  6,    TLG_VSTD_PAL_M  },
    {37,    611000000,  6,    TLG_VSTD_PAL_M  },
    {38,    617000000,  6,    TLG_VSTD_PAL_M  },
    {39,    623000000,  6,    TLG_VSTD_PAL_M  },
    {40,    629000000,  6,    TLG_VSTD_PAL_M  },
    {41,    635000000,  6,    TLG_VSTD_PAL_M  },
    {42,    641000000,  6,    TLG_VSTD_PAL_M  },
    {43,    647000000,  6,    TLG_VSTD_PAL_M  },
    {44,    653000000,  6,    TLG_VSTD_PAL_M  },
    {45,    659000000,  6,    TLG_VSTD_PAL_M  },
    {46,    665000000,  6,    TLG_VSTD_PAL_M  },
    {47,    671000000,  6,    TLG_VSTD_PAL_M  },
    {48,    677000000,  6,    TLG_VSTD_PAL_M  },
    {49,    683000000,  6,    TLG_VSTD_PAL_M  },
    {50,    689000000,  6,    TLG_VSTD_PAL_M  },
    {51,    695000000,  6,    TLG_VSTD_PAL_M  },
    {52,    701000000,  6,    TLG_VSTD_PAL_M  },
    {53,    707000000,  6,    TLG_VSTD_PAL_M  },
    {54,    713000000,  6,    TLG_VSTD_PAL_M  },
    {55,    719000000,  6,    TLG_VSTD_PAL_M  },
    {56,    725000000,  6,    TLG_VSTD_PAL_M  },
    {57,    731000000,  6,    TLG_VSTD_PAL_M  },
    {58,    737000000,  6,    TLG_VSTD_PAL_M  },
    {59,    743000000,  6,    TLG_VSTD_PAL_M  },
    {60,    749000000,  6,    TLG_VSTD_PAL_M  },
    {61,    755000000,  6,    TLG_VSTD_PAL_M  },
    {62,    761000000,  6,    TLG_VSTD_PAL_M  },
    {63,    767000000,  6,    TLG_VSTD_PAL_M  },
    {64,    773000000,  6,    TLG_VSTD_PAL_M  },
    {65,    779000000,  6,    TLG_VSTD_PAL_M  },
    {66,    785000000,  6,    TLG_VSTD_PAL_M  },
    {67,    791000000,  6,    TLG_VSTD_PAL_M  },
    {68,    797000000,  6,    TLG_VSTD_PAL_M  },
    {69,    803000000,  6,    TLG_VSTD_PAL_M  },
    {0, 0, 0, 0}
};

/* Default Channel Map for Argentina */
tlg_channel_t tlg_argentina_chn_map[] = {
    {2,      57000000,  6,    TLG_VSTD_PAL_NC  },
    {3,      63000000,  6,    TLG_VSTD_PAL_NC  },
    {4,      69000000,  6,    TLG_VSTD_PAL_NC  },
    {5,      79000000,  6,    TLG_VSTD_PAL_NC  },
    {6,      85000000,  6,    TLG_VSTD_PAL_NC  },
    {7,     177000000,  6,    TLG_VSTD_PAL_NC  },
    {8,     183000000,  6,    TLG_VSTD_PAL_NC  },
    {9,     189000000,  6,    TLG_VSTD_PAL_NC  },
    {10,    195000000,  6,    TLG_VSTD_PAL_NC  },
    {11,    201000000,  6,    TLG_VSTD_PAL_NC  },
    {12,    207000000,  6,    TLG_VSTD_PAL_NC  },
    {13,    213000000,  6,    TLG_VSTD_PAL_NC  },
    {14,    473000000,  6,    TLG_VSTD_PAL_NC  },
    {15,    479000000,  6,    TLG_VSTD_PAL_NC  },
    {16,    485000000,  6,    TLG_VSTD_PAL_NC  },
    {17,    491000000,  6,    TLG_VSTD_PAL_NC  },
    {18,    497000000,  6,    TLG_VSTD_PAL_NC  },
    {19,    503000000,  6,    TLG_VSTD_PAL_NC  },
    {20,    509000000,  6,    TLG_VSTD_PAL_NC  },
    {21,    515000000,  6,    TLG_VSTD_PAL_NC  },
    {22,    521000000,  6,    TLG_VSTD_PAL_NC  },
    {23,    527000000,  6,    TLG_VSTD_PAL_NC  },
    {24,    533000000,  6,    TLG_VSTD_PAL_NC  },
    {25,    539000000,  6,    TLG_VSTD_PAL_NC  },
    {26,    545000000,  6,    TLG_VSTD_PAL_NC  },
    {27,    551000000,  6,    TLG_VSTD_PAL_NC  },
    {28,    557000000,  6,    TLG_VSTD_PAL_NC  },
    {29,    563000000,  6,    TLG_VSTD_PAL_NC  },
    {30,    569000000,  6,    TLG_VSTD_PAL_NC  },
    {31,    575000000,  6,    TLG_VSTD_PAL_NC  },
    {32,    581000000,  6,    TLG_VSTD_PAL_NC  },
    {33,    587000000,  6,    TLG_VSTD_PAL_NC  },
    {34,    593000000,  6,    TLG_VSTD_PAL_NC  },
    {35,    599000000,  6,    TLG_VSTD_PAL_NC  },
    {36,    605000000,  6,    TLG_VSTD_PAL_NC  },
    {37,    611000000,  6,    TLG_VSTD_PAL_NC  },
    {38,    617000000,  6,    TLG_VSTD_PAL_NC  },
    {39,    623000000,  6,    TLG_VSTD_PAL_NC  },
    {40,    629000000,  6,    TLG_VSTD_PAL_NC  },
    {41,    635000000,  6,    TLG_VSTD_PAL_NC  },
    {42,    641000000,  6,    TLG_VSTD_PAL_NC  },
    {43,    647000000,  6,    TLG_VSTD_PAL_NC  },
    {44,    653000000,  6,    TLG_VSTD_PAL_NC  },
    {45,    659000000,  6,    TLG_VSTD_PAL_NC  },
    {46,    665000000,  6,    TLG_VSTD_PAL_NC  },
    {47,    671000000,  6,    TLG_VSTD_PAL_NC  },
    {48,    677000000,  6,    TLG_VSTD_PAL_NC  },
    {49,    683000000,  6,    TLG_VSTD_PAL_NC  },
    {50,    689000000,  6,    TLG_VSTD_PAL_NC  },
    {51,    695000000,  6,    TLG_VSTD_PAL_NC  },
    {52,    701000000,  6,    TLG_VSTD_PAL_NC  },
    {53,    707000000,  6,    TLG_VSTD_PAL_NC  },
    {54,    713000000,  6,    TLG_VSTD_PAL_NC  },
    {55,    719000000,  6,    TLG_VSTD_PAL_NC  },
    {56,    725000000,  6,    TLG_VSTD_PAL_NC  },
    {57,    731000000,  6,    TLG_VSTD_PAL_NC  },
    {58,    737000000,  6,    TLG_VSTD_PAL_NC  },
    {59,    743000000,  6,    TLG_VSTD_PAL_NC  },
    {60,    749000000,  6,    TLG_VSTD_PAL_NC  },
    {61,    755000000,  6,    TLG_VSTD_PAL_NC  },
    {62,    761000000,  6,    TLG_VSTD_PAL_NC  },
    {63,    767000000,  6,    TLG_VSTD_PAL_NC  },
    {64,    773000000,  6,    TLG_VSTD_PAL_NC  },
    {65,    779000000,  6,    TLG_VSTD_PAL_NC  },
    {66,    785000000,  6,    TLG_VSTD_PAL_NC  },
    {67,    791000000,  6,    TLG_VSTD_PAL_NC  },
    {68,    797000000,  6,    TLG_VSTD_PAL_NC  },
    {69,    803000000,  6,    TLG_VSTD_PAL_NC  },
    {0, 0, 0, 0}
};


p_tlg_channel_t p_tlg_cur_map     = NULL; /* Current Default Channel Map    */
int              tlg_cur_bw         = TLG_BW_NONE;   /* Current Bandwidth     */
int              tlg_cur_mode       = TLG_MODE_NONE; /* Current Mode          */
int              tlg_cur_std        = TLG_VSTD_NONE; /* Current Video Std     */
int              tlg_cur_chn_cnt    = 0;             /* Current Channel Count */
int              tlg_slope          = 0;             /* Current FM Slope      */
int              tlg_offset         = 0;             /* Current FM Offset     */
int              tlg_init_done      = 0;             /* Flag Init called      */
int              tlg_cur_lna        = TLG_LNA_NONE;  /* LNA Setting           */
uint16           tlg_cur_gain       = 0;             /* audio gain            */
uint16           tlg_cur_aud_mode   = 0;             /* audio mode            */
uint32           tlg_i2c_addr       = TLGI2C_DEFAULT_BASE_ADDR;
tlg_statep       tlg_power_state    = {TLG_STATE0};

TLG1100DLL_API void TLGAPP_Restart(void)
{
    p_tlg_cur_map = NULL; /* Current Default Channel Map*/
    tlg_cur_bw    = TLG_BW_NONE;   /* Current Bandwidth */
    tlg_cur_mode  = TLG_MODE_NONE; /* current Mode      */
    tlg_cur_std   = TLG_VSTD_NONE; /* Current Video Std */
    tlg_slope     = 0;             /* Current FM Slope  */
    tlg_offset    = 0;             /* Current FM Offset */
    tlg_init_done = 0;             /* Flag Init called  */
    tlg_cur_lna   = TLG_LNA_NONE;  /* LNA Setting       */
    tlg_cur_gain  = 0;             /* audio gain        */
    tlg_cur_aud_mode = 0;          /* audio mode        */

    TLG_ClearRegShadow(tlg_i2c_addr); /* clear reg cache*/
}

int TLGAPP_Ini_WriteReg(int start, uint32 i2c_addr, uint16 reg_addr, uint16 val)
{
    if (start == TLG_INIT_DEEP_SLEEP && (reg_addr >= 0x180))
        return TLG_ERR_SUCCESS;
    return TLG_WriteReg(i2c_addr, reg_addr, val);
}
/*****************************************************************************
* TLGAPP_Ini_Reg
* BEGIN CUSTOM SECTION: These are the recommended set of default register 
* settings for startup of the TLG1100. However, additional register writes may
* be added by customers as desired.
*****************************************************************************/
TLG1100DLL_API void TLGAPP_Ini_Reg(int start)
{
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0010, 0x16c8);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0011, 0x4605);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0012, 0xc810);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0015, 0x0640);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0016, 0x0640);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0017, 0x0001);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0018, 0x0001);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0019, 0x0005);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x001a, 0x0010);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x001f, 0x6640);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0025, 0x03f0);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0026, 0x03FF);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x002b, 0x000c);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x002c, 0x0009);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x002d, 0x000a);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0031, 0x0001);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0032, 0x0001);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0033, 0x0d01);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x004a, 0x0041);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0052, 0x0FFF);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0053, 0x7100);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0054, 0x90c8);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0059, 0x8046);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x006d, 0x160c);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0077, 0x1038);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x008b, 0x0009);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0097, 0x0000);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x009e, 0x0080);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0185, 0x0292);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0188, 0x0292);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x018b, 0x0292);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0193, 0x8080);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0198, 0x0003);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x01a4, 0x0282);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x01b3, 0x29F8);
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x01b4, 0x0261); 
TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x01b7, 0x0641);
#ifdef TLG_SUPPORT_RUNTIME_CHECK
    {uint32 version; TLG_GetChipVersion(tlg_i2c_addr, &version);}
#endif /* TLG_SUPPORT_RUNTIME_CHECK */
TLG_CHIP_VERS_1_3_BEGIN
    #if defined(TLG_CMP_CHIP_1_3)
	TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0010, 0x26c8);
	TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0025, 0x000c);
	TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0026, 0x0200);
	TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0030, 0x0000);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0056, 0x0490);
	TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x005e, 0x810f);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0061, 0x4104);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x006f, 0x40c0);
    #endif /* TLG_CMP_CHIP_1_3 */
TLG_CHIP_VERS_ELSE
    #if defined(TLG_CMP_CHIP_1_2) || defined(TLG_CMP_CHIP_1_1)
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x005e, 0x81ff);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0061, 0x4108);
    #endif /* !TLG_CMP_CHIP_1_3 */
TLG_CHIP_VERS_END
TLG_CHIP_VERS_1_2_BEGIN
    #if defined(TLG_CMP_CHIP_1_3) || defined(TLG_CMP_CHIP_1_2)
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x002e, 0x0600);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0027, 0x0200);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0030, 0x8000);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x001e, 0x0029);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x01a3, 0x0700);
    #endif /* TLG_CMP_CHIP_1_2 */
 TLG_CHIP_VERS_1_1_ELSE
    #ifdef TLG_CMP_CHIP_1_1
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x0027, 0x03FF);
    TLGAPP_Ini_WriteReg(start, tlg_i2c_addr, 0x001e, 0x003c);
    #endif /* TLG_CMP_CHIP_1_1 */
 TLG_CHIP_VERS_END
/**
 ** BEGIN CUSTOM SECTION: any additional register writes should go here.
 **/
}


/*****************************************************************************
* TLGAPP_Init_Aux
******************************************************************************/
TLG1100DLL_API int TLGAPP_Init_Aux(uint32 base_addr, int start)
{
    tlg_i2c_addr = base_addr;

    TLGAPP_Ini_Reg(start);
    if (start == TLG_NEW_INIT)
        TLG_Init(tlg_i2c_addr);
    else
        TLG_ReInitFromDeepSleep(tlg_i2c_addr);

    TLGAPP_InitVideoAndAudio();            /* see tlg1100customize.c */

    tlg_init_done = 1;

    return(TLG_ERR_SUCCESS);
}

TLG1100DLL_API int TLGAPP_Init(uint32 base_addr)
{
	TLGAPP_Restart();
	
    return TLGAPP_Init_Aux(base_addr, TLG_NEW_INIT);
}

TLG1100DLL_API int TLGAPP_PowerDown(void)
{
    tlg_power_state[0] = TLG_STATE0;
    TLG_DeepSleep(tlg_i2c_addr, tlg_power_state);
    return TLG_ERR_SUCCESS;
}
    

TLG1100DLL_API int TLGAPP_ReInitFromPowerDown(void)
{
    if (TLG_ReturnFromDeepSleep(tlg_i2c_addr, tlg_power_state) == TLG_ERR_SUCCESS)
    {
        TLGAPP_Restart();
        return TLGAPP_Init_Aux(tlg_i2c_addr, TLG_INIT_DEEP_SLEEP);
    } else
        return TLG_ERR_FAIL;
}

/*****************************************************************************
* TLGAPP_ChannelSetup
*****************************************************************************/
TLG1100DLL_API int TLGAPP_ChannelSetup(int mode, int standard, int bw)
{
    if (!tlg_init_done) TLGAPP_Init(tlg_i2c_addr);
    if (mode != tlg_cur_mode) 
    {
        TLG_SetChnMode(tlg_i2c_addr, (uint16) mode);
        tlg_cur_mode = mode;
    }
    if (standard != tlg_cur_std)
    {
        TLG_SetChnStandard(tlg_i2c_addr, (uint16) standard);
        tlg_cur_std = standard;
    }
    if (bw != tlg_cur_bw)
    {
        TLG_SetChnBandwidth(tlg_i2c_addr, (uint16) bw);
        tlg_cur_bw = bw;
    }
    return(TLG_ERR_SUCCESS);
}
    
/*****************************************************************************
* TLGAPP_SetChannelMap
******************************************************************************/
TLG1100DLL_API int TLGAPP_SetChannelMap(p_tlg_channel_t(map), int mode, int vidstd, int bw)
{
    int i;
    TLGAPP_ChannelSetup(mode, vidstd, bw);
    p_tlg_cur_map   = map;
    tlg_slope       = 0;
    tlg_offset      = 0;
    tlg_cur_chn_cnt = 0;
    for(i=0; p_tlg_cur_map[i] CHN_S != 0; i++)
	{
        tlg_cur_chn_cnt++;
    }
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLGAPP_SetChannelMapPALD
******************************************************************************/
TLG1100DLL_API int TLGAPP_SetChannelMapPALD(void)
{
    return TLGAPP_SetChannelMap(tlg_pald_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_D, TLG_BW_8);
}

/*****************************************************************************
* TLGAPP_SetChannelMapNTSC
******************************************************************************/
TLG1100DLL_API int TLGAPP_SetChannelMapNTSC(void)
{
    return TLGAPP_SetChannelMap(tlg_ntsc_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_NTSC_M, TLG_BW_6);
}

/*****************************************************************************
* TLGAPP_SetChannelMapFM
******************************************************************************/
TLG1100DLL_API int TLGAPP_SetChannelMapFM(void)
{
    int    i;
    uint32 minhz = 999999999;
    uint32 maxhz = 0;

    /* Always use NTSC, 6MHz setttings for FM Radio */
    TLGAPP_ChannelSetup(TLG_MODE_FM_RADIO, TLG_VSTD_NTSC_M, TLG_BW_6);
    p_tlg_cur_map = tlg_fm_chn_map;

    /* get min and max hz */
    for (i=0; p_tlg_cur_map[i] CHN_S != 0; i++)
    {
        if (p_tlg_cur_map[i] HZ_S < minhz) minhz = p_tlg_cur_map[i] HZ_S;
        if (p_tlg_cur_map[i] HZ_S > maxhz) maxhz = p_tlg_cur_map[i] HZ_S;   
    }
    return TLG_InitScanFMChn(tlg_i2c_addr, minhz, maxhz, &tlg_slope, &tlg_offset);
}


/*****************************************************************************
* TLGAPP_SwitchChannelMap
******************************************************************************/
TLG1100DLL_API int TLGAPP_SwitchChannelMap(p_tlg_channel_t(map))
{
    int i;
    TLG_NULLPTR_CHECK(map);
    p_tlg_cur_map = map;
    tlg_cur_chn_cnt = 0;
    for(i=0; p_tlg_cur_map[i] CHN_S != 0; i++)
	{
        tlg_cur_chn_cnt++;
    }
    return(TLG_ERR_SUCCESS);
}

/*****************************************************************************
* TLGAPP_SetChannelAux
******************************************************************************/
TLG1100DLL_API int TLGAPP_SetChannelAux(int chn, int useFast)
{
    int i = 0;
    int result;

    if (chn == 0) return 0;
	
    if (p_tlg_cur_map == NULL) return 0;
    
    if (!tlg_init_done) TLGAPP_Init(tlg_i2c_addr);

#if 0
    while (p_tlg_cur_map[i] CHN_S != 0)
    {
        /* found channel to change to */
        if (p_tlg_cur_map[i] CHN_S == chn)
        {

	    unsigned int  freq =p_tlg_cur_map[i] HZ_S;

	    Test_UART_SendData("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\r",  0 );
	    for ( freq = (p_tlg_cur_map[i] HZ_S - 1000000); freq <= ( p_tlg_cur_map[i] HZ_S + 2000000);  freq+=50000)
	    {

		    Test_UART_SendData(">",  0 );
			
	            /* change LNA if required */
	            TLGAPP_SetLnaGpio(freq);

	            /* update bw if needed */
	            TLGAPP_ChannelSetup(tlg_cur_mode, p_tlg_cur_map[i] STD_S, p_tlg_cur_map[i] BW_S);

		     if (tlg_cur_mode == TLG_MODE_ANALOG_TV) {
	                if (useFast)
	                    result = TLG_FastScanTVChn(tlg_i2c_addr, freq);
	                else
	                    result = TLG_ScanTVChn(tlg_i2c_addr, freq);
		     }
	            else
	                result = TLG_ScanFMChn(tlg_i2c_addr, freq,  tlg_slope, tlg_offset);

	    }
		
        }
    i++;
    }    

#else

    while (p_tlg_cur_map[i] CHN_S != 0)
    {
        /* found channel to change to */
        if (p_tlg_cur_map[i] CHN_S == chn)
        {
    
            /* change LNA if required */
            TLGAPP_SetLnaGpio(p_tlg_cur_map[i] HZ_S);

            /* update bw if needed */
            TLGAPP_ChannelSetup(tlg_cur_mode, p_tlg_cur_map[i] STD_S, p_tlg_cur_map[i] BW_S);
			if (tlg_cur_mode == TLG_MODE_ANALOG_TV) {
                if (useFast)
                    result = TLG_FastScanTVChn(tlg_i2c_addr, p_tlg_cur_map[i] HZ_S);
                else
                    result = TLG_ScanTVChn(tlg_i2c_addr, p_tlg_cur_map[i] HZ_S);
			}
            else
                result = TLG_ScanFMChn(tlg_i2c_addr, p_tlg_cur_map[i] HZ_S, 
                                     tlg_slope, tlg_offset);
        }
    i++;
    }    

#endif 

    return(result);
}

/*****************************************************************************
* TLGAPP_SetChannel
******************************************************************************/
TLG1100DLL_API int TLGAPP_SetChannel(int chn)
{
#ifdef ANALOG_TV_TEST_PATTERN_MODE
	return 0;
#else	
    return TLGAPP_SetChannelAux(chn, false /* useFast */);
#endif

}

/*****************************************************************************
* TLGAPP_FastSetChannel
******************************************************************************/
TLG1100DLL_API int TLGAPP_FastSetChannel(int chn)
{
    return TLGAPP_SetChannelAux(chn, true /* useFast */);
}

/*****************************************************************************
* TLGAPP_ScanChannels
******************************************************************************/
uint32 tlg_prev_fm_ssi = 0;
uint32 tlg_prev_fm_chn = 0;
extern TLG1100DLL_API uint32 tlg_cur_fm_ssi;
TLG1100DLL_API void TLGAPP_ScanChannels(p_tlg_channel_t(tlg_scan_map), int max_scan)
{
    int chni, scani=0;

	
    tlg_prev_fm_ssi = 0;
    tlg_prev_fm_chn = 0;
	
    for(chni=0; p_tlg_cur_map[chni] CHN_S != 0; chni++)
    {
        int locked;

#ifdef TLG_USE_FAST_LOCK_DETECT
        locked = TLGAPP_FastSetChannel(p_tlg_cur_map[chni] CHN_S);
#else
        locked = TLGAPP_SetChannel(p_tlg_cur_map[chni] CHN_S);
#endif /* TLG_USE_FAST_LOCK_DETECT */

        if (locked || tlg_prev_fm_ssi)
        {
            int schn = chni;
            /*** not locked, then report prev cached radio chn            ***/
            if (!locked)
            {
                schn = tlg_prev_fm_chn;
                tlg_prev_fm_chn = 0;
                tlg_prev_fm_ssi = 0;
            } else if (tlg_cur_mode == TLG_MODE_FM_RADIO) {
                /*** if locked and no prev radio, or prev weaker than cur ***/
                if (!tlg_prev_fm_ssi || tlg_prev_fm_ssi < tlg_cur_fm_ssi)
                {
                    tlg_prev_fm_ssi = tlg_cur_fm_ssi;
                    tlg_prev_fm_chn = chni; 
                    continue;
                } else { /*** previous wins ***/
                    schn = tlg_prev_fm_chn;
                    tlg_prev_fm_chn = 0;
                    tlg_prev_fm_ssi = 0;
                }
            }
            /* leave room for 0-valued entry to terminate channel map */
            if (scani >= (max_scan-1)) break;
           
            (*(tlg_scan_map + scani)) CHN_S = p_tlg_cur_map[schn] CHN_S;
            (*(tlg_scan_map + scani)) HZ_S  = p_tlg_cur_map[schn] HZ_S;
            (*(tlg_scan_map + scani)) BW_S  = p_tlg_cur_map[schn] BW_S;
            (*(tlg_scan_map + scani)) STD_S = p_tlg_cur_map[schn] CHN_S;
    

            /* customizable callback routine                          */
            TLGAPP_ScanChanFound(p_tlg_cur_map[schn] CHN_S);
        }
    }
    tlg_scan_map[scani] CHN_S   = 0;
    tlg_scan_map[scani] HZ_S    = 0;
    tlg_scan_map[scani] BW_S    = 0;
    tlg_scan_map[scani] STD_S = 0;



}

/*****************************************************************************
* TLGAPP_TurnOnTestPattern
******************************************************************************/
TLG1100DLL_API void TLGAPP_TurnOnTestPattern(void)
{
    if (!tlg_init_done) TLGAPP_Init(tlg_i2c_addr);
    TLG_SetVideoTestPatternState(tlg_i2c_addr, TLG_ON);
}

/*****************************************************************************
* TLGAPP_TurnOffTestPattern
******************************************************************************/
TLG1100DLL_API void TLGAPP_TurnOffTestPattern(void)
{
    if (!tlg_init_done) TLGAPP_Init(tlg_i2c_addr);
    TLG_SetVideoTestPatternState(tlg_i2c_addr, TLG_OFF);
}

TLG1100DLL_API void TLGAPP_TurnOnTestToneMode(void)
{
    /** test tones only for digital modes                                   */
    if (tlg_cur_aud_mode != TLG_DAC)
    {
        /** turn gain all the way down before turning on test tones         */
        TLG_SetAudioGain(tlg_i2c_addr, tlg_cur_aud_mode, TLG_MIN_AUD_GAIN);
        TLG_SetAudioTestToneMode(tlg_i2c_addr, TLG_ON);
    }
}

TLG1100DLL_API void TLGAPP_TurnOffTestToneMode(void)
{
    /** test tones only for digital modes                                   */
    if (tlg_cur_aud_mode != TLG_DAC)
    {
        /** restore gain setting                                            */
        TLG_SetAudioGain(tlg_i2c_addr, tlg_cur_aud_mode, tlg_cur_gain);
        TLG_SetAudioTestToneMode(tlg_i2c_addr, TLG_OFF);
    }
}
//////////////////////////////////////////////////////////////////
TLG1100DLL_API uint8 TLG_GetFMLevel(void)
{
	uint16 metric;
	
	TLG_GetFMSSI( tlg_i2c_addr, & metric );

	return metric;	
}

TLG1100DLL_API int TLG_GetSSI_FOR_TEST( uint32 base_addr )
{
	uint16 metric;

	TLG_GetTVSSI( tlg_i2c_addr , &metric);

	return metric;

}

TLG1100DLL_API  uint8 TLGAPP_GetChannel( uint8 channel_index )
{

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "TLGAPP_GetChannel: channel=%d, index=%d", p_tlg_cur_map[channel_index].chn, channel_index );
#endif	
	return p_tlg_cur_map[channel_index].chn;

}

TLG1100DLL_API uint8 TLGAPP_GetChannelIndex(uint8 channel )
{
	uint8 i;

	for( i = 0; p_tlg_cur_map[i].chn; i++ )
	{
		if ( p_tlg_cur_map[i].chn == channel ) {
#if defined(NOKE_DEBUG)
			noke_dbg_printf( "TLGAPP_GetChannelIndex: channel=%d, index=%d", channel, i );
#endif
			return i;
		}
	}	
	
	return 0;
}

TLG1100DLL_API int TLGAPP_SetChannelMapShenzhen(void)
{
    return TLGAPP_SetChannelMap(tlg_pal_I_shenzhen_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_I, TLG_BW_8);
}

TLG1100DLL_API int TLGAPP_SetChannelMapEurope(void)
{
    return TLGAPP_SetChannelMap(tlg_w_europe_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_G, TLG_BW_8);
}

TLG1100DLL_API int TLGAPP_SetChannelMapVietnam(void)
{
    return TLGAPP_SetChannelMap(tlg_vietnam_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_D, TLG_BW_8);
}

TLG1100DLL_API int TLGAPP_SetChannelMapHongkong(void)
{
    return TLGAPP_SetChannelMap(tlg_a_uk_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_B, TLG_BW_7);
}

TLG1100DLL_API int TLGAPP_SetChannelMapAmerica(void)
{
    return TLGAPP_SetChannelMap(tlg_ntsc_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_NTSC_M, TLG_BW_6);
}

TLG1100DLL_API int TLGAPP_SetChannelMapBrazil(void)
{
    return TLGAPP_SetChannelMap(tlg_brazil_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_M, TLG_BW_6);
}

TLG1100DLL_API int TLGAPP_SetChannelMapArgentina(void)
{
    return TLGAPP_SetChannelMap(tlg_argentina_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_NC, TLG_BW_6);
}

TLG1100DLL_API int TLGAPP_SetChannelMapJapan(void)
{
    return TLGAPP_SetChannelMap(tlg_ntsc_japan_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_NTSC_M, TLG_BW_6);
}
 
TLG1100DLL_API int TLGAPP_SetChannelMapChina(void)
{
    return TLGAPP_SetChannelMap(tlg_pald_chn_map, TLG_MODE_ANALOG_TV, 
                         TLG_VSTD_PAL_D, TLG_BW_8);
}
 
TLG1100DLL_API int TLGAPP_SetAudioEnable(int enable ) 
{

	return TLG_SetAudioEnable(tlg_i2c_addr, enable);
}



TLG1100DLL_API int  TLGAPP_GetTVSSI(uint16 * sigindicate)
{
	 TLG_GetTVSSI( tlg_i2c_addr,  sigindicate );
	 return TLG_ERR_SUCCESS;
}


TLG1100DLL_API int   TLGAPP_GetTotalGain(uint16 * totalGain)
{

	TLG_GetTotalGain( tlg_i2c_addr, totalGain );
	return TLG_ERR_SUCCESS;
}

TLG1100DLL_API int   TLGAPP_GetTFCalCode(uint16 * TFCalCode)
{
	TLG_GetTFCalCode( tlg_i2c_addr, TFCalCode );
	return TLG_ERR_SUCCESS;
}

TLG1100DLL_API int   TLGAPP_GetSSI_FOR_TEST( )
{
	return TLG_GetSSI_FOR_TEST(tlg_i2c_addr);
}
 
TLG1100DLL_API int TLGAPP_GetYUVScale(uint16 *y, uint16 *u, uint16 *v)
{
        TLG_GetYUVScale(tlg_i2c_addr,  y, u, v);
        return TLG_ERR_SUCCESS;
}

TLG1100DLL_API int TLGAPP_SetYUVScale(uint16 y, uint16 u, uint16 v)
{
        TLG_SetYUVScale(tlg_i2c_addr, y,  u, v);
        return TLG_ERR_SUCCESS;
}
 


