fscrypt.cc implements ECB mode


ECB
Takes the input and breaks it into blocks
Runs each block through the cipher individually


CBC
Takes the input and breaks it into blocks
Runs the input through the cipher using the formula
	Ci+1 = E(Ci ^ Pi+1, K)
	Needs an initialization vector to begin 
