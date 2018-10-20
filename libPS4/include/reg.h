#pragma once

/*
 * Register set accessible via /proc/$pid/regs and PT_{SET,GET}REGS.
 */
struct reg {
	uint64_t	r_r15;
	uint64_t	r_r14;
	uint64_t	r_r13;
	uint64_t	r_r12;
	uint64_t	r_r11;
	uint64_t	r_r10;
	uint64_t	r_r9;
	uint64_t	r_r8;
	uint64_t	r_rdi;
	uint64_t	r_rsi;
	uint64_t	r_rbp;
	uint64_t	r_rbx;
	uint64_t	r_rdx;
	uint64_t	r_rcx;
	uint64_t	r_rax;
	uint32_t	r_trapno;
	uint16_t	r_fs;
	uint16_t	r_gs;
	uint32_t	r_err;
	uint16_t	r_es;
	uint16_t	r_ds;
	uint64_t	r_rip;
	uint64_t	r_cs;
	uint64_t	r_rflags;
	uint64_t	r_rsp;
	uint64_t	r_ss;
};

/*
 * Register set accessible via /proc/$pid/fpregs.
 */
struct fpreg {
	/*
	 * XXX should get struct from fpu.h.  Here we give a slightly
	 * simplified struct.  This may be too much detail.  Perhaps
	 * an array of unsigned longs is best.
	 */
	unsigned long	fpr_env[4];
	unsigned char	fpr_acc[8][16];
	unsigned char	fpr_xacc[16][16];
	unsigned long	fpr_spare[12];
};

/*
 * Register set accessible via /proc/$pid/dbregs.
 */
/*
 * Register set accessible via /proc/$pid/dbregs.
 */
struct dbreg {
	unsigned long  dr[16];	/* debug registers */
				/* Index 0-3: debug address registers */
				/* Index 4-5: reserved */
				/* Index 6: debug status */
				/* Index 7: debug control */
				/* Index 8-15: reserved */
};

#define	DBREG_DR7_LOCAL_ENABLE	0x01
#define	DBREG_DR7_GLOBAL_ENABLE	0x02
#define	DBREG_DR7_LEN_1		0x00	/* 1 byte length          */
#define	DBREG_DR7_LEN_2		0x01
#define	DBREG_DR7_LEN_4		0x03
#define	DBREG_DR7_LEN_8		0x02
#define	DBREG_DR7_EXEC		0x00	/* break on execute       */
#define	DBREG_DR7_WRONLY	0x01	/* break on write         */
#define	DBREG_DR7_RDWR		0x03	/* break on read or write */
#define	DBREG_DR7_MASK(i)	(0xful << ((i) * 4 + 16) | 0x3 << (i) * 2)
#define	DBREG_DR7_SET(i, len, access, enable) ((uint64_t)((len) << 2 | (access)) << ((i) * 4 + 16) | (enable) << (i) * 2)
#define	DBREG_DR7_GD		0x2000
#define	DBREG_DR7_ENABLED(d, i)	(((d) & 0x3 << (i) * 2) != 0)
#define	DBREG_DR7_ACCESS(d, i)	((d) >> ((i) * 4 + 16) & 0x3)
#define	DBREG_DR7_LEN(d, i)	((d) >> ((i) * 4 + 18) & 0x3)

#define	DBREG_DRX(d,x)	((d)->dr[(x)])	/* reference dr0 - dr15 by register number */
#define	DBREG_DRXX(d,x)	((d).dr[(x)])	/* reference dr0 - dr15 by register number */