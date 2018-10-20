#pragma once

#define	PT_TRACE_ME	0	/* child declares it's being traced */
#define	PT_READ_I	1	/* read word in child's I space */
#define	PT_READ_D	2	/* read word in child's D space */
/* was	PT_READ_U	3	 * read word in child's user structure */
#define	PT_WRITE_I	4	/* write word in child's I space */
#define	PT_WRITE_D	5	/* write word in child's D space */
/* was	PT_WRITE_U	6	 * write word in child's user structure */
#define	PT_CONTINUE	7	/* continue the child */
#define	PT_KILL		8	/* kill the child process */
#define	PT_STEP		9	/* single step the child */

#define	PT_ATTACH	10	/* trace some running process */
#define	PT_DETACH	11	/* stop tracing a process */
#define PT_IO		12	/* do I/O to/from stopped process. */
#define	PT_LWPINFO	13	/* Info about the LWP that stopped. */
#define PT_GETNUMLWPS	14	/* get total number of threads */
#define PT_GETLWPLIST	15	/* get thread list */
#define PT_CLEARSTEP	16	/* turn off single step */
#define PT_SETSTEP	17	/* turn on single step */
#define PT_SUSPEND	18	/* suspend a thread */
#define PT_RESUME	19	/* resume a thread */

#define	PT_TO_SCE	20
#define	PT_TO_SCX	21
#define	PT_SYSCALL	22

#define	PT_FOLLOW_FORK	23
#define	PT_LWP_EVENTS	24	/* report LWP birth and exit */

#define	PT_GET_EVENT_MASK 25	/* get mask of optional events */
#define	PT_SET_EVENT_MASK 26	/* set mask of optional events */

#define	PT_GET_SC_ARGS	27	/* fetch syscall args */

#define PT_GETREGS      33	/* get general-purpose registers */
#define PT_SETREGS      34	/* set general-purpose registers */
#define PT_GETFPREGS    35	/* get floating-point registers */
#define PT_SETFPREGS    36	/* set floating-point registers */
#define PT_GETDBREGS    37	/* get debugging registers */
#define PT_SETDBREGS    38	/* set debugging registers */

#define	PT_VM_TIMESTAMP	40	/* Get VM version (timestamp) */
#define	PT_VM_ENTRY	41	/* Get VM map (entry) */

#define PT_FIRSTMACH    64	/* for machine-specific requests */

/* Events used with PT_GET_EVENT_MASK and PT_SET_EVENT_MASK */
#define	PTRACE_EXEC	0x0001
#define	PTRACE_SCE	0x0002
#define	PTRACE_SCX	0x0004
#define	PTRACE_SYSCALL	(PTRACE_SCE | PTRACE_SCX)
#define	PTRACE_FORK	0x0008
#define	PTRACE_LWP	0x0010
#define	PTRACE_VFORK	0x0020

#define	PTRACE_DEFAULT	(PTRACE_EXEC)

struct ptrace_io_desc {
	int	piod_op;	/* I/O operation */
	void	*piod_offs;	/* child offset */
	void	*piod_addr;	/* parent offset */
	size_t	piod_len;	/* request length */
};

/*
 * Operations in piod_op.
 */
#define PIOD_READ_D	1	/* Read from D space */
#define PIOD_WRITE_D	2	/* Write to D space */
#define PIOD_READ_I	3	/* Read from I space */
#define PIOD_WRITE_I	4	/* Write to I space */

/* 0x4200-0x4300 are reserved for architecture-independent additions.  */
#define PTRACE_SETOPTIONS       0x4200
#define PTRACE_GETEVENTMSG      0x4201
#define PTRACE_GETSIGINFO       0x4202
#define PTRACE_SETSIGINFO       0x4203

#define __LOW(v)	((v) & 0377)
#define __HIGH(v)	(((v) >> 8) & 0377)

#define WNOHANG         1	/* do not wait for child to exit */
#define WUNTRACED       2	/* for job control; not implemented */

#define WIFEXITED(s)	(__LOW(s) == 0)		    /* normal exit */
#define WEXITSTATUS(s)	(__HIGH(s))			    /* exit status */
#define WTERMSIG(s)	(__LOW(s) & 0177)		    /* sig value */
#define WIFSIGNALED(s)	((((unsigned int)(s)-1) & 0xFFFF) < 0xFF) /* signaled */
#define WIFSTOPPED(s) (__LOW(s) == 0177)		    /* stopped */
#define WSTOPSIG(s)	(__HIGH(s) & 0377)		    /* stop signal */

#define	SIGHUP	1	/* hangup */
#define	SIGINT	2	/* interrupt */
#define	SIGQUIT	3	/* quit */
#define	SIGILL	4	/* illegal instruction (not reset when caught) */
#define	SIGTRAP	5	/* trace trap (not reset when caught) */
#define	SIGABRT	6	/* abort() */
#define	SIGIOT	SIGABRT	/* compatibility */
#define	SIGEMT	7	/* EMT instruction */
#define	SIGFPE	8	/* floating point exception */
#define	SIGKILL	9	/* kill (cannot be caught or ignored) */
#define	SIGBUS	10	/* bus error */
#define	SIGSEGV	11	/* segmentation violation */
#define	SIGSYS	12	/* bad argument to system call */
#define	SIGPIPE	13	/* write on a pipe with no one to read it */
#define	SIGALRM	14	/* alarm clock */
#define	SIGTERM	15	/* software termination signal from kill */
#define	SIGURG	16	/* urgent condition on IO channel */
#define	SIGSTOP	17	/* sendable stop signal not from tty */
#define	SIGTSTP	18	/* stop signal from tty */
#define	SIGCONT	19	/* continue a stopped process */
#define	SIGCHLD	20	/* to parent on child stop or exit */
#define	SIGTTIN	21	/* to readers pgrp upon background tty read */
#define	SIGTTOU	22	/* like TTIN for output if (tp->t_local&LTOSTOP) */
#define	SIGIO	23	/* input/output possible signal */
#define	SIGXCPU	24	/* exceeded CPU time limit */
#define	SIGXFSZ	25	/* exceeded file size limit */
#define	SIGVTALRM 26	/* virtual time alarm */
#define	SIGPROF	27	/* profiling time alarm */
#define SIGWINCH 28	/* window size changes */
#define SIGINFO	29	/* information request */
#define SIGUSR1 30	/* user defined signal 1 */
#define SIGUSR2 31	/* user defined signal 2 */