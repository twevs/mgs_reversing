	opt	c+, at+, e+, n-
	section .text

	xdef jimctrl_kill_8003853C
jimctrl_kill_8003853C:
	dw 0x27BDFFE8 ; 0x8003853C
	dw 0xAFBF0010 ; 0x80038540
	dw 0x0C00E001 ; 0x80038544
	dw 0x00000000 ; 0x80038548
	dw 0x3C02800A ; 0x8003854C
	dw 0x0C009026 ; 0x80038550
	dw 0xAC40E28C ; 0x80038554
	dw 0x8FBF0010 ; 0x80038558
	dw 0x00000000 ; 0x8003855C
	dw 0x03E00008 ; 0x80038560
	dw 0x27BD0018 ; 0x80038564