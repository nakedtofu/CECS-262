; This program is called "My Little Chasing Cat."

        ORG 0000H
        MOV A, #01H
LOOP:   MOV P1, A
        RL A
		MOV R3, #0FFH
DLY0:   MOV R1, #0FFH
DLY1:   MOV R2, #0FFH
DLY2:   DJNZ R2, DLY2
        DJNZ R1, DLY1
		DJNZ R3, DLY0
		SJMP LOOP
		END