Brainfuck+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

alias

Brainfuck+^ff

alias

Bf+ff

Bf+ff is a minimalistic esoteric programming language derived from Brainfuck.
Its aim is to have a turing-complete language with as few commands as possible.
This is accomplished by using the already very small command set of Brainfuck (featuring 8 commands) and reducing it.

The Brainfuck commands '-', ',' and '.' are removed. The '-' command can be replaces by 255 '+' commands (due to byte overflow), hence the name of the language ("Brainfuck" followed by 255(=0xff) '+' chars).
Unlike Brainfuck, Bf+ff does not feature distinct tapes for input, data and output, but only one tape, that at the beginning contains the programs input (with the data pointer at the last (=rightmost) character of the input).
When a Bf+ff program is finished, the data from the data pointer to the next data byte that contains a 0 (reading left-to-right) shall be considered as the program's output.
As the input and output are on the same tape as the working data, the '.' and ',' commands of the Brainfuck language are not needed as no data has to be copied from the input tape or to the output tape.

Therefore, five of the eight original Brainfuck commands remain:

	+: increments the value at the data pointer

	<: moves the data pointer one step to the left

	>: moves the data pointer one step to the right

	[: jumps to the command after the matching ']', if the value at the data pointer is 0

	]: jumps to the command after the matching '[' if the value at the data pointer is not 0

Like usually implemented in Brainfuck, all characters, that are not part of the Brainfuck command set are ignored and thus can be used to add commentary to the code.
However, the use of the characters '-', ',' and '.' in Bf+ff may result in unspecified behaviour and thus, they shall not be used in Bf+ff.
