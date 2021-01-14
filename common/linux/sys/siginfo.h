/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*	Copyright (c) 1984, 1986, 1987, 1988, 1989 AT&T	*/
/*	  All Rights Reserved	*/
/* import from illumos-gate/usr/src/uts/common/sys/siginfo.h */

#ifndef _SYS_SIGINFO_H
#define	_SYS_SIGINFO_H

#include <sys/feature_tests.h>
#include <sys/types.h>
#include <signal.h>

/*
 * SIGTRAP signal codes
 */

#define	TRAP_BRKPT	1	/* breakpoint trap */
#define	TRAP_TRACE	2	/* trace trap */
#define	TRAP_RWATCH	3	/* read access watchpoint trap */
#define	TRAP_WWATCH	4	/* write access watchpoint trap */
#define	TRAP_XWATCH	5	/* execute access watchpoint trap */
#define	TRAP_DTRACE	6	/* problem with fasttrap DTrace provider */

#endif
