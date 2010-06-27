/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */





#ifndef _MREPORT_H
#define _MREPORT_H








typedef struct
{
    MmsMsgId msgId;           
    MmsReadStatus readStatus; 
} MmsReadReportInfo;











void readReportInitData(void);
void startReadReportCreation(const MmsSignal *sig);
void createReadReport(const MmsSignal *sig);
void createInfoFileForRR (const MmsSignal *sig );
void readReportDone(const MmsSignal *sig);
void create10report(MmsSignal *sig);
void freeReportGlobalData(void);
void deleteNewReadReport(void);

#endif 

