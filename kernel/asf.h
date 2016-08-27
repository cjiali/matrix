#pragma once


static inline u8	io_inb(
		u16	port)
{
	u8	data;
	__asm__ ("inb	%%dx, %%al" :
			"=al" (data)
			: "dx" (port));
	return	data;
}


static inline void	io_outb(
		u8	data,
		u16	port)
{
	__asm__ ("outb	%%al, %%dx" ::
			"al" (data),
			"dx" (port));
}


static inline void	io_insb(
		u16	port,
		void	*buf,
		size_t	cnt)
{
	__asm__ ("cld\nrep\ninsb" ::
			"dx" (port),
			"D" (buf),
			"c" (cnt));
}


static inline void	io_insl(
		u16	port,
		void	*buf,
		size_t	cnt)
{
	__asm__ ("cld\nrep\ninsl" ::
			"dx" (port),
			"D" (buf),
			"c" (cnt));
}


static inline void	io_outsb(
		u16	port,
		void	*buf,
		size_t	cnt)
{
	__asm__ ("cld\nrep\noutsb" ::
			"dx" (port),
			"S" (buf),
			"c" (cnt));
}


static inline void	io_outsl(
		u16	port,
		void	*buf,
		size_t	cnt)
{
	__asm__ ("cld\nrep\noutsl" ::
			"dx" (port),
			"S" (buf),
			"c" (cnt));
}


static inline void	io_outw(
		u16	data,
		u16	port)
{
	__asm__ ("outw	%%ax, %%dx" ::
			"ax" (data),
			"dx" (port));
}


static inline void	io_hlt()
{
	__asm__ ("hlt");
}


static inline void	io_sti()
{
	__asm__ ("sti");
}


static inline void	io_cli()
{
	__asm__ ("cli");
}


static inline u32	io_rdmsr(
		u32	addr)
{
	u32	res;
	__asm__ ("rdmsr"
			: "=eax" (res)
			: "ecx" (addr));
	return	res;
}


static inline void	io_wrmsr(
		u32	data,
		u32	addr)
{
	__asm__ ("wrmsr" ::
			"eax" (data), "ecx" (addr));
}


