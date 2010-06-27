/*
 * Copyright (C) Obigo AB, 2002-2006.
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

#ifndef _VERIFY_H /* Prevent multiple inclusion */
#define _VERIFY_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  /* Errors */

#define VERIFY_EBASE (0x0c000000) /* Module Code*/

#define VERIFY_EPARAM (VERIFY_EBASE + 0x00001) /* bad parameter */
#define VERIFY_ENTRNL (VERIFY_EBASE + 0x00002) /* internal failure */



typedef enum {INIT, TEST, WHY, FINISH} verifymode;

typedef int (*testtype)(verifymode, long);

/* Function:  <verify>
 * Syntax:    verify(argc, argv, funcnames, funcdepends, xtraparse, xtrainfo,
 *                testfuncs, testnames);
 * Semantics: Given an application's argc and argv, plus a 0-terminated
 *              sorted array of test names, an array of corresponding test
 *              dependencies, an array of test functions and an array of their
 *              names, this will run a series of tests as indicated by the
 *              command line arguments.  The functions are of type
 *                  int(verifymode mode, long seed)
 *              .. where mode will be one of INIT, TEST, WHY and FINISH:
 *                INIT:   Function should initialize its static variables;
 *                          seed should be used to seed its random number
 *                          generator.
 *                TEST:   Function should run one test.  A return value of 0
 *                          indicates failure, any other value indicates a
 *                          pass.
 *                WHY:    Function should display reason for failure of
 *                          previous test.
 *                FINISH: Function should tidy up after itself - this would
 *                          include freeing any space allocated during INIT.
 *              xtraparse(opt, arg, cmdname, fnames) is a function to parse an
 *                extra command line option (supplied in the verfy_xtraargs)
 *                opt with argument (if applicable) arg.
 *              xtrainfo() is called after the normal timing banner is
 *                dispayed to allow any extra state (such as that controlled
 *                by xtraparse()) to be displayed.
 * Example:   funcnames = {"add", "div", "mul", "sub", 0}
 *            funcdepends = {{add_sub, sub_add, add_mul, 0},
 *                           {mul_div, 0}, {add_mul, mul_div, 0},
 *                           {add_sub, sub_add, 0}}
 *            testfuncs = {add_sub, sub_add, add_mul, mul_div}
 *            testnames = {"add-sub", "sub-add", "add-mul", "mul-div", 0}
 *            command line = "verify -o add,sub -s 9283 -t 3.2"
 *            .. this would run tests add_sub(), sub_add() and add_mul() for
 *              3.2 CPU seconds each with a random number seed of 9283.
 */
extern void CST32EXPORTTYPE CST16EXPORTTYPE verify(int, char **, char **, testtype **,
    void (*)(char, char *, char *, char **), void (*)(void), testtype *,
    char **);

/* Variables: <verfy_xtraargs>, <verfy_xtrahelp>
 * Purpose:   verfy_xtraargs contains a getopt-style list of any extra
 *              arguments which verify should allow - these are parsed by
 *              xtraparse().
 *            verfy_xtrahelp contains a message which is tagged on to the end
 *              of the usage message displayed in case of bad arguments.
 */
extern char *verfy_xtraargs, *verfy_xtrahelp;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* not _VERIFY_H */
