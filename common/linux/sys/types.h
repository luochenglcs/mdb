# if !defined(SYS_TYPES_H)
# define SYS_TYPES_H

# include	<linux_types.h>
typedef short pri_t;
typedef struct _physadr { int r[1]; } *physadr;
typedef struct _lable { int val[10]; } label_t;
#define	P_MYID	(-1)
//# include	"/usr/include/sys/stat.h"
# endif
