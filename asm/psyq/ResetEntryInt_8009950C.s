	opt	c+, at+, e+, n-
	section .text

	xdef ResetEntryInt_8009950C
ResetEntryInt_8009950C:
	dw 0x240A00B0 ; 0x8009950C
	dw 0x01400008 ; 0x80099510
	dw 0x24090018 ; 0x80099514
	dw 0x00000000 ; 0x80099518