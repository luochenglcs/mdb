# if !defined(SYS_PROCSET_H)
# define	SYS_PROCSET_H

/*
 *      The following defines the values for an identifier type.  It
 *      specifies the interpretation of an id value.  An idtype and
 *      id together define a simple set of processes.
 */
# if 0 /* <sys/wait.h> */
typedef enum
#if !defined(_XPG4_2) || defined(__EXTENSIONS__)
        idtype          /* pollutes XPG4.2 namespace */
#endif
                {
        P_PID,          /* A process identifier.                */
        P_PPID,         /* A parent process identifier.         */
        P_PGID,         /* A process group (job control group)  */
                        /* identifier.                          */
        P_SID,          /* A session identifier.                */
        P_CID,          /* A scheduling class identifier.       */
        P_UID,          /* A user identifier.                   */
        P_GID,          /* A group identifier.                  */
        P_ALL,          /* All processes.                       */
        P_LWPID,        /* An LWP identifier.                   */
        P_TASKID,       /* A task identifier.                   */
        P_PROJID,       /* A project identifier.                */
        P_POOLID,       /* A pool identifier.                   */
        P_ZONEID,       /* A zone identifier.                   */
        P_CTID,         /* A (process) contract identifier.     */
        P_CPUID,        /* CPU identifier.                      */
        P_PSETID        /* Processor set identifier             */
} idtype_t;
# endif

typedef enum idop {
        POP_DIFF,       /* Set difference.  The processes which */
                        /* are in the left operand set and not  */  
                        /* in the right operand set.            */  
        POP_AND,        /* Set disjunction.  The processes      */  
                        /* which are in both the left and right */
                        /* operand sets.                        */  
        POP_OR,         /* Set conjunction.  The processes      */  
                        /* which are in either the left or the  */  
                        /* right operand sets (or both).        */  
        POP_XOR         /* Set exclusive or.  The processes     */  
                        /* which are in either the left or      */  
                        /* right operand sets but not in both.  */  
} idop_t;


/*
 *      The following structure is used to define a set of processes.
 *      The set is defined in terms of two simple sets of processes
 *      and an operator which operates on these two operand sets.
 */
typedef struct procset {
        idop_t          p_op;   /* The operator connection the  */  
                                /* following two operands each  */  
                                /* of which is a simple set of  */  
                                /* processes.                   */  

        idtype_t        p_lidtype;
                                /* The type of the left operand */
                                /* simple set.                  */  
        id_t            p_lid;  /* The id of the left operand.  */  

        idtype_t        p_ridtype;
                                /* The type of the right        */  
                                /* operand simple set.          */  
        id_t            p_rid;  /* The id of the right operand. */
} procset_t;

/*
 *      The following macro can be used to initialize a procset_t
 *      structure.
 */
#define setprocset(psp, op, ltype, lid, rtype, rid) \
                        (psp)->p_op             = (op); \
                        (psp)->p_lidtype        = (ltype); \
                        (psp)->p_lid            = (lid); \
                        (psp)->p_ridtype        = (rtype); \
                        (psp)->p_rid            = (rid);
# endif
